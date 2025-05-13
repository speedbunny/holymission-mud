inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
object ob;

int get(string arg){

  if(present("dragon")){
    ob = present("dragon");
    ob->set_aggressive(35);
    write("The dragon slaps you aside with his tail.\n");
    this_player()->hit_player(5);
    return 1;
  }
}

void reset(int arg) {
  clone_list = ({ 1, 1, "dragon", bm+"/dragon.c", 0,
		  2, 1, "cash", "obj/money", ({ "set_money",10000 }),
  });     
  ::reset(arg);
  if(arg) return;
  short_desc = "The Count's Bank";
  long_desc =
    "This is the place where Count Bismarck stores all his personal wealth. "+
    "Gold lies in piles all about the room. Finely carved, stained-glass "+
    "windows throw an odd light on the coins.  A rickety staircase leads down.\n";
  set_light(1);
  dest_dir = ({
    br+"/t-3-3.c","down",
  });
  items = ({
    "light",
    "It wavers and shakes as if it is alive",
    "piles",
    "Piles of gold",
    "count",
    "Count Bismarck, ruler of these lands",
    "bismarck",
    "The family name of the rulers of these lands",
    "windows",
    "Stained-glass windows",
    "staircase",
    "A rickety, wooden staircase",
  });
}
void init(){
  ::init();
  add_action("get","get");
}
