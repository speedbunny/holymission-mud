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
 CB + "21.c","north",
 CB + "22.c","northeast",
 CB + "20.c","northwest",
 CB + "30.c","east",
 CB + "28.c","west",
 CB + "37.c","south",
 CB + "38.c","southeast",
 CB + "36.c","southwest",
});
}
