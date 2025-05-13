inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Stagedoor of a theatre";
  long_desc = 
      "You are standing infront of a large wooden stage door for the old,"+
      " rundown theatre.  The doors appear to have long since begun to fall off"+
      " their hinges and are covered with a thin layer of dust.  There is the remains "+
      "of a cart to the left of the stagedoor which has the word 'Apples' carved into its"+
      "rotted wood.\n";
  dest_dir=({
      "/room/south/sshore9", "north",
      HAM+"room/droom1", "in",
  });
  items=({
      "wood", "Rotted wood about ready to fall apart",
      "apples", "Rotted and stinky apples",
      "cart", "An old fruit cart with a broken wheel",
      "wheel", "A cracked wooden wheel that has fallen off the fruit cart",
      "doors", "A wooden door cracked around the edges",
      "hinges", "Rusty, old hinges that are crumbling",
  });
  clone_list=({
      1, 1, "sign", HAM+"obj/sign", 0,
  });
  ::reset();
}
