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
long_desc = "You are standing on the eastern edge of the chessboard.  Thick " +
 "brush and trees prevent any progression to the east.  Looking down, you see " +
 "that you are standing on a black square.\n";
 items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
});
 dest_dir = ({
 CB + "8.c","north",
 CB + "7.c","northwest",
 CB + "15.c","west",
 CB + "24.c","south",
 CB + "23.c","southwest",
});
}
