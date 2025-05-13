inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="The eastern orc caves";

  long_desc="You are sneaking through the secret orc caves.  The passage "+
            "leads further to the north and west.  Noises filter down from "+
            "the north.  In the eastern wall there are tiny holes which "+
            "permit light to enter.  You can hear the chirping of birds "+
            "and the singing of the sea through the holes.\n";

  items=({"caves","The secret orc caves.  You aren't supposed to be here",
          "passage","It is dark and rancid",
          "wall","There are tiny holes in the wall",
          "holes","They permit outside light and sound to enter the caves",
          "light","Tiny beams of sunlight",
          "birds","They sound free and happy",
          "sea","You can hear its song through the holes",
        });
      
  dest_dir=({"/players/emerald/island/room/caves/room/ci20","north",
             "/players/emerald/island/room/caves/room/ci18","west",
           });

  clone_list=({
    1,1,"boy","obj/monster",({
      "set_name","orc boy",
      "set_alt_name","boy",
      "set_short","A busy orc boy",
      "set_race","orc",
      "set_long","An orc kitchen helper.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",5,
      "set_al",-100,
      "add_money",80+random(50),
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
    2,1,"guard","obj/monster",({
      "set_name","orc guard",
      "set_alt_name","guard",
      "set_short","An orc guard",
      "set_race","orc",
      "set_long","An orc guard protecting the cave.\n",
      "set_gender",1+random(1),
      "set_aggressive",1,
      "set_level",15,
      "set_al",-800,
      "add_money",800+random(50),
      "set_number_of_arms",2,
    }),
    -2,1,"axe","obj/weapon",({
      "set_name","axe",
      "set_long","A big steel axe for chopping wood.\n",
      "set_short","A steel axe",
      "set_weight",3,
      "set_class",13,
      "set_value",1500,
    }),
    -2,1,"jacket","obj/armour",({
      "set_name","dirty jacket",
      "set_alias","jacket",
      "set_short","A dirty leather jacket",
      "set_long","A dirty strong leather jacket.\n",
      "set_weight",2,
      "set_ac",3,
      "set_type","armour",
      "set_value",150,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");
}
