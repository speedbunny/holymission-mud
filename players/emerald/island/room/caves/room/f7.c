inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the heart of the forest";

  long_desc="You have arrived in the heart of the forest.  A small spring "+
            "of clear water bubbles at your feet.  Overhead, the branches "+
            "of the trees creak and groan in the wind.  Leaves rustle "+
            "eerily, and the volcano grunts and rumbles in the distance.\n";

  items=({"heart","The centre of the forest",
          "forest","A dark and dangerous forest",
          "spring","You could drink the spring's water",
          "water","Clean, clear water",
          "feet","Your feet need a bath, and the toenails need clipping",
          "branches","They rub against each other in an alarming manner",
          "trees","Dark, gnarled oaks and firs",
          "leaves","They slap against your face",
          "volcano","You are on a volcanic island",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/f9","north",
             "/players/emerald/island/room/caves/room/f6","west",
             "/players/emerald/island/room/caves/room/f8","east",
             "/players/emerald/island/room/caves/room/f3","south",
           });

  clone_list=({
    1,2,"hunter","obj/monster",({
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
  });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("do_drink","drink");
}

do_drink(str) {
  if(!str) {
    notify_fail("Drink what?\n");
    return 0;
  }
  if(str=="water") {
    write("Ahh, the water refreshes you !\n");
    say(this_player()->query_name()+" drinks from the spring.\n");
    return 1;
  }
}
