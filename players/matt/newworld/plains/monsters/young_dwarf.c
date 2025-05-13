inherit "/obj/monster";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("young dwarf");
  set_race("dwarf");
  set_short("A young dwarf");
  set_long("This small, bearded dwarf is very lively. His face glows with\n" +
	   "with ruddy youthfulness, though his eyes suggest that he is\n" +
	   "wise beyond his years.\n");
  set_level(5);
  set_gender(1);
  set_al(200);
  add_money(5);
}

set_savior(obj) {
  load_chat(10, ({
    "The young dwarf smiles happily.\n",
    "Dwarf says: " + obj->NAME + " saved my life!\n",
    "The dwarf bounces around.\n",
    "Dwarf says: I am indebted to " + obj->NAME + ".\n",
  }));
  return 1;
}
