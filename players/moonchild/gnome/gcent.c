inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Gnome city";
  long_desc="You are in the underground city of the gnomes. The main street streches\n"
	+ "east-west. To the north there appears to be a temple of some kind. To the\n"
	+ "south you can see a narrow alley.\n";
  dest_dir=({ "players/moonchild/gnome/temple", "north",
	"players/moonchild/gnome/eroad1", "east",
	"players/moonchild/gnome/alley1", "south",
	"players/moonchild/gnome/wroad1", "west" });
  items=({ "street", "It's rather dirty and muddy really",
	"temple", "It's pretty fine architecture for gnomes, actually",
	"alley", "It's an alley and it's narrow, not surprisingly" });
  property=({ "no_teleport" });
}
