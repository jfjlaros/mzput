#include <asm/io.h>   // outb
#include <sys/perm.h> // Just to remove a warning (iopl).

// Defenitions.
#define DEFAULT_LONG_UP       298 // Normal mode.
#define DEFAULT_LONG_DOWN     329
#define DEFAULT_SHORT_UP      160
#define DEFAULT_SHORT_DOWN    170

#define FAST_LONG_UP          250 // Fastest in normal mode.
#define FAST_LONG_DOWN        253
#define FAST_SHORT_UP         116
#define FAST_SHORT_DOWN       169

#define TURBO_2_LONG_UP       149 // Turbo 2x.
#define TURBO_2_LONG_DOWN     165
#define TURBO_2_SHORT_UP      80
#define TURBO_2_SHORT_DOWN    85

#define TURBO_3_LONG_UP       99  // Turbo 3x.
#define TURBO_3_LONG_DOWN     110
#define TURBO_3_SHORT_UP      53
#define TURBO_3_SHORT_DOWN    57

#define TURBO_FAST_LONG_UP    82  // Fastest in turbo mode.
#define TURBO_FAST_LONG_DOWN  49
#define TURBO_FAST_SHORT_UP   51
#define TURBO_FAST_SHORT_DOWN 54

// Prototypes.
int getportperms(void),     // Get port permission.
    releaseportperms(void); // Release port permission.
void cli(void),             // Disable all interrupts.
     sti(void);             // Enable all interrupts.
