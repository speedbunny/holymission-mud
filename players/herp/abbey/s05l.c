#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,so;
int i;

  if (!arg) {
     set_light(1);
     short_desc="The soldier's room";
     long_desc="You have entered the soldier's sleeping quarters.\n";
     dest_dir=({ PATH+"/s05","east" });
  }
  if (!(ob=present("soldier")) || !living(ob))
     for(i=0;i<2;i++) {
	so=clone_object("obj/monster");
	so->set_name("soldier");
	so->set_level(8);
	so->set_short("A soldier");
	so->set_long("A soldier in a black uniform.\n");
	ob=clone_object("obj/weapon");
	switch(random(2)) {
	case 0:
	  ob->set_name("sword");
	  ob->set_value(300);
	  ob->set_class(10);
	  break;
	case 1:
	  ob->set_name("axe");
	  ob->set_value(250);
	  ob->set_class(7);
	  break;
	}
	move_object(ob,so);
	move_object(so,this_object());
	command("wield weapon",so);
  }
}
