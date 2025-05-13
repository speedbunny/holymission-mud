inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A road through the farmland";

  long_desc="The road grades upwards to the north, reaching the level of " +
            "the town at the top.  To the south it slips down into the " +
            "valley.  The town walls dominate the landscape, which is " +
            "hardly surprising considering how flat most of the land is.\n";

  dest_dir=({"/players/emerald/country/19","northeast",
             "/players/emerald/country/17","south",
           });

  items=({"walls","Sturdy walls protecting the population of a town",
          "landscape","Quite flat",
          "town","It looks rather small from this distance",
        });


  ::reset(arg);
   replace_program("/room/room");

}
