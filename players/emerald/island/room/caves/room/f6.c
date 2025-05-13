inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In a dark mixed forest";
  long_desc="The wind causes the tree branches to groan and creak as "+
            "they bend and wave past one another.  Strange shadows are "+
            "visible on the ground, shadows which cause you to jump in "+
            "fear.  To the east of you is the sound of running water, and "+
            "off in the distance you can hear the rumbling of the volcano.\n";

  items=({"wind","It moans through the trees",
          "branches","They rub against each other, making alarming noises",
          "shadows","Frightening shadows on the ground",
          "ground","It is covered with rotting vegetation",
          "water","There must be a spring nearby",
          "volcano","It rumbles under your feet",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/f9","northeast",
             "/players/emerald/island/room/caves/room/f7","east",
             "/players/emerald/island/room/caves/room/f2","south",
           });

  clone_list=({
    1,3,"hunter","obj/monster",({
      "set_name","orc hunter",
      "set_alt_name","hunter",
      "set_short","An orc hunter",
      "set_race","orc",
      "set_long","A hungry orc hunting animals.\n",
      "set_gender",1+random(1),
      "set_aggressive",1,
      "set_level",11,
      "set_whimpy",10,
      "set_al",-400,
      "add_money",300+random(50),
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
    2,6,"guard","obj/monster",({
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
