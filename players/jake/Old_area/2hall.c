/* 12.16.93 Airborne: Fixed. */

inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "2hall";
  long_desc = 
  	"You are in the hall directly north of the lounge.\n"
        + "There are rooms east and west of you.\n"
	+ "There is loud music coming from the east.\n";
  dest_dir = ({"players/jake/lounge2", "south",
        "players/jake/room2","west",
        "players/jake/2halla","north",
	"players/jake/room1","east" });

replace_program("room/room");
}


