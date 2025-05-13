inherit "room/room";
#include "/players/jake/defs.h"
object a;
reset(arg) {
if (!a) {
a=clone_object("obj/monster");
a->set_name("White bishop");
a->set_alt_name("bishop");
a->set_short("White bishop");
a->set_long("A brave bishop of the chessboard.\n");
a->set_level(12);
a->set_walk_chance(25);
a->set_align(100);
a->set_aggressive(0);
move_object(a,this_object());
}
if(arg) return;
set_light(1);
short_desc = "On the Chessboard";
long_desc = "You are standing on the southern end of the chessboard.  Thick " +
 "brush and trees block any progression to the south.  The rest of the chessboard " +
 "stands to the north.  Looking down, you find that you are standing on a white square.\n";
items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
});
dest_dir = ({
 CB + "58.c","west",
 CB + "60.c","east",
 CB + "50.c","northwest",
 CB + "51.c","north",
 CB + "52.c","northeast",
});
}
