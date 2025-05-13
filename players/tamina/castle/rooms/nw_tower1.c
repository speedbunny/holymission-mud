/* This is the Sacrifice Room + Secret Passage  */

inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) {
  if (arg) return;

     set_light(1);
     short_desc = "NW Tower - Basement";
     long_desc = 
"This is the apparent source of the awful stench that you smelt outside...\n"+
"It smells so bad that you feel as though you are going to vomit!  Two\n"+ 
"braziers stand on either side of a large stone altar, which is absolutely\n"+
"covered in fresh blood and gore.  You can also see bodily parts roasting\n"+ 
"nicely on the braziers...  There are also other organs, and limbs lying\n"+ 
"discarded in a corner, rotting away...\n"+    
"There are also other lovely joys or torture present in this room, such as\n"+
"a rack, and an Iron Maiden, and a set of iron rods.\n";

      dest_dir = ({
   CROOMS + "nw_tower", "up",
     });
    
      items = ({
  "braziers",
"Two iron caskets full of burning coals, with the occasional "+
"heart, kidney, or bladder roasting away",
  "rack",
"A large wooden table with two rollers at either end of the table "+
"with ropes attached to the rollers.  There appear to be blackened "+
"marks at the ends of the rollers, where the ropes are..",
  "rods",
"Long, blackened iron rods, that on closer examination have a distinct "+
"crust at the sharpened ends..",
  "organs",
"Rotten pieces of human corpses",
  "limbs",
"Rotten pieces of human corpses",
  "altar",
"This foul, abominable structure is stained permanently black now "+
"with the amount of blood spilled on it", 
      });
 
     smell = "The rather peculiar smell of perhaps burning pork...\n"+
             "Or most likely burning flesh";

    clone_list = 
  ({1, 1, "iron maiden", "/players/tamina/castle/obj/maiden", 0,
    2, 1, "priest", "/players/tamina/castle/monsters/priest", 0});

    ::reset(arg);

    RPR("room/room");
}
