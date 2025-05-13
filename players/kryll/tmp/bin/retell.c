/*-------------------------------------------------------------------------*/
/* FILE : retell.c                                                         */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              retell the last message to a player, in case of typo in    */
/*              the name or needing to tell another player.                */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"
#include "/sys/player_defs.h"

int main(string str) {
  string msg;

  if(!str) {
    write("The correct syntax is : retell <player> \n");
    return 1;
  }

  str = lower_case(str);
  msg = TP->query_retell_message();
  (PLAYER + "tell")->main(str + " " + msg);
  return 1;
}
 
