inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On a prairie";

  long_desc="Thick grass and bushy shrubs grow on this small prairie.  "+
            "Ringing the prairie sky are the peaks of mountains.  An immense "+
            "cloud of yellow vapour hangs in the sky.  To the north, the "+
            "prairie becomes a thick forest of dark trees.\n";

  items=({"grass","Lush green grass",
          "shrubs","Their leaves have been nibbled on",
          "prairie","A small prairie on the volcano",
          "peaks","The rounded peaks of volcanic mountains",
          "mountains","Volcanic mountains",
          "cloud","A thick cloud of yellow volcano gasses",
          "vapour","Yellow volcano gasses",
          "sky","The sky is almost clear here",
          "forest","It is dark and emits a chilling fear",
          "trees","Dark, gnarled oaks and fir",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/p8","west",
             "/players/emerald/island/room/caves/room/p4","southwest",
             "/players/emerald/island/room/caves/room/f5","north",
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
