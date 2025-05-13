inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "2halla";
  long_desc = 
	"You are still travelling down the second floor hallway.\n"
        + "There is smoke coming from the west.\n"
	+ "You see a few cockroaches on the floor.\n";
   dest_dir = ({ "players/jake/2hall","south",
        "players/jake/2hallc","north",
	"players/jake/room3","east",
	"players/jake/room4","west" });
   clone_list = ({ 1, 3, "roach", "players/jake/monster/roach", 0 });

::reset();
replace_program("room/room");
}
