#include "/players/gareth/define.h"
inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_light(0);
     short_desc = "Cave";
     long_desc = 
      "You are in the caves of evil mischief. There is a dim\n"+ 
      "awareness of lurking evil that prevades your senses. Blood\n"+ 
      "red strata intertwines with bulging black veins that run through\n"+ 
      "the hewn rock walls and beyond the last section and down\n"+ 
      "further. The surface of the rock are rough with small\n"+
      "openings and minor cracks. This wide corridor is deathly \n"+
      "still. There is a faint groaning sound, and a shrill piping\n"+ 
      "sound may be occasionally heard.\n";
     
     items = ({
	"rock", "sharp - so becareful or get cut",
	"wall", "dark red and black rock",
	"strata", "looks like blood",
	"openings", "filled with Gareth's Blood",
	});
     
     dest_dir = ({
       ECAVE+"cave4","east",
       ECAVE+"cave2","south",
  
     });

}
}
