inherit "room/room";

reset(arg) {

  set_light(1);

  long_desc="You have entered a peaceful and serene valley.  A tall mountain "+
            "rises to the north, forming the end of the valley.  To the west "+
            "a forest begins, while to the east the valley seems to drop " +
            "off a bit.\n";
         
  short_desc="The peaceful valley";

  dest_dir=({"players/emerald/good/light/light2","south",
             "players/emerald/good/light/light10","west",
             "players/emerald/good/light/light11","north",
             "players/emerald/good/light/light9","east"
           });

  items=({"fields","The fields are beautiful",
          "forest","It seems rather open",
          "valley","A long and narrow valley",
          "view","One field after another another",
          "horizon","It is still some distance away",
        });

  clone_list=({
    1,1,"dog","obj/monster", ({
      "set_name", "lab",
      "set_alias", "black lab",
      "set_race", "dog",
      "set_long","A playful black dog.\n",
      "set_level", 5,
      "set_hp", 140,
      "set_al", 310,
      "set_short", "A playful black lab",
      "set_ac", 3,
      "set_wc", 10,
    }),
    -1,1,"stone","obj/treasure", ({
      "set_name","ruby",
      "set_alias", "gem",
      "set_short", "A small ruby",
      "set_weight", 2,
      "set_value", 400,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
