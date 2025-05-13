inherit "room/room";

reset(arg) {
  call_other("players/moonchild/gnome/serpent","????");
  if(arg) return;
  short_desc="Cave";
  long_desc="This is a dark, dank, watery cave.\n"
	+ "There is a bad smell of rotting corpses.\n";
  dest_dir=({ "players/moonchild/gnome/inriver", "east" });
  property=({ "no_teleport" });
}
