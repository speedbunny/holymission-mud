inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="At the western end of a huge chamber";

  long_desc="You are standing at the western end of a huge chamber.  The "+
            "centre can be seen to the east.  Huge stone monoliths stand "+
            "around you.  Shadows move behind them.  To the west, the "+
            "stone wall is covered with spots of blood.\n";

  items=({"end","The western end of the chamber",
          "chamber","An immense chamber filled with shadows and monoliths",
          "centre","It lies to the east",
          "monoliths","Towering stone monoliths",
          "shadows","They move behind the monoliths",
          "wall","It is covered with splashes of blood",
          "spots","Fresh spots of blood",
          "blood","Fresh, red blood",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci36","east",
           });

  clone_list=({
    1,2,"peasant","obj/monster",({
      "set_name","orc peasant",
      "set_alt_name","peasant",
      "set_short","An orc peasant",
      "set_race","orc",
      "set_long","A harmless looking orc.\n",
      "set_gender",1+random(1),
      "set_aggressive",1,
      "set_level",3,
      "set_whimpy",20,
      "set_al",-100,
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
    2,2,"shaman","/players/emerald/island/room/caves/obj/shaman",0,
    -2,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
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
  });

  ::reset(arg);
  replace_program("/room/room");

}
