#include "os_linux.h"

// Enable all interrupts.
void sti(void){
  asm("sti");
}//sti

// Disable all interrupts.
void cli(void) {
  asm("cli");
}//cli

// Get port permission.
int getportperms(void) {
  if (iopl(3) == -1)
    return 1;
  return 0;
}//getportperms

// Release port permission.
int releaseportperms(void) {
  if (iopl(0) == -1)
    return 1;
  return 0;
}//releaseportperms
