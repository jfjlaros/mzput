Usage
=====

This program must be run as root or Administrator. This is because of some
low-level routines that are used to enable real time operations in multitasking
systems like Linux or Windows.

When transferring directly to an MZ, first run the loader program (e.g., type
``L`` or ``C`` in the MZ-monitor program).

When using a data recorder, first position the tape correctly and push the REC
and PLAY buttons.

On the PC, transfer an MZF image named ``image.mzf``, using the following
command:

::

    mzput image.mzf

The program recognises the following options:

+----------+-----------------------------------------------------------------+
| option   | description                                                     |
+==========+=================================================================+
| ``-i``   | sets initial speed mode (0, 1, 2, 3 or 4), default = 0.         |
+----------+-----------------------------------------------------------------+
| ``-t``   | sets turbo speed mode (0, 1, 2, 3 or 4), default = 3.           |
+----------+-----------------------------------------------------------------+
| ``-1``   | sets correction for fast initial mode (-50 to 50).              |
+----------+-----------------------------------------------------------------+
| ``-2``   | sets correction for fast turbo mode (-50 to 50).                |
+----------+-----------------------------------------------------------------+
| ``-c``   | sets conventional sending mode.                                 |
+----------+-----------------------------------------------------------------+
| ``-s``   | sets fast sending mode.                                         |
+----------+-----------------------------------------------------------------+
| ``-w``   | sets turbo sending mode (default).                              |
+----------+-----------------------------------------------------------------+
| ``-p``   | reverse polarity.                                               |
+----------+-----------------------------------------------------------------+
| ``-v``   | displays version information.                                   |
+----------+-----------------------------------------------------------------+
| ``-l``   | displays the license.                                           |
+----------+-----------------------------------------------------------------+
| ``-d``   | displays more info and asks for confirmation before starting.   |
+----------+-----------------------------------------------------------------+

Note that during transfer, the PC will become completely unresponsive. This is
because all interrupts are disabled to allow for real time operations. A
running transfer can be aborted by pressing the ``ESC`` key.

It is recommended to *sync* the hard disks before each transfer and to install
NTP_ (or something similar). Disabling interrupts also means that the timer
interrupt is disabled, so the system clock will lag behind after each transfer.

Note for Windows users, it is recommended to make a *system restore point* and
copy the data to a directory inside the windows tree (e.g.,
``C:\WINDOWS\Restore``) this will enable you to restore the registry in the
event of a crash.


Operation modes
---------------

Fast sending mode
~~~~~~~~~~~~~~~~~

This is the easiest way to transfer a file. In this mode the long gap (a tape
marker) is 4000 pulses and the short gap is 5000 pulses. Both the header and
the MZF image body are transferred once.

Conventional sending mode
~~~~~~~~~~~~~~~~~~~~~~~~~

This is the safest (and slowest) way to transfer an image, everything is done
according to the Sharp MZ series conventions: A long gap is 22000 pulses, a
short gap is 11000 pulses. The header and body are transferred twice to allow
for errors.

Turbo sending mode
~~~~~~~~~~~~~~~~~~

In this mode, the turbo loader is transferred using fast sending mode, this
turbo loader enables the MZ to operate at higher transfer speeds. The MZF image
is then sent using fast sending mode, but now at a higher speed.

The speed at which the turbo loader is transferred is controlled with the
``-i`` option, the speed at which the MZF image is sent is controlled with the
``-t`` option.


Speeds
------

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

Corrections
~~~~~~~~~~~

Because the waveforms used by speeds 1 and 4 may not always work, two
correction factors for these speeds are implemented, controlled with the ``-1``
and ``-2`` options.


Polarity
--------

The polarity can be revered with the ``-p`` option.


.. _NTP: https://en.wikipedia.org/wiki/Network_Time_Protocol
