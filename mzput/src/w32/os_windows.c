#include <windows.h>
#include "gate.h"
#include "os_windows.h"
#include "ring0.h"

// Definitions.
#define PERSISTENCE 30

// Global variables.
WORD cgs_clisti,
     cgs_outb,
     cgs_inb;
short fc_clisti[3],
      fc_outb[3],
      fc_inb[3];

// Private function prototypes.
int pcreate(void (*), WORD, WORD *, short[3]), // Persistent create callgate.
    prelease(WORD);                            // Persistent release callgate.

// Persistent create callgate.
int pcreate(void (*func), WORD no, WORD *cgs, short fc[3]) {
  int i = 0;

  while (CreateCallGate(func, no, cgs) != SUCCESS) {
    if (i > PERSISTENCE)
      return 1;
    i++;
  }//while
  fc[2] = *cgs;
  return 0;
}//pcreate

// Persistent releast callgate.
int prelease(WORD cgs) {
  int i = 0;

  while (FreeCallGate(cgs) != SUCCESS) {
    if (i > PERSISTENCE)
      return 1;
    i++;
  }//while
  return 0;
}//prelease

// Public functions.
// Open a callgate for the asmoutb function.
int getportperms(void) {
  int i = 1;
  
  if (pcreate(asmoutb, 2, &cgs_outb, fc_outb))
    return 1;
  if (pcreate(asminb, 2, &cgs_inb, fc_inb)) {
    prelease(cgs_outb);
    return 1;
  }//if
  if (pcreate(asmclisti, 1, &cgs_clisti, fc_clisti)) {
    prelease(cgs_inb);
    prelease(cgs_outb);
    return 1;
  }//if
  return 0;
}//getportperms

// Close the callgate for the asmoutb function.
int releaseportperms(void) {
  int ret = 0;

  if (prelease(cgs_clisti))
    ret = 1;
  if (prelease(cgs_inb))
    ret = 1;
  if (prelease(cgs_outb))
    ret = 1;

  return 0;
}//releaseportperms

// Do direct I/O input.
int inb(int port) {
  int rval = 0;

  _asm {
    mov esi, port; // Push the port to read from on the stack.
    push esi;
    lea esi, rval;  // Push the address of the return value on the stack.
    push esi;

    call fword ptr [fc_inb]; // Do a far call.
  }//asm
  return rval & 0xff;
}//inb

// Call asmclisti with the cli parameter.
void cli(void) {
  _asm {
    mov esi, 0h;
    push esi;

    call fword ptr [fc_clisti]; // Do a far call.
  }//asm
}//cli

// Call asmclisti with the sti parameter.
void sti(void) {
  _asm {
    mov esi, 1h;
    push esi;

    call fword ptr [fc_clisti];
  }//asm
}//sti

// Do direct I/O output.
void outb(int value, int port) {
  _asm {
    mov esi, value; // Push the value on the stack.
    push esi;
    mov esi, port;  // Push the port on the stack.
    push esi;

    call fword ptr [fc_outb]; // Do a far call.
  }//asm
}//outb
