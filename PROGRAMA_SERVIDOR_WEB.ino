#if defined(ESP32)
  #include <WiFi.h> //inicializamos la libreria de wifi para esp32
#endif

const char* ssid = "COLEGIO ROBLES"; // determinas el nombre de la red a la que nos vamos a conectar
const char* password = "Laboratorio123"; // determinamos la contraseña de la red a la que nos vamos a conectar

WiFiServer server(80); //declaramos el controlador esp32 como servidor

String header; // variable para almacenar el protocolo de comunicacion que vamos a usar (http)

unsigned long lastTime, timeout = 2000; //declaramos los tiempos de espera del cliente

///////////// CODIGO ///////////////

const int outputPin = 4; // pin de salida // declaramos el pin de salida (en placa d3)
String outputState = "apagado"; //almacenar el estado actual de la salida


void setup() {

  
  Serial.begin(115200); // iniciamos el puerto serial con una velocidad de 115200 baudios

  pinMode(outputPin, OUTPUT); 
  digitalWrite(outputPin, LOW); //configuramos el pin de salida
  
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid,password); // conectamos a la red

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Dispositivo conectado.");
  Serial.println("Direccion IP: ");
  Serial.print(WiFi.localIP()); //mostramos la direccion ip necesaria para acceder al servidor desde la aplicacion

  server.begin(); //iniciamos el servidor

}

void loop() {

  WiFiClient client = server.available(); // verificamos si hay un cliente para conectarse

  if(client)
  {
    lastTime = millis();
    
    Serial.println("Nuevo cliente");
    String currentLine = "";

    while(client.connected() && millis() - lastTime <= timeout)
    {

      if(client.available())
      {
        
        char c = client.read();
        Serial.write(c);
        header += c;

        if(c == '\n')
        {
          
          if(currentLine.length() == 0)
          {

            ////////// ENCABEZADO HTTP ////////////

            client.println("HTTP/1.1 200 OK"); // lo primero que se muestra en el encabezado
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();


            if (header.indexOf("GET /on") >= 0) { // con el on u off encendemos o apagamos el servidor web, lo cambiamos en la direccion URL// manipulamos nuestra salida
              Serial.println("GPIO encendido");
              outputState = "encendido";
              digitalWrite(outputPin, HIGH);
            }                         
            else if (header.indexOf("GET /off") >= 0) {
              Serial.println("GPIO apagado");
              outputState = "apagado";
              digitalWrite(outputPin, LOW);
            } 
            

             //////// PAGINA WEB ////////////// DISEÑO
             
            client.println("<!DOCTYPE html><html>"); // etiquetas basicas de una pagina sin configurar, por que los vamos a configurar en APP INVENTOR
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"); // encabezado
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("</head>");

            client.println("<body></body>"); //cuerpo

            client.println("</html>");

            client.println();
            break;

            
            /////////////////////////////////////
          }
          else
          {
            currentLine = "";
          }
        }
        else if ( c != '\r')
        {
          currentLine += c;
        }
        
        
      }

      
    }

    header = "";
    client.stop();
    Serial.println("Cliente desconectado.");
    Serial.println("");
  }

}
