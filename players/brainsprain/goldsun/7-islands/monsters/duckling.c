inherit "/obj/monster";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"
void reset(int arg)
 {
 load_chat(25,({"Duckling is walking around.\n",
	 	"Duckling ducks lovely.\n",
 		"Duckling runs to you.\n",
		"Duckling smiles at you.\n"}));
 ::reset(arg);
if (arg) return;
set_name("duckling");
set_race("duck");
set_short("A duckling");
set_long(
"A tiny yellow duckling lays in the sun, soaking up its rays.  Its yellow "+
"feathers ruffle gently in the breeze and its eyes flutter as it begins "+
"to fall asleep.  Its little orange legs quiver as it gets a brief chill.\n");
set_level(1);
set_wc(1);
set_ac(1);
set_al(120);
set_size(1);          
set_dead_ob(this_object());
}

int monster_died(object ob){
  tell_room(environment(this_object()),"Mother duck arrives.\n");
  move_object(clone_object(im+"/duck"),
              environment(this_object()));
  return 0;
}
