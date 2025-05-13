inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";
  long_desc="You are standing in waist-high waving grass.  The grassland " +
            "extends for quite some distance in all directions.  To the " +
            "north rise the snow-capped peaks of grey mountains.  The Ilkin " +
            "Forest is barely visible to the south.  West lies the " +
            "enchanted path which will allow you to pass safely through " +
            "the dangers of this plain.\n";

  dest_dir=({"/players/emerald/plain/p23","north",
             "/players/emerald/plain/p04","south",
             "/players/emerald/plain/p14","east",
             "/players/kryll/rooms/path/ep15","west",
             "/players/emerald/plain/p24","northeast",
             "/players/kryll/rooms/path/ep16","northwest",
             "/players/emerald/plain/p05","southeast",
             "/players/kryll/rooms/path/ep14","southwest",
           });

  items=({"grass","The golden stems are quite high",
          "grassland","A vast area grass waving in the breeze",
          "peaks","Tall grey peaks with a permanent snow cover",
          "mountains","Imposing mountains forming a barrier to the north",
          "forest","The rumours of evil from the Ilkin Forest are legendary",
          "path","Return to it if you wish to pass unhindered",
          "plain","A vast area of grass waving in the breeze",
        });

  clone_list=({
    1,1,"groundhog","obj/monster", ({
      "set_name","groundhog",
      "set_race","rodent",
      "set_short","A near-sighted groundhog",
      "set_long","A bumbling groundhog nibbling the grass.\n",
      "set_level",12,
      "add_money",60,
    }),
    -1,1,"claw","obj/weapon", ({
      "set_name","groundhog claw",
      "set_alias","claw",
      "set_short","A groundhog claw",
      "set_long","The sharp claw of a groundhog.\n",
      "set_wc",3,
      "set_weight",1,
      "set_value",30,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
