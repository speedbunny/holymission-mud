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
 CB + "34.c","north",
 CB + "35.c","northeast",
 CB + "33.c","northwest",
 CB + "43.c","east",
 CB + "41.c","west",
 CB + "50.c","south",
 CB + "51.c","southeast",
 CB + "49.c","southwest",
});
}
