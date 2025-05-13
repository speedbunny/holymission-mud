inherit "room/room";

reset (arg){
  set_light(0);
  dest_dir = ({"players/airborne/temple/levela/room1", "south",
	"players/airborne/temple/levela/stairs3", "east", });
  short_desc = "A dirty room";
  long_desc = "This room is filthy! Dust and dirt are everywhere.\n";
  items = ({"dust", "So much dust it makes you want to sneeze",
	"dirt", "So much dirt your mother would have a fit", });

  clone_list = ({ 1, 4, "ghoul", "players/airborne/monsters/ghoul", 0 });

::reset();
replace_program("room/room");
}
