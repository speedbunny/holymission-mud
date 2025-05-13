inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A path";
  long_desc="You are walking along a small path leading towards a range of mountains.\n";
  dest_dir=({ "players/moonchild/trollslayer/pathb", "southwest",
	"players/moonchild/trollslayer/path3", "northwest", });
  items=({ "path", "A small, winding country path",
	"mountains", "A tall range of mountains to the distant north", });
}
