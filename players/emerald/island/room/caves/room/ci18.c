inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="The secret orc caves";

  long_desc="The orc caves lead further to the south and east.  As far "+
            "as can be seen in the gloom, blood stains the walls and "+
            "evil green moss grows on the ground.  The scent of death and "+
            "decay is heavy in the air.\n";

  items=({"caves","The secret orc caves",
          "gloom","Thick, sinister gloom",
          "blood","Fresh spots of blood on the walls",
          "walls","Old and crumbling stone walls",
          "moss","Nasty green moss, feeding upon dried blood",
          "ground","It is covered with moss",
          "air","The air is quite foetid",
        });
  
  dest_dir=({"/players/emerald/island/room/caves/room/ci15","south",
             "/players/emerald/island/room/caves/room/ci19","east",
           });

  smell="The air is rank with death.";

  ::reset(arg);
  replace_program("/room/room");

}
