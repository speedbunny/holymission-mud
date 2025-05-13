#include "abbey.h"
inherit "room/room";

reset(arg) {
object mo,ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="The Franciscan Debate";
     long_desc=
"You walk out onto a rocky knoll, overlooking the desolate\n"+
"cold and frozen countryside.\n";
     dest_dir=({ PATH+"/o15","north" });
  }
  if (!(ob=present("monk")) || !living(ob)) {
     for(i=0;i<3;i++) {
	mo=clone_object("obj/monster");
	mo->set_name("monk");
	mo->set_level(9);
	mo->set_short("A Franciscan Monk");
	mo->set_long("A monk in a plain, homespun robe.\n");
	mo->load_chat(10,
	({ "The Fransiscan says: We must help the poor.\n",
	   "The Fransiscan says: Jesus did *not* own his clothes.\n",
	   "The Fransiscan says: St. Francis advocated poverty.\n" }) );
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
