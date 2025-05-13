/*-------------------------------------------------------------------------*/
/* FILE : attr.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              see their attributes (ie. spells that are on them).        */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 10 1997  Kryll        Converted to a bin system call.
 
*/
 
#include "/sys/defs.h"
 
int main(string str) {
  int    i, sz;
  string *attrs, txt, tmp;
 
  txt = "Attributes:\n";
  if(guild_soul)
    tmp = guild_soul->attributes();
  if(tmp)
    txt += tmp;
  attrs = TP->effects();
  if(!attrs || !sizeof(attrs)) {
    write(txt);
    return 1;
  }
  txt += "\nAffected by:\n" + "-----------\n";
  for(i=0, sz=sizeof(attrs); i<sz; i++)
    txt += "  " + attrs[i] + "\n";
  write(txt);
  return 1;
}

