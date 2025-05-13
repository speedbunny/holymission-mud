#include "/players/matt/defs.h"

int stage, numfruit, iter;
object fruit;
mixed desc_array;

id(arg) { return arg == "lifetree" || arg == desc_array[stage][0]; }
short() { return desc_array[stage][1]; }
long() { write(desc_array[stage][2] + ".\n"); }

reset(arg) {
  if(stage >= 3) {
    if(iter >= 3) {
      ENV(TO)->reset_tree();
      destruct(TO);
    }
    else iter++;
    if(numfruit < 3) numfruit++;
  }
  if(arg) return;
  desc_array = ({
    ({ "sprout", "A tiny sprout poking out of the ground",
	 "A tiny golden sprout, the beginning of a new plant" }),
    ({ "sapling", "A small growing sapling",
	 "A small golden sapling, struggling to grow" }),
    ({ "tree", "A young tree",
	 "A young tree, budding with life but not yet full-grown" }),
    ({ "tree", "A large tree",
	 "A large, full-grown tree budding with fruit" })
  });
}

init() {
  add_action("mylook", "look");
  add_action("pick", "pick");
}

grow() {
  if(stage < 3) {
    TELLR(ENV(TO), "You notice growth from within the circle of light.\n");
    stage += 1;
    if(stage == 3) {
      numfruit = 3;
      return 1;
    }
    call_out("grow", 30);
    return 1;
  }
  return 1;
}

start_grow() {
  call_out("grow", 30);
  return 1;
}

pick(arg) {
  if(stage == 3) {
    if(arg == "fruit" || arg == "fruit from tree") {
      if(numfruit > 0) {
       fruit = clone_object(NWFORESTB + "objects/lifefruit");
	transfer(fruit, TP);
	write("You pick a piece of fruit from the tree.\n");
	say(TP->NAME + " picks a piece of fruit from the tree.\n");
	numfruit -= 1;
	return 1;
      }
      write("There is no ripe fruit left.\n");
      return 1;
    }
    write("Pick what?\n");
    return 1;
  }
}

mylook(arg) {
  if(stage == 3) {
    if(arg == "at fruit" && !present("fruit", TP) &&
       !present("fruit", ENV(TP))) {
      if(numfruit) write("Ripe, luscious-looking fruit.\n");
      else write("There is no ripe fruit left on the tree.\n");
      return 1;
    }
  }
}
