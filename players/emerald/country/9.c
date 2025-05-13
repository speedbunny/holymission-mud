inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the woods";

  long_desc="The ground begins to slope upwards to the southeast.  The " +
            "fields of grain brush up against more wooded land.  You find " +
            "this land to be an altogether pleasant place.\n";

  dest_dir=({"/players/emerald/country/8","northwest",
             "/players/emerald/country/10","southeast",
           });

  items=({"fields","Fields of barley and rye ripening in the sun",
        });

  clone_list=({
    1,1,"badger","obj/monster", ({
      "set_name","badger",
      "set_long","A vicious little badger.\n",
      "set_level",13,
      "set_wc",10,
      "set_ac",12,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
