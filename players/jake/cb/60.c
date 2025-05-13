inherit "room/room";
#include "/players/jake/defs.h"
object a;
reset(arg) {
if (!a) {
a=clone_object("obj/monster");
a->set_name("White king");
a->set_alt_name("king");
a->set_short("White king");
a->set_long("The ruler of the white pieces of the chessboard.\n");
a->set_level(15);
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
 "stands to the north.  A large throne stands upon this black square.\n";
items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
 "throne","The kings throne",
});
dest_dir = ({
 CB + "59.c","west",
 CB + "61.c","east",
 CB + "51.c","northwest",
 CB + "52.c","north",
 CB + "53.c","northeast",
});
}
