#include "/players/tatsuo/def.h"
inherit "room/room";


void reset(int arg)
  if(!present("halfling")) { MO(CO(HMON+"halfling"),TO); 
                             MO(CO(HMON+"halfling"),TO);        
                             MO(CO(HMON+"halfling"),TO); }


  if(arg) return;
    ::reset(arg);
  long_desc =  "The stream seems to run deeper here, and the sound "+
               "of cascading water comes from the south.  Looking "+
               "that way you seem to notice little puffs of smoke "+
               "eminating from behind a series of small hills.  The "+
               "path turns southeast here with the bend in the stream.\n";
 
  short_desc = "On the path to the Halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p3","southeast", HPATH+"p1","north" });

  items = ({ "stream","It runs south to north, rather like the Nile",
             "smoke","Rising from several spots, it rather seems like "+
             "a series of chiminies",
             ({"hills","small hills"}),"They are just that",
             "path","Stop looking at it and just walk on it, okay" });

   replace_program("room/room");
}


