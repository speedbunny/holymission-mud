/*-------------------------------------------------------------------------*/
/* FILE : exits.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              see the exits in the room they are in.                     */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 10 1997  Kryll        Converted to a bin system call.
 
*/

#include <sys_defs.h>
 
int main(string str) {
  string *exits, short;
  int    i, sz;
 
  if(!(sz = sizeof(exits = ENV(TP)->query_dest_dirs()))) {
    write("There are no obvious exits.\n");
    return 1;
  }

  write("Obvious Exits:\n\n");
  for(i=1; i<sz; i+=2) {
    if(catch(call_other(exits[(i-1)], "???")) == 0)
      short = exits[(i-1)]->short();
    else
      short = "Somewhere";

    printf("%-15s", "  " + exits[i]);
    if(stringp(short))
      printf("%-30s\n", short);
    else
      printf("%-30s\n", "Somewhere");
  }
  return 1;
}
