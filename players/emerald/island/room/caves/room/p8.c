inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On a prairie";

  long_desc="A cloud of yellow vapour hangs in the sky over a small "+
            "prairie of thick grass and small shrubs.  To the north begins "+
            "a dark forest which send a wave of fear flowing out over the "+
            "prairie.  The rounded peaks of volcanic mountains ring the "+
            "prairie.\n";

  items=({"cloud","A cloud of yellow volcano gasses",
          "vapour","Yellow volcano gasses",
          "sky","The sky is almost clear here",
          "prairie","A small prairie on the plateau of the volcano",
          "grass","Lush green grass",
          "shrubs","Succulent green shrubs",
          "forest","Sunlight cannot penetrate its canopy",
          "peaks","Tall, dark mountain peaks",
          "mountains","Old volcanic mountains",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/p9","east",
             "/players/emerald/island/room/caves/room/p7","west",
             "/players/emerald/island/room/caves/room/p4","south",
             "/players/emerald/island/room/caves/room/f4","north",
           });

  clone_list=({
    1,3,"watchman","obj/monster",({
      "set_name","orc watchman",
      "set_alt_name","watchman",
      "set_short","An orc watchman",
      "set_race","orc",
      "set_long","An orc watchman looking around for victims.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",7,
      "set_whimpy",20,
      "set_al",-400,
      "add_money",150+random(50),
    }),
    -1,1,"dagger","obj/weapon",({
      "set_name","stone dagger",
      "set_alias","dagger",
      "set_long","A small dagger made of obsidian.\n",
      "set_weight",1,
      "set_short","An obsidian dagger",
      "set_class",8,
      "set_type",1,
      "set_value",60,
    }),       
  });

  ::reset(arg);
  replace_program("/room/room");

}
