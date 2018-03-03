#include <stdio.h>
#include <stdlib.h> // Just to remove a warning (exit).
#include "args.h"
#include "methods.h"

#define VERSION "0.1 beta"

// Externs.
extern int speed_1,
           speed_2,
           corr_1,
           corr_2,
           debug;
extern char *filename;
extern void (*method)(byte *);

// Private function prototypes.
int chtoi(char *), // Convert the first char of a string to an integer.
    stoi(char *);  // Convert a string to an integer.
void license(void); // Print the license.

// Private functions.
// Convert the first char of a string to an integer and check the boundries.
int chtoi(char *string) {
  int temp = 0;
  
  if (!string)
    return -1;
  temp = (int)string[0] - 48;
  if ((temp < 0) || (temp > 4))
    return -1;
  return temp;
}//chtoi

// Convert the a string to an integer and check the boundries.
int stoi(char *string) {
  int i = 0,
      m = 1,
      temp = 0,
      ret = 0;
  
  if (!string)
    return -100;
  if (string[0] == '-') {
    m = -1;
    i++;
  }//if
    
  while (string[i]) {
    temp = (int)string[i] - 48;
    if ((temp < 0) || (temp > 9))
      return -100;
    ret *= 10;
    ret += temp;
    i++;
  }//while
  if (ret > 50)
    return -100;
  return m * ret;
}//stoi

// Print version information and stuff.
void info(void) {
  printf("Mzput %s.\n", VERSION);
  printf("Written by J. F. J. Laros, The Netherlands.\n\n");
}//info

void license(void) {
  info();
  printf("This program is freeware and may be used without paying any "
         "registration\nfees. It may be distributed freely provided it is "
         "done so using the\noriginal, unmodified version. Usage of parts "
         "of the source code is granted,\nprovided the author is "
         "referenced. For private use only. Re-selling or any\ncommercial "
         "use of this program or parts of it is strictly forbidden. The\n"
         "author is not responsible for any damage or data loss as a result "
         "of using \nthis program.\n");
}//license

// Public functions.
// Print usage and return an error code.
void error(int i) {
  info();
  printf("Usage: mzput <-i n> <-t n> <-1 n> <-2 n> <-c> <-s> <-w> filename\n"
         " -i sets initial speed mode (0, 1, 2, 3 or 4), default = 0.\n"
         " -t sets turbo speed mode (0, 1, 2, 3 or 4), default = 3.\n"
         " -1 sets correction for fast initial mode (-50 to 50).\n"
         " -2 sets correction for fast turbo mode (-50 to 50).\n"
         " -c sets conventional sending mode.\n"
         " -s sets fast sending mode.\n"
         " -w sets turbo sending mode (default).\n"
         " -p reverse polarity.\n"
         " -v displays version information.\n"
         " -l displays the license.\n"
         " -d displays more info while running the program.\n");
#ifdef LINUX
  printf("Run this program as root.\n");
#else
  printf("Run this program as administrator.\n"
       	 "Make sure callgate.dll and callgate.sys are in the "
	       "current directory.\n");
#endif
  exit(i);
}//error

// Set the configuration variables.
int setvars(int argc, char **argv) {
  int temp = 0,
      i = 1;
  
  while (i < argc) {
    if (argv[i][0] == '-')
      switch (argv[i][1]) {
        case 'i':                                   // Initial send speed.
          temp = chtoi(argv[i + 1]);
          if (temp == -1) {
            printf("No valid initial speed given.\n");
            error(1);
          }//if
          speed_1 = temp;
          i++;
          break;
        case 't':                                   // Turbo send speed.
          temp = chtoi(argv[i + 1]);
          if (temp == -1) {
            printf("No valid turbo speed given.\n");
            error(1);
          }//if
          speed_2 = temp;
          i++;
          break;
        case '1':                                   // Initial fast correction.
          temp = stoi(argv[i + 1]);
          if (temp == -100) {
            printf("No valid fast initial correction given.\n");
            error(1);
          }//if
          corr_1 = temp;
          i++;
          break;
        case '2':                                   // Initial fast correction.
          temp = stoi(argv[i + 1]);
          if (temp == -100) {
            printf("No valid fast turbo correction given.\n");
            error(1);
          }//if
          corr_2 = temp;
          i++;
          break;
        case 'c':
          method = conv;
          break;
        case 's':
          method = trans;
          break;
        case 'w':
          method = turbo;
          break;
        case 'p':
          reversepol();
          break;
        case 'v':
          info();
          exit(0);
        case 'l':
          license();
          exit(0);
        case 'd':
          debug = 1;
          break;
        default:
          printf("Unknown option: %s\n", argv[i]);
          error(1);
      }//switch
    else
      filename = argv[i];
    i++;
  }//while
  if (!filename) {
    printf("No filename given.\n");
    error(1);
  }//if
    
  return 0;
}//setvars
