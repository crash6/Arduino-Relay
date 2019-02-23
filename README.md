# Arduino-Relay


This library implements any physical relay plugged to the Arduino board. I modelled it like an object which can be controlled through two main methods :

- **_setState()_**;
- **_setState(*RelayState state)_**;

**_RelayState_** is simply an enum class type which can be :

- **_RelayState::ON_** 
- **_RelayState::OFF_**

The class object provides also a basic callback mechanism which can be useful when we want to be notified that the state of the relay is changed. The callback function can be passed to the constructor method of the object when we instatiate it.
