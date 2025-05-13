inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="Down a well";

  long_desc="You are down at the bottom of a dry and rather shallow " +
            "well.  A thin shaft of sunlight streams in from above you.  " +
            "You seem to have found the bucket for the rope, but something " +
            "beat you to it.\n";

  dest_dir=({"/players/emerald/country/5","out",
           });

  items=({"well","An old dry well with stone walls",
    });
  clone_list=({
    1,1,"dinosaur","obj/monster", ({
      "set_name","Purple dinosaur",
      "set_race","dinosaur",
      "set_alias","dinosaur",
      "set_long","He's big, he's purple, and he's got a really stupid\n" +
                 "grin on his face.\n",
      "set_level",25,
      "set_ac",15,
      "set_wc",15,
      "add_money",1000,
    }),
    -1,1,"bucket","players/emerald/quest/bucket2",0,
  });

  ::reset(arg);
  replace_program("room/room");

}
