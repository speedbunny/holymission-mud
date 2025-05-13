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
 CB + "45.c","north",
 CB + "46.c","northeast",
 CB + "44.c","northwest",
 CB + "54.c","east",
 CB + "52.c","west",
 CB + "61.c","south",
 CB + "62.c","southeast",
 CB + "60.c","southwest",
});
}
