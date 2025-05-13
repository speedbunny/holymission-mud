inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="On the garden path";
  long_desc="You are at the end of the path.  To the north is a hedge, " +
            "and to the south lies a beehouse.  There are bees all around " +
            "the apiary. It seems that the gardener is also a beekeeper.  " +
            "Maybe he gets the honey here for his master?\n";

  items=({"beehouse", "A big wooden beehouse",
          "apiary","The beehouse",
          "hedge","A thick hedge which keeps out the evil creatures",
          "path","It ends here",
        });

  dest_dir=({"/players/emerald/garden/garden4", "west",
           });


  clone_list=({
    1,3,"bee","obj/monster", ({
      "set_name","bee",
      "set_alias","bee",
      "set_short","A bee",
      "set_long","A normal honeybee.\n",
      "set_race","insect",
      "set_level",1,
      "set_hp",30,
      "set_wc",2,
      "set_ac",1,
      "add_money",20,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
