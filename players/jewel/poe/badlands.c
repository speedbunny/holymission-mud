/* Coded by Jewel of Holy Mission */
/* /players/jewel/poe/badlands.c */
/*    START OF AREA    */
 
#include "/players/jewel/defs.h"
 
inherit "room/room";
 
reset(arg) 
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Badlands";
  long_desc = 
  "Death and gloom surround this evil place.  Eerie white waifs "
+ "of supernatural mist rise from the unholy ground and envelop "
+ "your feet right before your eyes.  Out of the mist you "
+ "can barely make out the shape of a decrepit bridge to the north.  "
+ "As your eyes follow the bridge, you suddenly see an ominous "
+ "castle looming above you.  Fear and terror grip your heart, "
+ "yet you are still curious to see what lurks inside this home of evil.\n";
  items = ({ 
"mist","White creeping mist.  It looks eerie",
"ground","Unholy ground.  It is gray and void of life",
"feet","They are covered in mist",
"bridge","A stone bridge in ill-repair.  You hope you can make it across",
"castle","A gloomy castle.  You can see a fissure in one of its walls",
"fissure","It zigzags from the top to the bottom of the castle wall",
             });
  dest_dir = ({
        POE+"bridge", "north",
        PATH+"workroom", "south",
                });
  smell = "It smells quite foul here.";
  replace_program("room/room");
}

