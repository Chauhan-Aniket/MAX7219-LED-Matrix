#include <Arduino.h>
#include <LedControl.h>

#define MAX_DEVICES 3 // total number of LED matrix

#define DATA_PIN 11
#define CLK_PIN 13
#define CS_PIN 10

LedControl LC = LedControl(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// letter A
byte A[8] = {
    B00111100,
    B01000010,
    B01000010,
    B01000010,
    B01111110,
    B01000010,
    B01000010,
    B01000010};
// happy face
char hf[9] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100};
// neutral face
byte nf[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100};
// sad face
byte sf[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100};

void setup()
{
  // put your setup code here, to run once:
  for (int x = 0; x < MAX_DEVICES; x++)
  {
    LC.shutdown(x, false); // The MAX72XX is in power-saving mode on startup
    LC.setIntensity(x, 8); // Set the brightness to default value
    LC.clearDisplay(x);    // and clear the display
  }
}

void loop()
{
  // put nyour main code here, to run repeatedly:
  for (int i = 0; i < 8; i++)
  {
    LC.setRow(0, i, hf[i]);
  }
  delay(1000);
  for (int x = 0; x < MAX_DEVICES; x++)
    LC.clearDisplay(x);
}