inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the orc nursery";

  long_desc="This chamber is very warm and snug.  Thick curtains hang on "+
            "the walls to prevent drafts and chills.  Small pallets of "+
            "warm blankets are lined up against the walls.  What appears "+
            "to be baby bottles are placed next to each pallet.  But the "+
            "liquid inside them isn't milk, it's blood.\n";
  dest_dir=({"/players/emerald/island/room/caves/room/ci26","east",
           });

  items=({"chamber","The orc nursery",
          "curtains","Thick curtains to keep out the chill",
          "walls","Cold stone walls",
          "pallets","Just big enough for an orc baby",
          "blankets","Thick, dirty woolen blankets",
          "bottles","Baby bottles filled with blood",
          "liquid","Fresh red blood",
          "milk","The orc babies feed on blood, not milk",
          "blood","Nice, fresh warm blood",
        });

  clone_list=({
    1,3,"baby","/obj/monster",({
      "set_name","orc baby",
      "set_alt_name","baby",
      "set_short","A baby orc",
      "set_race","orc",
      "set_long","An orc baby.\n",
      "set_gender",1+random(2),
      "set_level",1,
      "set_whimpy",2,
      "set_al",-10,
    }),
    2,2,"guard","obj/monster",({
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
    3,1,"warrior","obj/monster",({
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
    -3,1,"axe","obj/weapon",({
      "set_name","war axe",
      "set_alias","axe",
      "set_short","A war axe",
      "set_long","A big iron axe, perfect for chopping off heads.\n",
      "set_weight",2,
      "set_class",16,
      "set_value",450,
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
    -3,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
    4,3,"female","obj/monster",({
      "set_name","female orc",
      "set_alt_name","female",
      "set_short","An orc female",
      "set_race","orc",
      "set_long","An orc female feeding her baby.\n",
      "set_gender",2,
      "set_aggressive",1,
      "set_level",6,
      "set_whimpy",20,
      "set_al",-100,
      "add_money",200+random(50),
    }),
    -4,1,"dagger","obj/weapon",({
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
