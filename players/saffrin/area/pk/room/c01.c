inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Elan Drac Asylum Courtyard";
  long_desc = 
      "You are standing in the courtyard of the Elan Drac Asylum.  There are "+
      "small, dried trees with their branches hanging limp.  Several shrubs "+
      "are brown from lack of watering and care.  The ground is covered with "+
      "dead grass that looks like as if it was trampled.  The sun is blaringly "+
      "hot as it beats down on you.  The courtyard continues to the southeast.  "+
      "You can enter the asylum to the north, west, northeast, northwest, "+
      "and southwest.\n";
  property=({
      "no_teleport",
  });
  dest_dir=({
      PK+"room/h6", "north",
      PK+"room/h10", "west",
      PK+"room/h7", "northeast",
      PK+"room/h5", "northwest",
      PK+"room/c02", "southeast",
      PK+"room/h11", "southwest",
  });
  items=({
      "ground", "Covered with dead grass",
      "grass", "Dead grass that has been trampled",
      "trees", "Small dried tree with branches hanging limp",
      "courtyard", "The courtyard of the Elan Drac Asylum",
      "asylum", "The Elan Drac Insane Asylum",
      "branches", "Limp branches from the trees",
      "shrubs", "Brown shrubs from lack of watering and care",
      "sun", "AAAAAAAAAAHHH!!!  You burn your eyeballs",
  });
  ::reset();
  replace_program("room/room");
}
