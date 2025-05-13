inherit "obj/treasure";

#include "/players/topaz/defs.h"

object jerk,part;
reset(arg) {
  ::reset();

    set_id("voodoo doll");
    set_name("Voodoo");
    set_alt_name("doll");
    set_short("A Voodoo Doll");
    set_long("This is a mystical Voodoo Doll.\n" +
             "With it you can be a real pain in the butt!\n" +
             "Or any place you want to be.  :)\n" +
             "To use it, first you have to name it after someone\n" +
             "who is currently playing.\n" +
             "Then you just 'jab <bodypart>'.\n" +
             "Have fun!\n");
    set_value(100);
    set_weight(1);
}

init() {
  ::init();
    add_action("_jab","jab");
    add_action("_name","name");
}

_name(str) {
string plyr;
object finded;
  if(jerk) {
    write("The doll is already named after " + CAP(jerk) + ".\n");
    return 1;
  }
  if(!str) {
    write("Name it what?\n");
    return 1;
  }
  else {
    plyr=str;
    finded=(find_player(plyr));
    if(!finded) {
      write("No such person is playing now.\n");
      return 1;
    }
    else {
      jerk=plyr;
      write("You name the doll after " + CAP(jerk) + ".\n");
      return 1;
    }
  }
}

_jab(str) {
 if(!jerk) {
  write("You must name the doll after a player first.\n");
  return 1;
 }
 else {
  if(!str) {
    write("Jab "+jerk+" where?\n");
    return 1;
  }
 }
}
