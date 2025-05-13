inherit "room/room";

#include "/players/jake/defs.h"

reset(arg) {
if(arg) return;
 set_light(1);
 short_desc = "In the cemetary";
 long_desc  = "You are standing in the center of a small cemetary.  Small grave\n" +
              "markers of various shapes and sizes stand all around you.  The\n" +
              "cemetary continues to the north and south, and a large tombstone stands\n" +
               "alone to the east.\n";
 items = ({
 "tombstone","Why don't you go check it out?",
 "markers","Stone and wood pieces to indicate where goblins are buried",
});
 DD = ({
 GOB + "clear","west",
 GOB + "clearb","east",
 GOB + "cl2","north",
 GOB + "cl3","south",
});
replace_program("room/room");
}
