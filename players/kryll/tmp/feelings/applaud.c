/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 13 1997  Kryll        Converted to a bin system call.
 
*/

#include "/sys/defs.h"
#include "/sys/bin/adverbs.h"

int main(string str) {
  object ob;
  string tmp, adv, who;
  int    where, len, idx;

  adv = "wholeheartedly";
  if(!str) {
    write("You applaud " + adv + ".\n");
    say(TP->NAME + " applauds " + adv + ".\n");
    return 1;
  }

  if(sscanf(str, "%s %s\n", who, tmp) == 2) {
    len = strlen(tmp);
    switch(len) {
      case 3 :
        idx = member_array(tmp[0], ALPHABET);
        if((where = member_array(tmp, SHORT_ADV_LIST[idx])) == -1) {
          notify_fail("Applaud " + who + " how?\n");
          return 0;
        }
        adv = ADVERB_LIST[idx][where];
        break;
      case 4 :
        idx = member_array(tmp[0], ALPHABET);
        if((where = member_array(tmp, LONG_ADV_LIST[idx])) == -1) {
          notify_fail("Applaud " + who + " how?\n");
          return 0;
        }
        adv = ADVERB_LIST[idx][where];
        break;
      default :
        adv = tmp;
    }
  }
  else {
    who = str;
  }

  ob = present(who, ENV(TP));
  if(!ob) {
    notify_fail(CAP(str) + " is not here.\n");
    return 0;
  }

  write("You " + adv + " applaud " + who + ".\n"); 
  TELL(ob, lw(TP->NAME + " applauds you " + adv + ".\n"));
  say(lw(TP->NAME + " applauds " + ob->NAME + " " + adv + ".\n"), ob);
  return 1;
}
