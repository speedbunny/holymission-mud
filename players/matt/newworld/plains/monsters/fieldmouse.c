inherit "/obj/monster";

#include "/players/matt/defs.h"

object cheese;

reset(arg) {
  ::reset(arg);
  if(!cheese) {
    cheese = clone_object(NWPLAINS + "objects/cheese");
    MOVE(cheese, TO);
  }
  if(arg) return;
  set_name("field mouse");
  set_race("rodent");
  set_alias("mouse");
  set_short("Field mouse");
  set_long("A small white field mouse hidden in the grass.\n");
  set_level(5);
  set_hp(60);
  set_al(30);
  set_wc(3);
  set_ac(30);
  add_money(10);
  load_chat(10, ({
    "Squeak!\n",
    "The mouse nibbles peckishly at its cheese.\n",
  }));
}
