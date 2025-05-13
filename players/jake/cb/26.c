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
 CB + "18.c","north",
 CB + "19.c","northeast",
 CB + "17.c","northwest",
 CB + "27.c","east",
 CB + "25.c","west",
 CB + "34.c","south",
 CB + "35.c","southeast",
 CB + "33.c","southwest",
});
}
