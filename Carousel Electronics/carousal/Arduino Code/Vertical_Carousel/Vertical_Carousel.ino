#include <HardwareSerial.h>

// Initialize hardware serial (use UART2 for flexibility)
HardwareSerial nextionSerial(2);

// Define the RX and TX pins for the ESP32 (match this to your wiring)
#define NEXTION_RX_PIN 16
#define NEXTION_TX_PIN 17

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);

  // Start serial communication with the Nextion
  nextionSerial.begin(9600, SERIAL_8N1, NEXTION_RX_PIN, NEXTION_TX_PIN);

  Serial.println("Ready to receive data from Nextion LCD...");
}

void loop() {
  // Check if data is available from the Nextion
  if (nextionSerial.available() > 0) {
    // Read available data into a buffer
    String receivedData = "";
    while (nextionSerial.available()) {
      char c = nextionSerial.read();
      receivedData += c;
      delay(2); // Small delay to ensure all bytes are read
    }

    // Display the received data on the serial monitor
   // Serial.print("Raw Received Data (Hex): ");
    for (size_t i = 0; i < receivedData.length(); i++) {
    //  Serial.print("0x");
    //  Serial.print((uint8_t)receivedData[i], HEX);
    //  Serial.print(" ");
    }
  //  Serial.println();

    // Convert received ASCII bytes to a number
    String numberString = "";
    for (size_t i = 0; i < receivedData.length(); i++) {
      numberString += (char)receivedData[i]; // Convert each byte to char
    }

    int number = numberString.toInt(); // Convert string to integer

    // Display the parsed number or incorrect data
    if (number >= 1 && number <= 12) {
      Serial.print("Parsed Number: ");
      Serial.println(number);
    } else {
      Serial.println("Incorrect Data");
    }
  }
}
