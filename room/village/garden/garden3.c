inherit "/room/room";

#include "/room/room_defs.h"

static int apple_count;
 
void reset(int arg) {
  clone_list = ({
    1, 4, "ant", "obj/monster", ({
      "set_name", "ant",
      "set_race", "insect",
      "set_short", "An ant",
      "set_long", "An ant scurrying along the ground looking for "+
        "something that you cannot fathom.\n",
      "set_al", 0,
      "set_size", 1,
      "set_level", 1,
      "set_gender", 0,
    }),
  });

  apple_count = 8;

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In a beautiful garden";
  no_castle_flag = 0;

  long_desc =
    "This is the southeastern corner of Chantilly's beautiful garden. "+
    "As with the rest of the garden, it has been well-kept, and there "+
    "is a beautiful apple tree near the wall. The village walls block "+
    "any travel south or east but the rest of the garden is wide open.\n";

  items = ({
    "walls", "The city walls were built to protect the town from the "+
      "evil that lurks outside",
    "tree", "It is a large, old apple tree. Perhaps you could pick the "+
      "apples or climb the tree",
    "garden", "The middle of the garden has many bushes",
    "wall", "It spans the town",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "garden6", "north",
    VILLAGE_GARDEN + "garden2", "west",
  });
}

void init() {
  ::init();
  add_action("_climb", "climb");
  add_action("_pick", "pick");
}

status _climb(string str) {
  switch(str) {
    case "wall" :
    case "the wall" :
    case "walls" :
    case "over wall" :
    case "over the wall" :
      write("You attempt to climb the wall, but it is too steep.\n");
      say(TP->NAME + " tries to climb the town wall, but slides down.\n");
      return 1;
    case "tree" :
    case "apple tree" :
    case "the tree" :
    case "the apple tree" :
    case "up tree" :
    case "up the tree" :
    case "up apple tree" :
    case "up the apple tree" :
      if(TP->query_size() > 4) {
        write("You are too big to climb into the branches.\n");
        return 1;
      }
      if(TP->query_dex() <= 8 && random(10) < 5) {
        write("You try to climb the tree but fall down.\n");
        say(TP->NAME + " tries to climb the tree, but falls down.\n");
        return 1;
      }
      write("You climb up the apple-tree.\n");
      TP->MOVEP("up the apple-tree#" + VILLAGE_GARDEN + "tree05");
      return 1;
    default :
      notify_fail("Climb what?\m");
      return 0;
  }
}

status _pick(string str) {
  object ob;

  switch(str) {
    case "apple" :
    case "an apple" :
      if(apple_count <= 0) {
        write("Sorry, but there are no apples with which you can reach.\n");
        return 1;
      }
      write("You pick an apple.\n");
      say(TP->NAME + " picked an apple.\n");
      apple_count--;
      ob=clone_object("/obj/food");
      ob->set_name("apple");
      ob->set_alias_list(({ "fruit", "red apple" }));
      ob->set_short("A bright red apple");
      ob->set_long("A delicious-looking apple. It is probably sweet and "+
                   "juicy.\n");
      ob->set_heal_amount(2+random(8));
      ob->set_value(20);
      ob->set_weight(1);
      if(transfer(ob, TP))
        MOVE(ob, ENV(TP));
      return 1;
    default :
      notify_fail("Pick what?\n");
      return 0;
  }
}

