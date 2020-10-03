#include <CUU_Parallel_M68.h>
#include <Noritake_VFD_CUU.h>
#include <util/delay.h>

// Change your pins to follow this order:
// RS, RW, E1, E2, D0, D1, D2, D3, D4, D5, D6, D7
CUU_Parallel_M68 interface(13,12, 11, 2, 3,4,5,6,7,8,9,10);

Noritake_VFD_CUU vfd;

int x;
int y;

int dx;
int dy;

void setup() {

  x = 9;
  y = 2;
  dx = 2;
  dy = -1;
  
  _delay_ms(500);
  vfd.interface(interface);
  
  vfd.CUU_init();

}


void loop() {

  vfd.currentModule = Both;
  
  vfd.CUU_clearScreen();
  
  vfd.CUU_setCursor(x, y);

  // Print trail
  vfd.print(0x97);
  
  if(x <= 1 || x > 38) {
    dx = -dx;
  }

  if(y < 1 || y > 2) {
    dy = -dy;
  }

  x += dx;
  y += dy;

  vfd.CUU_setCursor(x, y);

  // Print ball
  vfd.print(0x94);

  _delay_ms(60);

}
