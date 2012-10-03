#include <ChuckPlex.h>

int pins[] = {3,5,6,9}; // PWM pins
int nodes = 10;
ChuckPlex plex = ChuckPlex(pins, 4);
void setup(){
  // print the connections to make
  // you should remove this section once you've done your wiring
  Serial.begin(9600);
  delay(3000);
  plex.displayConnections(nodes);
}
void loop(){
  // choose a node at random
  for(int node=1; node<=nodes; node++){
    // fade on, then off using PWM
    for(int i=1; i<=16; i++){
      plex.write(node, i*i-1); // makes a nicer fade than linear
      delay(25);
    }
    for(int i=16; i>=1; i--){
      plex.write(node, i*i-1);
      delay(25);
    }
  }
}