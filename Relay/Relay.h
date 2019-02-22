/*
 * Relay.h - Library used to model a relay connected to the Arduino board 
 * Created by crash6, February 22, 2019.
 * Released into the public domain
 */

#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

enum class RelayState {  //I could use also the keywork 'struct' replacing 'class' ... same result
      OFF = 0,
      ON  = 1 
  };

class Relay {

  //public members
  public:
    Relay(int pin);
    Relay(int pin, RelayState state);
    Relay(int pin,void (*stateChangedEventHandler)());
    Relay(int pin, RelayState state, void (*stateChangedEventHandler)());   
    RelayState getState();
    void setState();
    void setState(RelayState state);
    bool isON();
    bool isOFF();

  //private members
  private:
    int _pin;  
    RelayState _state;
    void (*_stateChangedEventHandler)();
};

#endif
