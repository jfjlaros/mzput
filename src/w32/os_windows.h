// Definitions.
#define DEFAULT_LONG_UP       165 // Normal mode.
#define DEFAULT_LONG_DOWN     191
#define DEFAULT_SHORT_UP      90
#define DEFAULT_SHORT_DOWN    97

#define FAST_LONG_UP          139 // Fastest in normal mode.
#define FAST_LONG_DOWN        80
#define FAST_SHORT_UP         70
#define FAST_SHORT_DOWN       80

#define TURBO_2_LONG_UP       83  // Turbo 2x.
#define TURBO_2_LONG_DOWN     96
#define TURBO_2_SHORT_UP      45
#define TURBO_2_SHORT_DOWN    49

#define TURBO_3_LONG_UP       55  // Turbo 3x.
#define TURBO_3_LONG_DOWN     64
#define TURBO_3_SHORT_UP      30
#define TURBO_3_SHORT_DOWN    32

#define TURBO_FAST_LONG_UP    47  // Fastest in turbo mode.
#define TURBO_FAST_LONG_DOWN  25
#define TURBO_FAST_SHORT_UP   29
#define TURBO_FAST_SHORT_DOWN 30

// Prototypes.
int getportperms(void),     // Get port permission.
    releaseportperms(void), // Release port permission.
    inb(int);               // Direct I/O input.
void cli(void),             // Disable all interrupts.
     sti(void),             // Enable all interrupts.
     outb(int, int);        // Direct I/O output.
