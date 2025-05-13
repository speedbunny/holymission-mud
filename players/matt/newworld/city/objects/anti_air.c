inherit "/obj/thing";

#include "/players/matt/defs.h"

string *target_list;

reset(arg) {
  ::reset(arg);
  target_list = ({ "boomerang", "frisbee", "hamster" });
  set_name("crossbow");
  set_short("Magic Crossbow");
  set_long("This is a magical crossbow designed to seek out and destroy\n" +
	   "those annoying frisbees, boomerangs, and other airborne\n" +
	   "/objects. To use it, type \"seek <object>\" or, to be more\n" +
	   "specific, try \"fire at <player>'s <object>\".\n" +
	   "Enjoy!    - Matt\n");
  set_alias("magic crossbow");
  set_value(300);
}

init() {
  ::init();
  add_action("fire", "fire");
  add_action("seek", "seek");
}

fire(arg) {
  int i;
  string whom, what;
  object player, target;
  if(arg && sscanf(arg, "at %s's %s", whom, what)) {
    player = find_player(whom);
    if(player) {
      if(member_array(what, target_list) != -1) {
	target = present(what, player);
	if(target) {
	  write("You fire your crossbow and nail " + player->SNAME +
		"'s " + what + "!\n");
	  TELL(target, TP->SNAME + " destroys your " + what +
	       "with a crossbow bolt.\n");
	  shout(TP->SNAME + " destroys " + what + " with a " +
		"crossbow bolt!\n");
	  destruct(target);
	  return 1;
	}
	write(player->SNAME + " is not carrying that.\n");
	return 1;
      }
      write("Current list of targets:\n");
      for(i = 0; i < sizeof(target_list); i++)
	write("  " + target_list[i] + "\n");
      return 1;
    }
    write("You can't seem to aim at " + CAP(whom) + ".\n");
    return 1;
  }
  write("Syntax: fire at <player>'s <object>\n");
  return 1;
}

seek(arg) {
  int i;
  object target, *owners;
  if(member_array(arg, target_list) != -1) {
    owners = filter_array(users(), "owner_filter", TO, arg);
    if(sizeof(owners)) {
      target = present(arg, owners[0]);
      write(owners[0]->NAME + " is carrying the " + arg + ".\n");
      TELL(owners[0], "You feel like you're being targeted...\n");
      return 1;
    }
    write("You can't seem to aim at " + arg + ".\n");
    return 1;
  }
  write("Current list of targets:\n");
  for(i = 0; i < sizeof(target_list); i++)
    write("  " + target_list[i] + "\n");
  return 1;
}

owner_filter(obj, arg) {
  return present(arg, obj);
}
