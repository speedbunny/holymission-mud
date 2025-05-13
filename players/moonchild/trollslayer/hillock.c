inherit "players/moonchild/haunter/digroom";

int rope;

reset(arg) {
  object r;
  if(arg) return;
  set_light(1);
  short_desc="The top of a cliff";
  long_desc="You are standing at a hillock which marks the top of a cliff. You can see\n"
	+ "a tremendous view over the land to the west, below the cliff, but there looks\n"
	+ "to be no way down. A single tall tree stands here, overlooking the clifftop.\n";
  dest_dir=({ "players/moonchild/trollslayer/hillpath", "east", });
  items=({ "hillock", "A small hillock with a superb view down beyond a cliff",
	"cliff", "@@cliff_desc@@",
	"cliff-face", "@@cliff_desc@@",
	"view", "A superb view of a mountain range to the north, a large moor to\n"
	+ "the east, and the marshland at the bottom of the cliff-face",
	"tree", "@@tree_desc@@", });
  r=clone_object("obj/rope");
  move_object(r,this_object());
  r->auto_tie("tree",this_object());
  rope=1;
}

init() { ::init(); add_action("down", "down"); add_action("climb", "climb"); }

down() {
  if(!rope) {
    write("You couldn't scale the cliff.\n");
    return 1;
  }
  this_player()->move_player("south#players/moonchild/trollslayer/rope");
  return 1;
}

climb(str) {
  if(str=="down" || str=="rope" || str=="cliff" || str=="cliff-face")
	return down();
  if(str=="tree") {
    this_player()->move_player("up#players/moonchild/puzzle/treetop");
    return 1;
  }
  write("Climb what?\n");
  return 1;
}

tie(str) {
  if(str!="tree") return;
  rope=1;
  return 1;
}

untie(str) { rope=0; return 1; }

query_rope() { return rope; }

cliff_desc() {
  if(!rope) return "This is a huge cliff-face that seems to drop for hundreds of feet. There seems\n"
	+ "to be a cave entrance some way down the cliff-face, with a ledge beside it";
  return "This is a huge cliff-face that seems to drop for hundreds of feet. There seems\n"
	+ "to be a cave entrance some way down the cliff-face, with a ledge beside it.\n"
	+ "There is a rope tied to the tree which hangs down the cliff face";
}

tree_desc() {
  if(!rope) return "A tall pine tree. Maybe you could climb up it";
  return "A tall pine tree. Maybe you could climb up it. There is a rope tied to it";
}
