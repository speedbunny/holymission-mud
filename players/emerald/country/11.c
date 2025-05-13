inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the woods";

  long_desc="You have almost reached the top of the hill.  The trees seem " +
            "a little stunted here from the winds which sometimes sweep " +
            "along the higher elevations.  There is still plenty of shade, " +
            "and no one appreciates it more than the animals which live in " +
            "the woods.\n";

  dest_dir=({"/players/emerald/country/10","northwest",
             "/players/emerald/country/12","south",
           });

  items=({"trees","Willows and aspen",
          "hill","A small hill in the countryside",
          "shade","It has been kindly provided by the trees",
        });

  clone_list=({
    1,1,"bobcat","obj/monster", ({
      "set_name","bobcat",
      "set_short","A ferocious bobcat",
      "set_long","A hungry bobcat looking for his next meal.\n",
      "set_level",30,
      "set_wc",13,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
