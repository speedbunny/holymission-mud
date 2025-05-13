inherit "/obj/thing";

#include "/players/matt/defs.h"

#define rainbow_DAM 100

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rainbowstick");
  set_alias("stalk");
  set_short("rainbowstick");
  set_long("This is the rainbowstick that once belonged to Sophillicus.\n" +
	   "In combat, type 'beam <target>' to use it.\n");
  set_value(20000);
  set_weight(1);
}

void init() {
  ::init();
  add_action("beam", "beam");
}

beam(arg) {
  object target;
  if(arg) {
    if(ENV(TO) == TP) {
      target = present(arg, ENV(TP));
      if(target) {
	if(living(target)) {
	  write("You zap " + target->NAME + " with a beam from the rainbow!\n");
	  write("Some of the light is reflected back at you!\n");
	  say(TP->NAME + " zaps " + target->NAME + " with a beam of light!\n");
	  target->HIT(rainbow_DAM);
        TP->hit_player(30);
	  return 1;
	}
	write("You cannot zap " + arg + " .\n");
	return 1;
      }
      write("That is not here.\n");
      return 1;
    }
    write("You are not carrying the rainbowstick.\n");
    return 1;
  }
}
