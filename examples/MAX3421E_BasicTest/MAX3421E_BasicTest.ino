
#include <SPI.h>
#include <usbhub.h>
#include <Max3421e.h>

// Initialize USB Hub
USB Usb;

void setup() {
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect
  Serial.println("Initializing USB Host Shield...");
  if (Usb.Init() == -1) {
    Serial.println("OSC did not start.");
  }
  delay(200);
}

void loop() {
  Usb.Task();
  if (Usb.getUsbTaskState() == USB_STATE_RUNNING) {
    Serial.println("USB device detected!");
  } else {
    Serial.println("No USB device detected.");
  }
  delay(1000); // Check every second
}
