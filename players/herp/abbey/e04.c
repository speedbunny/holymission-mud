#include "abbey.h"
inherit "room/room";

reset(arg) {
object mo,ob;
  if (!arg) {
     set_light(1);
     short_desc="Outside the Abbey";
     long_desc=
  "A narrow track leading to an ancient abbey to the south.\n";
     dest_dir=({ PATH+"/e03","north",
		 PATH+"/e05","south" });
  }
  if (!(ob=present("monk")) || !living(ob)) {
	mo=clone_object("obj/monster");
	mo->set_name("monk");
	mo->set_short("A poor monk is standing here");
	mo->set_long("This is a poor monk.\n");
	mo->load_chat( 10,
	({ "The monk says: You must leave this place at once!\n",
	   "The monk says: The beast has killed four of my brothers.\n",
	   "The monk says: The devil is roaming this abbey!\n" }) );
	mo->load_a_chat( 10,
	({ "The monk says: The Holy Inquisitor wants to question you.\n" }) );
	mo->set_level(10);
	ob=clone_object("obj/armour");
	ob->set_name("shield");
	ob->set_short("shield");
	ob->set_type("shield");
	ob->set_value(100);
	ob->set_ac(1);
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wear shield",mo);
  }
}
