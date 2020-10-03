#include <CUU_Parallel_M68.h>
#include <Noritake_VFD_CUU.h>
#include <util/delay.h>

// Change your pins to follow this order:
// RS, RW, E1, E2, D0, D1, D2, D3, D4, D5, D6, D7
CUU_Parallel_M68 interface(13,12, 11, 2, 3,4,5,6,7,8,9,10);

Noritake_VFD_CUU vfd;
bool done;

class TypeWriter{

  const char *value;
  
  public:
    TypeWriter (const char *v){
      value = v;
    }
    void tick(){
      if (*value)
        vfd.print(*value++);
      else 
        done = true;
    }
};

TypeWriter writer("Hello, world!");


void setup() {
  
  _delay_ms(500);
  vfd.interface(interface);
  
  vfd.CUU_init();
  vfd.CUU_cursorOn();
  _delay_ms(3000);

}

bool on;

void loop() {
  if(!done) {
    writer.tick();
    return delay(random(100, 600));
  }
  
  if(on)
    vfd.CUU_cursorOn();
  else
    vfd.CUU_cursorOff();
    
  _delay_ms(500);
  on = ! on;
}
