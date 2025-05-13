inherit "/obj/monster";
#include "../meadow.h"

  reset(arg) {
  ::reset(arg);
  if (!arg) {
 
   set_name("rabbit");
   set_level(2);
   set_size(2);
   set_alias("field rabbit");
   set_short("A cute field rabbit");
   set_long("A cute rabbit with big brown eyes.\n");
   set_whimpy();
   set_spell_mess1("The cute rabbit hits you with its claw.");
   set_spell_mess2("The rabbit slaps you.");
   set_chance(20);
   set_spell_dam(2);
   move_object(clone_object(OBJ+"rabbit_claws"),this_object());
   init_command("wield claw");
}
}
