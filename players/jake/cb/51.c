inherit "room/room";
#include "/players/jake/defs.h"
object a;
reset(arg) {
 if(!a) {
 a=clone_object("obj/monster");
 a->set_name("White pawn");
 a->set_short("White pawn");
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
 long_desc = "You are standing on the chessboard.  You cannot tell how close " +
 "you are to the edge of the board.  Looking down, you see that you are standing " +
 "on a black square.\n";
 dest_dir = ({
 CB + "43.c","north",
 CB + "44.c","northeast",
 CB + "42.c","northwest",
 CB + "52.c","east",
 CB + "50.c","west",
 CB + "59.c","south",
 CB + "60.c","southeast",
 CB + "58.c","southwest",
});
}
