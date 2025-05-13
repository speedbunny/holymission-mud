inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="The secret orc caves";
  long_desc="You are sneaking through the secret orc caves.  Noises can be "+
            "heard coming from the north.  A pervasive scent of dead and "+
            "rotting flesh fills the air.  Blood stains the walls, and a "+
            "sickly green moss grows on the bottom of the cave.\n";

  items=({"caves","Dank and vile caves, inhabited by orcs",
          "air","It smells awful here",
          "blood","Both fresh and old bloodstains on the walls",
          "walls","The walls are covered in blood",
          "moss","Dank green moss, thriving on dried blood",
          "bottom","The bottom of the cave is covered in moss",
          "cave","A rank and foul cave",
        });

  smell="The scent of death.";

  dest_dir=({"/players/emerald/island/room/caves/room/ci13","south",
             "/players/emerald/island/room/caves/room/ci15","north",
           });

  ::reset(arg);
  replace_program("/room/room");

}
