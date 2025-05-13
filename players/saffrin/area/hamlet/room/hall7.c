inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The falconry";
  long_desc = 
      "You are in the dangerous and lively falconry of the castle of Denmark.  "+
      "The are several large wooden perches all along the south wall.  Hay is "+
      "scattered on top of the floor, enabling you to only see part of the wood "+
      "beneath it.  The ceiling is made up of small shafts leading high up into the "+
      "outside.  There are cages of all sizes lined up against the west wall.  "
      "There are some dropping on the ground from the falcons.\n";
  dest_dir=({
      HAM+"room/hall5", "north",
  });
  items=({
      "dropping", "Falcon droppings",
      "walls", "Made from hard sturdy wood",
      "floor", "Hard wood floor covered with hay.  Some dropping are there as well",
      "hay", "Golden strands of hay",
      "ceiling", "A high ceiling with shafts in it",
      "shafts", "They lead up and out",
      "perches", "Perches for the falcons to rest on",
      "cages", "Cages to transport the falcons in",
  });
  clone_list=({
      1, 4, "guard", HAM+"npc/dguard", 0,
      1, 3, "falcon", HAM+"npc/falcon", 0,
  });
  ::reset();
  replace_program("room/room");
}
