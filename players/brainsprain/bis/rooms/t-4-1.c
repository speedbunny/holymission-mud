inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int m_c;  //flag to see if the carpet has been moved
int o_d;  //flag to see if the door has been opened

int do_move(string arg){
  if (arg != "carpet"){
    write("Move what?\n");
    return 1;
  }
  else {
    write("You move the carpet aside revealing a trap door.\n");
    m_c = 1;
    return 1;
  }
}
int do_open(string str){
  if(str != "trapdoor" && str != "door" && str != "trap door"){
    write("Open what?\n");
    return 1;
  }
  else{
    if(m_c != 1){
      write("What?\n");
      return 1;
    }
    else {
      write("You open the trap door.\n");
      o_d = 1;
      return 1;
    }
  }
}
do_mv(){
  if(m_c != 1){
    write("What?\n");
    return 1;
  }
  if(o_d != 1){
    write("The trap door is closed.\n");
    return 1;
  }
  else{
    this_player()->move_player("down#/players/brainsprain/bis/rooms/b-1.c");
    return 1;
  }
}


void reset(int arg) {
  ::reset(arg);
  if(arg) return;  
  short_desc = "First floor of northeastern tower";
  long_desc =
    "This is the first floor of the northeastern tower.  This tower serves "+
    "As the prison for those nobles who have committed crimes against the "+
    "Count.  The top room of the tower contains the cell in which they are "+
    "held.  A staircase leads up.  There is a thick carpet in the center "+
    "of the room.\n";
  set_light(1);
  items = ({
    "floor",
    "The first floor of the northeastern tower",
    "tower",
    "The northeastern tower",
    "staircase",
    "A spiral staircase leading up",
    "carpet",
    "There is a slight bump in the middle of this",
  });
  dest_dir = ({
    br+"/ch-20.c","south",
    br+"/t-4-2.c","up",
  });

}

void init(){
  ::init();
  add_action("do_move","move");
  add_action("do_open","open");
  add_action("do_mv","down");
}


