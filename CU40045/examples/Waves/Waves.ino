#include <CUU_Parallel_M68.h>
#include <Noritake_VFD_CUU.h>
#include <util/delay.h>

// Change your pins to follow this order:
// RS, RW, E1, E2, D0, D1, D2, D3, D4, D5, D6, D7
CUU_Parallel_M68 interface(13,12, 11, 2, 3,4,5,6,7,8,9,10);

Noritake_VFD_CUU vfd;

int offset;

void setup() {

  offset = 0;
  
  _delay_ms(500);
  vfd.interface(interface);
  
  vfd.CUU_init();

}

void loop() {
  
  for( int y = 0; y < 4; y++) {
    for( int x = 0; x < 40; x++) {
      
      int pos = y * 4 + x + offset;
      
      vfd.CUU_setCursor(x, y);
      vfd.print(((pos * 8) % 9) + 16);
      
    }
  }

  offset = (offset + 1) % 9;
}
