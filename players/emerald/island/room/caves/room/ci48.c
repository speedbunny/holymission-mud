inherit "/room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="In a big hall";

  long_desc="This is the end of the secret orc caves.  An enormous wooden "+
            "table and ornately carved chair are the only furnishings "+
            "present.  A large fire glows against the wall.  You get the "+
            "feeling that important orc meetings take place here.\n";

  items=({"end","The end",
          "caves","The secret orc caves",
          "table","A huge wooden table, with deep gouges",
          "table","It contains gruesome carvings of war",
          "fire","It is set in a brazier next to the wall",
          "wall","It is blackened with soot",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci47","south",
           });

  clone_list=({
    1,1,"elder","obj/monster",({
      "set_name","elder orc",
      "set_alt_name","elder",
      "set_short","Elder orc",
      "set_race","orc",
      "set_long","A strong, wise-looking orc.\n",
      "set_gender",1+random(1),
      "set_aggressive",1,
      "set_level",50,
      "set_number_of_arms",3,
    }),
    -1,1,"ring","/players/emerald/island/room/caves/obj/ring",0,
    -1,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
    -1,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
    2,1,"shaman","/players/emerald/island/room/caves/obj/cshaman",0,
    -2,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
    -2,1,"bracelet","/players/whisky/obj/ruby_bracelet",0,
    -2,1,"robe","obj/armour",({
      "set_name","black robe",
      "set_alias","robe",
      "set_short","A black robe",
      "set_long","A long, black robe.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","cloak",
      "set_value",75,
    }),
    3,1,"chieftain","obj/monster",({
      "set_name","orc chieftain",
      "set_alt_name","chieftain",
      "set_short","An orc chieftain",
      "set_race","orc",
      "set_long","A strong looking orc warrior.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",35,
      "set_al",-800,
      "add_money",2000+random(50),
      "set_number_of_arms",3,
    }),
    -3,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
    -3,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
    -3,1,"helmet","obj/armour",({
      "set_name","leather helmet",
      "set_short","A leather helmet",
      "set_alias","helmet",
      "set_long","A strong leather helmet.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","helmet",
      "set_value",120,
    }),
    -3,1,"jacket","obj/armour",({
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
