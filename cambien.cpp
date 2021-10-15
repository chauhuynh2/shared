#include <Arduino.h>
#include <Wire.h>
#include "SHT31.h"

SHT31 sht31 = SHT31();

const int capteur_D = 4;
const int capteur_A = A0;

int val_waterDigital;
int val_waterAnalog;

void setup()
{
    pinMode(capteur_D, INPUT);
    pinMode(capteur_A, INPUT);

    Serial.begin(9600);
    while (!Serial);

    Serial.println("begin...");
    sht31.begin();
}

void loop()
{
    // Đọc độ ẩm
    float hum = sht31.getHumidity();
    Serial.print("Hum = ");
    Serial.print(hum);
    Serial.println("%");
    Serial.println();

    // Đọc mưa
    val_waterDigital = digitalRead(capteur_D);

    // Nếu độ ẩm > 80 hoặc có mưa
    if ((hum > 80) || (val_waterDigital == LOW))
    {
        // E thêm code chạy moto_1 20s ở đây
    }

    // Nếu độ ẩm < 30 hoặc không có mưa
    else if ((hum < 30) || (val_waterDigital == HIGH))
    {
        // E thêm code chạy moto_2 20s ở đây
    }

    //
    val_waterAnalog = analogRead(capteur_A);
    Serial.print("Analog value : ");
    Serial.println(val_waterAnalog);
    Serial.println("");
    delay(1000);

    delay(1000);
}
