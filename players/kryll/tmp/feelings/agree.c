/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 13 1997  Kryll        Converted to a bin system call.
 
*/

#include "/sys/defs.h"

int main(string str) {
  object ob;
  string tmp, adv, who;

  adv = "wholeheartedly";
  if(!str) {
    write("You agree " + adv + ".\n");
    say(TP->NAME + " agrees " + adv + ".\n");
    return 1;
  }

  if(sscanf(str, "%s %s\n", who, tmp) == 2) {
    if(!(adv = (string)ADVERB_ROOM->find_adverb(tmp))) {
      notify_fail("Agree with " + who + " how?\n");
      return 0;
    }
  }
  else {
    who = str;
  }

  ob = present(who, ENV(TP));
  if(stringp(who) && !ob && !(adv = (string)ADVERB_ROOM->find_adverb(str))) {
    notify_fail(CAP(str) + " is not here.\n");
    return 0;
  }

  write("You " + adv + " agree with " + who + ".\n"); 
  TELL(ob, lw(TP->NAME + " agrees with you " + adv + ".\n"));
  say(lw(TP->NAME + " agrees with " + ob->NAME + " " + adv + ".\n"), ob);
  return 1;
}
