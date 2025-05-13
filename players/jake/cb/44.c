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
 CB + "36.c","north",
 CB + "37.c","northeast",
 CB + "35.c","northwest",
 CB + "45.c","east",
 CB + "43.c","west",
 CB + "52.c","south",
 CB + "53.c","southeast",
 CB + "51.c","southwest",
});
}
