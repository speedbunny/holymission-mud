/* hut6 : A beach hut */

#include "path.h"
inherit "room/room";

  object note;

reset(arg) {

     if(!arg) {

      set_light(1);
      short_desc = "A beach hut";
      long_desc =
"This is a small but nice beach hut. You can see various posters on the \n"+
"walls. You are standing in the hut of Dennis Wilson, one of the famous \n"+
"Beach Boys! Unfortunately Dennis is not at home.\n";
      dest_dir = ({
       ROOM+"path3", "north"
		 });
	       }
    if (!note) {
       note = clone_object(OBJ+"note1");
       move_object(note, this_object());
       }
}
