# Introduction
This document covers a simple data cable and the software to transfer MZF
images from a PC directly to an MZ. Alternatively, the PC can be connected to
the data recorder of the MZ, a C64 datasette or other data recorders to
transfer MZF images to cassette.

The software is tested on Linux and Windows (NT4, W2k, XP) systems.


## Background
This project builds upon the
[MZF2WAV](https://github.com/jfjlaros/mzf2wav) utility, which is used to
convert an MZF image to a file that can be recorded on a cassette. Since
cassettes are getting outdated rapidly, and because ordinary sound cards can
not be used for speeds exceeding twice that of the normal transfer speed, the
parallel port is used for this project instead.

The *turbo loader* is from the related to the DOS utility
[TransManager](https://web.archive.org/web/20040218154731/http://mzunity.wz.cz/old/Hardware.htm).


# Hardware configuration
## Enable the external tape interface
For the MZ-711 and MZ-811, this step can be omitted. For other models, i.e.,
those with an internal data recorder or a quickdisk, the external tape
interface needs to be [enabled](https://sharpmz.org/mz-700/filetrans.htm), the
reverse of the operation described
[here](https://www.sharpmz.org/mz-700/usetape3.htm). This is done by
disconnecting the data recorder or quickdisk from connector P-12 and by
connecting the *jumper plug*. This plug will wire the read and write signals to
the external connectors and it will suppress the "Press play" message.

A jumper plug can be made from a plug similar to the one the data recorder and
quickdisk use.

![Jumper Plug](doc/jumper_plug.svg)

The wires are connected as follows:

| MZ | MZ | signal
|----|----|:--
|  1 |  7 | write
|  2 |  8 | read
|  5 |  9 | sense

These wires can also be soldered on the plug and optionally, the sense signal
can be wired to an external switch.

The MZ-80K/MZ-80A/MZ-80B do not have external connectors. For these models an
internal connection must be made.

## Transfer cable
To wire an MZ to a PC, the following cable is used.

![Transfer cable](doc/transfer_cable.svg)

Wiring is as follows:

|    PC |           MZ | signal
|-------|           --:|:--
|     3 |     read tip | read
|    10 |    write tip | write
| 18-25 | both sleeves | ground


## Alternative setup
To connect the data recorder to a PC, the following wiring should be used:

|    PC | Data recorder | signal
|-------|---------------|:--
|     3 |             7 | read
|    10 |             8 | write
| 18-25 |             9 | ground
|     9 |             4 | motor on
|     - |             6 | +5V

The +5V must be provided by an external power supply (5V / min. 0.3A).

# Installation
## Binaries
The binaries can be found
[here](https://sharpmz.org/download/mzput_0.1_beta.zip). After unzipping this
archive, the binaries for Linux can be found in `src/linux/release`, those for
Windows can be found in `src/w32/release`.

## From source
Retrieve the source code with Git.

    git clone https://github.com/jfjlaros/mzput.git

To compile for Linux:

    cd mzput/src/linux
    sh build.sh

For Windows, use:

    cd mzput\src\w32
    build.bat

The binary will be placed in the `release` subdirectory.

Notes for Windows users:

- This program uses the
  [callgate](https://web.archive.org/web/20121103010240/http://www.sonic.net:80/~undoc/ntcallgate.html)
  mechanism for real time operations. Since this mechanism is also used by
  viruses, the virusscanner may need to be disabled.
- The files `callgate.sys` and `callgate.dll` must reside in the same folder as
  `mzput.exe`, or they can be installed in one of the folders in the system
  path.


# Usage
This program must be run as root or Administrator. This is because of some
low-level routines that are used to enable real time operations in multitasking
systems like Linux or Windows.

When transferring directly to an MZ, first run the loader program (e.g., type
`L` or `C` in the MZ-monitor program).

When using a data recorder, first position the tape correctly and push the REC
and PLAY buttons.

On the PC, transfer an MZF image named `image.mzf`, using the following
command:

    mzput image.mzf

The program recognises the following options:

| option | description
|--------|:--
|   `-i` | sets initial speed mode (0, 1, 2, 3 or 4), default = 0.
|   `-t` | sets turbo speed mode (0, 1, 2, 3 or 4), default = 3.
|   `-1` | sets correction for fast initial mode (-50 to 50).
|   `-2` | sets correction for fast turbo mode (-50 to 50).
|   `-c` | sets conventional sending mode.
|   `-s` | sets fast sending mode.
|   `-w` | sets turbo sending mode (default).
|   `-p` | reverse polarity.
|   `-v` | displays version information.
|   `-l` | displays the license.
|   `-d` | displays more info and asks for confirmation before starting.

Note that during transfer, the PC will become completely unresponsive. This is
because all interrupts are disabled to allow for real time operations. A
running transfer can be aborted by pressing the `ESC` key.

It is recommended to *sync* the hard disks before each transfer and to install
[NTP](https://en.wikipedia.org/wiki/Network_Time_Protocol) (or something
similar). Disabling interrupts also means that the timer interrupt is disabled,
so the system clock will lag behind after each transfer.

Note for Windows users, it is recommended to make a *system restore point* and
copy the data to a directory inside the windows tree (e.g.,
`C:\WINDOWS\Restore`) this will enable you to restore the registry in the event
of a crash.

## Operation modes
### Fast sending mode
This is the easiest way to transfer a file. In this mode the long gap (a tape
marker) is 4000 pulses and the short gap is 5000 pulses. Both the header and
the MZF image body are transferred once.

### Conventional sending mode
This is the safest (and slowest) way to transfer an image, everything is done
according to the Sharp MZ series conventions: A long gap is 22000 pulses, a
short gap is 11000 pulses. The header and body are transferred twice to allow
for errors.

### Turbo sending mode
In this mode, the turbo loader from the TransManager is transferred using the
fast sending mode, this turbo loader enables the MZ to operate with higher
transfer speeds. The MZF image is then sent using fast sending mode, but now at
a higher speed.

The speed at which the turbo loader is transferred is controlled with the `-i`
option, the speed at which the MZF image is sent is controlled with the `-t`
option.

## Speeds
Apart from increasing the pulse frequency, the waveforms themselves can be
altered in order to increase speed. The "fast waveform" was found by minimising
the high and the low states of the pulses independently.

At this time, five speeds are implemented:

- Speed 0: normal speed with normal waveforms.
- Speed 1: normal speed with fast waveforms.
- Speed 2: 2x speed with normal waveforms.
- Speed 3: 3x speed with normal waveforms.
- Speed 4: 3x speed with fast waveforms.

These speeds can be set for all operation modes, although some combinations may
not work. The most commonly used speeds are: speed 0 or 1 for initial speed
mode and speed 2 or higher for turbo speed mode.

If multiple images are transferred, using speed 3 or 4 with fast sending mode
may be preferred.

### Corrections
Because the waveforms used by speeds 1 and 4 may not always work, two
correction factors for these speeds are implemented, controlled with the `-1`
and `-2` options.

## Polarity
The polarity can be revered with the `-p` option.
