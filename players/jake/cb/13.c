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
 long_desc = "You are standing on the chessboard.  You cannot tell how close " +
 "you are to the edge of the board.  Looking down, you see that you are standing " +
 "on a white square.\n";
 dest_dir = ({
 CB + "5.c","north",
 CB + "6.c","northeast",
 CB + "4.c","northwest",
 CB + "14.c","east",
 CB + "12.c","west",
 CB + "21.c","south",
 CB + "22.c","southeast",
 CB + "20.c","southwest",
});
}
