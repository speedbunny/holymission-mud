inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The stables";
  long_desc = 
      "You are the main stables for the castle of Denmark's horses.  "+
      "The floor is covered in a thick layer of hay blended in with horse dung.  Along the "+
      "east wall are several stalls made from sturdy wood.  There are swinging gates "+
      "attached to the stalls to keep the horse from escaping.  Several leather pouches of "+
      "oats are along the south wall.  There is the buzzing of flies about the room.\n";
  dest_dir=({
      HAM+"room/hall12", "west",
  });
  items=({
      "floor", "Covered with hay and horse dung",
      "dung", "EWWW!!!  Gross thing to look at",
      "hay","Golden hay",
      "stalls", "Stalls for the horse",
      "gates", "Gates to keep the horses in",
      "pouches", "Pouches of leather filled with oats",
      "oat", "Oat for the horse to eat",
      "wood", "Hard and sturdy wood",
  });
  clone_list=({
      1, 4, "horse", HAM+"npc/horse", 0,
  });
  ::reset();
  replace_program("room/room");
}
