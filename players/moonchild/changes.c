inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Change board room";
  long_desc="This is the room where archwizards should note changes made to other people's\n"
	+ "code that they have made if they think that other wizards should know about it.\n\nBoard removed...\n";
  dest_dir=({ "players/whisky/genobj/coding_room", "north" });
}
