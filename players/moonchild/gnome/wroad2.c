inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc="Muddy road";
  long_desc="You are walking along a muddy road which curves southeast into\n"
	+ "the main part of the city and north into the gloomy darkness.\n";
  dest_dir=({ "players/moonchild/gnome/wroad1", "southeast",
	"players/moonchild/gnome/wroad3", "north" });
  property=({ "no_teleport" });
}
