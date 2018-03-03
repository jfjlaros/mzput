#ifdef LINUX
#include "linux/os_linux.h"
#else
#include "w32/os_windows.h"
#endif

// Defenitions.
typedef unsigned char byte;
typedef unsigned short word;

// Prototypes.
void reversepol(void),      // Reverse polarity.
     gap(int),              // i short pulses.
     tapemark(int),         // i long, i short and two long pulses.
     writecs(word),         // Write the checksum.
     setspeed(int);         // Define the waveform.
word writebyte(byte),       // Write a byte and count the ones. 
     getfilesize(byte *);   // Get the file size.
int esc(void),              // Read the ESC key status.
    assert(byte *, word);   // See if the MZF file is valid.
