/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Bush";
        long_desc=
  "Here the bushes and trees are more scattered again. It seems like a\n"+
  "peaceful place, where you can hear the birds and other wildlife\n"+
  "singing and playing around freely. You notice a creek behind the bushes.\n";
        
        dest_dir=({ 
            ROOM + "land2", "north",
            ROOM + "land4", "west",
                  });
        items=({
  "bushes","Scattered bushes",
  "creek","A little creek with water flowing slowly",
  "trees","They are eucalyptus and gum trees",
  "water","The water is crystal clear",
               });
        smell = "You smell fresh eucalytus leaves";
  
     }

init()
{
  ::init();
}
