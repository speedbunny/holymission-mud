inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";
  long_desc="Waving grass surrounds you on all sides.  Only the landmarks " +
            "provided by the high peaks of the cold, silent mountains to " +
            "the north and the dark treeline of the Ilkin Forest to the " +
            "south keep you from getting lost.  A small patch of clover " +
            "shows evidence of recent nibbling.\n";

  dest_dir=({"/players/emerald/plain/p24","north",
             "/players/emerald/plain/p05","south",
             "/players/emerald/plain/p15","east",
             "/players/emerald/plain/p13","west",
             "/players/emerald/plain/p25","northeast",
             "/players/emerald/plain/p23","northwest",
             "/players/emerald/plain/p06","southeast",
             "/players/emerald/plain/p04","southwest",
           });

  items=({"grass","It glints gold in the sunlight",
          "landmarks","They provide orientation in this otherwise endless " +
                      "sea of grass",
          "peaks","The pinnacles of the mountain range",
          "mountains","They form the northern boundary to the plain",
          "treeline","It is the southern boundary of the plain",
          "forest","A place off evil repute",
          "clover","The leaves show traces of dainty nibbling",
        });

  clone_list=({
    1,1,"rabbit","obj/monster", ({
      "set_name","rabbit",
      "set_race","mammal",
      "set_short","A brown rabbit",
      "set_long","A wide-eyed and nervous brown rabbit.\n",
      "set_level",11,
      "add_money",50,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
