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
 CB + "29.c","north",
 CB + "30.c","northeast",
 CB + "28.c","northwest",
 CB + "38.c","east",
 CB + "36.c","west",
 CB + "45.c","south",
 CB + "46.c","southeast",
 CB + "44.c","southwest",
});
}
