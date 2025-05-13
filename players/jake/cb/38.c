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
 CB + "30.c","north",
 CB + "31.c","northeast",
 CB + "29.c","northwest",
 CB + "39.c","east",
 CB + "37.c","west",
 CB + "46.c","south",
 CB + "47.c","southeast",
 CB + "45.c","southwest",
});
}
