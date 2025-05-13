inherit "/room/room";
void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="At the eastern end of a huge chamber";

  long_desc="You are standing at the eastern end of a huge chamber.  The  "+
            "centre can be seen to the west.  Giant stone monoliths stand "+
            "all around you.  Shadows dart in and behind the monoliths.  "+
            "The wall to the east is covered in blood.\n";

  items=({"end","The eastern end of a huge chamber",
          "chamber","A large chamber in the secret orc caves",
          "center","It lies to the west",
          "monoliths","Towering pillars of stone",
          "shadows","They move furtively through the chamber",
          "wall","The eastern wall is covered in blood",
          "blood","Fresh red blood stains the wall",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci36","west",
           });

  clone_list=({
    1,1,"warrior","obj/monster",({
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
    -1,1,"axe","obj/weapon",({
      "set_name","war axe",
      "set_alias","axe",
      "set_short","A war axe",
      "set_long","A big iron axe, perfect for chopping off heads.\n",
      "set_weight",2,
      "set_class",16,
      "set_value",450,
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
    -1,1,"helmet","obj/armour",({
      "set_name","leather helmet",
      "set_short","A leather helmet",
      "set_alias","helmet",
      "set_long","A strong leather helmet.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","helmet",
      "set_value",120,
    }),
    -1,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
    2,1,"female","obj/monster",({
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
    -2,1,"dagger","obj/weapon",({
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
