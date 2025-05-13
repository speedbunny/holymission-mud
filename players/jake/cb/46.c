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
 CB + "38.c","north",
 CB + "39.c","northeast",
 CB + "37.c","northwest",
 CB + "47.c","east",
 CB + "45.c","west",
 CB + "54.c","south",
 CB + "55.c","southeast",
 CB + "53.c","southwest",
});
}
