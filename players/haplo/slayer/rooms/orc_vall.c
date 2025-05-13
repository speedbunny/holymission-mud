inherit "room/room";

#include "/room/orc/orc.h"

reset(arg) {

  if(arg) return;
  short_desc="The orc valley";
  long_desc=
            "You are in Orc Valley.  There are limbs thrown about all " +
            "around you.  Broken bones from past victims are scattered on " +
            "the ground.  The ground has been stained red from the blood " +
            "that has been spilled here.  There are signs of orcs everywhere.  " +
            "Faint growls and grunts can be heard somewhere in the distance.\n";
  set_light(1);
  items=({
            "valley","The Orc Valley",
            "red", "Blood red",
            "somewhere", "Somewhere in the distance",
            "distance", "Somewhere far",
            "signs", "Signs of orcs",
            "everywhere", "All around you",
            "limbs","Limbs of past victims",
            "bones","Bones of past victims",
            "blood", "Blood of past victims",
            "ground", "Covered in blood",
            "grunts", "You cannot see a sound",
            "growls", "You cannot see a sound",
            "sounds", "You cannot see a sound",

  });
  smell="It smells like orcs!!!!!!\n";
  dest_dir=({
             ORC+"fortress","north",
             "/room/slope","east",
             ORC+"v0","west",
  });
  clone_list=({ 
             1, 4, "orc", "obj/orc", 0,
  });
  ::reset();
}
