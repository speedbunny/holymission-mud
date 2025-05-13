inherit "room/room";

reset(arg) {
  set_light(1);
  if(arg) return;
  short_desc="Narrow alley";
  long_desc="The narrow alley comes to an end here. There is a pub to the east.\n";
  dest_dir=({ "players/moonchild/gnome/alley1", "north",
	"players/moonchild/gnome/pub", "east",
	"players/moonchild/gnome/bank", "west" });
  items=({ "pub", "It looks friendly enough" });
  property=({ "no_teleport" });
}
