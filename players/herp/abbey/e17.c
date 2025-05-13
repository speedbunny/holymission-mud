#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,mo;
int i;

  if (!arg) {
     set_light(1);
     short_desc="The Chapel";
     long_desc=
"You have entered the chapel.  The choir is practicing.\n";
     dest_dir=({ PATH+"/e16","north",
		 PATH+"/e18","south",
		 PATH+"/g01","west",
		 PATH+"/e1701","east" });
  }

  if (!(ob=present("monk")) || !living(ob)) {
     for(i=0;i<5;i++) {
	mo=clone_object("obj/monster");
	mo->set_name("monk");
	mo->set_short("Monk");
	mo->set_long("A monk.\n");
	mo->set_level(10);
	mo->load_chat(10,
	({ "The monks sing: A monk should keep silent.\n",
	   "The monks sing: In much wisdom is much grief.\n",
	   "The monks sing: After the hailstorm and the trumpet.\n",
	   "The monks sing: A monk should not laugh.\n",
	   "The monks sing: The sea became blood, and BEHOLD!\n",
	   "The tenor sings: He who increaseth knowledge, increaseth sorrow.\n",
	   "The monks sing: Take pleasure from the defects of vulgar people.\n"
	}) );
	ob=clone_object("obj/weapon");
	switch(random(2)) {
	case 0:
	  ob->set_name("axe");
	  ob->set_class(5);
	  break;
	case 1:
	  ob->set_name("shortsword");
	  ob->set_type("sword");
	  ob->set_class(7);
	  break;
	}
	ob->set_value(250);
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wield weapon",mo);
     }
  }
}
