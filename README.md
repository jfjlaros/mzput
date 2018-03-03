# MZPut
## Overview
The following section describes a simple cable and the usage of the software to
transfer files from your PC to the data recorder or to the MZ directly.

You can use the data recorder of your MZ, a C64 datassette, or other data
recorders at your PC to save your MZ-programs.

The software is ready for download here and is to be run under Win NT-systems
(NT4, W2k, XP) or Linux. The usage for other Win-systems isn't in progress. May
be, if you ask the author and if it is of major interest to run it under Win
9x/ME, he also will put such a program here?


## Cable
### Connecting the data recorder directly to the PC
The hardware needed is very simple. At the PC site you need a parallel male
plug (SUB-D, 25 pins) to connect the data recorder to your LPT port. At the
site of your MZ-data recorder you need a male plug to connect this plug to your
data recorder female plug. If you use a C64 datassette or other recorders use
the plug needed. The two plugs must be wired as follows:

| SUB-D pin # |     Signal | MZ-1T01/MZ-1T04 pin # | Signal |
|:-----------:|:--         |:---------------------:|:--     |
|           3 | data bit 1 |                     7 |  Write |
|       18-25 |        GND |                     9 |  GND/E |
|           - |          - |                     6 |    +5V |

E.g., you have to connect pin 3 at the PC site to pin 7 at the MZ's / data
recorder's site.

You must use an external power supply (5V / min. 0.3A), alternatively you can
use the power available by one of the joystick connectors at the rear of the MZ
(available only for the 700 and 800 series; for the pin descriptions take a
look into the Service Manual available in my Download Sections). Connect the
power to the pins 9 (-5V) and 6 (+5V) at the MZ's / data recorder's site (see
table above). The power supply is needed to supply your data recorder because
the PC's LPT port cannot do this.

Please wait for the pin descriptions for the MZ-80K/80A/80B or try yourself
(see the Download sections for Service Manuals).

### Connecting the MZ directly to the PC
If you use this method you do not have to store a program on tape and next to
read it from tape. Your MZ-file will be directly loaded into the MZ's memory.
This is the quickest method, but you do not have a copy of the program for
later use.

Using this method you have to connect the MZ to the PC in a similar way as
described above. The difference is, that you connect a plug directly with the
data recorder's plug on the MZ's motherboard by removing the data recorder's
plug (if any) or alternative directly with the external recorder "READ" cinch
plug at the rear of the MZ. If you decide to use the MZ-700/800 external READ
cinch plug, you need a common cinch plug (male). Read the author's
documentation file about how to make this very simple connection by a cinch
plug.

The MZ-80K/MZ-80A/MZ-80B do not have such an external connector. For these
models you always have to make an internal connection by a connector or by
soldering the wires directly (depending on the model you have).

You do not need an external power supply if you connect the MZ directly to the
PC. A connection to +5V isn't required.

If you want to use the READ plug (you do not make a direct connection to the
motherboard) and you're using one of the following models 721, 731 or 821 then
you also have to make a simple change which is described here. These models
need to be prepared. The author of this interface has put also an information
in his documentation file about the necessary preparation for these MZ-models.
No changes are necessary if you connect directly with the MZ's motherboard.

Please wait for the pin description of the MZ-80K/80A/80B or try yourself
(see the Download sections of Service Manuals).


## Software
### Installing the software
Unzip all files into their given directories.

- The software is freeware and the source code is included to enable you to
  change the program for your own purposes.

All files (`callgate.sys` and `callgate.dll`) must reside in the directory
where the `mzput.exe` resides or they can reside in the root directory (`C:`).

### Operation
The software is to be run with administrator rights and privileges under Win
NT-systems (NT4, W2k, XP) or Linux.

Make ready your MZ or data recorder for the data transfer as described next. Do
it now - you have no chance to do it later!

If you use a data recorder then position the tape correctly and push the REC
and PLAY buttons.

If you use the MZ then run your loader program (e.g., type `L` or `C` in the
MZ-monitor program).

Execute mzput and use the optional options described in the author's
documentation file. For example, if you want to do a "normal" data transfer
(i.e., normal speed, no turbo modes, really like the 1200 baud transfer of the
MZ), then use the following options:

    mzput.exe -c

`-c` means that the conventional mode of 1200 baud is to be used by mzput.

- Don't be confused: Your system is locked while transferring data. It will be
  unlocked when the data transfer finishes. This means, you cannot do anything
  more in this time. Even the mouse interrupt is suppressed. The lock is
  necessary because any interrupt could falsify the data written.
- It may be that you'll get the following error message under W2k: Couldn't
  release I/O privilege level. Ignore the message. The data transfer should be
  done correctly. This version is a beta test, and, it may be, that there is a
  bug in your W2k system version SP3.
- The author and I would be very thankful if you send him your error messages,
  any problems, and any comments for this beta version. Please contact him, if
  you want to help.

### Download
Download the beta test version for NT-systems and Linux (130 kb). The source
code and the documentation are included.

### What's new in version 0.1 beta?
- The ability to abort the transfer by pressing ESC.
- The motor control.
- The "can't release I/O privelege" message is gone (in normal operation, so it
  can't be safely ignored anymore).
- The option `-d` to print out more info and asks the user to press ENTER
  before beginning the transfer.
- A readme for each version (and a word of caution for windows).
- The documentation is also updated.
- The code is now tested for windows XP. 
