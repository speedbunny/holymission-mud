inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On a prairie";

  long_desc="The tall peaks of mountains surround this open prairie.  "+
            "Far off to the north is a dark forest, while off to the "+
            "south appears to be a way into the volcano.  A huge cloud of "+
            "yellow vapour hangs in the air above the green grass.\n";

  items=({"peaks","The rounded peaks of volcanic mountains",
          "mountains","Volcanic mountains",
          "prairie","Grasses and shrubs grow in the rich soil",
          "forest","It lies off in the distance",
          "volcano","To the south is an opening into the volcano itself",
          "cloud","A cloud of yellow volcano gasses",
          "vapour","Yellow volcano gasses",
          "air","The air is almost pure up here",
          "grass","The grass is lush and thick",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/p2","west",
             "/players/emerald/island/room/caves/room/p4","east",
             "/players/emerald/island/room/caves/room/p7","north",
             "/players/emerald/island/room/caves/room/p1","south",
           });

  clone_list=({
    1,2,"watchman","obj/monster",({
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
