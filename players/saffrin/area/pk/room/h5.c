inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Elan Drac Asylum Entrance Hall";
  long_desc = 
      "You are standing in the entrance hall of the Elan Drac Asylum.  There are "+
      "cobwebs hanging from a brass chandelier, that is barely lighting "+
      "your way.  There are long, barely lit halls that lead south, east, "+
      "and west of here.  To the southeast and southwest, there is a old "+
      "courtyard.  There is a small marble staircase that leads out of the "+
      "asylum.  There is an odd sense of security in this room.  "+
      "A foul stench assaults your nose and makes your eyes water.\n";
  property=({
      "no_teleport",
      "no_attack",
  });
  smell="It smells like urine and dung.\n";
  dest_dir=({
      PK+"room/h10", "south",
      PK+"room/h6", "east",
      PK+"room/h4", "west",
      PK+"room/c01", "southeast",
      PK+"room/c1", "southwest",
      PK+"room/d", "down",
  });
  items=({
      "floor", "It is filthy, smeared with urine and dung",
      "urine", "Yellow urine",
      "room", "There are cells",
      "filth", "Urine and dung",      
      "feathers", "It is part of the pads",
      "bars", "Iron bars that are covered with rust",
      "cotton", "It is part of the pads",
      "courtyard", "An entrance to a courtyard",
      "entrance", "An entrance to a courtyard",
      "halls", "The halls of an insane asylum",
      "hall", "The hall of an insane asylum",
      "dung", "EEEEEEWWWWWW!!!  Brown Dung",
      "nose", "You cannot see your own face",
      "eyes", "You cannot see your own face",
      "face", "You cannot see your own face",
      "asylum", "The Elan Drac Insane Asylum",
      "chandelier", "Brass chandelier with cobwebs, barely lighting the way",
      "cobwebs", "Cobwebs covering a brass chandelier",
      "cells", "Old cells that have their doors opened",
      "doors", "Doors that have been rusted open",
      "rust", "Rust covering the doors",
  });
  ::reset();
  replace_program("room/room");
}
