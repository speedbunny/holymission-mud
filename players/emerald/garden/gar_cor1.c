inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Garden corridor";
  long_desc="You are now west of the garden entrance.  The golden hedge " +
            "continues to the south and north.  Further west will lead you " +
            "into the garden.  You can smell the sweet fragrance of the " +
            "flowers from here.\n";

  items=({"hedge", "The hedge looks like it is made out of gold",
          "garden","It is filled with vibrant flowers",
        });

  dest_dir=({"/players/emerald/garden/gard_ent","east",
             "/players/emerald/garden/gar_cor2","west",
           });

  ::reset();
  replace_program("/room/room");

}
