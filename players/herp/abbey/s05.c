#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,so;
int i;

  if (!arg) {
     set_light(1);
     short_desc="A central hall";
     long_desc=
"You have entered a large room, filled with tables and chairs.\n"+
"It seems to be where the inquisition will be held.\n";
     dest_dir=({ PATH+"/s06","north",
		 PATH+"/s04","south",
		 PATH+"/s05r","east",
		 PATH+"/s05l","west" });
  }
  if (!(ob=present("soldier")) || !living(ob))
     for (i=0;i<3;i++) {
	so=clone_object("obj/monster");
	so->set_name("soldier");
	so->set_level(8);
	so->set_short("A soldier in a black uniform");
	so->set_long("The soldier is sharpening his weapon.\n");
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
