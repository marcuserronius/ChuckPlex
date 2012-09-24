#include <ChuckPlex.h>

int pins[] = {3,5,6,9};
ChuckPlex plex = ChuckPlex(pins, 4);
void setup(){
  // no setup
}
void loop(){
  // choose a node at random
  int node = random(10);
  // turn it on and fade it out using PWM
  for(int i=255; i>0; i--){
    plex.write(node, i);
    delay(2);
  }
}
