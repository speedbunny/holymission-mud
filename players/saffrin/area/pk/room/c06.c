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
      "hot as it beats down on you.  "+
      "The courtyard continues to the north, south, east, west, northeast, "+
      "northwest, southeast, and southwest.\n";
  property=({
      "no_teleport",
  });
  dest_dir=({
      PK+"room/c03", "north",
      PK+"room/c09", "south",
      PK+"room/c05", "east",
      PK+"room/c07", "west",
      PK+"room/c04", "northeast",
      PK+"room/c02", "northwest",
      PK+"room/c010", "southeast",
      PK+"room/c08", "southwest",
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
  clone_list=({
      1, 1, "bathory", PK+"npc/bath", 0,
  });
  ::reset();
  replace_program("room/room");
}
