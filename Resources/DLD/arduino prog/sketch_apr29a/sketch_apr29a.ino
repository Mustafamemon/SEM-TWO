#define USE_ARDUINO_INTERRUPTS true // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h> // Includes the PulseSensorPlayground Library.
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include<SPI.h>
#include<SD.h>

const int rxPin = 0;
const int txPin = 1;

const int LED13 = 10;

SoftwareSerial mySerial(rxPin, txPin);

LiquidCrystal lcd(9, 8 , 6, 5, 3, 2);
PulseSensorPlayground pulseSensor;
File MyFile ;

int Threshold = 550;
int data = A0;
int start = 7;
int myBPM = 0;
int avg = 0;

unsigned long temp = 0;

String string = "\0";
String data1 = {".txt"};

char ch = '\0';

byte customChar1[8] = {0b00000, 0b00000, 0b00011, 0b00111, 0b01111, 0b01111, 0b01111, 0b01111};
byte customChar2[8] = {0b00000, 0b11000, 0b11100, 0b11110, 0b11111, 0b11111, 0b11111, 0b11111};
byte customChar3[8] = {0b00000, 0b00011, 0b00111, 0b01111, 0b11111, 0b11111, 0b11111, 0b11111};
byte customChar4[8] = {0b00000, 0b10000, 0b11000, 0b11100, 0b11110, 0b11110, 0b11110, 0b11110};
byte customChar5[8] = {0b00111, 0b00011, 0b00001, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000};
byte customChar6[8] = {0b11111, 0b11111, 0b11111, 0b11111, 0b01111, 0b00111, 0b00011, 0b00001};
byte customChar7[8] = {0b11111, 0b11111, 0b11111, 0b11111, 0b11110, 0b11100, 0b11000, 0b10000};
byte customChar8[8] = {0b11100, 0b11000, 0b10000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000};

void setup()
{
  Serial.begin(115200);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

  if (!SD.begin(4))
  {
    lcd.print("Failed...");
    while (1);
  }

  lcd.setCursor(0, 0);
  lcd.print("Done...");

  delay(1000);

  pulseSensor.analogInput(data);
  pulseSensor.blinkOnPulse(LED13); //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin())
  {
    lcd.setCursor(0, 0);
    lcd.print("Heart Rate");
    delay(1000);
  }

  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);
  lcd.createChar(5, customChar5);
  lcd.createChar(6, customChar6);
  lcd.createChar(7, customChar7);
  lcd.createChar(8, customChar8);

  pinMode(start, INPUT_PULLUP);
  mySerial.begin(9600);
  /* lcd.setCursor(0, 0);
    lcd.print("ConnectBluetooth");
    lcd.setCursor(0, 1);
    lcd.print("And Login...");*/
}

void loop()
{

  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Place The Finger");
  lcd.setCursor(0, 1);
  lcd.print("And Press Start");

  while (digitalRead(start) > 0);


  lcd.clear();

  temp = millis();

  while (millis() <= (temp + 10000))
  {
    if (pulseSensor.sawStartOfBeat())
    {
      myBPM = myBPM + pulseSensor.getBeatsPerMinute();
      avg++;
    }

    lcd.setCursor(0, 0);
    lcd.print("BPM : ");
    lcd.print(myBPM);

    lcd.setCursor(0, 1);
    lcd.print("Reading :");
    lcd.print(avg);

    lcd.setCursor(12, 0);
    lcd.write(byte(1));
    lcd.setCursor(13, 0);
    lcd.write(byte(2));
    lcd.setCursor(14, 0);
    lcd.write(byte(3));
    lcd.setCursor(15, 0);
    lcd.write(byte(4));

    lcd.setCursor(12, 1);
    lcd.write(byte(5));
    lcd.setCursor(13, 1);
    lcd.write(byte(6));
    lcd.setCursor(14, 1);
    lcd.write(byte(7));
    lcd.setCursor(15, 1);
    lcd.write(byte(8));

    delay(200);

    lcd.clear();
  }

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.setCursor(2, 0);
  lcd.write(byte(1));
  lcd.setCursor(3, 0);
  lcd.write(byte(2));
  lcd.setCursor(4, 0);
  lcd.write(byte(3));
  lcd.setCursor(5, 0);
  lcd.write(byte(4));

  lcd.setCursor(2, 1);
  lcd.write(byte(5));
  lcd.setCursor(3, 1);
  lcd.write(byte(6));
  lcd.setCursor(4, 1);
  lcd.write(byte(7));
  lcd.setCursor(5, 1);
  lcd.write(byte(8));
  lcd.setCursor(6, 1);

  myBPM = myBPM / avg;

  lcd.print("BPM : ");
  lcd.print(myBPM);
  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("ConnectBluetooth");
  lcd.setCursor(0, 1);
  lcd.print("And Login...");




  while (1)
  {
    while (mySerial.available() <= 0);

    ch = ((byte)mySerial.read());
    if (ch == '#')
      break;
    string += ch;
  }
  string = string + data1;

  MyFile = SD.open(string, FILE_WRITE);

  if (MyFile)
  {
    MyFile.print("BPM : ");
    MyFile.println(myBPM);
    MyFile.println("\n*************************\n");
    MyFile.close();
  }

  MyFile = SD.open(string, FILE_READ);

  if (MyFile)
  {
    while (MyFile.available())
    {
      mySerial.write(MyFile.read());
    }
    MyFile.close();
  }
  else
  {
    mySerial.println("error opening");
  }

  myBPM = 0;
  temp = 0;

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(string);
  lcd.setCursor(0, 1);
  lcd.print("Done");

  while (1);

}
