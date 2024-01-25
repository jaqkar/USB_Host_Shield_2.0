#include <PIJ.h>
#include <Usb.h>

#define PRODUCT_HID_KEYBOARD    0x200

#define VENDOR_ID                   0x2021

#define PRODUCT_ID                  0x0037

USB Usb;

// USB Kide report lengths must be equal to 8 bytes.
#define KB_REPORT_LENGTH    8

// Global variables
unsigned char oldKeys[KB_REPORT_LENGTH];
unsigned char keys[KB_REPORT_LENGTH];

void setup() {
  Serial.begin(115200);
  if (Usb.Init() == -1) {
    Serial.println("OSC failed to start.");
    while(1); //halt
  }
  else {
    Serial.println("USB initialized");
  }
}

void loop() {
  // Check Usb task
  Usb.Task();

  if (Usb.getUsbTaskState() == USB_STATE_RUNNING) {
    if (Usb.deviceAddress || true) { //Check if any device is connected
      // read keyboard
    }
  }
}
