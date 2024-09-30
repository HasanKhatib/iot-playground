#include <ArduinoBLE.h>

// Define BLE service and characteristic
BLEService ledService("180A");
BLEByteCharacteristic switchCharacteristic("2A57", BLERead | BLEWrite);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("Starting BLE failed!");
    while (1);
  }

  BLE.setLocalName("TheTallGuy");
  BLE.setAdvertisedService(ledService);

  ledService.addCharacteristic(switchCharacteristic);

  BLE.addService(ledService);

  BLE.advertise();
  Serial.println("Bluetooth device active, waiting for connections...");
}

void loop() {
  // Wait for a BLE central device to connect
  BLEDevice central = BLE.central();

  // If a central is connected, print its details
  if (central) {
    Serial.print("new central: ");
    Serial.println(central.address());

    // While the central is connected, keep checking characteristic changes
    while (central.connected()) {
      // All good
    }

    // If disconnected, print message
    Serial.print("disconnected: ");
    Serial.println(central.address());
  }
}
