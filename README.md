# AlbionHack
This package contains the readout libraries to access:
 - FASER's trigger logic board (TLB).
 - FASER's tracker readout board (TRB) and via this the SCT modules.

Each readout library depends on the GPIObase library, the base library for access to a UniGe GPIO board.
The UniGe GPIO front-end interface specifications are documented here:
[GPIO front-end interface specifcations in sharepoint](https://espace.cern.ch/faser-share/Shared%20Documents/Trigger,%20DAQ%20and%20DCS/Unige%20FrontEnd%20Interface%20-%20UFE_Protocol-v1.4.pdf)

## Requirements:
 - libusb. Installation on CC7 - like system: 
```
 sudo yum install libusbx-devel 
```

## Installation:
```
mkdir build
cd build
cmake ../
make
```

## TRBACCESS

### How to run:
A simple command line program exists to provide basic functionality. Please see the the help to get detailed information:
```
MenuTRB -h
```
E.g., to configure modules 0 and 1  just do
```
MenuTRB -c 3
```
Where 3 is the bitmask of modules to configure. To configure all 8 modules use -c 255.

## Documentation:

Documentation is automatically build when commits are pushed to gitlab and are available here:
[http://faserdaq.web.cern.ch/faserdaq/gpiodrivers/doc/html/annotated.html](http://faserdaq.web.cern.ch/faserdaq/gpiodrivers/doc/html/annotated.html)

In order to manually generate the documentation pleae run doxygen using the Doxyfile in the repository.
