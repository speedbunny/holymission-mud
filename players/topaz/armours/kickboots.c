inherit "obj/armour";

#include "/players/topaz/defs.h"

int busy;
reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Kickboots");
    short_desc="Kickboots";
    long_desc="These are heavy boots with pointed toes.\n" +
              "To use them, type 'kick <opponent>' or\n" +
              "just 'kick' when in a fight.\n";
    set_alias("boots");
    set_type("boot");
    set_ac(1);
    set_weight(3);
    set_value(200);
  }
return 1;
}

init() {
  ::init();

    add_action("_kick","kick");
}


_kick(arg) {
  int ouch;
  string jerk;

 if(worn) {
  if (!arg && !(TP->query_attack())) {
    write("Kick whom ?\n");
    return 1;
  }
  else {
    if(busy) {
      write("Your feet need a rest.\n");
      return 1;
    }
    else {
      if(arg) 
        jerk=arg;
      ouch=5+(random(6));
      write("You kick " + jerk->query_name() + " in the leg.\n");
      jerk->restore_hit_points(ouch);
      jerk->attacked_by(TP);
      busy=1;
      call_out("_rest",5);
      return 1;
    }
  }
 }
 else {
  write("You must be wearing the boots to use them.\n");
  return 1;
 }
}

_rest() {
  busy=0;
  return 1;
}
