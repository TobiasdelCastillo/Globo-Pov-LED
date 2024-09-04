#if defined(ESP32)
  #include <WiFi.h> //inicializamos la libreria de wifi para esp32
#endif
///////////////////////apa102/////////////////////////
#include <FastLED.h>
#define NUM_LEDS 24
#define DATA_PIN 23
#define CLOCK_PIN 22
int infrarrojo=15;
int valor=0;
CRGB leds[NUM_LEDS];

unsigned char i;
unsigned char m;
unsigned int wait = 100;
unsigned int wait2 = 1000;
bool hall = 1;
bool S[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{1,0,0,0,0,0,0},
{1,0,0,0,0,0,0},
{1,1,1,1,1,1,1},

};

bool E[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
};
bool P[8][7] = {
  

{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
  
};

bool T[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},

};
bool I[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{1,1,1,1,1,1,1},

};
bool M[8][7] = {

{1,1,0,0,0,1,1},
{1,0,1,0,1,0,1},
{1,0,0,1,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},

};
bool O[8][7] = {

{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,1,1,1,1,1,1},

};
//////////////////////////////////////


///////////////////////////////////////////////////////
bool A[8][7] = {

{0,0,0,1,0,0,0},
{0,0,1,0,1,0,0},
{0,1,0,0,0,1,0},
{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},

};
bool B[8][7] = {

{0,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{0,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{0,1,1,1,1,1,1},

};
bool C[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},

};
bool D[8][7] = {

{0,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{0,1,1,1,1,1,1},

};
bool F[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},

};
bool G[8][7] = {

{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,1,1,1,1,1,1},

};
bool H[8][7] = {

{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},

};
bool J[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{1,0,0,1,0,0,0},
{1,1,1,1,0,0,0},

};
bool K[8][7] = {

{1,1,0,0,0,0,1},
{1,0,1,0,0,0,1},
{1,0,0,1,0,0,1},
{1,0,0,0,1,1,1},
{1,0,0,0,1,1,1},
{1,0,0,1,0,0,1},
{1,0,1,0,0,0,1},
{1,1,0,0,0,0,1},

};
bool L[8][7] = {

{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},

};
bool U[8][7] = {

{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,1,1,1,1,1,1},

};
bool V[8][7] = {

{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{0,1,0,0,0,1,0},
{0,0,1,0,1,0,0},
{0,0,0,1,0,0,0},

};
bool W[8][7] = {

{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,1,0,0,1},
{1,0,1,0,1,0,1},
{1,1,0,0,0,1,1},

};
bool X[8][7] = {

{1,0,0,0,0,0,1},
{0,1,0,0,0,1,0},
{0,0,1,0,1,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,1,0,1,0,0},
{0,1,0,0,0,1,0},
{1,0,0,0,0,0,1},

};
bool Q[8][7] = {

{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{0,0,0,1,0,0,0},
{0,0,1,0,0,0,0},

};
bool Y[8][7] = {

{1,0,0,0,0,0,1},
{0,1,0,0,0,1,0},
{0,0,1,0,1,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},

};
bool Z[8][7] = {

{1,1,1,1,1,1,1},
{0,1,0,0,0,0,0},
{0,0,1,0,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,0,1,0,0},
{0,0,0,0,0,1,0},
{1,1,1,1,1,1,1},

};
bool N[8][7] = {

{1,0,0,0,0,0,1},
{1,0,0,0,0,1,1},
{1,0,0,0,1,0,1},
{1,0,0,1,0,0,1},
{1,0,0,1,0,0,1},
{1,0,1,0,0,0,1},
{1,1,0,0,0,0,1},
{1,0,0,0,0,0,1},

};
bool ESPACIO[8][7] = {

{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},

};

///////////////////////////////apa102//////////////////////////////

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


  ///////////////apa102//////////////////////
  
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);


//////////////////apa102///////////////////////////

  

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


            if (header.indexOf("GET /1") >= 0) { // con el on u off encendemos o apagamos el servidor web, lo cambiamos en la direccion URL// manipulamos nuestra salida
              Serial.println("GPIO encendido1");
              outputState = "encendido1";
             for(int i=0;i<20;i++){
    leds[i] = CRGB::Blue;
  }

     for(int i=20;i<40;i++){
    leds[i] = CRGB::Yellow;
  }
   for(int i=40;i<60;i++){
    leds[i] = CRGB::Blue;
  }  
      for(int i=60;i<80;i++){
    leds[i] = CRGB::Blue;
  }

     for(int i=80;i<100;i++){
    leds[i] = CRGB::Yellow;
  }
   for(int i=100;i<120;i++){
    leds[i] = CRGB::Blue;
  }    
  FastLED.show();
  delay(1000);

  }
  if (header.indexOf("GET /0") >= 0) { // con el on u off encendemos o apagamos el servidor web, lo cambiamos en la direccion URL// manipulamos nuestra salida
              Serial.println("GPIO encendido1");
              outputState = "encendido1";
                         for(int i=0;i<20;i++){
    leds[i] = CRGB::Black;
  }

     for(int i=20;i<40;i++){
    leds[i] = CRGB::Black;
  }
   for(int i=40;i<60;i++){
    leds[i] = CRGB::Black;
  }  
      for(int i=60;i<80;i++){
    leds[i] = CRGB::Black;
  }

     for(int i=80;i<100;i++){
    leds[i] = CRGB::Black;
  }
   for(int i=100;i<120;i++){
    leds[i] = CRGB::Black;
  }    
  FastLED.show();
  delay(1000);

  
                                    
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
