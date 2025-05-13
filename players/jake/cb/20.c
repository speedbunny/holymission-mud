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
 CB + "12.c","north",
 CB + "13.c","northeast",
 CB + "11.c","northwest",
 CB + "21.c","east",
 CB + "19.c","west",
 CB + "28.c","south",
 CB + "29.c","southeast",
 CB + "27.c","southwest",
});
}
