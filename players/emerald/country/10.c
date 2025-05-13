inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the woods";

  long_desc="You are climbing a little hill.  There are trees growing on " +
            "both sides of road.  The dappled shade they give is a pleasant " +
            "relief from the heat of the noonday sun.  From somewhere " +
            "beyond the treeline you can hear the rushing of water.\n";

  dest_dir=({"/players/emerald/country/9","northwest",
             "/players/emerald/country/11","southeast",
           });

  items=({"trees","Willows and aspen",
          "hill","A small hill",
          "road","A cobbled road",
          "shade","It is pleasant after the heat of the sun",
        });

  clone_list=({
    1,1,"deer","obj/monster", ({
      "set_name","deer",
      "set_short","A deer",
      "set_long","A frightened deer hiding under the trees.\n",
      "set_level",24,
      "set_wc",13,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
