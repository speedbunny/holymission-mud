inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A road through the farmland";

  long_desc="You are travelling through good farm country.  The fields of " +
            "grains are thick and full, with very few weeds.  You begin to " +
            "wonder where the farmers are who grow these crops.\n";

  dest_dir=({"/players/emerald/country/15","north",
             "/players/emerald/country/7","south",
           });

  items=({"fields","Beautiful fields of grains",
          "trees","You are too far away to see what species they are",
          "road","It is paved with stone cobbles",
        });


  ::reset(arg);
   replace_program("/room/room");

}
