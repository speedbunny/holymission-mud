/* hut3 : A beach hut */

#include "path.h"
inherit "room/room";

  object brian;

reset(arg) {

     if(!arg) {

      set_light(1);
      short_desc = "A beach hut";
      long_desc =
"This is a small but nice beach hut. You can see various posters on the \n"+
"walls. You are standing in the hut of Brian Wilson, one of the famous \n"+
"Beach Boys! You feel very proud to meet him.\n";
      dest_dir = ({
       ROOM+"beach2", "west"
		 });
	       }
    if (!brian) {
       brian = clone_object(NPC+"brian");
       move_object(brian, this_object());
       }
}
