inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="The secret orc caves";

  long_desc="You are lurking in the secret orc caves.  Blood stains the "+
            "walls, while moss grows on the ground.  A sickly-sweet odour "+
            "permeates the air, like something has died here recently.  "+
            "A few noises filter in from the north.\n";

  items=({"caves","The secret orc caves",
          "blood","The recently dried blood of unfortunate adventurers",
          "walls","Crumbling stone walls",
          "moss","Clinging green and brown moss",
          "ground","Moss grows on the ground",
          "air","The air is foul and wretched in here",
        });

  smell="The stench of death.";

  dest_dir=({"/players/emerald/island/room/caves/room/ci14","north",
             "/players/emerald/island/room/caves/room/ci12","east",
           });

  ::reset(arg);
  replace_program("/room/room");

}
