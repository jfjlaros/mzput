First of all let me give you some advise before using this program.
- Make a system restore checkpoint.
- Copy the data from that checkpoint to somewhere in the windows directory
  (C:\WINDOWS\Restore for example), this will make sure you can access your
  backup when you're in the recovery console.
- Sync your harddisk before using the program. A binary to do this can be
  found at: http://www.sysinternals.com/ntw2k/source/misc.shtml#
These things are wise to do because mzput has total disrespect for the 
operating system and things could go wrong.

Basic setup:
- See mzput.ps page 5 for the cable and jumper plug.
- Use mzput with an mzf file as argument.

Connecting a tape recorder to your PC:
- See mzput.ps page 6 for the cable.
- Use mzput -c with an mzf file as argument.

You may use the -d option to have more control over what's going on.
