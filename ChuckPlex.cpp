
#include "ChuckPlex.h"

// Set up a ChuckPlex instance
ChuckPlex::ChuckPlex(int * pins, int pinCount){
  int pinsTemp[pinCount];
  memcpy(pinsTemp, pins, sizeof(int)*pinCount);
  this->pins = pinsTemp;
  this->pinCount = pinCount;
  this->maxNodes = pinCount*(pinCount-1);
}

// Enable (turn on) a node.
void ChuckPlex::enable(int node){
  if(node>maxNodes) return;  // really? fail silently?
  int hiPin = pins[hi(node)];
  int loPin = pins[lo(node)];
  
  clear();
  
  digitalWrite(hiPin,HIGH);
  digitalWrite(loPin,LOW);
  pinMode(hiPin,OUTPUT);
  pinMode(loPin,OUTPUT);

}

// If you used PWM pins, this will work like analogWrite()
void ChuckPlex::write(int node, int value){
  if(node>maxNodes) return;  // hmm there should be an error...
  int hiPin = pins[hi(node)];
  int loPin = pins[lo(node)];
  
  clear();
  
  analogWrite(hiPin,value);
  digitalWrite(loPin,LOW);
  pinMode(hiPin,OUTPUT);
  pinMode(loPin,OUTPUT);
}

// clear all nodes
void ChuckPlex::clear(){
  for(int i=0; i<pinCount; i++){
    pinMode(pins[i],INPUT);
  }
}

// display the wiring between nodes and pins
void ChuckPlex::displayConnections(int nodeCount){
  if(nodeCount > maxNodes){
    Serial.println("not enough pins for that number of nodes.");
    Serial.print("for ");
    Serial.print(pinCount);
    Serial.print(" pins, there's a maximum of ");
    Serial.print(maxNodes);
    Serial.println(" nodes.");
    Serial.print("You'll need ");
    Serial.print((int) ceil((1+sqrt(1+4*nodeCount))/2));
    Serial.print(" pins.");
    return;
  }
  for(int p = 0; p<pinCount; p++){
    // print the pin number
    Serial.print("Pin ");
    Serial.print(pins[p]);
    Serial.print(": ");
    
    // print all anodes that it is connected to
    for(int n=1; n<=nodeCount; n++){
      if(hi(n) == p){
        Serial.print(n);
        Serial.print("+ ");
      }
    }
    // print all cathodes that it is connected to
    for(int n=1; n<=nodeCount; n++){
      if(lo(n) == p){
        Serial.print(n);
        Serial.print("- ");
      }
    }
    Serial.println("");
  }
}

// private: returns the HIGH pin for a given node
int ChuckPlex::hi(int node){
  return (node-1)/(this->pinCount-1);
}

// private: returns the LOW pin for a given node
int ChuckPlex::lo(int node){
  int result =  (node-1)%(this->pinCount-1);
  if(result >= hi(node)) result++;
  return result;
}

