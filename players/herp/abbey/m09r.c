#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Master's Room";
     long_desc=
"You have entered the quiet, austere room of a scholar.\n";
     dest_dir=({ PATH+"/m09","west" });
  }
  if (!(ob=present("master")) || !living(ob))
	ob=clone_object(PATH+"/m09m");
	move_object(ob,this_object());
}
