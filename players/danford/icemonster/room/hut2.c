/* hut2 : A beach hut */

#include "path.h"
inherit "room/room";

  object mike;

reset(arg) {

     if(!arg) {

      set_light(1);
      short_desc = "A beach hut";
      long_desc =
"This is a small but nice beach hut. You can see various posters on the \n"+
"walls. You are standing in the hut of Mike Love, one of the famous \n"+
"Beach Boys! You feel very proud to meet him.\n";
      dest_dir = ({
       ROOM+"beach1", "west"
		 });
	       }
    if (!mike) {
       mike = clone_object(NPC+"mike");
       move_object(mike, this_object());
       }
}
