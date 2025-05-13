inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are standing on the beautiful beach of the island.  The "+
            "sun is shining and the waves lap gently against the sand.  "+
            "A few large bushes grow to the west.  They seem to be shaking, "+
            "which is strange, since there isn't a breeze to move them.\n";

  items=({"beach","A long, sandy beach",
          "island","A volcanic island",
          "sun","The sun shines down rather strongly on the beach",
          "waves","Tiny blue waves",
          "sand","The sand is soft and warm from the sun",
          "bushes","Tall, thick bushes",
        });

  dest_dir=({"/players/emerald/island/room/i25", "east",
             "/players/emerald/island/room/i9", "west",
           });

  clone_list=({
    1,3,"native","obj/monster",({
      "set_name","native",
      "set_level",8,
      "set_ac",4,
      "set_al",-10,
      "set_whimpy",30,
      "set_race","human",
      "set_short","A native",
      "set_long","An aggressive looking native.\n",
      "set_gender",1,
      "set_ac",4,
      "set_aggressive",1,
    }),
    -1,1,"spear","obj/weapon",({
      "set_name","spear",
      "set_class",10,
      "set_weight",1,
      "set_value",200,
      "set_alias","native spear",
      "set_short","A native spear",
      "set_long","The weapon of the natives from the volcanic island.\n",
      "set_type",2,
    }),
    -1,1,"jacket","obj/armour",({
      "set_name","jacket",
      "set_alias","native jacket",
      "set_short","A native's jacket",
      "set_long","A small but strong monkey-fur jacket.\n",
      "set_type","armour",
      "set_ac",2,
      "set_weight",2,
      "set_value",80,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
