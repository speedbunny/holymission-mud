inherit "room/room";
#include "/players/gareth/define.h"
reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_light(0);
     short_desc = "Cave";
     long_desc = 
      "You are in the caves of evil mischief. There is a dim\n"+ 
      "awareness of lurking evil that prevade your senses. Blood\n"+ 
      "red strata intrwines with bulging black veins that run through\n"+ 
      "the hewn rock walls and beyond the last section and down\n"+ 
      "further. The surface of the rock are rough with small\n"+
      "openings and minor cracks. This wide corridor is deathly \n"+
      "still. There is a faint groaning sound, and a shrill piping\n"+ 
      "noise may be occasionally heard.\n";
     
     dest_dir = ({
       ECAVE+"cave26","east",
       ECAVE+"cave20","south",
                });

}
}
