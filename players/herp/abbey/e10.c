#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,mo;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Central Courtyard";
     long_desc=
"You are at the northern end of the great central courtyard.\n";
     dest_dir=({ PATH+"/e09","north",
		 PATH+"/e11","south" });
  }
  if (!(mo=present("monk")) || !living(mo)) {
	mo=clone_object("obj/monster");
	mo->set_name("monk");
	mo->set_short("A monk");
	mo->set_long("An abbey monk in a richly embroidered robe.\n");
	mo->load_chat(10,
	({ "The monk says: When love turns, it becomes lycantrophy.\n",
	   "The monk says: The master will help you.\n",
	   "The monk says: More bitter than death is woman.\n" }) );
	mo->set_level(15);
	ob=clone_object("obj/weapon");
	ob->set_name("staff");
	ob->set_short("A small wooden staff");
	ob->set_class(15);
	ob->set_value(500);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("robe");
	ob->set_type("cloak");
	ob->set_value(100);
	ob->set_short("An embroidered robe");
	ob->set_class(1);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("shield");
	ob->set_type("shield");
	ob->set_value(150);
	ob->set_short("A silver embossed shield");
	ob->set_class(1);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("boots");
	ob->set_type("boot");
	ob->set_value(200);
	ob->set_short("A pair of boots");
	ob->set_class(1);
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wield staff",mo);
	command("wear robe",mo);
	command("wear shield",mo);
	command("wear boots",mo);
  }
}
