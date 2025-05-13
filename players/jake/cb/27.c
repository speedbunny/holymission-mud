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
 CB + "19.c","north",
 CB + "20.c","northeast",
 CB + "18.c","northwest",
 CB + "28.c","east",
 CB + "26.c","west",
 CB + "35.c","south",
 CB + "36.c","southeast",
 CB + "34.c","southwest",
});
}
