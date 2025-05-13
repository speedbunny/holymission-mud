/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(0);
        short_desc= "Small forest";
        long_desc=
  "This place is full of eucalypt trees which give you shade from the harsh\n"+
  "sunlight. It is very quiet and dim here. You notice some koalas on the\n"+ 
  "trees, looking very lazy, just dousing and eating eucalyptus leaves.\n";
        
        dest_dir=({ 
            ROOM + "zoo1", "north",
            ROOM + "zoo3", "west",
                  });
        items=({
  "tree","A tall eucalyptus tree",
               });
        smell = "You smell eucalyptus eminating from trees surround you";
  
     }

init()
{
  ::init();
}
