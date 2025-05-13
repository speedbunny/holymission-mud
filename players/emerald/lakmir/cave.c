inherit "room/room";

reset(arg) {

  set_light(1);

  short_desc="In a cave";

  long_desc="You have entered a large cave.  The walls are of dark grey " +
            "granite.  The air is a little stuffy, and the shadows along the "+
            "walls are quite thick, capable of concealing many evil and " +
            "nasty creatures.\n";

  dest_dir=({"/players/emerald/lakmir/valley","east",
           });

  items=({"cave","It has a sinister feeling",
          "walls","Smooth granite walls",
          "granite","The light seems to be absorbed by the dark stone",
          "shadows","They cloak the corners and nooks",
        });
  clone_list=({
    1,1,"snake","obj/monster", ({
      "set_name","snake",
      "set_alias","black snake",
      "set_short","A black snake",
      "set_long","A long python, darting with its tongue.\n",
      "set_race","reptile",
      "set_level",16,
      "set_hp",900,
      "set_al",-500,
      "set_wc",16,
      "set_ac",3,
      "set_size",2,
      "set_no_steal",1,
      "set_whimpy",-1,
    }),
    -1,1,"ruby","obj/treasure", ({
      "set_id","ruby",
      "set_short","A ruby",
      "set_long","A beautiful ruby. Worth selling!\n",
      "set_value",900,
      "set_weight",1,
    }),
    -1,1,"skin","obj/armour", ({
      "set_name","snake skin",
      "set_alias","skin",
      "set_short","A thick snake skin",
      "set_long","A thick, heavy snake skin.\n",
      "set_weight",4,
      "set_type","armour",
      "set_wc",4,
      "set_value",1500,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
