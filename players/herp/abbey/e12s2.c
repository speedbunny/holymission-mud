#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Grainery";
     long_desc=
"You have entered a storage shed filled to the rafters with canvas\n" +
"bags bulging with grain.\n";
     dest_dir=({ PATH+"/e12s1","west",
		 PATH+"/e12s3","east" });
  }
  if (!(ob=present("rat")) || !living(ob)) {
     for(i=0;i<5;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("rat");
	ob->set_short("A rat");
	ob->load_chat( 10,
	({ "A rat runs over your foot.\n",
	   "You hear rats scurrying for cover.\n" }) );
	move_object(ob,this_object());
     }
  }
}	
