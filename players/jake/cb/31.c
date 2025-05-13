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
 CB + "23.c","north",
 CB + "24.c","northeast",
 CB + "22.c","northwest",
 CB + "32.c","east",
 CB + "30.c","west",
 CB + "39.c","south",
 CB + "40.c","southeast",
 CB + "38.c","southwest",
});
}
