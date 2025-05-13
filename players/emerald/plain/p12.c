inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The edge of the plains";

  long_desc="Shrubs have taken over from the grass here at the edge of " +
            "of the Ilkin Forest.  The trees are close and thick; their " +
            "dark green foliage forming a barrier running northeast " +
            "and south from here.  To the north, the high peaks of the " +
            "mountains cut the horizon into sections.\n";

  dest_dir=({"/players/emerald/plain/p21","north",
             "/players/emerald/plain/p22","northeast",
             "/players/emerald/plain/p11","west",
             "/players/emerald/plain/p20","northwest",
           });

  items=({"shrubs","Roses and hazlenut bushes",
          "grass","Long stemmed grass",
          "forest","The trees are quite tall, with dense branches",
          "foliage","Leaves in various shades of green",
          "peaks","Snow-capped peaks outlines against the sky",
          "mountains","The tower above you to the north",
        });

  clone_list=({
    1,1,"deer","obj/monster", ({
      "set_name","deer",
      "set_race","ruminant",
      "set_short","A grazing deer",
      "set_long","A brown deer grazing on the shrubs.\n",
      "set_level",16,
      "add_money",100,
    }),
    -1,1,"antler","obj/weapon", ({
      "set_name","antler",
      "set_wc",5,
      "set_weight",1,
      "set_value",150,
      "set_long","A long-tined antler.\n",
    }),
    -1,1,"skin","obj/armour", ({
      "set_name","Deer skin",
      "set_ac",2,
      "set_weight",2,
      "set_value",200,
      "set_short","A heavy deer skin",
      "set_alias","skin",
    }),
  });

  ::reset();
  replace_program("/room/room");

}
