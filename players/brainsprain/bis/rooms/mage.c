inherit "/obj/std_shop";
#include "/players/brainsprain/bis/bisdef.h"
int opened;

int do_lift(string arg){
  if(present("relmux",TO)){
    write("Relmux puts his foot on the board and waggles his finger at you!\n");
    return 1;
  }
  if(arg != "plank"){
    if(arg == "planks") {
      return write("Maybe you should trying lifting one at a time.\n"), 1;
    }
    else {
      return write("Lift what?\n"),1;
    }
  }
  else {
    opened = 1;
    write("You lift the plank exposing a hole leading down.\n");
    return 1;
  }
}

int do_down(){
  if (opened == 0){
    write("What ?\n");
    return 1;
  }
  else {
    TP->move_player("down#/players/brainsprain/bis/rooms/strm.c");
    return 1;
  }
}

int do_enter(string arg2){
  if(arg2 != "hole"){
    write("Enter what ?\n");
    return 1;
  }
  else {
    do_down();
  }
}

void reset(int arg)
{
  clone_list = ({ 1, 1, "relmux", bm+"/relmux", 0 });
  ::reset(arg);
  if(arg) return;

  short_desc = "Apothecary and Magic shop";
  long_desc =
    "This entire room is painted and decorated in white.  A white quartz "+
    "counter sits along a wall where you can purchase items of magical power."+
    "  Ancient, white planks make up the almost seamless floor. "+
    "A white sign hangs from the wall and the letters on it are an off white,"+
    " making it impossible to read.\n";
  items = ({
    "floor",
    "It is made up of wooden planks",
    "sign",
    "It is too worn for you to read",
    "letters",
    "They are too worn for you to read",
    "room",
    "Towpath Apothecary and Magic Shop",
    "towpath",
    "The town you are in",
    "counter",
    "A white quartz counter",
    "wall",
    "A white wall",
    "planks",
    "One of the planks seems a little loose",
  });
  dest_dir = ({
    br+"/tr-14.c","south",
  });
  set_light(1);
  store = br+"/strm";
  keeper = "Relmux";
  property=({ "no_fight","has_fire", });
}
void init(){
  ::init();
  add_action("do_enter","enter");
  add_action("do_lift","lift");
  add_action("do_down","down");
}

