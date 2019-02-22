#include "Relay.h"

#define DEFAULT_INITIAL_RELAY_STATE RelayState::OFF

//Class constructor
Relay::Relay(int pin){
  _pin = pin;  //I don't check if the pin received is valid
  _state = DEFAULT_INITIAL_RELAY_STATE;
  _stateChangedEventHandler = NULL;  

  pinMode(_pin, OUTPUT);

  if(_state == RelayState::ON){
    digitalWrite(_pin, HIGH);
  }  
}

//Class constructor
Relay::Relay(int pin, RelayState state){
  _pin = pin;  //I don't check if the pin received is valid
  _state = state;
  _stateChangedEventHandler = NULL;  

  pinMode(_pin, OUTPUT);

  if(_state == RelayState::ON){
    digitalWrite(_pin, HIGH);
  }  
}

//Class constructor
Relay::Relay(int pin, void (*stateChangedEventHandler)()){
  _pin = pin;  //I don't check if the pin received is valid
  _state = DEFAULT_INITIAL_RELAY_STATE;
  _stateChangedEventHandler = stateChangedEventHandler;  

  pinMode(_pin, OUTPUT);

  if(_state == RelayState::ON){
    digitalWrite(_pin, HIGH);
  }    
}

//Class constructor
Relay::Relay(int pin, RelayState state, void (*stateChangedEventHandler)()){
  _pin = pin;  //I don't check if the pin received is valid
  _state = state;
  _stateChangedEventHandler = stateChangedEventHandler;  

  pinMode(_pin, OUTPUT);

  if(_state == RelayState::ON){
    digitalWrite(_pin, HIGH);    
  }  
}

//Returns the state of the relay
RelayState Relay::getState(){
  return _state;
}

//Changes the state of the relay (e.g. if it's ON, this method turns it to OFF and vice versa)
void Relay::setState(){
  
  if(_state == RelayState::OFF){
      _state = RelayState::ON;
      digitalWrite(_pin, HIGH);
  } else {
      _state = RelayState::OFF;
      digitalWrite(_pin, LOW);
  }

  if(_stateChangedEventHandler != NULL){
    _stateChangedEventHandler();
  }  
}

//Changes the state of the relay using the value passed to the method
void Relay::setState(RelayState state){
    if(_state == state){ 
      return;
    }

    if(_state == RelayState::OFF){
        _state = RelayState::ON;
        digitalWrite(_pin, HIGH);
    } else {
        _state = RelayState::OFF;
        digitalWrite(_pin, LOW);
    }

    if(_stateChangedEventHandler != NULL){
    _stateChangedEventHandler();
   }             
}

//Returns true if the state of relay is ON, false otherwise.
bool Relay::isON(){
 return (_state == RelayState::ON)?(true):(false); 
}

//Returns true if the state of relay is OFF, false otherwise.
bool Relay::isOFF(){
  return (_state == RelayState::OFF)?(true):(false);
}
