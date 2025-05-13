#include "/players/gareth/define.h"
inherit "room/room";
int opened, searched;
object drow;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "sleeping quarters";
  long_desc = 
   "These quarters are similar to the quarters below it contains \n"+
   "a bed, table, and chairs. There is a single cot with a feather\n"+
   "filled mattress, a table with two chairs.  There's shelf attached\n"+
   "to the wall.  In addition there is a footlocker at the end of the\n"+ 
   "of the bed.  There is a window on the northern wall, which is \n"+
   "covered with thick drapes.\n";
  
  items = ({
    "cot","Large undone cots, with purple sheets and covers and large pillows",
    "mattress","Large mattress, filled with feathers",
    "wall","It has a window built into it",
    "window","A window that is barred and covered by large black shades",
    "shelf","Brown wooden shelf",
    "locker","Large footlocker, resting at the end of cot",
    "foot locker","An ordinary foot locker resting next the cot",
    });

	MO((CO(MON+"drow_m")),TO);    
  dest_dir = ({
    ETOWN+"lvl3b","south",
    ETOWN+"lvl3c","west",
    ETOWN+"lvl2d","down",
             });

}
}
  void init() {
    ::init();
    AA("_search","search");
    AA("_open","open");
  }

  status _open(string str){
      if(str!="locker" && str!="footlocker")
          return 0;

      if(!opened) {
          write("The locker is open and there's something.\n");
          TR(CO(ITEM+"duck"), TP);

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
          TR(CO(ITEM+"res_scroll"), TP);
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

