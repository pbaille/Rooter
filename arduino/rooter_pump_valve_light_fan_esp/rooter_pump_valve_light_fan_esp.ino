#include <ESP8266WiFi.h>

const char* ssid = "BELL345";
const char* password = "!V3ymgdESuSq10BTme4fLIe?";
WiFiServer server(80);


const int pump1 = 2;
const int valve1 = 0;
const int valve2 = 13;
const int valve3 = 12;
const int valve4 = 14;
const int valve5 = 4;
const int valve6 = 5;
const int led1 = 16;
const int fan1 = 1;
const int led2 = 3;
const int fan2 = 15;
/*
const int leds1 = 15;
const int leds2 = 16;
const int fans1 = 1;
const int fans2 = 3;
*/



void setup() {
  Serial.begin(115200);
  delay(2000);
  
  pinMode(pump1, OUTPUT);
  digitalWrite(pump1, HIGH);
  pinMode(valve1, OUTPUT);
  digitalWrite(valve1, HIGH);
  pinMode(valve2, OUTPUT);
  digitalWrite(valve2, HIGH);
  pinMode(valve3, OUTPUT);
  digitalWrite(valve3, HIGH);
  pinMode(valve4, OUTPUT);
  digitalWrite(valve4, HIGH);
  pinMode(valve5, OUTPUT);
  digitalWrite(valve5, HIGH);
  pinMode(valve6, OUTPUT);
  digitalWrite(valve6, HIGH);
  pinMode(led1, OUTPUT);
  digitalWrite(led1, HIGH);
  pinMode(fan1, OUTPUT);
  digitalWrite(fan1, HIGH);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, HIGH);
  pinMode(fan2, OUTPUT);
  digitalWrite(fan2, HIGH);

  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
  
}

   
void loop() {
  // Control de la connection client
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

 
  int value = LOW;
  int ledValue1 = LOW;
  int ledValue2 = LOW;
  int fanValue1 = LOW;
  int fanValue2 = LOW;


  //valve1
  if (value != HIGH && request.indexOf("/VALVE=11") != -1)  {
    value = HIGH;
    digitalWrite(valve1, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(30000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve1, HIGH);
    value = LOW; 
  }
  if (value != HIGH && request.indexOf("/VALVE=14") != -1)  {
    value = HIGH;
    digitalWrite(valve1, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(120000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve1, HIGH);
    value = LOW; 
  }

  //valve2
  if (value != HIGH && request.indexOf("/VALVE=21") != -1)  {
    value = HIGH;
    digitalWrite(valve2, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(30000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve2, HIGH);
    value = LOW;
  }
  if (value != HIGH && request.indexOf("/VALVE=24") != -1)  {
    value = HIGH;
    digitalWrite(valve2, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(120000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve2, HIGH);
    value = LOW;
  }

  //valve3
  if (value != HIGH && request.indexOf("/VALVE=31") != -1)  {
    value = HIGH;
    digitalWrite(valve3, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(30000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve3, HIGH);
    value = LOW;
  }
  if (value != HIGH && request.indexOf("/VALVE=34") != -1)  {
    value = HIGH;
    digitalWrite(valve3, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(120000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve3, HIGH);
    value = LOW;
  }

  //valve4
  if (value != HIGH && request.indexOf("/VALVE=41") != -1)  {
    value = HIGH;
    digitalWrite(valve4, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(30000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve4, HIGH);
    value = LOW;
  }
  if (value != HIGH && request.indexOf("/VALVE=44") != -1)  {
    value = HIGH;
    digitalWrite(valve4, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(120000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve4, HIGH);
    value = LOW;
  }

  //valve5
  if (value != HIGH && request.indexOf("/VALVE=51") != -1)  {
    value = HIGH;
    digitalWrite(valve5, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(30000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve5, HIGH);
    value = LOW;
  }
  if (value != HIGH && request.indexOf("/VALVE=54") != -1)  {
    value = HIGH;
    digitalWrite(valve5, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(120000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve5, HIGH);
    value = LOW;
  }

  //valve6
  if (value != HIGH && request.indexOf("/VALVE=61") != -1)  {
    value = HIGH;
    digitalWrite(valve6, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(30000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve6, HIGH);
    value = LOW;
  }
  if (value != HIGH && request.indexOf("/VALVE=64") != -1)  {
    value = HIGH;
    digitalWrite(valve6, LOW);
    delay(500);
    digitalWrite(pump1, LOW);
    delay(120000);
    digitalWrite(pump1, HIGH);
    delay(500);
    digitalWrite(valve6, HIGH);
    value = LOW;
  }


  //LEDS & FANS
  if (request.indexOf("/LED1=ON") != -1)  {
    ledValue1 = HIGH;
    digitalWrite(led1, LOW);
    
  }
  if (request.indexOf("/LED1=OFF") != -1)  {
    ledValue1 = LOW;
    digitalWrite(led1, HIGH);
    
  }
 
  if (request.indexOf("/LED2=ON") != -1)  {
    ledValue2 = HIGH;
    digitalWrite(led2, LOW);
    
  }
  if (request.indexOf("/LED2=OFF") != -1)  {
    ledValue2 = LOW;
    digitalWrite(led2, HIGH);
    
  }

  if (request.indexOf("/FAN1=ON") != -1)  {
    fanValue1 = HIGH;
    digitalWrite(fan1, LOW);
    
  }
  if (request.indexOf("/FAN1=OFF") != -1)  {
    fanValue1 = LOW;
    digitalWrite(fan1, HIGH);
    
  }

  if (request.indexOf("/FAN2=ON") != -1)  {
    fanValue2 = HIGH;
    digitalWrite(fan2, LOW);
    
  }
  if (request.indexOf("/FAN2=OFF") != -1)  {
    fanValue2 = LOW;
    digitalWrite(fan2, HIGH);
    
  }



  
  

 
  // Réponse à la requête
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("</head>");
  client.println("<body>");

  /*
  client.println("<div style=\"text-align:center\">");
  
  client.println("<p style=\"text-align:center; font-weight: bold; font-size: 50px;\">Garden</p><br>");

  
  client.println("<a href=\"/VALVE=1\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> Water 1 </button></a>");
  client.println("<a href=\"/VALVE=2\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> Water 2 </button></a>");
  client.println("<a href=\"/VALVE=3\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> Water 3 </button></a><br><br>");
  client.println("<a href=\"/VALVE=4\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> Water 4 </button></a>");
  client.println("<a href=\"/VALVE=5\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> Water 5 </button></a>");
  client.println("<a href=\"/VALVE=6\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> Water 6 </button></a><br><br>");

  client.println("<a href=\"/LED1=ON\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> LED 1 on </button></a>");
  client.println("<a href=\"/LED1=OFF\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> LED 1 off </button></a>");
 
  client.println("<a href=\"/FAN1=ON\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> FAN 1 on </button></a>");
  client.println("<a href=\"/FAN1=OFF\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> FAN 1 off </button></a><br><br>");
 
  client.println("<a href=\"/LED2=ON\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> LED 2 on </button></a>");
  client.println("<a href=\"/LED2=OFF\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> LED 2 off </button></a>");

  client.println("<a href=\"/FAN2=ON\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> fan 2 on </button></a>");
  client.println("<a href=\"/FAN2=OFF\"\"><button style=\"height: 150px; width: 150px; background-color: #FFFFFF; font-size: 30px; font-weight: bold; border-radius: 30px; color: #000000\"> fan 2 off </button></a><br><br>");
  */


 
  client.println("</body>");
  client.println("</html>");
 
  delay(100);
  Serial.println("Client disconnected");
  Serial.println("");

  /*DHT.read11(dht_apin);
  int temp = DHT.temperature;
  Serial.print("temperature = ");
  Serial.print(temp); 
  Serial.println(" C");
  if (temp > 29) {
    mySender.send(rawDataOn,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(F("AC Switched On"));
  }
  else if (temp < 26) {
    mySender.send(rawDataOff,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(F("AC Switched Off"));
  }
  delay(5000);*/
}
