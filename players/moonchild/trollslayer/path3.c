inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A junction";
  long_desc="You are standing at a junction between one path, leading north and southeast,\n"
	+ "and another which leads southwestwards. There is a large signpost here.\n";
  dest_dir=({ "players/moonchild/haunter/path4", "north",
	"players/moonchild/trollslayer/patha", "southeast",
	"players/moonchild/trollslayer/path2", "southwest", });
  items=({ "path", "A small, winding country path",
	"signpost", "A tall white signpost, pointing northwards. Perhaps you should read it" });
}

init() { ::init(); add_action("read", "read"); }

read(str) {
  if(str!="signpost")  return;
  write("The signpost reads: This way to the Mountains of Madness.\n");
  return 1;
}
