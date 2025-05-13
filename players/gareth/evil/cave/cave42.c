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
      "sound may be occasionally heard. The air seems to be have alot\n"+
      "more moisture. It becomes more damp as you walk further north.\n"+
      "There seems to be a dripping sound as if water is near by.\n";
     
     dest_dir = ({
       ECAVE+"water1","north",
       ECAVE+"cave41","south",
                });

}
}
