inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc="Entrance to underground caverns";
  long_desc="You are in the entrance to some underground caverns.\n"
	+ "You can see some dim light coming from the north.\n";
  dest_dir=({ "players/moonchild/gnome/pit", "north",
	"players/moonchild/gnome/maze6", "south" });
  items=({ "light", "It's very dim",
	"caverns", "They look very extensive" });
  property=({ "no_teleport" });
}

move(str) {
  if(query_verb()=="north") "players/moonchild/gnome/pit"->set_trap();
  return ::move(str);
}
