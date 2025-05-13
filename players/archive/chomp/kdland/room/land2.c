/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(0);
        short_desc= "Bush";
        long_desc=
  "Here the bushes and trees are very thick, you can hardly see the\n"+
  "sunlight. Under the trees, there are little shacks made of leaves and\n"+
  "branches, where the Aboriginal tribes live.\n";
        
        dest_dir=({ 
            ROOM + "land3", "south",
            ROOM + "land1", "west",
                  });
        items=({
  "bushes","Thick bushes",
  "shack","A simple shelter made from leaves and tree branches",
  "trees","They are eucalyptus and gum trees",
               });
        smell = "You smell eucalyptus eminating from trees surround you";
  
     }

init()
{
  ::init();
}
