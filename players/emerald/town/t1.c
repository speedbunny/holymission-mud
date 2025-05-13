inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The main street in town";

  long_desc="You have passed through the gates into the main street of " +
            "the town.  Booths and stalls are set up along the side.  " +
            "Crowds of people surround the busy proprietors.  The sound of" +
            " their haggling fills your ears.  The street continues to " +
            "the north and a side street begins to the east.\n";

  dest_dir=({"/players/emerald/town/t5","north",
             "/players/emerald/town/t2","east",
             "/players/emerald/country/20","south",
           });

  items=({"stalls","Brightly coloured stalls filled with goods",
          "proprietors","Merchants and vendors selling their goods",
          "gates","The inside of the town gates",
          "street","A wide street, currently filled with a market",
          "crowds","Hoards of people haggling and bartering",
          "booths","Stands contained the wares of the vendors",
        });

  clone_list=({
    1,2,"vendor","obj/monster", ({
      "set_name","vendor",
      "set_long","A greedy vendor selling less than quality items.\n",
      "set_race","human",
      "set_level",25,
      "set_gender",1,
      "add_money",500,
      "set_wc",17,
      "set_ac",15,
    }),
    2,1,"woman","obj/monster", ({
      "set_name","woman",
      "set_race", "human",
      "set_long","She is trying to haggle with the vendor for a good price.\n",
      "set_level",18,
      "set_gender",2,
      "add_money",240,
    }),
    -2,1,"sack","obj/container", ({
      "set_name","sack",
      "set_long","A handy sack.\n",
      "set_value",100,
      "set_weight",1,
      "set_max_weight",12,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
