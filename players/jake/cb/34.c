inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "On the Chessboard";
 long_desc = "You are standing on the chessboard.  You cannot tell how close " +
 "you are to the edge of the board.  Looking down, you see that you are standing " +
 "on a white square.\n";
 dest_dir = ({
 CB + "26.c","north",
 CB + "27.c","northeast",
 CB + "25.c","northwest",
 CB + "35.c","east",
 CB + "33.c","west",
 CB + "42.c","south",
 CB + "43.c","southeast",
 CB + "41.c","southwest",
});
}
