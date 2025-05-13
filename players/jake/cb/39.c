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
 CB + "31.c","north",
 CB + "32.c","northeast",
 CB + "30.c","northwest",
 CB + "40.c","east",
 CB + "38.c","west",
 CB + "47.c","south",
 CB + "48.c","southeast",
 CB + "46.c","southwest",
});
}
