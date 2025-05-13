inherit "room/room";
#include "/players/jake/defs.h"
object a;
reset(arg) {
 if(!a) {
 a=clone_object("obj/monster");
 a->set_name("Black pawn");
 a->set_short("Black pawn");
 a->set_alt_name("pawn");
 a->set_long("A brave pawn of the chessboard.\n");
 a->set_level(9);
 a->set_align(100);
 a->set_aggressive(0);
 a->set_walk_chance(100);
 move_object(a,this_object());
}
if(arg) return;
set_light(1);
short_desc = "On the Chessboard";
long_desc = "You are standing on the western edge of the chessboard.  Thick " +
 "brush and trees prevent any progression to the west.  Looking down, you see " +
 "that you are standing on a white square.\n";
 items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
});
 dest_dir = ({
 CB + "1.c","north",
 CB + "2.c","northeast",
 CB + "10.c","east",
 CB + "17.c","south",
 CB + "18.c","southeast",
});
}
