inherit "/obj/npc";
#include "../meadow.h"

  reset(arg) {
  ::reset(arg);
  if (!arg) {
 
   set_name("bear");
   set_level(15);
   set_size(4);
   set_alias("brown bear");
   load_chat(8,({"B R U mmmmmmmmmmm\n"}));
   set_short("A dangerous brown bear");
   set_long("It looks harmless but very strong.\n");
   set_spell_mess1("The bear hits you with its claw.");
   set_spell_mess2("The bear bites you.");
   set_chance(20);
   set_spell_dam(8);
   set_attacks(1);
   set_attacks_change(30);
   set_dodge(5);
   move_object(clone_object(OBJ+"bear_claw"),this_object());
   move_object(clone_object(OBJ+"bear_fur"),this_object());
   init_command("wield claw");
}
}
