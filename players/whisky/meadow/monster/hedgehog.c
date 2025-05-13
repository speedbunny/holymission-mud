inherit "/obj/monster";
#include "../meadow.h"

  reset(arg) {
  ::reset(arg);
  if (!arg) {
 
   set_name("hedgehog");
   set_level(3);
   set_size(2);
   set_short("A little hedgehog");
   set_long("A harmless little hedgehog, with big brown eyes.\n");
   set_spell_mess1("The hedgehog bites you in your finger.");
   set_spell_mess2("The hedgehog hits you with its stinger.");
   set_chance(20);
   set_spell_dam(3);
   move_object(clone_object(OBJ+"stinger"),this_object());
   init_command("wield stinger");
}
}
