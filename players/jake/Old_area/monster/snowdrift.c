inherit "/obj/monster";

#include "/players/jake/defs.h"
object ice;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("snow drift");
  set_alias("drift");
  add_money(300);
  set_alt_name("snow");
  set_short("Snow drift");
  set_long("This is a snowy monster called the snow drift.\nBe careful of him.\n");
  set_race("monster");
  set_level(10);
  set_al(-243);
  set_ac(3);
  set_aggressive(0);
ice = clone_object("players/jake/Old_area/armour/iceshield");
  move_object(ice,this_object());
 init_command("wear ice shield");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
