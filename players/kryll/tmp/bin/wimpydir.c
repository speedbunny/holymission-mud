/*-------------------------------------------------------------------------*/
/* FILE : wimpydir.c                                                       */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              choose what direction they will go when they wimpy.        */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  if(str) {
    switch(str) {
      case "n"    : str = "north"; break;
      case "nw"   : str = "northwest"; break;
      case "w"    : str = "west"; break;
      case "sw"   : str = "southwest"; break;
      case "s"    : str = "south"; break;
      case "se"   : str = "southeast"; break;
      case "e"    : str = "east"; break;
      case "ne"   : str = "northeast"; break;
      case "u"    : str = "up"; break;
      case "d"    : str = "down"; break;
      case "off"  :
      case "none" : str = "NULL"; break;
      default     : str = "EMPTY"; break;
    }
    if(str != "EMPTY")
      TP->set_wimpydir(str);
    else
      write("Your selection is invalid.\n");
    return 1;
  }
  write("Wimpydir is currently set to: " + TP->query_wimpydir() + ".\n");
  return 1;
}

