
#include <SPI.h>
#include <Usb.h>

USB Usb;
MAX3421E Max;

void setup() {
    Serial.begin(115200);
    Serial.println("Start");

    if (Usb.Init() == -1) {
        Serial.println("OSC failed to start.");
        while(1); //halt
    } else {
        Serial.println("USB host shield initialized.");
    }
}

void loop() {
    Max.gpioWr(LOW);
    delay(500);
    Max.gpioWr(HIGH);
    delay(500);
    Serial.println("LED test");
}
