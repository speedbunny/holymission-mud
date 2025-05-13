#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,ca;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Rabbit Hutch";
     long_desc=
"You are standing in a large open area where rabbits are kept.  The\n" +
"soft bunnies have made a bit of a mess, I'm afraid.\n";
     dest_dir=({ PATH+"/e0806","north",
		 PATH+"/e09s2","west",
		 PATH+"/e10s3","south",
		 PATH+"/e09s4","east" });
  }
  if (!(ob=present("rabbit")) || !living(ob)) {
     for(i=0;i<5;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("rabbit");
	ob->set_short("A rabbit");
	ob->set_long("A soft-furred, lop earred, white rabbit.\n");
	ob->load_chat(10,
	({ "A rabbit wiggles his nose at you.\n",
	   "Hop, hop!\n" }) );
	ca=clone_object("obj/food");
	ca->set_name("carrot");
	ca->set_short("A carrot");
	ca->set_long("Looks tasty.\n");
	ca->set_eater_mess("Tastes good.\n");
	ca->set_strength(5);
	move_object(ca,ob);
	move_object(ob,this_object());
     }
  }
}
