inherit "room/room";

reset(arg){
  set_light(0);
  short_desc = "Storage room";
  long_desc = "This looks like it was once a storage room.\n"
		"Big barrels line the far wall.\n";
  dest_dir = ({"players/airborne/temple/levelc/room18", "west" });
  items = ({"barrels", "Big large wine barrels. They look solid." });
  clone_list = ({ 1, 1, "syth", "players/airborne/monsters/syth", 0 });

::reset();
replace_program("room/room");
}
