inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/levelb/room5", "west", });
  short_desc = "Empty room";
  long_desc =
"This room looks like it was once a study for the worshipers "
"of the Old Ones. The shelves along the walls do not seem to show "
"the centuries they have been standing. Unfortunately, the books they once "
"held cannot say the same.\n";
  items = ({"books", "The books that remain are turning to dust",
	"shelves", "The shelves are made of the same metal the temple is", });

  clone_list = ({ 1, 4, "ghouls", "players/airborne/monsters/ghoul", 0 });

::reset();
replace_program("room/room");
}
