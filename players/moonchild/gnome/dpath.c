inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc="A dark path";
  long_desc="You are on a path. It is very dark here. You hear some sounds\n"
	+ "to the northeast, and a shadow looms above you to the east.\n";
  dest_dir=({ "players/moonchild/gnome/pit", "northeast",
	"players/moonchild/gnome/bystat", "east",
	"players/moonchild/gnome/wroad3", "west" });
  items=({ "shadow", "It's very big, but not well defined" });
  property=({ "no_teleport" });
}

move(str) {
  if(query_verb()=="northeast") "players/moonchild/gnome/pit"->set_trap();
  return ::move(str);
}
