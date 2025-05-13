inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are wandering through the dark, secret orc caves.  "+
            "The corridor leads further to the west and south.  The air "+
            "is rank with the stench of death and decay.  Blood stains "+
            "the walls, and moss grows on the ground.\n";

  items=({"caves","The secret orc caves, inhabited by orcs",
          "corridor","It leads to the west and south",
          "air","The air is rank with death",
          "blood","Fresh red blood splashed on the walls",
          "walls","They crumbling walls are patched with blood",
          "moss","Wretched green moss",
          "ground","The ground is covered in foul moss",
        });

  smell="The horrible scent of death.";

  dest_dir=({"/players/emerald/island/room/caves/room/ci42","west",
             "/players/emerald/island/room/caves/room/ci40","south",
           });

  ::reset(arg);
  replace_program("/room/room");

}
