inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "On the Chessboard";
long_desc = "You are standing on the western edge of the chessboard.  Thick " +
 "brush and trees prevent any progression to the west.  Looking down, you see " +
 "that you are standing on a white square.\n";
 items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
});
 dest_dir = ({
 CB + "17.c","north",
 CB + "18.c","northeast",
 CB + "26.c","east",
 CB + "33.c","south",
 CB + "34.c","southeast",
});
}
