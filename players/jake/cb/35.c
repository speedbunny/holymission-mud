inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "On the Chessboard";
 long_desc = "You are standing on the chessboard.  You cannot tell how close " +
 "you are to the edge of the board.  Looking down, you see that you are standing " +
 "on a black square.\n";
 dest_dir = ({
 CB + "27.c","north",
 CB + "28.c","northeast",
 CB + "26.c","northwest",
 CB + "36.c","east",
 CB + "34.c","west",
 CB + "43.c","south",
 CB + "44.c","southeast",
 CB + "42.c","southwest",
});
}
