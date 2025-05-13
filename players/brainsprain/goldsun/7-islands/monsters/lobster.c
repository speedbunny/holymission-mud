inherit "/obj/monster";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("lobster");
set_race("animal");
set_short("A sea lobster");
set_long(
"A sea lobster snaps wildly at the air with its strong claws.  "+
"Its blue body shimmers slightly as it moves about the area.  "+
"Its shell acts almost like an a piece of armour for it and due "+
"to its enormous size you might be able to use it as a shield.\n");
set_level(8);
set_gender(1);
set_wc(9);
set_ac(5);
set_spell_mess1("Lobster pinches you.\n");
set_spell_mess2("");
set_spell_dam(11);
set_chance(22);
set_size(2); 
move_object(clone_object(ii+"/shield"),
   this_object());
}

