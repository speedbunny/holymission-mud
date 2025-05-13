#include "abbey.h"
inherit "room/room";

reset(arg) {
object mo,ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="The Benedictine Debate";
     long_desc=
"You walk out onto a southern rocky knoll. Around you\n"+
"spreads the desolate countryside.\n";
     dest_dir=({ PATH+"/o21","north" });
  }
  if (!(ob=present("monk")) || !living(ob)) {
     for(i=0;i<3;i++) {
	mo=clone_object("obj/monster");
	mo->set_name("monk");
	mo->set_level(9);
	mo->set_short("A Benedictine Monk");
	mo->set_long("A richly robed priest in a peculiar hat.\n");
	mo->load_chat(10,
	({ "The monk says: We must have money to fight infidels.\n",
	   "The Benedictine says: Jesus owned the clothes he wore.\n",
	   "The Benedictine says: The church must have money.\n" }) );
	mo->load_a_chat(10,
	({ "The monk says: Stop! I bid you peace....\n" }) );
	ob=clone_object("obj/weapon");
	switch(random(2)) {
	case 0:
	  ob->set_name("sword");
	  ob->set_class(9);
	  break;
	case 1:
	  ob->set_name("axe");
	  ob->set_class(7);
	  break;
	}
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wield weapon",mo);
     }
  } 
}
