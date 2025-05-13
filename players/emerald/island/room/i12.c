inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="The air is choked with ash particles here.  You can barely "+
            "see the paths that lead away from this place.  One leads "+
            "down to the west, where the air is clearer.  Two others lead "+
            "east and north, where the air becomes worse.\n";

  dest_dir=({"/players/emerald/island/room/i11", "down",
             "/players/emerald/island/room/i17", "north",
             "/players/emerald/island/room/i13", "east",
            });

  items=({"air","It is filled with ash",
          "paths","There are several paths leading away from here",
          "place","The atmosphere is rather unhealthy here",
        });

  clone_list=({
    1,1,"monkey","obj/monster",({
      "set_name","monkey",
      "set_level",12,
      "set_ac",2,
      "set_wc",6,
      "set_al",10,
      "set_race","animal",
      "set_short","A little monkey",
      "set_long","You see a cute brown-eyed island-monkey.\n",
      "set_whimpy",90,
    }),
    -1,1,"banana","/players/emerald/island/obj/banana",0,
    -1,1,"fur","obj/armour",({
      "set_name","fur",
      "set_alias","monkey fur",
      "set_type","cloak",
      "set_ac",1,
      "set_short","A monkey fur",
      "set_long","The protection of the little island-monkey.\n",
      "set_value",60,
      "set_weight",1,
    }),
    2,1,"native","obj/monster",({
      "set_name","native",
      "set_level",8,
      "set_ac",4,
      "set_al",-10,
      "set_whimpy",30,
      "set_race","human",
      "set_short","A native",
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
    -2,1,"spear","obj/weapon",({
      "set_name","spear",
      "set_class",10,
      "set_weight",1,
      "set_value",200,
      "set_alias","native spear",
      "set_short","A native spear",
      "set_long","The weapon of the natives from the volcanic island.\n",
      "set_type",2,
    }),
    -2,1,"jacket","obj/armour",({
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
