inherit "/room/room";

#include "/players/matt/defs.h"

int dug, gotbox, moved;
object held_by;

reset(arg) {
  dug = 0;
  gotbox = 0;
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    You find yourself on a crude path through the forest, a\n" +
    "path that is obviously not natural but which has fallen into\n" +
    "a state of disrepair. It is overgrown with weeds and grass,\n" +
    "but is still clearly visible.\n" +
    "    A fallen tree lies across the path before you, huge and\n" +
    "half-rotted. It looks as though it has been here for some\n" +
    "time, cut down not by nature but by human hands.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b16", "east",
    NWFORESTB + "rooms/b11", "southwest",
  });
  
  items = ({
    "forest", "The lush green forest surrounds you",
    "path", "An overgrown, man-made path",
    "weeds", "Tall weeds growing in patches scattered about",
    "grass", "Lush green grass covering the ground",
    "tree", "A fallen oak lying before you; maybe you could move it",
  });
}

init() {
  ::init();
  add_action("move_tree", "move");
  add_action("dig", "dig");
  add_action("let", "let");
  add_action("myget", "get");
  add_action("mylook", "look");
  add_action("mydrop", "drop");
}

move_tree(arg) {
  if(arg == "tree" || arg == "fallen tree") {
    if(!moved && !held_by) {
      write("You heave and strain with all your might, and you manage\n");
      write("to roll the tree aside a bit, revealing a soft patch of\n");
      write("earth underneath. You can't hold the tree much longer.\n");
      say(TP->NAME + " heaves the tree aside a bit, revealing a soft ");
      say("patch\nof earth underneath.\n");
      held_by = TP;
      moved = 1;
      if(dug && !gotbox) do_box();
      call_out("let_go", 20);
      return 1;
    }
    write("The tree is already held up.\n");
    return 1;
  }
  write("Move what?\n");
  return 1;
}

dig(arg) {
  if(moved) {
    if(held_by != TP) {
      if(arg == "in earth" || arg == "in patch" ||
	 arg == "in patch of earth") {
	if(!dug) {
	  write("You dig in the earth and find a small box.\n");
	  say(TP->NAME + " digs in the patch of earth.\n");
	  do_box();
	  dug = 1;
	  return 1;
	}
	write("You dig for a while but find nothing unusual.\n");
	say(TP->NAME + " digs around in the earth.\n");
	return 1;
      }
      write("Dig where?\n");
      return 1;
    }
    write("You try to dig, but your grip on the tree slips.\n");
    let_go();
    return 1;
  }
}

let(arg) {
  if(arg == "go of tree" || arg == "go") {
    if(moved && (held_by == TP)) {
      let_go();
      return 1;
    }
    write("You are not holding it.\n");
    return 1;
  }
}

myget(arg) {
  object box;
  if(arg == "box" || arg == "small box") {
    box = present("small box", ENV(TP));
    if(box) {
      if(!gotbox) {
	if(held_by != TP) {
	  write("You pick up the small box.\n");
	  say(TP->NAME + " picks up the small box.\n");
	  transfer(box, TP);
	  gotbox = 1;
	  return 1;
	}
	let_go();
	return 1;
      }
    }
  }
}

mylook(arg) {
  if(moved) {
    if(arg == "at earth" || arg == "at patch" ||
       arg == "at patch of earth") {
      write("A small, soft patch of earth where the tree used to sit.\n");
      return 1;
    }
  }
}

mydrop(arg) {
  if(arg == "tree") {
    if(moved && held_by == TP) {
      let_go();
      return 1;
    }
    write("You are not carrying that.\n");
    return 1;
  }
}

let_go() {
  object box, spec;
  if(moved) {
    write("You let go of the tree, and it rolls back into place.\n");
    say(TP->NAME + " lets go of the tree and it rolls back into place.\n");
    if(!gotbox) {
      box = present("small box", ENV(TP));
      if(box) {
	spec = present("spectacles", box);
	if(spec) destruct(spec);
	box->set_opened();
	destruct(box);
      }
    }
  }
  moved = 0;
  held_by = 0;
  return 1;
}

do_box() {
  object box, spec;
  box = clone_object(NWFORESTB + "objects/box");
  spec = clone_object(NWFORESTB + "objects/spectacles");
  MOVE(box, ENV(TP));
  MOVE(spec, box);
  return 1;
}

exit(obj) {
  if(held_by == obj) let_go();
}
