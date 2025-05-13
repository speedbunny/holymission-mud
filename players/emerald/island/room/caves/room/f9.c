#define TO this_object()
#define TP this_player()
#define TPN TP->query_name()
inherit "/room/room";

int move(string str) {
  if(!str)
    str=query_verb();
  switch(str) {
    case "north" :
      if(present("orc",TO) && !TP->query_immortal()) {
        write("The orc prevents you from going further in.\n");
        say(TPN+" tries to go north, but is stopped by the orc.\n");
        return 1;
      }
  }
  return ::move(str);
}

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In a dark mixed forest, in front of a cave";

  long_desc="You are wandering through a dark, mixed forest.  The shadows "+
            "cast on the ground by the trees are truly horrific.  Leaves "+
            "rustle menacingly overhead, and the volcano rumbles in the "+
            "distance.  The entrance to a cave is to the north, partially "+
            "blocked by boulders.\n";

  items=({"forest","It is dark and creepy in the forest",
          "shadows","The move in frightening manners",
          "trees","Dark, gnarled oaks",
          "leaves","They rustle in the wind",
          "volcano","It eternally rumbles",
          "entrance","The entrance to the cave is partially open",
          "cave","It might be interesting to explore the cave",
          "boulders","They partially block the cave",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/f6","southwest",
             "/players/emerald/island/room/caves/room/ci1","north",
             "/players/emerald/island/room/caves/room/f7","south",
             "/players/emerald/island/room/caves/room/f8","southeast",
           });

  clone_list=({
    1,5,"guard","obj/monster",({
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
  });

  ::reset(arg);

}
