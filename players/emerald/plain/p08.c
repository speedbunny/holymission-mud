inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The edge of a grassy plain",

  long_desc="You are in a grassy plain which borders the northern edge " +
            "of the Ilkin Forest.  Long stems of golden grass wave and " +
            "bend in the slight breeze.  The mountains to the north " +
            "look cold and silent from this distance.\n";

  dest_dir=({"/players/emerald/plain/p17","north",
             "/players/emerald/plain/p09","east",
             "/players/emerald/plain/p07","west",
             "/players/emerald/plain/p18","northeast",
             "/players/emerald/plain/p16","northwest",
           });

  items=({"plain","A large flat grassland",
          "forest","The evil, dark Ilkin Forest.  It is much too thick to " +
                   "enter here",
          "stems","Long golden stems of ripe grass",
          "grass","It bends in the breeze",
          "mountains","Cold grey maountains",
        });

  clone_list=({
    1,1,"fox","obj/monster", ({
      "set_name","red fox",
      "set_race","mammal",
      "set_short","A red fox",
      "set_long","A wary red fox.\n",
      "set_alias","fox",
      "set_aggressive",1,
      "set_level",13,
      "add_money",150,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
