inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="At the northern end of a huge chamber";

  long_desc="This is the northern end of the huge chamber.  To the south "+
            "stand giant stone monoliths.  Shadows weave between them.  A "+
            "dark hallway leads off to the north.\n";

  items=({"end","The northern end of a vast chamber",
          "chamber","A large chamber, filled with shadows and monoliths",
          "monoliths","Tall pillars of black stone",
          "shadows","They move quickly to and from the monoliths",
          "hallway","It leads further to the north",
        });
      
  dest_dir=({"/players/emerald/island/room/caves/room/ci36","south",
             "/players/emerald/island/room/caves/room/ci40","north",
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
    2,1,"troll","obj/monster",({
      "set_name","troll cave guard",
      "set_alt_name","guard",
      "set_short","troll cave guard",
      "set_race","troll",
      "set_long","The troll cave guard is enormously strong and towers about "+
                 "20 feet over your head.  The length of its body seems to "+
                 "be nothing but rippling muscles.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",30,
      "set_al",-1200,
      "add_money",500+random(50),
    }),
    -2,1,"club","obj/weapon", ({
      "set_name","wooden club",
      "set_alias","club",
      "set_short","A spiked, wooden club",
      "set_long","A heavy, spiked wooden club.\n",
      "set_weight",2,
      "set_class",16,
      "set_type",1,
      "set_value",2000,
    }),
    3,1,"ugh","obj/monster",({
      "set_name","orc guard",
      "set_alt_name","guard",
      "set_short","An orc guard",
      "set_race","orc",
      "set_long","An orc guard protecting the cave.\n",
      "set_alias","ugh",
      "set_gender",1+random(1),
      "set_aggressive",1,
      "set_level",15,
      "set_al",-800,
      "add_money",800+random(50),
      "set_number_of_arms",2,
    }),
    -3,1,"axe","obj/weapon",({
      "set_name","axe",
      "set_long","A big steel axe for chopping wood.\n",
      "set_short","A steel axe",
      "set_weight",3,
      "set_class",13,
      "set_value",1500,
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
