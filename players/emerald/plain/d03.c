inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="In the sand dunes";
  long_desc="The sand dunes slope down to the meet the beach which runs " +
            "east towards the sea.  Wisps of grass and the woody stems of " +
            "bushes grow at random in the valleys between the dunes.  A " +
            "large divet at the base of a dune attracts your attention.  " +
            "To the east, the breaking of the waves on the beach forms an " +
            "almost mesmerizing attraction to the sea.\n";

  dest_dir=({"/players/emerald/plain/d05","north",
             "/players/emerald/plain/d01","south",
             "/players/emerald/plain/b06","east",
             "/players/emerald/plain/d02","west",
             "/players/emerald/plain/b08","northeast",
             "/players/emerald/plain/d04","northwest",
             "/players/emerald/plain/b04","southeast",
           });

  items=({"dunes","Large mounds of sand",
          "beach","A wide, clean, white sand beach",
          "wisps","The grass does not grow in clumps", 
          "grass","A few tall stems of grass",
          "stems","The stalks of the bushes",
          "bushes","Small, scrufty bushes growing in the dunes",
          "divet","It appears to be a turtle nest",
          "dune","A mound of sand",
          "waves","Small blue waves crested with foam",
          "sea","A clear blue sea",
        });

  clone_list=({
    1,1,"turtle","obj/monster", ({
      "set_name","turtle",
      "set_short","A sea turtle",
      "set_race","reptile",
      "set_long","A medium-sized sea-going turtle.\n",
      "set_level",14,
      "set_ac",10,
      "add_money",300,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
