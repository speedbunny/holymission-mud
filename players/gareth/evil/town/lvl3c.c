#include "/players/gareth/define.h"

inherit "room/room";
int opened, searched;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "cleric's quarters";
  long_desc = 
   "This room contains beds, tables, and chairs. There are \n"+
   "two cots with feather filled mattresses, two tables with two\n"+ 
   "chairs at each.  There's shelf attached to the wall.  In addition\n"+ 
   "there are footlockers at the end of each bed.  There are two \n"+
   "windows on the northern wall, both of which are covered with \n"+
   "thick drapes.\n";
  
  items = ({
    "cot","undone cot, with purple sheets and covers and large pillows",
    "mattress","Large feather filled mattress",
    "wall","",
    "","Two windows that are barred and covered by large black shades",
    "","Brown wooden shelf",
    "trunk","Large black and gold trunk, leaning agianist the wall",
         });
    
  dest_dir = ({
    ETOWN+"lvl3a","east",
    ETOWN+"lvl3d","south",
             });

}
}
  void init() {
    ::init();
    AA("_search","search");
    AA("_open","open");
  }

  status _open(string str){
      if(str!="trunk")
          return 0;

      if(!opened) {
          write("The trunk is open and inside is a scroll which you can take.\n");
          TR(CO(ITEM+"recall_scroll"), TP);

          opened = 1;
          return 1;
}       
          write("The trunk has already been opened.\n");
          return 1;
}


  string trunk() {
    if(!opened)
        return "The trunk is closed";
    else
        return "The trunk is has been opened before you";
}

