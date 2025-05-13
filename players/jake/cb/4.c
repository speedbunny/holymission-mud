inherit "room/room";
#include "/players/jake/defs.h"
object a;
reset(arg) {
if (!a) {
a=clone_object("obj/monster");
a->set_name("Black king");
a->set_alt_name("king");
a->set_short("Black king");
a->set_long("The ruler of the black pieces of the chessboard.\n");
a->set_level(15);
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
 "stands to the south.  A large throne stands upon this white square.\n";
items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
 "throne","The kings throne",
});
dest_dir = ({
 CB + "3.c","west",
 CB + "5.c","east",
 CB + "11.c","southwest",
 CB + "12.c","south",
 CB + "13.c","southeast",
});
}
