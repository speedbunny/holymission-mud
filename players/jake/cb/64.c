inherit "room/room";
#include "/players/jake/defs.h"
object a;
reset(arg) {
if (!a){
 a=clone_object("obj/monster");
 a->set_name("White rook");
 a->set_alt_name("rook");
 a->set_short("White rook");
 a->set_long("A brave rook of the chessboard.\n");
 a->set_level(10);
 a->set_walk_chance(25);
 a->set_align(100);
 a->set_aggressive(0);
 move_object(a,this_object());
}
if (arg) return;
set_light(1);
short_desc = "On the Chessboard";
long_desc = "You have reached the southeastern corner of the chessboard.  Thick" +
 " brush and trees block any progression to the south or east.  The rest of the " +
 "chessboard stands to the east, north, and northwest of you.  Looking down, " +
 "you find that you are standing on a black square.\n";
items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
});
dest_dir = ({
 CB + "63.c","west",
 CB + "56.c","north",
 CB + "55.c","northwest",
});
}
