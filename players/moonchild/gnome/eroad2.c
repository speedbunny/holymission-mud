inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Muddy road";
  long_desc="You are walking along a muddy road. To the north there is some\n"
	+ "kind of building while to the southeast is an underwater river.\n";
  dest_dir=({ "players/moonchild/gnome/building", "north",
	"players/moonchild/gnome/river", "southeast",
	"players/moonchild/gnome/eroad1", "west" });
  items=({ "building", "It looks like it is used for storing things in",
	"river", "It seems clean enough" });
  property=({ "no_teleport" });
}
