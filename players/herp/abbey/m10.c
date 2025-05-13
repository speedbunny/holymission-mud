#include "abbey.h"
inherit "room/room";

reset(arg) {
object mo,ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="The Prayer Room";
     long_desc=
"You have entered a large meeting room where the monks congregate\n"+
"to receive instruction in spiritual matters from their elders.\n";
     dest_dir=({ PATH+"/m09","south" });
  }
  if (!(ob=present("monk")) || !living(ob))
     for (i=0;i<3;i++) {
	mo=clone_object("obj/monster");
	mo->set_name("monk");
	mo->set_level(8);
	mo->set_short("A monk");
	mo->load_a_chat(10,
	({ "Monk says: Stop you fool!\n",
	   "Monk says: Bow before me!\n",
	   "Monk says: You must challenge the holy Inquisitor!\n",
	   "Monk says: What are you doing here??\n" }) );
	ob=clone_object("obj/weapon");
	switch(random(2)) {
	case 0:
	  ob->set_name("sword");
	  ob->set_short("A sword");
	  ob->set_value(300);
	  ob->set_class(10);
	  break;
	case 1:
	  ob->set_name("axe");
	  ob->set_short("An axe");
	  ob->set_value(250);
	  ob->set_class(7);
	  break;
	}
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wield weapon",mo);
     }
}
