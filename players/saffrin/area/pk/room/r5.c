inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Elan Drac Asylum Cell";
  long_desc = 
      "You are standing in one of the padded cells of the Elan Drac Asylum.  "+
      "There is some sparse light flickering in the room from the halls. "+
      "The walls are lined with pads that have been contructed from cotton "+
      "and feathers.  A few tears in the pads are fluttering feathers to "+
      "the floor, which is already covered in filth.  The door to the cell "+
      "is made from iron bars that have rusted over due to lack of care.  "+
      "A foul stench assaults your nose and makes your eyes water.  "+
      "To the south and southeast are the halls.\n";
  property=({
      "no_teleport",
  });
  smell="It smells like urine and dung.\n";
  dest_dir=({
      PK+"room/h6", "south",
      PK+"room/h7", "southeast",
  });
  items=({
      "floor", "It is filthy, smeared with urine and dung. Some feathers are here",
      "urine", "Yellow urine",
      "dung", "EEEEEEWWWWWW!!!  Brown Dung",
      "cells", "Cells of the asylum",
      "cell", "A cell of the asylum",
      "pads", "Pads lining the walls that are made from feathers and cotton",
      "tears", "Tears that are in the pads.  They are leaking feathers",
      "bars", "Iron bars that are covered with rust",
      "doors", "Doors that have been rusted open",
      "rust", "Rust covering the doors",
      "room", "There are cells",
      "filth", "Urine and dung",      
      "feathers", "It is part of the pads",
      "bar", "Iron bars that are covered with rust",
      "cotton", "It is part of the pads",
      "courtyard", "An entrance to a courtyard",
      "entrance", "An entrance to a courtyard",
      "halls", "The halls of an insane asylum",
      "walls", "The walls of the cell",
      "door", "The door of the cell",
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
      "light", "Very little light",
  });
  ::reset();
  replace_program("room/room");
}
