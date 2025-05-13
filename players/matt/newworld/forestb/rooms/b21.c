inherit "/room/room";

#include "/players/matt/defs.h"

int planted;
string planter;

reset(arg) {
  if(!present("lifetree", TO)) planter = 0;
  if(arg) return;
  set_light(1);
  short_desc = "Hidden Grove";
  long_desc =
    "    You stand in a secluded forest grove. So untouched is this\n" +
    "place, so pure and whole, that you believe that you are the\n" +
    "first person ever to lay eyes on it. A wide sunbeam shines\n" +
    "down to make a perfect circle of light on the forest floor,\n" +
    "illuminating a patch of ground sprouting brightly-colored\n" +
    "flowers and exotic plants.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b18", "southwest",
  });

  items = ({
    "grove", "A beautiful forest grove",
    "sunbeam", "A wide band of sunlight shining through a hole above you",
    "circle", "This is a perfect circle of sunlight",
    "hole", "A gap in the tree branches overhead",
    "branches", "Thick dark tree branches",
    "light", "The sunlight forms a perfect circle from above",
    "floor", "The forest floor is illuminated by the beam of sunlight",
    "patch", "Flowers and plants grow thickly on this patch of ground",
    "ground", "The ground is covered with all types of plants",
    "flowers", "Beatiful, sweet-smelling flowers of all varieties",
    "plants", "Lush green flora",
  });
}

init() {
  ::init();
  add_action("plant", "plant");
}

plant(arg) {
  object seed;
  seed = present("large seed", TP);
  if(seed) {
    if(arg == "seed") {
      write("Where do you want to plant the seed?\n");
      return 1;
    }
    if(arg == "seed in ground") {
      write("You must be more specific.\n");
      return 1;
    }
    if(arg == "seed in circle" || arg == "seed in light" ||
       arg == "seed in beam" || arg == "seed in sunbeam" ||
       arg == "seed in circle of light" ||
       arg == "seed in sunlight") {
      if(!planted) {
	write("You plant the seed in the circle of light.\n");
	say(TP->NAME + " plants a seed in the circle of light.\n");
	planted = 1;
	planter = TP->RNAME;
	destruct(seed);
        return 1;
      }
      write("A seed has already been planted.\n");
      return 1;
    }
    write("Plant what?\n");
    return 1;
  }
  write("You have nothing to plant.\n");
  return 1;
}

smash_it() {
  object tree;
  if(planted && !present("lifetree", TO)) {
    TELLR(TO, "You notice a tiny sprout emerge from the circle of light.\n");
    tree = clone_object(NWFORESTB + "objects/lifetree");
    MOVE(tree, TO);
    tree->start_grow();
  }
  return 1;
}

reset_tree() {
  planter = 0;
  planted = 0;
}
query_smash() { return 1; }
query_planter() { return planter; }
