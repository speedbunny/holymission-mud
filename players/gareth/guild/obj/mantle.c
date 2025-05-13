#include "/players/gareth/define.h"
INHERIT

drop() {
  if(query_verb()=="sell" || query_verb()=="give") {
		write("You decide not to part with your guild armour.\n");
		return 1;
	}
  write("You drop your guild armour and it quickly rusts and crumbles to dust.\n");
  destruct(this_object());
  return 1;
}

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_type("guild");
  set_name("mantle");
  set_ac(this_player()->query_level() / 3);
  set_short("Fighters mantle");
  set_long("This is a protection mantle created ONLY for Fighters.\n");
  set_value(0);
  set_weight(0);
  set_info("mantle (created by Fighter Capablanca using Uranus' Wand)");
  return 1;
}

throw_out_transfer() { return 1; }
