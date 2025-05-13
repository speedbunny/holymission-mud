inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are wandering through the dark, secret orc caves.  The "+
            "dark passage leads to the north and east.  The air has a "+
            "sickly-sweet smell, as if something has died here recently.  "+
            "The ground is covered with moss, and there is blood on the "+
            "stone walls.\n";

  items=({"caves","The secret orc caves",
          "passage","It leads further to the north and east",
          "air","It reeks of foulness and death",
          "ground","Wretched moss grows on the ground",
          "moss","Nasty green moss",
          "blood","Old patches of dried blood",
          "walls","Crumbling stone walls",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci41","east",
             "/players/emerald/island/room/caves/room/ci43","north",
           });

  smell="The stench of death.";

  ::reset(arg);
  replace_program("/room/room");

}
