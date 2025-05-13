#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;

  if (!arg) {
     set_light(1);
     short_desc="The Dispensary";
     long_desc=
"To your west is a small building.  You see two monks leaving the building\n"+
"carrying a dead body on a stretcher. They wear kerchiefs over their noses\n"+
"to dispell the odor. To the south you see a cemetery.\n";
     dest_dir=({ PATH+"/m03","east" });
  }
  if (!(ob=present("spirit")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("spirit");
	ob->set_level(12);
	ob->set_short("The spirit of the herbalist");
	ob->set_long("The spirit wails: release me!!\n");
	ob->load_a_chat(70,
	({ "The spirit wails: Get the relic first!\n" }) );
	move_object(ob,this_object());
  } 
}
