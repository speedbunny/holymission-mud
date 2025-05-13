#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Bath Stall";
     long_desc=
"You enter a steamy room, recently used.  You see a great wooden tub, still\n"+
"filled with cold, soap-scum coverd water.  A rat scurries around behind it\n"+
"as you enter.\n";
     items=({ "tub","A wooden tub, fully of scummy water" });
     dest_dir=({ PATH+"/c07","south" });
  }
  if (!(ob=present("rat")) || !living(ob))
     for(i=0;i<4;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("rat");
	ob->set_short("A rat");
	ob->set_level(3);
	move_object(ob,this_object());
     }
}
