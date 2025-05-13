inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "A magical forest";
  long_desc = 
      "You are in a dark forest with trees all around you.  Sounds of animals "+
      "scampering can be heard in the distance.  A few beams of light break through "+
      "the cover of the tree branches above your head.  A few leaves are covering "+
      "the ground, crunching as you step.\n";
  smell="The air smells sweet.\n";
  dest_dir=({
      AINE+"room/for66", "south",
      AINE+"room/for79", "east",
  });
  items=({
      "forest", "A magical forest",
      "area", "A wooded area",
      "air", "DUH!  You cannot see the air",
      "dark", "DUH!  You cannot see the dark",
      "you", "You cannot see yourself",
      "yourself", "You cannot see yourself",
      "animals", "You can hear them in the distance",
      "distance", "A far off place",
      "place", "A far off place",
      "cover", "The cover of the trees",
      "ground", "The ground you are standing on",
      "step", "You cannot see your own step",
      "twigs", "Twigs from the trees",
      "leaves", "Brown, gold, and red leaves",
      "brown", "A color",
      "gold", "A color",
      "face", "You cannot look at your own face",
      "head", "You cannot look at your own head",
      "sky", "The sky above your head",
      "red", "A color",
      "white", "A color",
      "color", "Brown, white, gold, and red",
      "branches", "Branches covered with multicolored leaves",
      "light", "A few beams of white light",
      "tree" , "Magical trees that appear to be watching you",
      "beams", "A few beams of white light",
      "trees" , "Magical trees that appear to be watching you",
  });
  clone_list=({
      1, 2, "pixie", AINE+"npc/pixie", 0,
  });
  ::reset();
  replace_program("room/room");
}
