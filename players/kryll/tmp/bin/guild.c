/*-------------------------------------------------------------------------*/
/* FILE : guild.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              speak over their guild line.                               */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  int    gd_num;
  string gnam, msg, v;

  if(TP != TI)
    return 0; /* faked call */

  gd_num = TP->query_guild();
  if(!str) {
    write("Guild members online:\n\n");
    return CD->print_line(gd_num);
  }

  if(str=="on" || str=="off")
    return CD->set_line(TP, gd_num, str == "on" ? 1 : 0);

  gnam = CAP(GM->query_name(gd_num));
  v = query_verb();
  if(v[strlen(v) - 1] == '/')
    msg = "[*" + gnam + "*] " + CAP(TP->RNAME) + " "; /* emote .. */
  else
    msg = "[*" + gnam + " " + CAP(TP->RNAME) + "*] ";
  return CD->do_chat(gd_num, msg + str + "\n");
}

