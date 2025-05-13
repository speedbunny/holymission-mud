inherit "room/room";

reset(arg) {
  call_other("players/moonchild/gnome/beggar", "???");
  if(arg) return;
  set_light(1);
  short_desc="Narrow alley";
  long_desc="This is a narrow alley wending its way through the gnome village.\n"
	+ "To the west you notice a building which appears as if it is a shop.\n"
	+ "To the east is some waste ground.\n";
  dest_dir=({ "players/moonchild/gnome/gcent", "north",
	"players/moonchild/gnome/waste", "east",
	"players/moonchild/gnome/alley2", "south",
	"players/moonchild/gnome/shop", "west" });
  items=({ "shop", "Yes, it's a shop",
	"building", "Yes, it's a shop",
	"waste", "It's strewn with litter and rubbish",
	"waste ground", "It's strewn with litter and rubbish" });
  property=({ "no_teleport" });
}
