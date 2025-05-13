inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The main street in town";

  long_desc="The crowds of people are still thick in this section of " +
            "the street.  It looks as though the vendors haven't become " +
            "any nicer either.  Arguments over price and quality look like " +
            "they might errupt at any time into a full-blown fight.\n";

  dest_dir=({"/players/emerald/town/t6","north",
             "/players/emerald/town/t1","south",
           });

  items=({"street","You can't really see it through the crowd",
          "crowds","Lots and lots of people eager for the vendors' wares",
        });

  clone_list=({
    1,3,"vendor","obj/monster", ({
      "set_name","vendor",
      "set_long","A greedy vendor selling less than quality items.\n",
      "set_race","human",
      "set_level",25,
      "set_gender",1,
      "add_money",500,
      "set_wc",17,
      "set_ac",15,
    }),
    2,1,"man","obj/monster", ({
      "set_name","man",
      "set_race", "human",
      "set_long","This man is getting very angry with a pesky vendor.\n",
      "set_level",25,
      "set_gender",1,
      "add_money",240,
    }),
    -2,1,"cloak","obj/armour", ({
      "set_name","cloak",
      "set_short","A cloak",
      "set_value",350,
      "set_long","A thick wool cloak.\n",
      "set_weight",1,
      "set_ac",2,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
