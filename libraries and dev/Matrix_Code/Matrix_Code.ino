//#include "LedControl.h"
#include "src/LedControl/LedControl.h"
#include "Data.h"


LedControl lc=LedControl(21,23,22,4);//DataIn , CLK , CS , number of screens


unsigned long delayTime=1000;  // Delay between Frames


int intensity=1;//5;


void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);
  lc.shutdown(3,false);
  lc.setIntensity(0,intensity);  // Set intensity levels
  lc.setIntensity(1,intensity);
  lc.setIntensity(2,intensity);
  lc.setIntensity(3,intensity);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
}


void loop()
{
// Put #1 frame on both Display
    sinvader1a(0);    delay(delayTime);
    sinvader2a(3);    delay(delayTime);

    sinvader1b(0);    delay(delayTime);
    sinvader2b(3);    delay(delayTime);


    sinvader3a(0);    delay(delayTime);
    sinvader4a(3);    delay(delayTime);

    sinvader3b(0);    delay(delayTime);
    sinvader4b(3);    delay(delayTime);

}






//  Take values in Arrays and Display them
void sinvader1a(int number)
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(number,i,invader1a[i]);
  }
}

void sinvader1b(int number)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(number,i,invader1b[i]);
  }
}

void sinvader2a(int number)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(number,i,invader2a[i]);
  }
}

void sinvader2b(int number)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(number,i,invader2b[i]);
  }
}

void sinvader3a(int number)
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(number,i,invader1a[i]);
  }
}

void sinvader3b(int number)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(number,i,invader1b[i]);
  }
}

void sinvader4a(int number)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(number,i,invader2a[i]);
  }
}

void sinvader4b(int number)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(number,i,invader2b[i]);
  }
}

