inherit "room/room";

reset(arg) {

  set_light(1);

  short_desc="The top of a hill";
  long_desc="You have climbed to the top of a hill.  It is quite rocky and " +
            "craggy up here, providing a perfect nesting site for an " +
            "eagle.  The hill commands a spectacular view of the valley " +
            "and forest below.  Far off to the east, you can see the " +
            "sparkling blue waters of the bay.\n";

  dest_dir=({"/players/emerald/lakmir/hillside2","down"
           });

  items=({"hill","A bump in the landscape",
          "site","A flat ledge for an eagle to nest",
          "valley","A dip in the landscape",
          "forest","A dark forest of ancient oak trees",
          "waters","They glisten in the sunlight",
          "bay","A shallow bay",
        });

  clone_list=({
    1,1,"eagle","obj/monster", ({
      "set_name","eagle",
      "set_short","An eagle",
      "set_long","The eagle glares at you.\n",
      "set_race","bird",
      "set_gender",2,
      "set_level",25,
      "set_al",200,
      "set_wc",18,
      "set_ac",8,
     }),
  });

  ::reset();
  replace_program("/room/room");

}

