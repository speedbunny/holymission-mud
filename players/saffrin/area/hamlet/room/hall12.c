inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The entrance to the stables";
  long_desc = 
      "You are in the entrance to the stables for the castle of Denmark's horses.  "+
      "The floor is covered in a thick layer of hay blended in with horse dung.  Along the "+
      "west wall are several leather saddles polished to a shine.  Above the saddles are "+
      "an array of riding crops in various sizes.  A small wooden chair is near the south wall.  "+
      "A few pails of oats are next to the chair, ready for the next feeding time.\n";
  dest_dir=({
      HAM+"room/hall11", "north",
      HAM+"room/hall13", "east",
  });
  items=({
      "floor", "Covered with hay and horse dung",
      "dung", "EWWW!!!  Gross thing to look at",
      "hay","Golden hay",
      "saddles", "Several saddles polished to a shine",
      "crops", "Crops of many shapes and sizes",
      "pail", "A metal pail",
      "oat", "Oat for the horse to eat",
      "chair", "A small wooden chair",
  });
// Mangla changed the clone list since frandisc did not exist, but fransisc did.
  clone_list=({
      1, 1, "guard", HAM+"npc/fransisc", 0,
  });
  ::reset();
  replace_program("room/room");
}
