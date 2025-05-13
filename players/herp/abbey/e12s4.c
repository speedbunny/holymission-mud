#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="The Goat Pen";
     long_desc=
"There is a strong odor of uncut ram in this pen.  It makes you hold you\n" +
"your nose.\n";
     dest_dir=({ PATH+"/e11s4","north",
		 PATH+"/e12s3","west" });
  }
  if (!(ob=present("ram")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("ram");
	ob->set_short("A large ram");
	ob->set_long("The goat lowers his large set of horns at you.\n");
	ob->set_level(10);
	move_object(ob,this_object());
  }
}
