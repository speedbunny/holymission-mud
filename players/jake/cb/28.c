inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "On the Chessboard";
 long_desc = "You are standing on the chessboard.  You cannot tell how close " +
 "you are to the edge of the board.  Looking down, you see that you are standing " +
 "on a black square.\n";
 dest_dir = ({
 CB + "20.c","north",
 CB + "21.c","northeast",
 CB + "19.c","northwest",
 CB + "29.c","east",
 CB + "27.c","west",
 CB + "36.c","south",
 CB + "37.c","southeast",
 CB + "35.c","southwest",
});
}
