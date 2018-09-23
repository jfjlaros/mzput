Installation
============

Hardware configuration
----------------------

Enable the external tape interface
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

For the MZ-711 and MZ-811, this step can be omitted. For other models, i.e.,
those with an internal data recorder or a quickdisk, the external tape
interface_ needs to be enabled, also see a description of the reverse_ of this
operation.

Enabling the external interface is done by disconnecting the data recorder or
quickdisk from connector P-12 and by connecting the *jumper plug*. This plug
will wire the read and write signals to the external connectors and it will
suppress the "Press play" message.

A jumper plug can be made from a plug similar to the one the data recorder and
quickdisk use.

.. figure:: ../doc/jumper_plug.svg
   :alt: Jumper Plug

   Jumper Plug

The wires are connected as follows:

+------+------+----------+
| MZ   | MZ   | signal   |
+======+======+==========+
| 1    | 7    | write    |
+------+------+----------+
| 2    | 8    | read     |
+------+------+----------+
| 5    | 9    | sense    |
+------+------+----------+

These wires can also be soldered directly on the connector and optionally, the
sense signal can be wired to an external switch.

The MZ-80K/MZ-80A/MZ-80B do not have external connectors. For these models an
internal connection must be made.

Also see an `instruction video`_ on this subject.

Transfer cable
~~~~~~~~~~~~~~

To wire an MZ to a PC, the following cable is used.

.. figure:: ../doc/transfer_cable.svg
   :alt: Transfer cable

   Transfer cable

Wiring is as follows:

+---------+----------------+----------+
| PC      | MZ             | signal   |
+=========+================+==========+
| 3       | read tip       | read     |
+---------+----------------+----------+
| 10      | write tip      | write    |
+---------+----------------+----------+
| 18-25   | both sleeves   | ground   |
+---------+----------------+----------+

Alternative setup
~~~~~~~~~~~~~~~~~

To connect the data recorder to a PC, the following wiring should be used:

+---------+-----------------+------------+
| PC      | Data recorder   | signal     |
+=========+=================+============+
| 3       | 7               | read       |
+---------+-----------------+------------+
| 10      | 8               | write      |
+---------+-----------------+------------+
| 18-25   | 9               | ground     |
+---------+-----------------+------------+
| 9       | 4               | motor on   |
+---------+-----------------+------------+
| -       | 6               | +5V        |
+---------+-----------------+------------+

The +5V must be provided by an external power supply (5V / min. 0.3A).


Software installation
---------------------

Binaries
~~~~~~~~

The binaries can be found in `this archive`_. After unzipping this archive, the
binaries for Linux can be found in ``src/linux/release``, those for Windows can
be found in ``src\w32\release``.

From source
~~~~~~~~~~~

Retrieve the source code with Git.

::

    git clone https://github.com/jfjlaros/mzput.git

To compile for Linux:

::

    cd mzput/src/linux
    sh build.sh

For Windows, use:

::

    cd mzput\src\w32
    build.bat

The binary will be placed in the ``release`` subdirectory.

Notes for Windows users:

- This program uses the callgate_ mechanism for real time operations. Since
  this mechanism is also used by viruses, the virusscanner may need to be
  disabled.
- The files ``callgate.sys`` and ``callgate.dll`` must reside in the same
  folder as ``mzput.exe``, or they can be installed in one of the folders in
  the system path.


.. _interface: https://web.archive.org/web/20170831235447/http://www.sharpmz.org/mz-700/filetrans.htm
.. _reverse: https://web.archive.org/web/20170831235523/http://www.sharpmz.org/mz-700/usetape3.htm
.. _instruction video: https://www.youtube.com/watch?v=iwD3-5ENyE8&t=86
.. _this archive: https://web.archive.org/web/20150926202647/http://www.sharpmz.org/download/mzput_0.1_beta.zip
.. _callgate: https://web.archive.org/web/20121103010240/http://www.sonic.net:80/~undoc/ntcallgate.html
