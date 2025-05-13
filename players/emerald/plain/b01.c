inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The end of the beach";


  long_desc="You have reached the southernmost portion of this stretch of " +
            "seacoast.  A river emerges from the forest to meet with the " +
            "sea, flowing quickly into the breaking waves.  To the west " +
            "the Ilkin forest hides the rest of the river within its " +
            "dark branches.  The soft sand beach is littered with pebbles " +
            "and shells.\n";

  dest_dir=({"/players/emerald/plain/b03","north",
             "/players/emerald/plain/b02","northwest",
           });


  items=({"seacoast","The merger of land and water",
          "river","The mouth of the river of Ilkin Forest",
          "forest","The dark and thick Ilkin Forest",
          "sea","A shining blue sea with white-capped waves",
          "waves","They roll to the shore in endless succession",
          "branches","They are too thick at this point to penetrate",
          "beach","It is smooth and flat",
          "pebbles","Small, round, water-rolled stones in many colours",
          "shells","They are of different shapes and sizes",
        });

  clone_list=({
    1,1,"crab","obj/monster", ({
      "set_name","horseshoe crab",
      "set_alias","crab",
      "set_race","crab",
      "set_short","A dark brown horseshoe crab",
      "set_level",5,
      "set_ac",7,
      "add_money",15,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
