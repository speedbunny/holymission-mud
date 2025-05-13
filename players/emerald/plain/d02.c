inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="In the dunes";
  long_desc="The sun is not as intense in this section of the dunes.  " +
            "Shade from the thick foliage of the Ilkin Forest to the west " +
            "and south provides relief during the heat of the day.  " +
            "Shrubby vegetation provides the transition from the dunes to " +
            "the forest.  To the east, the waves roll in at a constant " +
            "rate from the blue sea on to a wide white beach.\n";


  dest_dir=({"/players/emerald/plain/d04","north",
             "/players/emerald/plain/d03","east",
             "/players/emerald/plain/d05","northeast",
             "/players/emerald/plain/d01","southeast",
           });

  items=({"dunes","Large mounds of sand",
          "shade","Areas where sunlight cannot penetrate",
          "foliage","The leaves from the trees of the forest",
          "forest","The dark and evil Ilkin Forest",
          "vegetation","They grow out into the sand of the dunes",
          "waves","Foamy waves of water crashing on to the sand",
          "sea","A clear blue sea",
          "beach","It is quite wide and flat",
        });

  clone_list=({
    1,1,"frog","obj/monster", ({
      "set_name","frog",
      "set_race","amphibian",
      "set_short","A tree frog",
      "set_long","A cute little green tree frog, sitting in the shrubs.\n",
      "set_level",4,
      "add_money",15,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
