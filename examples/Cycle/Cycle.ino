#include <ChuckPlex.h>

int pins[] = {2,3,4,5};
ChuckPlex plex = ChuckPlex(pins, 4);
void setup(){
  // no setup
}
void loop(){
  // cycle through the nodes
  for(int i=0; i<12; i++){
    plex.enable(i);
    delay(500);
  }
}
