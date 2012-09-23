ChuckPlex
=========

### A simple but powerful charlieplexing library for Arduino

This library automates most of the setup use of a charlieplexed array, and simplifies the code needed to use them. It supports any number of nodes (up to 182 nodes on UNO, or 2862 on the Mega!), assuming you have enough free pins to control them. If the chosen pins are PWM pins, you can use them in that way, as well.

### Usage

Once you know how many nodes you want, run the included ruby script (node_configure.rb). First you will be prompted for the number of nodes (LEDs). It will sy how many pins will be required, and ask you to list their numbers. Enter them, and it will list which nodes' positive and negative leads to connect to which pins.

After all connections have been made, just load up the library and use it to control your charlieplexed array:

    #include <ChuckPlex.h>
    
    int leds[] = {2,3,4,5};
    ChuckPlex leds = ChuckPlex(leds,4);
    
    // blink the fourth led in the array
    void loop(){
      // light the fourth led
      leds.enable(3);
      delay(1000);
      // turn off all leds
      leds.clear();
      delay(1000);
    }

That's it!