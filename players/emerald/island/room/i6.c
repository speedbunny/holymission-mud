inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are standing in between two rows of palm trees.  White "+
            "sand  shifts under your feet.  The shrieking of monkeys "+
            "fills the air, drowning out the rumbles of the volcano.  A "+
            "huge black rock blocks the way north and west.\n";

  items=({"rows","Rows of palm trees",
          "trees","Really tall palm trees, loaded with coconuts",
          "sand","Soft, warm sand under your feet",
          "feet","Long flat appendages at the ends of your legs",
          "air","The air is clear here",
          "volcano","You are on a volcanic island",
          "rock","A really huge black rock",
        });

  dest_dir=({"/players/emerald/island/room/i5","up",
             "/players/emerald/island/room/i2","south",
             "/players/emerald/island/room/i7","east",
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
    2,1,"tree","/players/emerald/island/obj/tree",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
