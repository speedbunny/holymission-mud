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
      "hot as it beats down on you.  The courtyard continues to the southwest.  "+
      "You can enter the asylum to the north, east, northeast, northwest, "+
      "and southeast.\n";
  property=({
      "no_teleport",
  });
  dest_dir=({
      PK+"room/h4", "north",
      PK+"room/h10", "east",
      PK+"room/h5", "northeast",
      PK+"room/h3", "northwest",
      PK+"room/h11", "southeast",
      PK+"room/c2", "southwest",
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
