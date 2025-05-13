/*  This is the North_West Tower */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

     set_light(0);
     short_desc = "North-West Tower ";
     long_desc =
"You have just entered the tower in the north-west corner of the castle.\n"+ 
"The awful smell that you encountered earlier is definitely getting stronger\n"+
"much to your displeasure... This room is very sparsely decorated, with only\n"+ 
"an unobtrusive table resting against the far wall.\n"+
"There is a staircase leading both up and down to different levels in the tower\n";     

     dest_dir = ({
   CROOMS + "nw_tower2", "up",
   CROOMS + "nw_tower1", "down",
   CROOMS + "wcorridor2", "south",
     });
    
      items = ({
  "table",
"A simple wooden table",
  "wall",
"The wall is standing there, minding its own business",
  "stairs",
"One set leading up...and the other leading down",
      });

    ::reset (arg);

    RPR("room/room");
}
