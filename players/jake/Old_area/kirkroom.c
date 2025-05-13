inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "Kirkroom";
  long_desc = 
  	"This is the suite of Kirk, the killer RD.\n"
  	"He is the Resident Director of Jake's place, "
   	"and doesn't like messy rooms.\n"
  	"The room is furnished luxuriously, with a plush carpet on the floor.\n"
  	"A cute little cat is laying on the carpet.\n";
  dest_dir = ({ "players/jake/suite", "north" });
  clone_list = ({ 1, 1, "kirk", "players/jake/monster/kirk", 0,
	2, 1, "blitz", "players/jake/monster/blitz", 0, });

::reset();
replace_program("room/room");
}

