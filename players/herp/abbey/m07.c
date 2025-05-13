#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,mo;
  if (!arg) {
     set_light(1);
     short_desc="Monk Cells Hallway";
     long_desc=
"You are in the entry to the monks quarters.\n"; 
     dest_dir=({ PATH+"/m08","north",
		 PATH+"/m02","south",
		 PATH+"/m07r","east",
		 PATH+"/m07l","west" });
  }
  if (!(ob=present("monk")) || !living(ob)) {
	mo=clone_object("obj/monster");
	mo->set_name("monk");
	mo->set_level(15);
	mo->set_short("A monk guarding the entrance");
	mo->set_long("A fierce looking monk, taking his duty seriously.\n");
	mo->load_a_chat(10,
	({ "The monk casts a shock, you feel weaker.\n" }) );
	ob=clone_object("obj/weapon");
	ob->set_name("flail");
	ob->set_short("A flail");
	ob->set_value(350);
	ob->set_class(12);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("platemail");
	ob->set_alias("mail");
	ob->set_short("A golden platemail");
	ob->set_value(1500);
	ob->set_weight(4);
	ob->set_ac(3);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("helm");
	ob->set_type("helmet");
	ob->set_short("A golden helm");
	ob->set_value(500);
	ob->set_weight(2);
	ob->set_ac(1);
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wield flail",mo);
	command("wear helmet",mo);
	command("wear mail",mo);
  }
}

init() {
  ::init();
  add_action("block","north");
  add_action("block","east");
  add_action("block","west");
}

block() {
object ob;
  if ((ob=present("monk")) && living(ob)) {
     write("The monk bars the way.\n");
     return 1;
  }
  return ::move(query_verb());
}
