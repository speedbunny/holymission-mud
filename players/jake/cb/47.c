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
 CB + "39.c","north",
 CB + "40.c","northeast",
 CB + "38.c","northwest",
 CB + "48.c","east",
 CB + "46.c","west",
 CB + "55.c","south",
 CB + "56.c","southeast",
 CB + "54.c","southwest",
});
}
