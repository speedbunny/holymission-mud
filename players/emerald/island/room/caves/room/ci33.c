inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="The dark corridors of the secret orc caves lead to the "+
            "west and south.  A strange, sickly-sweet smell is in the "+
            "air.  Dark spots of blood cover the walls, and an evil-"+
            "looking moss grows on the ground.  Strange noises come from "+
            "the passage to the west.\n";

  items=({"ground","The ground is covered with moss",
          "corridors","They are dark and dank, with an evil tinge",
          "caves","The secret orc caves.  You shouldn't be in them",
          "walls","The walls are made of stone",
          "spots","You see big spots of blood",
          "air","It is thick and stifling",
          "moss","Strange and unhealthy-looking moss",
          "passage","Noises come from the passage to the west",
          "blood","You see big spots of blood",
        });
      
  dest_dir=({"/players/emerald/island/room/caves/room/ci34","west",
             "/players/emerald/island/room/caves/room/ci32","south",
           });

  smell="The foetid smell of death.";

  ::reset(arg);
  replace_program("/room/room");

}
