/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 13 1997  Kryll        Converted to a bin system call.
 
*/

#include "/sys/defs.h"

int main(string str) {
  object ob;

  if(!str) {
    write("You arc an eyebrow.\n");
    say(TP->NAME + " arcs an eyebrow.\n");
    return 1;
  }

  ob = present(str, ENV(TP));
  if(!ob) {
    notify_fail(CAP(str) + " is not here.\n");
    return 0;
  }

  write("You arc an eyebrow at " + CAP(str) + ".\n");
  TELL(ob, lw(TP->NAME + " arcs an eyebrow at you.\n"));
  say(lw(TP->NAME + " arcs an eyebrow at " + ob->NAME + ".\n"), ob);
  return 1;
}
