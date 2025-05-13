#include "/players/gareth/define.h"

inherit "room/room";
int opened, searched;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "sleeping quarters";
  long_desc = 
   "These quarters contain beds, tables, and chairs. There are \n"+
   "two cots with feather filled mattresses, two tables with two\n"+ 
   "chairs at each.  There's shelf attached to the wall.  In addition\n"+ 
   "there are footlockers at the end of each bed.  There are two \n"+
   "windows on the northern wall, both of which are covered with \n"+
   "thick drapes.\n";
  
  items = ({
    "cots","Large undone cots, with purple sheets and covers and large pillows",
    "mattresses","Large mattresses, filled with feathers. It looks rather comfortable",
    "wall","The wall of this room is facing north. It has two windows built into it",
    "windows","Two windows that are barred and covered by large black shades",
    "shelf","Brown wooden shelf",
    "lockers","Large footlockers, resting beside the cots",
    "foot lockers","Ordinary foot lockers resting beside the cots",
    });
    
  dest_dir = ({
    ETOWN+"lvl2a","south",
    ETOWN+"lvl2d","east",
             });

}
}
  void init() {
    ::init();
    AA("_search","search");
    AA("_open","open");
  }

  status _open(string str){
      if(str!="lockers" && str!="footlockers")
          return 0;

      if(!opened) {
          write("The locker is open and you find a bag.\n");
          TR(CO(ITEM+"bag"), TP);

          opened = 1;
          return 1;
}       
          write("The footlocker is already opened.\n");
          return 1;
}

  status _search(string str){
      if(!str || str!="shelf"){
          NF("search what?\n");
          return 0;
      }
      if(!searched){
          write("You find a scroll on the shelf which you quickly take.\n");
          TR(CO(ITEM+"stone_scroll"), TP);
          searched = 1;
          return  1;
}
  
  write("You search but the shelf is bare.\n");
     return 1;

}
  string shelf() {
    if(!searched)
        return "The looks like there's something on the shelf";
    else
        return "The shelf appears to have been rummaged through already";
}

  string footlocker() {
    if(!opened)
        return "The locker is closed";
    else
        return "The footlocker has been open prior to your arrival";
}

