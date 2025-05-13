#include "path.h"
inherit "room/room";

object sign;

init() {
	::init();
/*
	add_action("south", "south");
*/
}

reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A small Path on a nice beach";
      long_desc = 
"You are walking on a small path on a very nice beach which leads north.\n"+
"There seems to be a kind of a village made out of beach huts to the north, \n"+
"from where you can hear music. There are also pathes to the west and to the \n"+
"east, from where you smell the sea. You suddenly realise the secret of this\n"+
"village: It's always Saturday Afternoon! What a wonderful place to live!\n"+
"To the south there seems to be a small quay.\n";
      dest_dir = ({
       ROOM + "quay", "south", 
       ROOM + "path5", "east",
       ROOM + "path6", "west",
       ROOM + "beach1", "north" 
                });

 }

     if (!sign) {
	sign = clone_object(OBJ + "city_sign");
	move_object(sign, this_object());
	}

}

