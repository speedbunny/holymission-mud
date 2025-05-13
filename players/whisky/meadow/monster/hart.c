inherit "/obj/monster";
#include "../meadow.h"

  reset(arg) {
  ::reset(arg);
  if (!arg) {
 
   set_name("buck");
   set_level(10);
   set_size(4);
   set_alias("big buck");
   set_short("A big aggressive buck.");
   set_long("Quick! Run away, it looks dangerous.\n");
   set_race("animal");
   set_spell_mess1("The buck hits you with its antler.");
   set_spell_mess2("The buck hurts you badly.");
   set_chance(20);
   set_spell_dam(4);
   move_object(clone_object(OBJ+"antlers"),this_object());
}
}
