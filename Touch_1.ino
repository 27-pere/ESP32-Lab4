#include "BluetoothSerial.h"
#include "Wire.h"
#include "SHT2x.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif

BluetoothSerial SerialBT;
HTU21 sht;

const int touchPin = 2;   
const int ledPin = 16;    

int touchValue;
int threshold = 300;  

void setup()
{
  Serial.begin(115200);
  SerialBT.begin("LnwJoanZaKarn"); 
  // Serial.println("The device started, now you can pair it with bluetooth!");

//humidity

  // Serial.println();
  // Serial.println(__FILE__);
  // Serial.print("SHT2x_LIB_VERSION: \t");
  // Serial.println(SHT2x_LIB_VERSION);
  // Serial.println();

  Wire.begin();
  sht.begin();

  uint8_t stat = sht.getStatus();
  Serial.print(stat, HEX);
  Serial.println();

  //end

  pinMode(ledPin, OUTPUT);
}

void loop()
{
  touchValue = touchRead(touchPin);
  // Serial.print("Touch value: ");
  Serial.print(touchValue);
  Serial.print(",");
  //humidity
   sht.read();

  Serial.print(sht.getTemperature(), 1);
  Serial.print(",");
  Serial.println(sht.getHumidity(), 1);

  if (touchValue < threshold) {
    digitalWrite(ledPin, HIGH);
    // Serial.println("LED on");
    if (SerialBT.connected()) SerialBT.println("TOUCH detected, LED on");
  } else {
    digitalWrite(ledPin, LOW);
    // Serial.println("LED off");
  }
  delay(1000);
}
