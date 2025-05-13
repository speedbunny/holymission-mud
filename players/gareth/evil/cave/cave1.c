#include "/players/gareth/define.h"
inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_light(0);
     short_desc = "Cave";
     long_desc = 
      "You are now in the caves of evil mischief. As you enter\n"+ 
      "there is a dim awareness of lurking evil that prevades your\n"+ 
      "senses. Blood red strata intertwines with bulging black veins\n"+ 
      "that run through the hewn rock walls and beyond the entrance\n"+ 
      "and down further. The surface of the rock are rough with small\n"+
      "openings and minor cracks. This wide corridor is deathly \n"+
      "still. There is a faint groaning sound, and a shrill piping\n"+ 
      "sound may be occasionally heard.\n";
         
     items = ({
        "openings", "Filled with Gareth's blood",
        "rock", "Red and black colored",
	"walls", "Thick and dark with sharp jagged egdes",
           });
     dest_dir = ({
       ECAVE+"cave2","north",
       ECAVE+"entcave","west",
  
     });

}
}
