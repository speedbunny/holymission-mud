#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,co;
  if (!arg) {
     set_light(1);
     short_desc="The Abbey Kitchen";
     long_desc=
"You are in the vast kitchen, where meals are prepared each day for the\n"+
"many monks who inhabit the abbey.  Great cauldrons and kettles hang from\n"+
"hooks from the rafters.  Herbs and spices dry along one wall.\n";
     dest_dir=({ PATH+"/c01","northwest",
		 PATH+"/c19","south",
		 PATH+"/c13","east" });
  }
  if (!(co=present("cook")) || !living(co)) {
	co=clone_object("obj/monster");
	co->set_name("cook");
	co->set_short("A cook");
	co->set_long("You see a powerful looking cook.\n");
	co->load_chat(10,
	({ "The cook says: Good day.\n",
	   "The cook says: What can I do for you?\n",
	   "The cook bows before you.\n" }) );
	co->set_level(7);
	ob=clone_object("obj/weapon");
	ob->set_name("ladle");
	ob->set_short("A cook's fine ladle");
	ob->set_class(5);
	move_object(ob,co);
	ob=clone_object("obj/armour");
	ob->set_name("apron");
	ob->set_short("A padded apron");
	ob->set_ac(3);
	move_object(ob,co);
	move_object(co,this_object());
	command("wear apron",co);
	command("wield ladle",co);
  }
}

init() {
  ::init();
  add_action("block","south");
}

block() {
object ob;
  if ((ob=present("cook")) && living(ob)) {
     write("The cook bars the way!\n");
     return 1;
  }
  return ::move(query_verb());
}
