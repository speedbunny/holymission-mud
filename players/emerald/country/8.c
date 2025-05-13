inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the woods";

  long_desc="You are following the main road.  It is winding through the " +
            "settled lands of the farmer's fields towards a wooded hill.  " +
            "The sun is high overhead and you find yourself seeking some " +
            "shade to provide a bit of relief.\n";

  dest_dir=({"/players/emerald/country/7","northwest",
             "/players/emerald/country/9","southeast",
           });

  items=({"fields","Fields of barley and rye ripening in the sun",
          "sun","Looking at the sun is bad for your eyes",
          "hill","A small hill",
          "road","A stone cobbled road",
        });

  clone_list=({
    1,3,"fox","obj/monster", ({
      "set_name","fox",
      "set_long","A rather nasty little fox.\n",
      "set_level",12,
      "set_aggressive",1,
      "add_money",240,
      "set_wc",14,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
