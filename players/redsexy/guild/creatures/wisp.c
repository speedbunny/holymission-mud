#include "lw.h"
#include "/players/redsexy/guild/obdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"

object att;

id(arg) {
  return arg == "wisp" || arg == "will-o-the-wisp" ||
    arg == "wisp_object";
}

short() { return "A Will-O-The-Wisp"; }
long() { write("A Will-O-The-Wisp giving out light.\n"); }

init() {
    add_action("ban",  "ban");
}

get() { return 1; }
drop() { return 1; }

extra_look() {
  return "A Will-O-The-Wisp hovers around " + TP->POS + " giving out light";
}

ban(arg) {
  if(id(arg)) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(RAVEN_BAN_SP);
    write("You banish your Wisp.\n");
    say(TP->SNAME + " gestures towards " + TP->POS + " Wisp, " +
	"and it explodes in a blinding flash of light!\n");
    destruct(TO);
    return 1;
  }
}

destroy_me(silent) {
  if(!silent) {
    write("Your Wisp vanishes.\n");
    say(TP->SNAME + "'s Wisp vanishes.\n");
  }
  destruct(TO);
  return 1;
}
