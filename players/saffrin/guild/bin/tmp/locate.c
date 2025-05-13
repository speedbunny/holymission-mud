#include "/players/saffrin/guild/defs.h"

int main(string target) {

  object obj;

  if (!target) {
    write("Usage : locate <playername>\n");
    return 1;
  }

  obj=find_player(target);
  if (!obj) {
    write("Your locate spell for "+CAP(target)+" fizzles.\n");
    return 1;
  }

  if ( (obj->query_immortal()) && (!TP->query_immortal()) ) {
    write("You are not skilled enough to locate an immortal.");
    return 1;
  }

  obj=ENV(obj);
  if (!obj) {
    write("You sense that "+CAP(target->RNAME)+" is in a void of time.\n");
    return 1;
  }

  write("After careful concentration, you locate " + CAP(target) + ".\n");
  write("They are located in the following room:\n");
  if (TP->query_immortal()) {
    write("\n");
    write("FILE : " + file_name(obj) + "\n");
    write("\n");
  }
  write(obj->long());
  return 1;
}
