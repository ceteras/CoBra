# CoBra

CoBra is a Z80 computer designed in 1986 at a research center in Brasov, Romania (ITCI).  

![CoBra mainboard](https://github.com/ceteras/CoBra/blob/main/mainboard/2layer/images/mainboard_view.png?raw=true)

In its official version, its specs are:
- 3.5MHz Z80A CPU
- 64KB ram, made up of 4 banks of 8x 4116 chips each
- 2KB ROM boot code (2716 EPROM, could be swapped for a 2732/2764)
- 16KB ROM for the BASIC interpreter (8x 2716)
- 58 keys keyboard, featuring 50 keys for ZX Spectrum mode plus 8 for CP/M
- i8272 floppy interface - on a daughter board (not included in the repo for now)
- RS232 port (bit-banged)
- joystick port
- 8 bit parallel port, input only, signals hared with the joystick interface
- extension port using a 3x32 pin DIN41612 connector

It's a two-in-one machine, it can be either a ZX Spectrum compatible or a CP/M machine.
CoBra has three different memory maps: one for power-on, one for ZX Spectrum, and one for CP/M.  
The memory configuration change is done in software, using the bit 7 of the R register.  
On power-on, the memory map includes both ROMs, the first RAM bank (Bank 0) and the video memory bank (Bank 1).  
This way, it can copy boot code to RAM, then switch the memory map to te desired architecture and start executing from address zero.  
Boot code can be copied from ROM for ZX Spectrum mode, and from the floppy interface for CP/M.
Tape interface can also be an option, which should be great for development.

Many thanks to [cobrasov.com](https://cobrasov.com/CoBra%20Project/index.html), my main inspiration source in this endeavour.  
You can find out a lot about this incredible machine on the website.  
Gerber files are also available there if you want to order your own boards.  

This repo is a "revival" approach, aiming to re-create the original computer in Kicad, adding only some minor tweaks.  
Current status is work in progress, a first batch of 5 boards has been ordered for production and are on the way.  

Links:
- ![2 Layer PCB project](https://github.com/ceteras/CoBra/tree/main/mainboard/2layer) - a 4 layer version is in the works too
- ![Schematic in pdf format](https://github.com/ceteras/CoBra/blob/main/main.pdf)
- ![Gerber files](https://github.com/ceteras/CoBra/tree/main/mainboard/2layer/kicad/fabrication)
- ![Interactive BOM](https://github.com/ceteras/CoBra/blob/main/mainboard/2layer/kicad/bom/ibom.html)
- ![A PAL encoder with S-Video connector](https://github.com/ceteras/CoBra/tree/main/s-video) - a draft, not tested yet

![CoBra mainboard](https://github.com/ceteras/CoBra/blob/main/mainboard/2layer/images/main.png?raw=true)
