inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";
  long_desc="You are sneaking through the secret orc caves.  The corridor "+
            "leads north and south.  Moss covers the ground, and blood "+
            "stains the walls.  The sickly sweet smell of death lingers "+
            "in the air.\n";

  items=({"ground","The ground is covered with moss",
          "caves","The atmosphere is sickening in these caves",
          "corridor","It leads north and south",
          "moss","Unhealthy moss covers the ground",
          "walls","The walls are made of stone",
          "air","The air is close and stifling",
          "blood","You see big spots of human blood",
        });

  smell="The sickening stench of death.";
      
  dest_dir=({"/players/emerald/island/room/caves/room/ci33","north",
             "/players/emerald/island/room/caves/room/ci31","south",
           });

  ::reset(arg);
  replace_program("/room/room");

}
