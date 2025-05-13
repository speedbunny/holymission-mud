#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,so;
  if (!arg) {
     set_light(1);
     short_desc="The Beginning of the Hallway";
     long_desc=
"You are in a short hallway in the barracks of the soldiers.\n";
     dest_dir=({ PATH+"/s05","north",
		 PATH+"/s03","south",
		 PATH+"/s04r","east",
		 PATH+"/s04l","west" });
  }
  if (!(ob=present("soldier")) || !living(ob)) {
	so=clone_object("obj/monster");
	so->set_name("soldier");
	so->set_level(12);
	so->set_short("A soldier guarding the entrance");
	so->set_long("A fierce looking soldier, with a self-righteous expression.\n");
	ob=clone_object("obj/armour");
	ob->set_name("ring");
	ob->set_type("ring");
	ob->set_short("An opal ring");
	ob->set_value(350);
	ob->set_ac(1);
	move_object(ob,so);
	ob=clone_object("obj/weapon");
	ob->set_name("club");
	ob->set_value(270);
	ob->set_class(10);
	move_object(ob,so);
	move_object(so,this_object());
	command("wear armour",so);
	command("wield club",so);
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
  if ((ob=present("soldier")) && living(ob)) {
     write("The soldier bars the way "+query_verb()+".\n");
     return 1;
  }
  return ::move(query_verb());
}
