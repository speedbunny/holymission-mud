#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="The Horse Stall";
     long_desc=
"You see a comfortably, hay-lined stall, made of soft old wood. It has a\n" +
"chewed look from years of horses chewing the walls in boredom.\n";
     dest_dir=({ PATH+"/e0807","north",
		 PATH+"/e09s3","west",
		 PATH+"/e10s4","south" });
  }
  if (!(ob=present("horse")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("horse");
	ob->set_alias("brucellus");
	ob->set_level(10);
	ob->set_short("A horse named Brucellus");
	ob->set_long("The horse turns his head and looks tiredly at you.\n");
	move_object(ob,this_object());
  }
}
