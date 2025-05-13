inherit "room/room";
#include "/players/jake/defs.h"
object a;
reset(arg) {
if (!a) {
a=clone_object("obj/monster");
a->set_name("White queen");
a->set_alt_name("queen");
a->set_short("White queen");
a->set_long("The bride of the white king.\n");
a->set_level(20);
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
 "stands to the north.  A smaller throne stands upon this white square.\n";
items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
 "throne","The queens throne",
});
dest_dir = ({
 CB + "60.c","west",
 CB + "62.c","east",
 CB + "50.c","northwest",
 CB + "51.c","north",
 CB + "52.c","northeast",
});
}
