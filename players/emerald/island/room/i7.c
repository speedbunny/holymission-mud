inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="Rows of palm trees sway in the breeze.  They are growing out "+
            "of the sand to incredible heights.  A huge black rock sits "+
            "to the north, while the beach and the sea lie to the south.  "+
            "Amidst the rumblings of the volcano can be heard the shrieks "+
            "of monkeys.\n";

  items=({"rows","Rows and rows of tall palm trees",
          "trees","Palm trees swaying in the breeze",
          "sand","Soft white sand",
          "rock","An enormous black rock",
          "beach","The broad sandy beach of the island",
          "sea","The clear blue sea",
          "volcano","It eternally rumbles and belches out ash",
          "monkeys","The island monkeys, gathering bananas",
        });

  dest_dir=({"/players/emerald/island/room/i3","south",
             "/players/emerald/island/room/i8","east",
             "/players/emerald/island/room/i6","west",
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
      "set_long","You see a cute brown-eyed island monkey.\n",
      "set_whimpy",90,
    }),
    -1,1,"banana","/players/emerald/island/obj/banana",0,
    -1,1,"fur","obj/armour",({
      "set_name","fur",
      "set_alias","monkey fur",
      "set_type","cloak",
      "set_ac",1,
      "set_size",2,
      "set_short","A monkey fur",
      "set_long","The protection of the little island monkey.\n",
      "set_value",60,
      "set_weight",1,
    }),
    2,1,"tree","/players/emerald/island/obj/tree",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
