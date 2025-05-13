inherit "/obj/monster";
#include "../meadow.h"

reset(arg) {

  ::reset(arg);
  if (!arg) {
 
   set_name("bull");
   set_level(12);
   set_size(4);
   set_alias("big bull");
   load_chat(20,({"S c h n a u b !\n"}));
   set_short("A dangerous red bull.");
   set_long("!!!!!! It starts to attack you.\n");
   set_aggressive(1);
   set_whimpy();
   set_spell_mess1("The bull hits you with its horn.");
   set_spell_mess2("The bull hits you with its hoof.");
   set_chance(20);
   set_spell_dam(6);
   move_object(clone_object(OBJ+"horn"),this_object());
   init_command("wield horn");
   }
}
