inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Elan Drac Asylum Hall";
  long_desc = 
      "You are standing in the hall of the Elan Drac Asylum.  There are "+
      "cobwebs hanging from a brass chandelier, that is barely lighting "+
      "your way.  There are open cells to the south, southeast, "+
      "and southwest of here.  "+
      "The iron bars on the cells have rusted over due to lack of care.  "+
      "A foul stench assaults your nose and makes your eyes water.  "+
      "There is an entrance to an old courtyard to the north, northeast, and northwest.  "+
      "The hall continues to the east and west.\n";
  property=({
      "no_teleport",
  });
  smell="It smells like urine and dung.\n";
  dest_dir=({
      PK+"room/c9", "north",
      PK+"room/r20", "south",
      PK+"room/h16", "east",
      PK+"room/h14", "west",
      PK+"room/c8", "northeast",
      PK+"room/c10", "northwest",
      PK+"room/r21", "southeast",
      PK+"room/r19", "southwest",
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
