inherit "room/room";

void reset(int arg) {
  if(arg)
    return;
  set_light(1);
  short_desc="Forest";
  long_desc="You are standing in the dark forest. The trees are somewhat less dense here\n"
	+ "than in other places. A rope hangs down from on top of a tall rowan tree here.\n";
  dest_dir=({ "room/south/sshore16", "north",
	"room/south/sshore15", "east",
	"room/south/sforst42", "south",
	"room/south/sforst39", "west" });
  items=({ "trees", "There are still a lot of them around here",
	"tree", "Any particular tree?",
	"rowan tree", "You could probably climb up the tree using this rope",
	"rope", "You could probably climb up the tree using this rope" });
}

void init() {
  ::init();
  add_action("climb", "climb");
}

int climb(string str) {
  if(str!="rowan tree" && str!="tree" && str!="rope") {
    notify_fail("Climb what?\n");
    return 0;
  }
  this_player()->move_player("up the rope#players/patience/tree_city/orowan");
  return 1;
}
