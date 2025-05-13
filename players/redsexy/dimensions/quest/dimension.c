inherit "/obj/thing";

#include "/players/matt/defs.h"

#define EYE_DAM 50

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("eyestalk");
  set_alias("stalk");
  set_short("Eyestalk");
  set_long("This is the crippled eyestalk of a Beholder.\n" +
	   "In combat, type 'beam <target>' to use it.\n");
  set_value(500);
  set_weight(1);
}

init() {
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
	  write("You zap " + target->NAME + " with a beam from the eye!\n");
	  write("The eye vanishes in mass of oily smoke.\n");
	  say(TP->NAME + " zaps " + target->NAME + " with a beam of light!\n");
	  target->HIT(EYE_DAM);
	  destruct(TO);
	  return 1;
	}
	write("You cannot zap " + arg + " .\n");
	return 1;
      }
      write("That is not here.\n");
      return 1;
    }
    write("You are not carrying the eyestalk.\n");
    return 1;
  }
}
