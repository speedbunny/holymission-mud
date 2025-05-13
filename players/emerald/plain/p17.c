inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";
  long_desc="Waves of billowing grass spread out in all directions.  To " +
            "the north they are halted by high grey mountains which loom " +
            "against the horizon.  The ancient trees of the dark Ilkin " +
            "Forest cut them off to the south.  High above, a lone cloud " +
            "scoots across the intense azure sky.\n";

  dest_dir=({"/players/emerald/plain/p27","north",
             "/players/emerald/plain/p08","south",
             "/players/emerald/plain/p18","east",
             "/players/emerald/plain/p16","west",
             "/players/emerald/plain/p28","northeast",
             "/players/emerald/plain/p26","northwest",
             "/players/emerald/plain/p09","southeast",
             "/players/emerald/plain/p07","southwest",
           });

  items=({"waves","The grass bends in waves",
          "grass","Long stems of golden grass",
          "mountains","Silent, forboding mountains forming the northern " +
                      "boundary",
          "trees","Tall dark trees whose branches are unaffected by the " +
                  "breeze",
          "cloud","A small puffy white cloud",
          "sky","It is an intense blue that you have never seen before",
        });

  clone_list=({
    1,1,"calf","obj/monster", ({
      "set_name","buffalo calf",
      "set_alias","calf",
      "set_alt_name","buffalo",
      "set_level",10,
      "set_short","A half-grown buffalo calf",
      "set_long","A staring buffalo calf.\n",
      "add_money",75,
    }),
    -1,1,"hide","obj/armour", ({
      "set_name","hide",
      "set_short","A thick calf hide",
      "set_ac",3,
      "set_value",200,
      "set_weight",2,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
