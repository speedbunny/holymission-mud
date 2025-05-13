inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="A large black rock blocks the expansion of the beach further "+
            "to the east.  A few palm trees grow to the north, their leafy "+
            "tops swaying in the breeze.  The warm sun shines down, making "+
            "this a really pleasant place, except for the eternal rumbles "+
            "of the volcano.\n";

  items=({"rock","A big black rock",
          "trees","Really tall palm trees",
          "beach","A soft, sandy beach",
          "tops","The crown of palm fronds sways in the breeze",
          "breeze","A small breeze, lightly brushing the palm trees",
          "sun","A large sphere of burning gas, providing light and heat "+
                "to this world",
          "volcano","Yes, this island is volcanic.  Very astute of you",
        });

  dest_dir=({"/players/emerald/island/room/i1", "southwest",
             "/players/emerald/island/room/i8", "north",
             "/players/emerald/island/room/i3", "west",
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
    -1,1,"banana","/players/emerald/island/obj/banana",0,
  });

  ::reset(arg);
  replace_program("/room/room");
  
}
