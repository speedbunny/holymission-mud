inherit "room/room";
#include "/players/gareth/define.h"
reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_light(1);
     short_desc = "Jail/Torture room";
     long_desc = 
         "As you enter, there's an overwhelming stench of decay.\n"+ 
         "There are various implements of torture here, both large\n"+ 
         "and small; a rack, iron maiden, tongs, whips, pinchers,\n"+ 
         "and other devices of which you have never seen before. \n"+
         "There are comfortable looking chairs scattered along the\n"+
         "walls, evidently placed there to allow visitors an enjoyable\n"+
         "view of the proceedings. There is a faint murmur coming from\n"+
         "the corner of the room.\n";
     
     items = ({
       "rack","The standard rack used for torture",
       "iron maiden","A painful looking device used for torture",
       "maiden","A painful looking device used to inflict injury",
       "tongs","torturing devices that look rather lethal",
       "whips","whips used for torture, not sex you pervert!",
       "chairs","they look rather comfortable",
             });
     
     dest_dir = ({
      ETOWN+"tr2","west",
  
     });

}
}
