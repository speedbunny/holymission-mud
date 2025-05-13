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
 CB + "14.c","north",
 CB + "15.c","northeast",
 CB + "13.c","northwest",
 CB + "23.c","east",
 CB + "21.c","west",
 CB + "30.c","south",
 CB + "31.c","southeast",
 CB + "29.c","southwest",
});
}
