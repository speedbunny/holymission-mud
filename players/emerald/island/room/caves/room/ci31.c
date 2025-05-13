inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are sneaking through the secret orc caverns.  The corridor "+
            "leads further to the north and south.  A smell like rotting "+
            "corpses fills the air.  Moss grows on the ground, while "+
            "blood stains the walls.\n";

  items=({"caverns","The secret orc caverns",
          "corridor","The dark passage continues north and south",
          "air","The air is foetid",
          "moss","Unhealthy looking moss",
          "ground","It is covered in unwholesome moss",
          "blood","The vital fluid of animals",
          "walls","Crumbling stone walls",
        });
      
  dest_dir=({"/players/emerald/island/room/caves/room/ci32","north",
             "/players/emerald/island/room/caves/room/ci29","south",
           });

  smell="Something died here quite recently.";

  ::reset(arg);
  replace_program("/room/room");

}
