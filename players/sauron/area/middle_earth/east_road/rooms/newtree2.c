inherit "/room/room";

#include "/players/sauron/defs.h"

climb(arg) {
  if(!arg || arg!="branch")
    return notify_fail("Climb what?\n");
  write("You start climbing up the branch.\n");
  say(TP->NAME+" starts to climb up.\n");
  call_out("stage2", 3);
  return 1;
}

stage2() {
  write("You finally reach the tip of the branch.\n");
  say(TP->NAME+" is near the tip of the branch.\n");
  call_out("stage3", 1);
  return 1;
}

stage3() {
  TP->MOVEP("up#/players/colossus/guild/portal");
  say(TP->NAME+" vanishes from sight.\n");
  return 1;
}

follow(arg) {
  if(arg == "ring") {
    write("You start to walk along the branch with a ring carved into it.\n");
    say(TP->NAME+" starts to walk along a branch.\n");
    call_out("branch2r", 2);
    return 1;
  }
  else if(arg == "church") {
    write("You start to walk along the branch with a church carved into it.\n");
    say(TP->NAME+" starts to walk along a branch.\n");
    call_out("branch2c", 2);
    return 1;
  }
  else if(arg == "shop") {
    write("You start to walk along the branch with a shop carved into it.\n");
    say(TP->NAME+" starts to walk along a branch.\n");
    call_out("branch2s", 2);
    return 1;
  }
  else {
    write("Follow what?\n");
  return 1;
  }
}

branch2r() {
  write("You reach the end of the branch.\nSuddenly the world becomes a " +
        "blur....\n");
  TP->MOVEP("along a branch#" + MERRMS + "newstart");
  say(TP->NAME+" reaches the end of the branch and vanishes from sight.\n");
  return 1;
}

branch2c() {
  write("You reach the end of the branch.\nSuddenly the world becomes a " +
        "blur....\n");
  TP->MOVEP("along a branch#/room/church");
  say(TP->NAME+" reaches the end of the branch and vanishes from sight.\n");
  return 1;
}

branch2s() {
  write("You reach the end of the branch.\nSuddenly the world becomes a " +
        "blur....\n");
  TP->MOVEP("along a branch#/room/main_shop");
  say(TP->NAME+" reaches the end of the branch and vanishes from sight.\n");
  return 1;
}

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="Top of the Tree of Time and Space";
    long_desc="This is the top of the Tree of Time and Space. Now that " +
              "you're closer you realize that the branches just stretch as far as " +
              "the eyes can see. Legend says that you can enter the " +
              "realm of Middle Earth by following the ring carved on one of " +
              "the branches. Other branches are told to lead to the church " +
              "and the shop. There is a particularly long branch that leads " +
              "further up the tree.\n";
    dest_dir=({
      "/players/colossus/mearth/tree1","down",
    });
    items=({
      "branches","They are big, think and strong, and go as far as your eye " +
                 "can see. Three of the branches have carvings on them",
       "carvings","On three of the branches you can see carvings - one of a " +
                 "church, one of a shop and one of a ring. You feel that by " +
                 "following a specific carving you will get to the place " +
                 "depicted by the carving",
      "branch","A particularly long branch that leads steadily upwards",
      "ring","A carving of a smooth gold ring",
      "church","A carving of the church",
      "shop","A carving of the shop",
    });
  }
}

init() {
  ::init();
  add_action("climb", "climb");
  add_action("follow", "follow");
}
