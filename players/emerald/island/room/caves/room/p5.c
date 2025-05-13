inherit "/room/room";
void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On a prairie";

  long_desc="Mountain peaks surround the open prairie.  Grass and shrubs "+
            "grow densly in the rich volcanic soil.  To the north lies "+
            "a dark forest, with thick intertwining branches which block "+
            "block the sunlight from entering it.  A large cloud of yellow "+
            "vapour lingers overhead.\n";

  items=({"peaks","The peaks of volcanic mountains",
          "grass","Lush green grass",
          "shrubs","Bushy shrubs, good grazing for animals",
          "soil","Nutrient-rich volcanic soil",
          "forest","It looks rather forboding",
          "branches","They intertwine to form a dense canopy",
          "prairie","A grassy prairie on the volcano",
          "sunlight","It cannot enter the forest",
          "cloud","A cloud of yellow volcano gasses",
          "vapour","Yellow volcano gasses",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/p6","east",
             "/players/emerald/island/room/caves/room/p2","southeast",
             "/players/emerald/island/room/caves/room/f1","north",
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
