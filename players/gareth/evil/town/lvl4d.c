#include "/players/gareth/define.h"
inherit "room/room";
int opened, searched;
object drow;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "storage room";
  long_desc = 
   "This is the place where the guards keep all their items,\n"+
   "weapons, armor, and other useful equipment as well. There \n"+ 
   "is a display case filled with unusual things as well as semi\n"+ 
   "fine crafted weapons. This room is also filled with not so \n"+
   "valueable things. \n";
   
  items = ({
    "case","A large display case used for holding things",
    "display","A large case used for holding things",
    });

	MO((CO(MON+"drow_m2")),TO);
    
  dest_dir = ({
    ETOWN+"lvl4c","north",
    ETOWN+"lvl4a","west",
    ETOWN+"lvl5","up"
             });

}
}
  void init() {
    ::init();
    AA("_search","search");
    AA("_open","open");
  }

  status _open(string str){
      if(str!="case" && str!="display")
          return 0;

      if(!opened) {
          write("The display case is open and you find many things.\n");
          TR(CO(ITEM+"duck"), TP);
          TR(CO(ITEM+"diamond"), TP);
          TR(CO(ITEM+"fine_sword"), TP);
          TR(CO(ITEM+"pois_scroll"), TP);

          opened = 1;
          return 1;
}       
          write("The display case is already opened.\n");
          return 1;
}

string _case() {
    if(!opened)
        return "The display case is closed";
    else
        return "The display case has been cleaned out before you";
}
