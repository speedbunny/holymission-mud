inherit "room/room";
#include "/players/jake/defs.h"
object a;
reset(arg) {
if (!a) {
a=clone_object("obj/monster");
a->set_name("Black bishop");
a->set_alt_name("bishop");
a->set_short("Black bishop");
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
long_desc = "You are standing on the northern end of the chessboard.  Thick " +
 "brush and trees block any progression to the north.  The rest of the chessboard " +
 "stands to the south.  Looking down, you find that you are standing on a white square.\n";
items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
});
dest_dir = ({
 CB + "5.c","west",
 CB + "7.c","east",
 CB + "13.c","southwest",
 CB + "14.c","south",
 CB + "15.c","southeast",
});
}
