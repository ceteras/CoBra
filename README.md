# CoBra

CoBra is a Z80 computer designed in 1986 at a research center in Brasov, Romania (ITCI).
It was a two-in-one machine, it could be a ZX Spectrum compatible or a CP/M machine.

![CoBra mainboard](https://github.com/ceteras/CoBra/blob/main/mainboard/2layer/images/mainboard_view.png?raw=true)

In its official version, its specs are:
- 3.5MHz Z80A CPU
- 64KB ram, made up of 4 banks of 8x 4116 chips each
- 2KB ROM boot code (2716 EPROM, could be swapped for a 2732/2764)
- 16KB ROM for the BASIC interpreter (8x 2716)
- 58 keys keyboard, featuring 50 keys for ZX Spectrum mode plus 8 for CP/M
- i8272 floppy interface
- RS232 port (bit-banged)
- joystick port
- extension port using a 3x32 pin DIN41612 connector

CoBra has three different memory maps: one for power-on, one for BASIC, and one for CP/M.
The memory configuration change is done in software.
On power-on, the memory map includes both ROMs, the first RAM bank and the video memory bank.
This way, it can copy the BASIC ROM to RAM, or load CP/M from Floppy, or it can load from the tape interface.
After copying code to bank 0 RAM, it can switch the memory map, then start executing code from RAM.

Many thanks to [cobrasov.com](https://cobrasov.com/CoBra%20Project/index.html), my main inspiration source in this endeavour.
You can find out a lot about this incredible machine on the website. 
Gerber files are also available there if you want to order your own boards.

This repo is a "revival" approach, aiming to re-create the original computer in Kicad, adding only some minor tweaks.
No gerbers were generated yet, still doing final checks.

![CoBra mainboard](https://github.com/ceteras/CoBra/blob/main/mainboard/2layer/images/main.png?raw=true)
