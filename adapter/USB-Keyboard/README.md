# USB Keyboard Adapter (experimental)

Based on RP2040 Zero, emulates the CoBra switch matrix keyboard. 


The USB keyboard is connected to RP2040 USB port. Key codes are decoded and translated to an 8 byte array.
RP2040 reads the matrix column bus (KC[8..15] connected to A[8..15] through diodes) and sends the data  
corresponding to each key pressedi, from the array to the KR[0..5] bus.

Inputs to RP2040 are pulled high to 3.3V, so in theory this should be safe, as the 5V A[8..15] bus is behind reverse  
polarized diodes.  
Outputs are pulled high to 5V on the CoBra mainboard, hence the schottky diodes, for protection.
The keyboard input is an 8255 and its input voltage thresholds are safe for 3.3V logic (minimum 2V for input "1").


![Adapter schematic](https://github.com/ceteras/CoBra/blob/main/adapter/USB%20Keyboard/images/schematic.png?raw=true)


Key mapping:
- ALT / ALT gr - Symbol Shift
- GUI (Win key) - Caps Shift
- Cursor keys - CS + 5,6,7,8
- Backspace - CS + 0
- Insert - CS + 1 (edit)
- Application menu key - SS + X (pound)
- all symbols on a US keyboard [{]};:'"\|,<.>/?!@#$%^&*()_-+=   
  are mapped to their coreesponding CoBra key combinations  
  eg ")" - SS + 9, "~" - Extended mode + SS + A  
 
  
