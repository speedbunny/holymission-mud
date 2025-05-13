#include "/players/gareth/define.h"
inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_light(0);
  short_desc = "Post entrance";
  long_desc = 
   "You come to the end of the cave, and realize that before\n"+
   "you is a large building. It appears to be made directly into\n"+ 
   "the cave rock itself. There's no sound what so ever or \n"+ 
   "any movement as well. Footprints lead into and out of the \n"+
   "entrance. There's a large pool of dried blood in numerous places\n";
  
  items = ({
    "building","It appears to be some kind of fort",
    "rock","Black and dirty, careful, it's sharp",
    "entrance","It lets you into the building, what else?",
    "footprints","Many sets of prints, that lead in to the fort",
    "blood","Dried blood - looks like it was Gareth's blood",
    "pools","Dried pools of Gareth's Blood",
    });

  dest_dir = ({
    ECAVE+"cave48","west",
             });

}
}

init() {
  ::init();
  AA("_enter","enter");
 }
  _enter(str) {
  if(str!="fort") {
  NF("Where do you wanna go???\n");
  return 0;
}
  TP->MP("into the fort#players/gareth/evil/town/lvl1");
  return 1;
}

