inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "On the Chessboard";
long_desc = "You are standing on the eastern edge of the chessboard.  Thick " +
 "brush and trees prevent any progression to the east.  Looking down, you see " +
 "that there are some footprints coming from the east on the black square.\n";
 items = ({
 "brush","Thick bushes and scrub trees that are impossible to get through",
 "trees","Scrub trees that grow with the bushes",
});
 dest_dir = ({
 CB + "24.c","north",
 CB + "23.c","northwest",
 CB + "31.c","west",
 CB + "40.c","south",
 CB + "39.c","southwest",
});
}
