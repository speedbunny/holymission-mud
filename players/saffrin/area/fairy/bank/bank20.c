inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Water Bank";
  long_desc = 
        "You are on the lush, green banks of Elphame Lake.  Small gray pebbles are "+
        "scattered around you.  You can see a thick forest filled with fir trees to "+
        "the east of you.  There are several small moonworts growing along "+
        "the water's edge to the west of you.  The bank of the lake leads to "+
        "the north and south.\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"bank/bank21", "north",
        FAIRY+"bank/bank19", "south",
        FAIRY+"water/lake18", "west",
  });
  items=({
        "banks", "The bank of the water",
        "you", "You cannot see yourself",
        "edge", "The edge of the water",
        "forest", "A thick forest of fir trees",
        "lake", "Elphame Lake",
        "plant" , "A plant growing all around the water's edge",
        "moonworts", "A plant growing all around the water's edge",
        "water", "Rare silver water",
        "fir" , "Fir trees that have grown in thick",
        "trees" , "Fir trees that have grown in thick",
        "pebbles", "Small gray pebbles",
  });
  clone_list=({
        1, 2, "pwca", FAIRY+"npc/pwca", 0,
  });
  ::reset();
  replace_program("room/room");
}
