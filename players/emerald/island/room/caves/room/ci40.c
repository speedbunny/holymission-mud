inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are wandering through the secret orc caves.  The dark "+
            "passage leads to the north and south.  The ground is "+
            "covered in sickly green moss.  Dark stains of blood are on "+
            "the walls.  The air has a foetid smell, as is something has "+
            "died here recently.\n";

  items=({"caves","The secret orc caves",
          "passage","A dark, foetid passageway",
          "ground","It is covered in evil green moss",
          "stains","Old and fresh stains of blood on the walls",
          "blood","Fresh and old blood splotches on the walls",
          "walls","The are covered in blood",
          "air","It reeks in here",
        });

  smell="The stench of death.";

  dest_dir=({"/players/emerald/island/room/caves/room/ci41","north",
             "/players/emerald/island/room/caves/room/ci39","south",
           });

  ::reset(arg);
  replace_program("/room/room");

}
