inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A road through the farmland";

  long_desc="You begin to notice the change in elevation more here.  The " +
            "ground has also become slightly more rocky.  Pebbles and " +
            "stones slip and slide under you feet as you trudge along the " +
            "dusty road.  A few seem to have become lodged in your shoes.\n";

  dest_dir=({"/players/emerald/country/17","north",
             "/players/emerald/country/15","south",
           });

  items=({"stones","Irritating stones that have worked into your shoes",
          "pebbles","Smooth, worn stones sliding under your feet as you walk",
          "ground","It's what you walk on, usually",
          "road","A cobbled road",
        });

  clone_list=({
    1,1,"farmer","obj/monster", ({
      "set_name","farmer",
      "set_race","human",
      "set_long","An old, ornery-looking farmer.\n",
      "set_level",16,
      "set_gender",1,
    }),
    2,1,"donkey","obj/monster", ({
      "set_name","donkey",
      "set_long","An old, tired-looking donkey.\n",
      "set_race","donkey",
      "set_level",18,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
