#include "HX711.h"
#include "BluetoothSerial.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 32;
const int LOADCELL_SCK_PIN = 27;
const int LED = LED_BUILTIN;

BluetoothSerial SerialBT;
HX711 scale;

void setup() 
{
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  SerialBT.begin("Load_cell_BT_2");
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  
}

void loop() 
{
  long reading = scale.read();
  SerialBT.println(reading);
}
