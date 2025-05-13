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
 CB + "28.c","north",
 CB + "29.c","northeast",
 CB + "27.c","northwest",
 CB + "37.c","east",
 CB + "35.c","west",
 CB + "44.c","south",
 CB + "45.c","southeast",
 CB + "43.c","southwest",
});
}
