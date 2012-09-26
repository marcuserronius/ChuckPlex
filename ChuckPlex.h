#include <Arduino.h>


#ifndef CHUCKPLEX_H
#define CHUCKPLEX_H

class ChuckPlex{
  public:
    ChuckPlex(int * pins, int pinCount);
    void enable(int node);
    void write(int node, int value);
    void clear();
    void displayConnections(int nodeCount);
  private:
    int * pins;
    int pinCount;
    int maxNodes;
    int hi(int node);
    int lo(int node);
};
#endif
