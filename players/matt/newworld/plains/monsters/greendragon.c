inherit "/obj/monster";

#include "/players/matt/defs.h"

object wand;

reset(arg) {
  ::reset(arg);
  if(!wand) {
    wand = clone_object(NWPLAINS + "objects/alignwand");
    MOVE(wand, TO);
  }
  if(arg) return;
  set_name("green dragon");
  set_race("dragon");
  set_short("Green dragon");
  set_long("This massive dragon with shiny green scales towers over you\n" +
	   "menacingly, glaring down as if daring you to attack it. Its\n" +
	   "eyes burn with an unholy red glow.\n");
  set_level(30);
  set_hp(1000);
  set_al(-1000);
  set_wc(20);
  set_ac(20);
  set_no_steal(1);
  set_chance(30);
  set_spell_mess1("The dragon draws a breath and blows out smoky flames!\n");
  set_spell_mess2("The dragon breathes fire at you!\n");
  set_spell_dam(50);
  add_money(2000);
  load_chat(10, ({
    "The dragon says: Leave this place.\n",
    "The dragon guards its treasure protectively.\n",
    "Steam curls up from the dragon's nostrils.\n"
  }));
  load_a_chat(10, ({
    "The dragon growls: I will crush you!\n",
    "The dragon's claws and fangs rip and bite mercilessly.\n",
    "The dragon roars loudly!\n"
  }));
}
