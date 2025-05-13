/* Edited by Colossus: 070994 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) 
	return;
    set_light(0);
    short_desc="Inside a big cave";
    long_desc=
    "You are in another part of the huge cave complex. Several large\n\
rocks are strewn about due to prior seismic activity that have\n\
caused near cave-ins. The cave extends as far as your eyes can see.\n";
    items=({
      "cave", "A huge cave complex",
      "rocks", "The large rocks are scattered all about the cave",
    });
    dest_dir=({
      "/players/sherman/hills/cave6","east",
      "/players/sherman/hills/cave1","west"
    });
}
