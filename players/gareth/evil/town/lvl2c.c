#include "/players/gareth/define.h"

inherit "room/room";
int opened, searched;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "guest room";
  long_desc = 
   "This bedroom seems more elgant than the others, with purple \n"+
   "and violet quilts on both beds, a black linen cloth spread out\n"+ 
   "on the table.  A dark blue woven rug nearly covers the entire \n"+ 
   "floor.  Both beds have nightstands beside them.  There is a large\n"+
   "shelf closet in the corner of the room.\n";
   
  items = ({
    "table","large oaken table covered with linen cloth",
    "rug","A beautiful blue rug with a skull design stitched into it",
    "nightstands","wooden night stands with lamps on them",
    "lamps","ordinary oil burning lamps",
    "beds","large queen sized beds with dark sheets and covers",
    "closet","a large closet that is closed",
          });
    
  dest_dir = ({
    ETOWN+"lvl2d","north",
    ETOWN+"lvl2a","west",
             });

}
}
  void init() {
    ::init();
    AA("_search","search");
    AA("_open","open");
  }

  status _open(string str){
      if(str!="closet" && str!="large closet")
          return 0;

      if(!opened) {
          write("The closet is open and inside is a shield.\n");
          TR(CO(ITEM+"fshield"), TP);

          opened = 1;
          return 1;
}       
          write("The closet is already opened.\n");
          return 1;
}


  string closet() {
    if(!opened)
        return "The closet is closed";
    else
        return "The closet has been pilfered before you";
}

