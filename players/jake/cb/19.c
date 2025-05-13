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
 CB + "11.c","north",
 CB + "12.c","northeast",
 CB + "10.c","northwest",
 CB + "20.c","east",
 CB + "18.c","west",
 CB + "27.c","south",
 CB + "28.c","southeast",
 CB + "26.c","southwest",
});
}
