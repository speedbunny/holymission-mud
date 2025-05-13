/*-------------------------------------------------------------------------*/
/* FILE : wimpy.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              set their wimpy.                                           */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  int tmp, max;

  if(!str) {
    write("Give an argument in percent.\n");
    return 1;
  }
  if(str == "brave")
    str = "-1";
/*
  if(sscanf(str, "%d", tmp)) {
*/
  if(intp(str))
    tmp = str;
  else {
    write("Give an argument in percent.\n");
    return 1;
  }
  if(tmp < -1)
    tmp = -1;
  max = 20 + 2 * TP->query_wis();
  if(tmp > max) {
    tmp = max;
    write("Not even you are that wimpy!\n");
  }
  TP->set_wimpy(tmp);

  if(tmp == -1)
    write("You are in brave mode now!\n");
  else
    write("Wimpy changed to " + whimpy + "%\n");
  return 1;
}

