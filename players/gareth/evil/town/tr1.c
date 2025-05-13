#include "/players/gareth/define.h"
inherit "/room/room";

reset(arg) {
   if (!arg) {
   set_light(1);
   short_desc= "Cliff";
   long_desc= "You stand on a cliff above the imfamous hometown\n"+
              "of the evil drow. The 'sky' is illuminatd by a purple\n"+
              "hue. The surronding walls of the cavern has been polished\n"+ 
              "smooth, so that the crimson color looks like blood from\n"+ 
              "a fresh wound. You can see many drow buildings in the\n"+
              "village. The dark dwellings mirror the evilness of their\n"+ 
              "people. There is a scent of death in the air.\n";
   items = ({
            "sky","The top of the cavern has a purple glow",
            "cavern","A big hole in the mountain hidng drow village",
            "walls","Dark crimson colored walls",
            "buildings","Evil looking buildings that house the drow",
           });
   dest_dir =({
     ETOWN+"tr2","down",
     ETOWN+"lvl5","back",
     });
   
   }

}


