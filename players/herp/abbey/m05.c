#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,gd;
  if (!arg) {
     set_light(1);
     short_desc="The Slope";
     long_desc=
"You are on a steep, snow-covered slope.  Far to the north you see some\n"+
"living quarters.  West is a cemetery, looking mournful and abandoned.\n"+
"The wind cuts through your clothing, chilling you.\n";
     dest_dir=({ PATH+"/m03","north",
		 PATH+"/m06","west" });
  }
  if (!(ob=present("gravedigger")) || !living(ob)) {
	gd=clone_object("obj/monster");
	gd->set_name("gravedigger");
	gd->set_level(5);
	gd->set_short("A gravedigger");
	gd->set_long("You see a filthy gravedigger.\n");
	gd->load_chat(10,
	({ "The gravedigger says: What do you want here?\n",
	   "The gravedigger says: You look too lively to me!\n",
	   "The gravedigger says: Eventually I see you all.\n" }) );
	gd->load_a_chat(10,
	({ "The gravedigger throws sand in your eyes.\n" }) );
	ob=clone_object("obj/weapon");
	ob->set_name("shovel");
	ob->set_class(3);
	ob->set_short("A gravediggers fine shovel");
	move_object(ob,gd);
	ob=clone_object("obj/armour");
	ob->set_name("shroud");
	ob->set_type("cloak");
	ob->set_short("A padded shroud");
	ob->set_ac(1);
	move_object(ob,gd);
	move_object(gd,this_object());
	command("wear cloak",gd);
	command("wield shovel",gd);
  } 
}
