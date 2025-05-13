inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Muddy road";
  long_desc="You are walking along a muddy road that leads east-west.\n";
  dest_dir=({ "players/moonchild/gnome/eroad2", "east",
	"players/moonchild/gnome/gcent", "west" });
  property=({ "no_teleport" });
}
