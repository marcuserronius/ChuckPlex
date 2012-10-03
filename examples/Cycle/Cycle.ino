#include <ChuckPlex.h>

int pins[] = {2,3,4,5};
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
  // cycle through the nodes
  for(int i=1; i<=nodes; i++){
    plex.enable(i); // turn off other nodes, enable this one
    delay(500);
  }
}
