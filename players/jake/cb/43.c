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
 CB + "35.c","north",
 CB + "36.c","northeast",
 CB + "34.c","northwest",
 CB + "44.c","east",
 CB + "42.c","west",
 CB + "51.c","south",
 CB + "52.c","southeast",
 CB + "50.c","southwest",
});
}
