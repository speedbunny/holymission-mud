inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Muddy road";
  long_desc="You are walking along a muddy road which curves east into the\n"
	+ "main part of the city and northwest into the gloomy darkness.\n";
  dest_dir=({ "players/moonchild/gnome/gcent", "east",
	"players/moonchild/gnome/wroad2", "northwest" });
  property=({ "no_teleport" });
}
