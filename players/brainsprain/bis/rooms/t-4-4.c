inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

int i;
int do_down(){
  if(i!=1){
    write("The door is closed!\n");
    call_out("opn_dr",35);
    return 1;
  }
}
void opn_dr(){
  remove_call_out("opn_dr");
  write("A swarthy guard arrives.\n");
  write("Guard says: What are you doing here?\n");
  write("Guard says: Get out of my cell.\n");
  i = 1;
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  short_desc = "Bismarck Royal Jail";
  long_desc =
    "The door swings shut behind you !\n\n"+
    "A single window sit high up on the northern face of the wall.  The only "+
    "furniture in this room is a old bed frame with no mattress and a bed pan. "+
    "Currently this cell is empty other than yourself and a few rats.\n";
  items = ({
    "window",
    "It is to high for you to climb out of",
    "face",
    "The facade of the wall",
    "wall",
    "A wall of the prison cell",
    "cell",
    "The royal prison cell",
    "staircase",
    "A winding staircase",
    "door",
    "An solid oak door",
    "frame",
    "An old bed frame",
    "pan",
    "A rusty old bed pan",
    "rats",
    "A few scurvy looking jail rats",
  });
  set_light(1);
  dest_dir = ({
    br+"/t-4-3.c","down",
  });
}
void init(){
  ::init();
  add_action("do_down","down");
}
