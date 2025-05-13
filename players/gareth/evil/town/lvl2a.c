#include "/players/gareth/define.h"
inherit "room/room";
int opened, searched;
object guard;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "sleeping quarters";
  long_desc = 
   "These quarters contain beds, tables, and chairs. There are\n"+
   "two cots with feather filled mattresses, two tables with \n"+
   "two chairs at each.  There's shelf attached to the wall. \n"+ 
   "In addition there are footlockers at the end of each bed.\n"+  
   "There are two windows on the northern wall, both of which\n"+
   "are covered with thick drapes.\n";
  
  items = ({
    "cots","Large undone cots, with purple sheets and covers and large pillows",
    "mattresses","Large mattresses, filled with feathers. It looks rather comfortable",
    "wall","The wall of this room is facing north. It has two windows built into it",
    "windows","Two windows that are barred and covered by large black shades",
    "shelf","Brown wooden shelf",
    "lockers","Large footlockers, resting beside the cots",
    "foot lockers","Ordinary foot lockers resting beside the cots",
            });
    
        MO((CO(MON+"guard")),TO);
  dest_dir = ({
    ETOWN+"lvl2c","east",
    ETOWN+"lvl2b","north",
    ETOWN+"lvl1","down",
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
          write("The locker is open and there's a potion which you can take.\n");
          TR(CO(ITEM+"hearo_potion"), TP);

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
          write("You find a ring on the shelf.\n");
          TR(CO(ITEM+"iring"), TP);
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

