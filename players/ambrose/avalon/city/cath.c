

#include "/players/ambrose/room.h"

void reset(int arg)
 {
  ::reset(arg);
    if(arg)
       return;
      set_light(1);
     short_desc="The Cathedral";
     long_desc=
     "You are standing before the altar in the grand cathedral of avalon.\n"
    +"The altar rises above you a full 5 feet, covered in gold and white \n"
    +"cloth.  Ornate designs are over the sides and seem to be in a old form\n"
    +"of the celtic tongue.  You are unable to read all of it but you can \n"
    +"decipher that this altar is in worship of Danae, god of the Tuatha De\n"
    +"Dunan.\n";
      dest_dir=({
                "/players/ambrose/avalon/entrance/entran1","down",
      });
      items=({
      "room","You need to make it into something!",

           });
       smell="Does'nt smell like anything.";
     }
  void init()
  {
   ::init();
    add_action("no_way_out","",1);
 }






