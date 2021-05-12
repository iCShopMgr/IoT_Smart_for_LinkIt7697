/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Wed, 12 May 2021 05:19:26 GMT
 */

#include <DHT.h>

int fire;

int rain;

int temp;

int humid;

int light;

DHT dht11_p12(12, DHT11);

void setup()
{
  Serial.begin(9600);


  pinMode(11, INPUT);
  dht11_p12.begin();
  pinMode(13, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}


void loop()
{
  fire = digitalRead(11);
  Serial.println(String() + "fire: " + fire);
  if (fire == 0) {
    tone(10, 330);
    delay(100);
    noTone(10);
    delay(100);

  }
  rain = analogRead(14);
  Serial.println(String() + "rain: " + rain);
  if (rain > 200) {
    tone(10, 349);
    delay(100);
    noTone(10);
    delay(100);

  }
  temp = dht11_p12.readTemperature();
  humid = dht11_p12.readHumidity();
  Serial.println(String() + "Temp: " + temp);
  Serial.println(String() + "Humid: " + humid);
  light = digitalRead(13);
  Serial.println(String() + "Light: " + light);
  if (light == 0) {
    analogWrite(4, 0);
    analogWrite(5, 0);
    analogWrite(3, 0);

  } else {
    analogWrite(4, 255);
    analogWrite(5, 255);
    analogWrite(3, 255);

  }
}