inherit "room/room";
#include "/players/jake/defs.h"
object a;
reset(arg) {
if (!a) {
a=clone_object("obj/monster");
a->set_name("Black queen");
a->set_alt_name("queen");
a->set_short("Black queen");
a->set_long("The bride of the black king.\n");
a->set_level(20);
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
 "stands to the south.  A smaller throne stands upon this black square.\n";
items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
 "throne","The queens throne",
});
dest_dir = ({
 CB + "4.c","west",
 CB + "6.c","east",
 CB + "12.c","southwest",
 CB + "13.c","south",
 CB + "14.c","southeast",
});
}
