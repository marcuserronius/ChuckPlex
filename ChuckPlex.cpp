
#include "ChuckPlex.h"

// Set up a ChuckPlex instance
ChuckPlex::ChuckPlex(int * pins, int pinCount){
  this->pins = pins;
  this->pinCount = pinCount;
}

// Enable (turn on) a node.
void ChuckPlex::enable(int node){
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

// private: returns the HIGH pin for a given node
int ChuckPlex::hi(int node){
  return node/(this->pinCount-1);
}

// private: returns the LOW pin for a given node
int ChuckPlex::lo(int node){
  int result =  node%(this->pinCount-1);
  if(result >= hi(node)) result++;
  return result;
}

