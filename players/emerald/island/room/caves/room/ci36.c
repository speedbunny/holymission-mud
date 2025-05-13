inherit "/room/room";
void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the centre of a big chamber";

  long_desc="You are standing in the centre of an immense chamber.  "+
            "Passages lead off in the four cardinal directions.  All around "+
            "you are huge stone monoliths.  You can see shadows moving "+
            "behind them.\n";

  items=({"centre","The centre of a strange chamber",
          "chamber","It contains ominous monoliths and mobile shadows",
          "passages","They lead off north, south, east, and west",
          "monoliths","Towering stone monoliths",
          "shadows","They are incredibly animated for shadows",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci39","north",
             "/players/emerald/island/room/caves/room/ci35","south",
             "/players/emerald/island/room/caves/room/ci37","west",
             "/players/emerald/island/room/caves/room/ci38","east",
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
  });

  ::reset(arg);
  replace_program("/room/room");

}
