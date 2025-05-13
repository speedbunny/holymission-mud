#include "abbey.h"
inherit "room/room";

reset(arg) {
object mo,ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="The Tithing Desk";
     long_desc=
"You have entered the huge inner courtyard.  You are pushed roughly\n" +
"into line before a desk where monks gather the tithes for the abbey.\n";
     items=({
	"desk","You see a wooden desk, piled high with farm produce" });
     dest_dir=({ PATH+"/e07","north",
		 PATH+"/e09","south",
		 PATH+"/e0802","west",
		 PATH+"/e0803","east" });
  }
  if (!(mo=present("monk")) || !living(mo)) {
     for(i=0;i<5;i++) {
	mo=clone_object("obj/monster");
	mo->set_name("monk");
	mo->set_long("A simple rustic monk in a brown robe.\n");
	mo->load_chat(10,
	({ "The monk kisses you firmly on the mouth in welcome.\n",
	   "The monk welcomes you to the Abbey of the Ancient Rose.\n",
	   "The monk washes the road dust from your feet.\n",
	   "The monk washes your hands tenderly.\n",
	   "The humble monk bows before you.\n",
	   "The monk says: You must tithe to support the abbey!\n",
	   "The monk says: You must tithe to gain grace!\n" }) );
	mo->set_level(3);
	ob=clone_object("obj/weapon");
	ob->set_name("flail");
	ob->set_short("Flail");
	ob->set_value(150);
	ob->set_class(5);
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wield flail",mo);
     }
  }
}
