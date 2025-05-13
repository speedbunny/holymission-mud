inherit "players/moonchild/haunter/digroom";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A small moorland path";
  long_desc="This is a small moorland path, leading up to the top of a hillock with a\n"
	+ "tree on it, and also leading onto the main part of the moor.\n";
  dest_dir=({ "players/moonchild/haunter/moor31", "southeast",
	"players/moonchild/trollslayer/hillock", "west" });
  items=({ "path", "A small winding moorland path",
	"hillock", "A small hillock at the end of the path",
	"tree", "There is a single tree at the top of the hillock" });
}
