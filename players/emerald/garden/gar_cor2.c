inherit "/room/room";

reset(arg) {

  if(arg) return;

  set_light(1);

  short_desc="Garden corridor";
  long_desc="You are on the path leading into the garden.  Before you " +
            "is a passage which enters the hedge.  Could " +
            "this be a way into the garden?  There are some strange heaps " +
            "of earth on both sides of the path.  These could have been " +
            "made by the moles the gardener was speaking about.  Perhaps " +
            "you could catch one or two of them, and help the gardener to " +
            "keep them out of his garden.\n";

  dest_dir=({"/players/emerald/garden/gar_cor3","west",
             "/players/emerald/garden/gar_cor1","east",
           });

  items=({"path","It leads into the garden",
          "hedge","The golden border of the garden",
          "passage","It enters the hedge",
          "heaps","Small piles of dirt",
          "earth","Moist, black earth",
          "garden","It is full of flowers",
        });

  clone_list=({
    1,2,"mole","obj/monster", ({
      "set_name","mole",
      "set_short","A mole",
      "set_long","This seems to be one of the moles the gardener is worried\n" +
        "about.  It looks out from a heap of earth and seems to be very\n" +
        "content to destroy the beauty of the garden.\n",
      "set_race","rodent",
      "set_level",1,
      "set_wc",2,
      "set_ac",1,
      "set_al",-50,
      "add_money",50,
    }),
  });

  ::reset();
  replace_program("/room/room");

}

