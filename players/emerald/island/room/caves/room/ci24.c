inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="The eastern orc caves";

  long_desc="Tiny holes in the eastern wall permit sunlight to enter the "+
            "cave.  The sounds of birds and the sea filter through the "+
            "wall, making you long for fresh air.  To the north is an "+
            "old wooden stairway leading up.  The passage continues to the "+
            "south.\n";

  items=({"holes","They permit sunlight to enter the caves",
          "sunlight","Tiny beams of sunlight makes patterns on the floor",
          "cave","A cave inhabited by orcs",
          "birds","They sound quite happy",
          "sea","You can hear it roaring in the distance",
          "air","The air in here is rather foul",
          "stairway","You can hear grunting coming from up the stairs",
          "passage","It continues to the south",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci22","south",
             "/players/emerald/island/room/caves/room/ci25","up",
            });

  clone_list=({
    1,1,"guard","obj/monster",({
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
    -1,1,"axe","obj/weapon",({
      "set_name","axe",
      "set_long","A big steel axe for chopping wood.\n",
      "set_short","A steel axe",
      "set_weight",3,
      "set_class",13,
      "set_value",1500,
    }),
    -1,1,"jacket","obj/armour",({
      "set_name","dirty jacket",
      "set_alias","jacket",
      "set_short","A dirty leather jacket",
      "set_long","A dirty strong leather jacket.\n",
      "set_weight",2,
      "set_ac",3,
      "set_type","armour",
      "set_value",150,
    }),
    2,1,"warrior","obj/monster",({
      "set_name","orc warrior",
      "set_alt_name","warrior",
      "set_short","orc warrior",
      "set_race","orc",
      "set_long","A strong looking orc warrior.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",25,
      "set_al",-800,
      "add_money",300+random(50),
      "set_number_of_arms",2,
    }),
    -2,1,"axe","obj/weapon",({
      "set_name","war axe",
      "set_alias","axe",
      "set_short","A war axe",
      "set_long","A big iron axe, perfect for chopping off heads.\n",
      "set_weight",2,
      "set_class",16,
      "set_value",450,
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
    -2,1,"helmet","obj/armour",({
      "set_name","leather helmet",
      "set_short","A leather helmet",
      "set_alias","helmet",
      "set_long","A strong leather helmet.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","helmet",
      "set_value",120,
    }),
    -2,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
