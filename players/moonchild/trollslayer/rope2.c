inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="On a rope";
  long_desc="You are shinning down a long rope that hangs down a cliff-face\n"
	+ "You don't want to spend too much time here in case you fall!\n";
  dest_dir=({ "players/moonchild/trollslayer/ledge", "up",
	"players/moonchild/trollslayer/ground", "down", });
  items=({ "rope", "A long rope tied to a tree above you and hanging down below you",
	"cliff", "A huge tall cliff just a few metres away from you",
	"cliff-face", "A huge tall cliff just a few metres away from you", });
}
