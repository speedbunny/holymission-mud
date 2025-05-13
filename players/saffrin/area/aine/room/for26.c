inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "A magical forest";
  long_desc = 
      "You are in a magical forest that is thick and dark.  Tall trees loom over "+
      "your head, stretching up to the sky.  Several branches stem off the trees, "+
      "entwining themselves in each other.  The ground is covered with twigs and "+
      "colorful leaves that have fallen.\n";
  smell="The air smells sweet.\n";
  dest_dir=({
      AINE+"room/for37", "north",
      AINE+"room/for21", "south",
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
      1, 2, "cyhyre", AINE+"npc/cyhyre", 0,
  });
  ::reset();
  replace_program("room/room");
}
