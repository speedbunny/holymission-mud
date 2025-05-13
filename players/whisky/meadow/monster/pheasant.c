inherit "/obj/monster";
#include "../meadow.h"

  reset(arg) {
  ::reset(arg);
  if (!arg) {
 
   set_name("pheasant");
   set_level(2);
   set_size(2);
   set_alias("brown pheasant");
   set_short("A shy pheasant");
   set_long("A cute little bird with brown feathers.\n");
   set_whimpy();
   set_spell_mess1("The pheasant picks you with its bill.");
   set_spell_mess2("Ruuuuuuuuuuuuuuuuuhhhhhhhhhh !");
   set_chance(20);
   set_spell_dam(2);
   move_object(clone_object(OBJ+"pheasant_claw"),this_object());
   init_command("wield claw");
}
}
