inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Aine's Waterfalls";
  long_desc = 
      "You have come upon the secret Aine Waterfall, named after the goddess "+
      "who tends to bath here.  There is a slowly falling waterfall flowing from the "+
      "clear green stones, spilling into a small lake.  Several rose bushes "+
      "line the shores of this enchanted place.  Soft mist hits your face from "+
      "the impact of water on water.\n";
  property=({
      "no_teleport",
  });
  smell="The air smells sweet.\n";
  dest_dir=({
      AINE+"room/for74", "west",
  });
  items=({
     "lake", "A small lake that is said to be where Aine bathes"
     "Aine", "She is not here, silly",
     "water", "Clear blue water",
     "goddess", "She is not here, silly",
     "here", "Right here!  Where you are standing",
     "shores", "The shores of the lake lined with wild parsley",
     "parsley", "Wild parsley growing around wild nutmeg",
     "nutmeg", "Wild nutmeg growing with wild parsley", 
     "place", "This enchanted place",
     "aine", "Aine is hiding her naked body from you",
     "body", "I said: Aine is hiding her naked body from you",
     "face", "You cannot see your own face",
     "mist", "Moist mist hitting your face",
     "bushes", "Bushes with blooming roses on them",
     "roses", "Soft peach roses with red tipped petals",
     "stones", "Clear green stones that are very large in size.  A small waterfall flows from them",
     "waterfall", "A small waterfall flowing from clear green stones",
     "petals", "The petals of a rose",
     "rose", "Soft peach roses with red tipped petals",
  });
  clone_list=({
      1, 1, "grian", AINE+"npc/grian", 0,
      1, 1, "fionn", AINE+"npc/fionn", 0,
  });
  ::reset();
  replace_program("room/room");
}
