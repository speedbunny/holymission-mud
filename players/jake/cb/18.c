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
 CB + "10.c","north",
 CB + "11.c","northeast",
 CB + "9.c","northwest",
 CB + "19.c","east",
 CB + "17.c","west",
 CB + "26.c","south",
 CB + "27.c","southeast",
 CB + "25.c","southwest",
});
}
