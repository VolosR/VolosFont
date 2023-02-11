#include <TFT_eSPI.h>
#include <RotaryEncoder.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);



void setup() {
 
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  sprite.createSprite(320,170);
  }

byte letter[]={255,255,204,204,255,255};

void draw()
{
sprite.fillSprite(TFT_BLACK);
  for(int i=0;i<6;i++)
  {
    for(int j=7;j>=0;j--)
    if(bitRead(letter[i],j)==1)
    sprite.fillRect(i*10,(7-j)*10,10,10,TFT_RED);
  }
sprite.pushSprite(0,0);
}

void loop() {
  draw();
}
