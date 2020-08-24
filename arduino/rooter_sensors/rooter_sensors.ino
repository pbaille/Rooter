#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <BH1750.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Adafruit_BME280.h>
#include <Arduino.h>
//#include <analogWrite.h>

#define I2C_SDA 21
#define I2C_SCL 22
Adafruit_BME280 bme;
BH1750 lightMeter (0x23);
#define DHTPIN 7 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht = DHT(DHTPIN, DHTTYPE);
#define SEALEVELPRESSURE_HPA (1013.25)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);


int SoilPin1 = A0;
int SoilPin2 = A1;
//int SoilPin3 = A2;
//int SoilPin4 = A3;
int redPin1 = 27;
int greenPin1 = 28;
int bluePin1 = 26;
int redPin2 = 23;
int greenPin2 = 24;
int bluePin2 = 22;
//int redPin3 = 12;
//int greenPin3 = 11;
//int bluePin3 = 10;
//int redPin4 = 15;
//int greenPin4 = 14;
//int bluePin4 = 13;
int sensorValue1 = 0;
int sensorValue2 = 0;
//int sensorValue3 = 0;
//int sensorValue4 = 0;
//int sensorValue5 = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  lightMeter.begin(BH1750::CONTINUOUS_LOW_RES_MODE);
  dht.begin();
  !bme.begin(0x76);
  
  lcd.init();
  lcd.backlight();
  
  /*//Set BH1750 measurement mode
  if (lightMeter.begin(BH1750::CONTINUOUS_LOW_RES_MODE)) {
    Serial.println(F("BH1750-Initialized"));
  }
  else {
    Serial.println(F("Error-initialising-BH1750"));
  }
  Serial.println("DHT22-test!");
  dht.begin();

  if (!bme.begin(0x76)) {
    Serial.println("Could-not-find-a-valid-BME280-sensor-check-wiring!");
    while (1);
  }*/
  
  //pinMode(SoilPin1, INPUT);
  //pinMode(SoilPin2, INPUT);
  //pinMode(SoilPin3, INPUT);
  //pinMode(SoilPin4, INPUT);
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  //pinMode(redPin3, OUTPUT);
  //pinMode(greenPin3, OUTPUT);
  //pinMode(bluePin3, OUTPUT);
  //pinMode(redPin4, OUTPUT);
  //pinMode(greenPin4, OUTPUT);
  //pinMode(bluePin4, OUTPUT);
  

}

void loop() {
    
  float t1 = dht.readTemperature();
  float h1 = dht.readHumidity();
  float t2 = bme.readTemperature();
  float h2 = bme.readHumidity();
  float pres = bme.readPressure() / 100.0F;
  float alt = bme.readAltitude(SEALEVELPRESSURE_HPA);
  uint16_t lux = lightMeter.readLightLevel();

  delay(5000);

  /*for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }

  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }

  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }*/
  
  
  /*Compute heat index in Fahrenheit (default):
  float hif = dht.computeHeatIndex(f, h);
  Compute heat index in Celsius:
  float hic = dht.computeHeatIndex(t, h, false);*/
  
  /*Serial.print("--- Heat index: ");
  Serial.print(hic);
  Serial.print(" \xC2\xB0");
  Serial.println("C | ");*/
  
  
  Serial.print(t1);
  Serial.print(" , ");
  
  Serial.print(t2);
  Serial.print(" , ");
  
  Serial.print(h1);
  Serial.print(" , ");
  
  Serial.print(h2);
  Serial.print(" , ");
  
  Serial.print(pres);
  Serial.print(" , ");
  
  
  Serial.print(lux);
  Serial.print(" , ");
  
  /*Serial.print(alt);
  Serial.print(" , ");*/
  
  sensorValue1 = analogRead(SoilPin1);
  sensorValue1 = map(sensorValue1, 250, 450, 100, 0);
  //analogWrite(9, sensorValue1);
  Serial.print(sensorValue1);
  Serial.print(" , ");
  if(sensorValue1 >= 80){
    //Serial.println(" (Soak)");
    digitalWrite(redPin1, 0);
    digitalWrite(greenPin1, 0);
    digitalWrite(bluePin1, 255);
    }
  else if(sensorValue1 >= 50 && sensorValue1 < 80){
    digitalWrite(redPin1, 0);
    digitalWrite(greenPin1, 255);
    digitalWrite(bluePin1, 0);
    }
  else if(sensorValue1 >= 30 && sensorValue1 < 50){
    digitalWrite(redPin1, 255);
    digitalWrite(greenPin1, 255);
    digitalWrite(bluePin1, 0);
    }
  else if(sensorValue1 < 30){
    digitalWrite(redPin1, 255);
    digitalWrite(greenPin1, 0);
    digitalWrite(bluePin1, 0);
    }  
    
    
  sensorValue2 = analogRead(SoilPin2);
  sensorValue2 = map(sensorValue2, 250, 450, 100, 0);
  //analogWrite(9, sensorValue2);
  Serial.print(sensorValue2);
  Serial.println(" , ");
  if(sensorValue2 >= 80){
    digitalWrite(redPin2, 0);
    digitalWrite(greenPin2, 0);
    digitalWrite(bluePin2, 255);
    }
  else if(sensorValue2 >= 50 && sensorValue2 < 80){
    digitalWrite(redPin2, 0);
    digitalWrite(greenPin2, 255);
    digitalWrite(bluePin2, 0);
    }
  else if(sensorValue2 >= 30 && sensorValue2 < 50){
    digitalWrite(redPin2, 255);
    digitalWrite(greenPin2, 185);
    digitalWrite(bluePin2, 0);
    }
  else if(sensorValue2 < 30){
    digitalWrite(redPin2, 255);
    digitalWrite(greenPin2, 0);
    digitalWrite(bluePin2, 0);
    }
  
/*    
sensorValue3 = analogRead(SoilPin3);
  sensorValue3 = map(sensorValue3, 180, 630, 100, 0);
  analogWrite(9, sensorValue3);
  Serial.print("--- BASILIC: ");
  Serial.print(sensorValue3);
  Serial.print("% ");
  if(sensorValue3 >= 80){
    Serial.println(" (Soak)");
    digitalWrite(redPin3, 0);
    digitalWrite(greenPin3, 0);
    digitalWrite(bluePin3, 255);
    }
  else if(sensorValue3 >= 50 && sensorValue3 < 80){
    Serial.println(" (Wet)");
    digitalWrite(redPin3, 0);
    digitalWrite(greenPin3, 255);
    digitalWrite(bluePin3, 0);
    }
  else if(sensorValue3 >= 30 && sensorValue3 < 50){
    Serial.println(" (almost Dry)");
    digitalWrite(redPin3, 255);
    digitalWrite(greenPin3, 255);
    digitalWrite(bluePin3, 0);
    }
  else if(sensorValue3 < 30){
    Serial.println(" (Dry)");
    digitalWrite(redPin3, 255);
    digitalWrite(greenPin3, 0);
    digitalWrite(bluePin3, 0);
    }*/
/*
sensorValue4 = analogRead(SoilPin4);
  sensorValue4 = map(sensorValue4, 180, 630, 100, 0);
  analogWrite(9, sensorValue4);
  Serial.print("--- BASILIC: ");
  Serial.print(sensorValue4);
  Serial.print("% ");
  if(sensorValue4 >= 80){
    Serial.println(" (Soak)");
    digitalWrite(redPin4, 0);
    digitalWrite(greenPin4, 0);
    digitalWrite(bluePin4, 255);
    }
  else if(sensorValue4 >= 50 && sensorValue4 < 80){
    Serial.println(" (Wet)");
    digitalWrite(redPin4, 0);
    digitalWrite(greenPin4, 255);
    digitalWrite(bluePin4, 0);
    }
  else if(sensorValue4 >= 30 && sensorValue4 < 50){
    Serial.println(" (almost Dry)");
    digitalWrite(redPin4, 255);
    digitalWrite(greenPin4, 255);
    digitalWrite(bluePin4, 0);
    }
  else if(sensorValue4 < 30){
    Serial.println(" (Dry)");
    digitalWrite(redPin4, 255);
    digitalWrite(greenPin4, 0);
    digitalWrite(bluePin4, 0);
    }
*/


  lcd.clear();
  lcd.setCursor(0, 0); // set the cursor to column 0, line 2
  lcd.print("Temperature (in/out)");//print name
  lcd.setCursor(0, 1);
  lcd.print(t1);
  lcd.print(" / ");
  lcd.print(t2);
  lcd.print(" C");
  lcd.setCursor(0, 2); // set the cursor to column 0, line 2
  lcd.print("Humidity (in/out)");//print name
  lcd.setCursor(0, 3);
  lcd.print(h1);
  lcd.print(" / ");
  lcd.print(h2);
  lcd.print(" %");
  
  delay(45000);
  
  lcd.clear();
  lcd.setCursor(0, 0); // set the cursor to column 0, line 2
  lcd.print("Pressure");//print name
  lcd.setCursor(0, 1);
  lcd.print(pres);
  lcd.print(" hPa");
  lcd.setCursor(0, 2); // set the cursor to column 0, line 2
  lcd.print("Light");//print name
  lcd.setCursor(0, 3);
  lcd.print(lux);
  lcd.print(" lux");
  
  delay(45000);
  
  /*lcd.clear();
  lcd.setCursor(0, 0); // set the cursor to column 0, line 2
  lcd.print("The ROOTER v2.1");//print name
  lcd.setCursor(0, 1);
  lcd.print("192.168.20.166");*/


  lcd.clear();
  lcd.setCursor(0, 0); // set the cursor to column 0, line 2
  lcd.print("Open your browser &");//print name
  lcd.setCursor(0, 1); // set the cursor to column 0, line 2
  lcd.print("check your ROOTER at");//print name
  lcd.setCursor(0, 3);
  if (Serial.available()) {
    while (Serial.available() > 0) {
      char c = Serial.read();
      lcd.write(c);
    }
  lcd.print(":5000");
  }

  /*if (Serial.available() > 0) {
    lcd.setCursor(0, 1);
    char c = Serial.read();
    lcd.write(c);
  }*/

  
  //else {
  //  lcd.print("Is Not Running");
  //}

  
  delay(25000);

  
}

/*void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin1, redValue);
  analogWrite(greenPin1, greenValue);
  analogWrite(bluePin1, blueValue);
  analogWrite(redPin2, redValue);
  analogWrite(greenPin2, greenValue);
  analogWrite(bluePin2, blueValue);
}*/
