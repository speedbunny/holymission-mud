inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";


  long_desc="Palm trees surround you, continuing to the east with their "+
            "tall, swaying tops.  Soft white sand is warm under your "+
            "feet.  The island monkeys hoot and call among the trees, the "+
            "volcano rumbles, and a really odd sound can be heard from "+
            "somewhere to the east.\n";

  items=({"trees","Tall, swaying palm trees",
          "tops","The leafy tops sway in the breeze",
          "sand","Your feet sink slightly into the soft sand",
          "feet","Your feet are slowly sinking into the sand",
          "monkeys","The annoying island monkeys, running and playing",
          "volcano","The volcano is quite active",
        });

  dest_dir=({"/players/emerald/island/room/i9","east",
             "/players/emerald/island/room/i7","west",
             "/players/emerald/island/room/i4","south",
           });

  clone_list=({
    1,2,"monkey","obj/monster",({
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
