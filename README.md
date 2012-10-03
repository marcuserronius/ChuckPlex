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

If you didn't calculate the required pins yourself, you can let ChuckPlex do it by changing the code here:

    void setup(){
      int pins[] = {2,3}; // the pins you'll be using
      int pinCount = 2;
      int nodes = 10;

Since this is clearly not enough pins (2 pins are only enough for 2 nodes!), you will get a message over the serial connection informing you that it's not enough, and telling you how many will be required. Once you have the correct number of pins included, though, you will get a message like this:

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

## Reference

Here's a little more detailed reference for this class.

### `ChuckPlex(int * pins, int pinCount)`

Creates an instance of the class. `pins` is an array of output pin numbers, and `pincount` is the number of output pins.

### `void enable(int node)`

Turns on the numbered `node`. Note that nodes indices start at one, not zero. This is the primary function you will use for just turning nodes on. `enable()` will call `clear()` to turn off all currently powered nodes before it turns this one on.

### `void clear()`

Turns off all nodes. Use this when you don't want anything powered.

### `void write(int node, int value)`

If you used PWM pins for your output pins, you can use `write()` to control the node as if it was connected directly to a PWM pin. `node` is the node you want to control, and `value` is in the range (0..255), just like `analogWrite()`. You only want to use this method if you used PWM pins, though. Otherwise, just stick to `enable()` and `clear()`.

### `void displayConnections(int nodeCount)`

This is the method to call when you are first setting up the array. Note that using it in your sketch greatly increases the size of the compiled sketch; so once you have gotten your information, you'll want to remove the reference to it.

This method will print to the serial connection the list of connections that must be made for the particular charlieplexed matrix you are setting up. If you didn't initialize the object with enough pins in the call to `ChuckPlex()`, it will print out a message telling you how many pins you need.

If you have the correct number of pins, it will print out a list of connections. Each line will start with the output pin number, then a series of node numbers, with positive and negative values. These correspond to the positive and negative leads of each node. Connect all these wires to the given output pin number, using appropriate resistors. If all your nodes can be supplied with the same voltage, simply use one resistor on each pin, of half the required resistance (since there will be a resistor at each end of the connection).

## Bugs, suggestions, and feedback

Please report any bugs to the GitHub issues page:
https://github.com/marcuserronius/ChuckPlex/issues

or report bugs, or post general feedback to this forum thread:
http://arduino.cc/forum/index.php/topic,124481.0.html

Thank you!