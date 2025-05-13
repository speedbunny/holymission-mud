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
 CB + "22.c","north",
 CB + "23.c","northeast",
 CB + "21.c","northwest",
 CB + "31.c","east",
 CB + "29.c","west",
 CB + "38.c","south",
 CB + "39.c","southeast",
 CB + "37.c","southwest",
});
}
