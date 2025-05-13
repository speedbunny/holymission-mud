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
 CB + "37.c","north",
 CB + "38.c","northeast",
 CB + "36.c","northwest",
 CB + "46.c","east",
 CB + "44.c","west",
 CB + "53.c","south",
 CB + "54.c","southeast",
 CB + "52.c","southwest",
});
}
