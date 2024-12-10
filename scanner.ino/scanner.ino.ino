#include <Wire.h>

void setup() {
  Wire.begin(D2, D1);          // Initialize I2C with SDA=D2 (GPIO4), SCL=D1 (GPIO5)
  Serial.begin(9600);        // Start Serial communication at 115200 baud rate
  while (!Serial);             // Wait for Serial Monitor to open
  Serial.println("\nI2C Scanner for ESP8266");
}

void loop() {
  Serial.println("Scanning...");

  int nDevices = 0;
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }

  delay(5000); // Wait 5 seconds before scanning again
}
