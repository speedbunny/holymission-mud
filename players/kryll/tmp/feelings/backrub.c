/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 13 1997  Kryll        Converted to a bin system call.
 
*/

#include "/sys/defs.h"

int main(string str) {
  object ob;

  if(!str) {
    notify_fail("Backrub who?\n");
    return 0;
  }

  ob = present(str, ENV(TP));
  if(!ob) {
    notify_fail(CAP(str) + " is not here.\n");
    return 0;
  }

  write("You give " + CAP(str) + " a really good backrub.\n");
  TELL(ob, lw(TP->NAME + " gives you a really good backrub. "+
              "You feel much more relaxed now.\n"));
  say(lw(TP->NAME + " gives " + ob->NAME + " a really enjoyable "+
         "backrub. " + ob->NAME + " looks very relaxed now.\n"), ob);
  return 1;
}
