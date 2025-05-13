#include "abbey.h"
inherit "room/room";

reset(arg) {
object mo,ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Central Courtyard";
     long_desc=
"You stand in the great central courtyard, with the Abbey all around you.\n";
     dest_dir=({ PATH+"/e12","north",
		 PATH+"/e14","south" });
  }
  if (!(ob=present("monk")) || !living(ob)) {
	mo=clone_object("obj/monster");
	mo->set_name("monk");
	mo->set_short("A monk in a rough brown robe");
	mo->set_level(15);
	mo->load_chat(10,
	({ "The monk says: Ahh my son, the times we live in!\n",
	   "The monk says: The Master will help you.\n",
	   "The monk says: The beast is still here, I can sense him.\n" }) );
	ob=clone_object("obj/armour");
	ob->set_name("gauntlets");
	ob->set_type("glove");
	ob->set_value(100);
	ob->set_short("brass gauntlets");
	ob->set_ac(1);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("shield");
	ob->set_type("shield");
	ob->set_value(120);
	ob->set_short("A black shield");
	ob->set_ac(1);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("robe");
	ob->set_type("cloak");
	ob->set_value(100);
	ob->set_short("A soft, brown robe");
	ob->set_ac(1);
	move_object(ob,mo);
	ob=clone_object("obj/weapon");
	ob->set_name("staff");
	ob->set_value(500);
	ob->set_short("A small wooden staff");
	ob->set_class(12);
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wear gauntlets",mo);
	command("wear shield",mo);
	command("wear robe",mo);
	command("wield staff",mo);
  }	
}
