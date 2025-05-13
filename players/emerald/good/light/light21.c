inherit "/room/room";

reset(arg) {

  set_light(1);

  long_desc="A rather large bull elk can be found here sometimes.  He is " +
            "usually occupying himself munching on the grass, or trying " +
            "to find a cow to mate with.\n";

  short_desc="The home of the elk";

  dest_dir=({"players/emerald/good/light/light20","south",
           });

  items=({"grass","Succulent green grass, perfect food for an elk",
        });

  clone_list=({
    1,1,"bull","obj/monster", ({
      "set_name", "bull elk",
      "set_alias", "bull",
      "set_race", "elk",
      "set_level", 17,
      "set_al", 900,
      "set_short", "A large bull elk",
      "set_long","This bull is a monster. On his head are a set of " +
                 "perfectly shaped antlers.\n",
      "set_ac", 10,
      "set_wc", 18,
    }),
    -1,1,"antlers","obj/weapon", ({
      "set_name", "antlers",
      "set_alias", "horns",
      "set_short", "A large set of elk antlers",
      "set_long","These are the finest set of antlers around.\n",
      "set_class",10,
      "set_value", 2200,
      "set_weight", 3,
    }),
    2,3,"cow","obj/monster", ({
      "set_name", "cow elk",
      "set_alias", "cow",
      "set_race", "elk",
      "set_level", random(9) + 2,
      "set_al", 400,
      "set_short", "A cow elk",
      "set_ac", 5,
      "set_wc", 11,
    }),  
    -2,1,"horn","obj/treasure", ({
      "set_name","tooth",
      "set_alias", "elk's tooth",
      "set_short", "An elk's tooth",
      "set_long", "An elk's tooth, pure ivory.\n",
      "set_weight", 2,
      "set_value", random(400) + 50,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
