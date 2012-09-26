ChuckPlex
=========

### A simple but powerful charlieplexing library for Arduino

This library automates most of the setup use of a charlieplexed array, and simplifies the code needed to use them. It supports any number of nodes (up to 182 nodes on UNO, or 2862 on the Mega!), assuming you have enough free pins to control them. If the chosen pins are PWM pins, you can use them in that way, as well.

### Usage

Once you have determined how many nodes you need to address, you can determine how many pins to use. You can either calculate this yourself, or just move on and let ChuckPlex calculate it for you.

To get the wiring information, create a simple sketch that looks like this:

    #include <ChuckPlex.h>
    
    void setup(){
      int pins[] = {2,3,4,5}; // the pins you'll be using
      int pinCount = 4;
      int nodes = 10; // the number of LEDs or whatever you'll be using.
      ChuckPlex plex = ChuckPlex(pins,pinCount);
      Serial.begin(9600);
      delay(3000); // give us time to open the serial monitor window
      plex.displayConnections(nodes);
    }

If you didn't calculate the required pins yourself, you can let ChuckPlex do it by changing it to this:

    void setup(){
      int pins[] = {2,3}; // the pins you'll be using
      int pinCount = 2;
      int nodes = 10;

Since this is clearly not enough pins (it's only enough for 2 nodes!), you will get a message over the serial connection informing you that it's not enough, and telling you how many will be required. Once you have the correct number of pins included, though, you will get a message like this:

    Pin 2: 1+ 2+ 3+ 4- 7- 10- 
    Pin 3: 4+ 5+ 6+ 1- 8- 
    Pin 4: 7+ 8+ 9+ 2- 5- 
    Pin 5: 10+ 3- 6- 9-

This means that you connect pin 2 to the positive leads of nodes 1, 2 and 3; and the negative leads of nodes 4, 7 and 10. And so on.

After all connections have been made, just load up the library and use it to control your charlieplexed array:

    #include <ChuckPlex.h>
    
    int pins[] = {2,3,4,5};
    ChuckPlex plex = ChuckPlex(pins,4);
    
    void setup(){
      // no setup!
    }
    
    // blink the fourth led in the array
    void loop(){
      // light the fourth led
      plex.enable(4);
      delay(1000);
      // turn off all leds
      plex.clear();
      delay(1000);
    }

That's it!