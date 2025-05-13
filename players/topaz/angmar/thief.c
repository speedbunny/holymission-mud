inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("thief");
    set_short("A suspicious looking thief");
    set_long("He's a thief.  What else is there to say?\n");
    set_aggressive(0);
    set_level(14);
    set_wc(13);
    set_ac(5);
    set_al(-100);
    set_hp(150);
    add_money(250+(random(250)));
    move_object(clone_object(PATH + "angmar/stiletto"),this_object());
    command("wield stiletto");
  }
  return 1;
}
