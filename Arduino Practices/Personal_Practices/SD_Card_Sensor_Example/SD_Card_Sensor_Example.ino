#include <SPI.h>
#include <SD.h>

#define CHIP_SELECT 10 // Required for our projects

File dataFile;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing SD card...");

  // Start the SD card
  if (!SD.begin(CHIP_SELECT)) {
    Serial.println("SD init failed!");
    return;
  }
  Serial.println("SD init success!");

  // --------------WRITE EXAMPLE------------
  dataFile = SD.open("log.txt", FILE_WRITE);

  if (dataFile) {
    Serial.println("Writing to log.txt...");

    for (int i = 0; i < 5; i++) {
      sensorValue = analogRead(A0);
      dataFile.print("Reading ");
      dataFile.print(i);
      dataFile.print(": ");
      dataFile.println(sensorValue);
      delay(500);
    }

    dataFile.close();
    Serial.println("Done writing.");
  } else {
    Serial.println("Error opening log.trxt for writing");
  }

  // ------------ READ EXAMPLE --------------
  dataFile = SD.open("log.txt");

  if (dataFile) {
    Serial.println("\nReading from log.txt:");
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  } else {
    Serial.println("Error opening log.txt for reading");
  }
}

void loop() {
  // Nothing here, all actions are done in setup
}
