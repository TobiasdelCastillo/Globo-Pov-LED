#if defined(ESP32)
  #include <WiFi.h> //inicializamos la libreria de wifi para esp32
#endif
///////////////////////apa102/////////////////////////
#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 23
#define CLOCK_PIN 22
int infrarrojo=15;
int valor=0;
CRGB leds[NUM_LEDS];

unsigned char i;
unsigned char m;
bool hall = 1;
unsigned int wait = 100;
unsigned int wait2 = 1000;

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


///////////////////////////////apa102//////////////////////////////

const char* ssid = "Wifi del Castillo 2.4GHZ"; // determinas el nombre de la red a la que nos vamos a conectar
const char* password = "Pakamatode2022"; // determinamos la contraseña de la red a la que nos vamos a conectar

WiFiServer server(80); //declaramos el controlador esp32 como servidor

String header; // variable para almacenar el protocolo de comunicacion que vamos a usar (http)

unsigned long lastTime, timeout = 2000; //declaramos los tiempos de espera del cliente

///////////// CODIGO ///////////////



void setup() {
  
  Serial.begin(115200); // iniciamos el puerto serial con una velocidad de 115200 baudios


  ///////////////apa102//////////////////////
  
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
  pinMode(infrarrojo, INPUT);


//////////////////apa102///////////////////////////

  

  
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


            while (header.indexOf("GET /uno") >= 0) { // con el on u off encendemos o apagamos el servidor web, lo cambiamos en la direccion URL// manipulamos nuestra salida
              Serial.println("GPIO encendido1");
              

                valor= digitalRead(infrarrojo);
  if(valor==LOW){
    Serial.println("boca");
            for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (O[i][m] == 1) {
          leds[i + 11] = CRGB::Red;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

    for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (M[i][m] == 1) {
          leds[i + 11] = CRGB::Green;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

    for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (I[i][m] == 1) {
          leds[i + 11] = CRGB::Yellow;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

     for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (T[i][m] == 1) {
          leds[i + 11] = CRGB::Blue;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

     for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (P[i][m] == 1) {
          leds[i + 11] = CRGB::Orange;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

     for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (E[i][m] == 1) {
          leds[i + 11] = CRGB::Purple;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

     for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (S[i][m] == 1) {
          leds[i + 11] = CRGB::White;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

   
    for (int i = 11; i < 17; i++) {
      leds[i] = CRGB ::Red;
    }
    leds[18] = CRGB::Red;
    FastLED.show();
    delayMicroseconds(wait);

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);


  
  }
  if(valor==HIGH){
    Serial.println("nada");
  for(int i=0;i<120;i++){
    leds[i] = CRGB::Black;
  }
  
  }
    FastLED.show();
   delayMicroseconds(wait);



            }

           
             while(header.indexOf("GET /dos") >= 0) { // con el on u off encendemos o apagamos el servidor web, lo cambiamos en la direccion URL// manipulamos nuestra salida
              Serial.println("GPIO encendido2");
              

                valor= digitalRead(infrarrojo);
  if(valor==LOW){
    Serial.println("verde");
             for(int i=0;i<20;i++){
    leds[i] = CRGB::Red;
  }

     for(int i=20;i<40;i++){
    leds[i] = CRGB::Green;
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


  
  }
  if(valor==HIGH){
    Serial.println("nada2");
  for(int i=0;i<120;i++){
    leds[i] = CRGB::Black;
  }
  
  }
    FastLED.show();
   delayMicroseconds(wait);

 
             }
            
 

  if (header.indexOf("GET /tres") >= 0) { // con el on u off encendemos o apagamos el servidor web, lo cambiamos en la direccion URL// manipulamos nuestra salida
              Serial.println("GPIO encendido3");
              
                         for(int i=0;i<20;i++){

                valor= digitalRead(infrarrojo);
  if(valor==LOW){
    Serial.println("verde");
             for(int i=0;i<20;i++){
    leds[i] = CRGB::Blue;
  }

     for(int i=20;i<40;i++){
    leds[i] = CRGB::Green;
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


  
  }
  if(valor==HIGH){
    Serial.println("nada2");
  for(int i=0;i<120;i++){
    leds[i] = CRGB::Black;
  }
  
  }
    FastLED.show();
   delayMicroseconds(wait);

 
             }

   if (header.indexOf("GET /nada1") >= 0) { // con el on u off encendemos o apagamos el servidor web, lo cambiamos en la direccion URL// manipulamos nuestra salida
              Serial.println("GPIO apagado1");
              
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
   if (header.indexOf("GET /nada2") >= 0) { // con el on u off encendemos o apagamos el servidor web, lo cambiamos en la direccion URL// manipulamos nuestra salida
              Serial.println("GPIO apagado2");
              
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
  if (header.indexOf("GET /nada3") >= 0) { // con el on u off encendemos o apagamos el servidor web, lo cambiamos en la direccion URL// manipulamos nuestra salida
              Serial.println("GPIO apagado3");
              
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
          else //// doble salto de linea para verificar si hay un servidor disponible
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
