#include <DS3231.h>

DS3231 rtc(SDA, SCL); // Creates an rtc object and tells it whcih pins to use for I2C communication (SDA & SCL)
// SDA == A4, SCL = A5 on Arduino UNO (I2C bus)

void setup() {
  Serial.begin(9600); // Starts serial communication so we can print to Serial Monitor
  rtc.begin(); // Wakes up and initializes the real-time clock module

  // ---------- SET TIME ONCE ----------
  // UNCOMMENT THESE LINES THE FIRST TIME YOU UPLOAD THE PROGRAM, THEN COMMENT THEM OUT AGAIN AND
  // RE-UPLOAD TO AVOID RESETTING TIME EACH BOOT

  rtc.setDOW(WEDNESDAY); // Sets the day of week
  rtc.setTime(15, 30, 0); // Sets time to 15:30:00 (24-hour format)
  rtc.setDate(27, 11, 2025); // Sets dates (Day, Month, Year)


}

void loop() {
  // Request and display the time once per second
  delay(1000);

  // Print current date and time infor to Serial Monitor
  Serial.print("Day: ");
  Serial.println(rtc.getDOWStr()); // Prints Monday/Tuesday/etc

  Serial.print("Date: ");
  Serial.println(rtc.getDateStr()); // Prints DD/MM/YYYY

  Serial.print("Time: ");
  Serial.println(rtc.getTimeStr()); // Prints HH:MM:SS

  Serial.println("----------------------");
}
