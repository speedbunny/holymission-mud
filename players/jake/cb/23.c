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
 CB + "15.c","north",
 CB + "16.c","northeast",
 CB + "14.c","northwest",
 CB + "24.c","east",
 CB + "22.c","west",
 CB + "31.c","south",
 CB + "32.c","southeast",
 CB + "30.c","southwest",
});
}
