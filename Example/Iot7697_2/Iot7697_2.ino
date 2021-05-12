/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Wed, 12 May 2021 07:28:12 GMT
 */

#include <LRemote.h>
#include <DHT.h>

int fire;

int rain;

int temp;

int humid;

int light;

LRemoteLabel label1;
LRemoteLabel label2;
LRemoteLabel label3;
LRemoteLabel label4;
LRemoteLabel label5;
LRemoteButton button1;
LRemoteSlider slider1;
LRemoteSlider slider2;
LRemoteSlider slider3;
DHT dht11_p12(12, DHT11);

void setup()
{
  Serial.begin(9600);

  LRemote.setName("LinkIt 7697");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(3, 5);
    label1.setPos(0, 0);
    label1.setText("");
    label1.setSize(1, 1);
    label1.setColor(RC_ORANGE);
    LRemote.addControl(label1);

    label2.setPos(1, 0);
    label2.setText("");
    label2.setSize(1, 1);
    label2.setColor(RC_BLUE);
    LRemote.addControl(label2);

    label3.setPos(2, 0);
    label3.setText("");
    label3.setSize(1, 1);
    label3.setColor(RC_GREEN);
    LRemote.addControl(label3);

    label4.setPos(0, 1);
    label4.setText("");
    label4.setSize(1, 1);
    label4.setColor(RC_PINK);
    LRemote.addControl(label4);

    label5.setPos(1, 1);
    label5.setText("");
    label5.setSize(1, 1);
    label5.setColor(RC_YELLOW);
    LRemote.addControl(label5);

    button1.setPos(2, 1);
    button1.setText("Buzzer");
    button1.setSize(1, 1);
    button1.setColor(RC_GREY);
    LRemote.addControl(button1);

    slider1.setPos(0, 2);
    slider1.setSize(3, 1);
    slider1.setText("R");
    slider1.setValueRange(0, 255, 0);
    slider1.setColor(RC_PINK);
    LRemote.addControl(slider1);

    slider2.setPos(0, 3);
    slider2.setSize(3, 1);
    slider2.setText("G");
    slider2.setValueRange(0, 255, 0);
    slider2.setColor(RC_GREEN);
    LRemote.addControl(slider2);

    slider3.setPos(0, 4);
    slider3.setSize(3, 1);
    slider3.setText("B");
    slider3.setValueRange(0, 255, 0);
    slider3.setColor(RC_BLUE);
    LRemote.addControl(slider3);
  LRemote.begin();
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
  if (LRemote.connected()) {
    LRemote.process();
    label1.updateText(String(String() + "T:" + temp));
    label2.updateText(String(String() + "H:" + humid));
    label3.updateText(String(String() + "L:" + light));
    label4.updateText(String(String() + "F:" + fire));
    label5.updateText(String(String() + "R:" + rain));
    if (button1.isValueChanged()) {
      if (button1.getValue() == 1) {
        tone(10, 262);

      } else {
        noTone(10);

      }

    }
    if (slider1.isValueChanged()) {
      analogWrite(4, slider1.getValue());

    }
    if (slider2.isValueChanged()) {
      analogWrite(5, slider2.getValue());

    }
    if (slider3.isValueChanged()) {
      analogWrite(3, slider3.getValue());

    }

  }
  delay(100);
}