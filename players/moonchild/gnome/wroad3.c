inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Muddy road";
  long_desc="You are walking along a muddy road which leads south from here.\n"
	+ "There is a building to the north and a dark path to the east.\n"
	+ "High up you can see a rock ledge far out of climbing distance.\n";
  dest_dir=({ "players/moonchild/gnome/inn", "north",
	"players/moonchild/gnome/dpath", "east",
	"players/moonchild/gnome/wroad2", "south" });
  items=({ "building", "It looks like an inn of some description",
	"path", "It's very gloomy down there, you would need a torch",
	"ledge", "It's very far up there" });
  property=({ "no_teleport" });
}
