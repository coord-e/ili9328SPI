#include <ili9328.h>
#include <SPI.h>
#include <Adafruit_GFX.h>

#define CS A1
#define RESET A2

ili9328SPI tft(CS, RESET);

//Beautiful Colors For UI.
#define BLACK   0x29ea
#define BLUE    0x2c17
#define RED     0xc1c5
#define GREEN   0x256c
#define YELLOW  0xF621
#define WHITE   0xef9e

void setup() {
  Serial.begin(9600);
  
  tft.begin();
  
  Serial.println(F("Hello LCD World!!"));
  Serial.println(F("ILI9328 library test"));
  
  tft.fillScreen(BLACK);

  tft.setCursor(0,60);
  tft.setTextColor(YELLOW);
  tft.setTextSize(4);
  tft.println("Hello World!!");
  tft.setTextColor(GREEN);
  tft.setTextSize(2);
  tft.println("Welcome to LCD World!");
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("Lorem ipsum dolor sit amet,");
  tft.println("consectetur adipisicing elit,");
  tft.println("sed do eiusmod tempor incididunt ut");
  tft.println("labore et dolore magna aliqua.");
  delay(5000);
  
  Serial.println(F("Fill"));
  tft.fillScreen(BLACK);
  tft.fillScreen(RED);
  tft.fillScreen(GREEN);
  tft.fillScreen(BLUE);
  tft.fillScreen(BLACK);

}

void loop() {
  tft.fillRect(random(0, TFT_WIDTH - 1), random(0, TFT_HEIGHT - 1), random(0, TFT_WIDTH - 1), random(0, TFT_HEIGHT - 1), random(0xffff));
}

