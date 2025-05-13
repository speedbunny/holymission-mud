/* hut5 : A beach hut */

#include "path.h"
inherit "room/room";

  object bruce;

reset(arg) {

     if(!arg) {

      set_light(1);
      short_desc = "A beach hut";
      long_desc =
"This is a small but nice beach hut. You can see various posters on the \n"+
"walls. You are standing in the hut of Bruce Johnston, one of the famous \n"+
"Beach Boys! You feel very proud to meet him.\n";
      dest_dir = ({
       ROOM+"path1", "south"
		 });
	       }
    if (!bruce) {
       bruce = clone_object(NPC+"bruce");
       move_object(bruce, this_object());
       }
}
