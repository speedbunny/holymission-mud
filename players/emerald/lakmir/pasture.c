inherit "room/room";

reset(arg) {

  set_light(1);

  short_desc="A pasture";

  long_desc="Lying in between the forest and the meadow is a small " +
            "pasture, just big enough for a few bovines.  The grass is " +
            "closely cropped by the passing of their teeth.  Clumps of " +
            "thistles and other inedible plants are dotted throughout the " +
            "pasture.  You take care not to step in the small brown lumps " +
            "which also lurk in the pasture.\n";

  dest_dir=({"/players/emerald/lakmir/meadow1","east",
             "/players/emerald/lakmir/path3","north",
             "/players/emerald/lakmir/forest1","west",
           });

  items=({"forest","The dark forest of the Druid Lakmir",
          "meadow","A blooming meadow",
          "pasture","A field of grass",
          "grass","It is quite short",
          "bovines","A few cows, perhaps a bull",
          "thistles","Tall knots of plants with painful leaves and lavender " +
                     "flowers",
          "plants","The cows have not eaten them",
          "lumps","Dung",
        });

  clone_list=({
    1,2,"cow","obj/monster", ({
      "set_name","brown cow",
      "set_short","A brown cow",
      "set_alias","cow",
      "set_long","A brown cow chewing her cud.\n",
      "set_gender",2,
      "set_level",13,
      "set_race","bovine",
    }),
    2,1,"bull","obj/monster", ({
      "set_name","bull",
      "set_short","A big and aggressive bull",
      "set_long","The bull guards his cows!\n",
      "set_level",17,
      "set_wc",10,
      "set_ac",9,
      "set_aggressive",1,
      "set_gender",1,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
