#include "/players/gareth/define.h"

inherit "room/room";

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "training room";
  long_desc = 
   "This is the room where thr sentries practice their combat \n"+
   "skills.  There are no windows in the room, and the walls\n"+ 
   "and floors are covered with padding. There is an erie sense \n"+ 
   "of silence in here. \n";
  
  items = ({
    "walls","They are covered with padding",
    "floor","It's covered with padding",
    "padding","Soft thick material to prevent injury",
           });
    
  dest_dir = ({
    ETOWN+"lvl4d","south",
    ETOWN+"lvl4b","west",
             });

}
}

