#define TP this_player()
inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="SPLASH!  You have landed on a sandbank in the sea.  The "+
            "sunlight glitters on the water.  A few crabs snap at your "+
            "toes.  The volcanic island rises to the east.  The water is "+
            "deep and warm here, and you might try going for a swim.\n";

  items=({"sandbank","A long sandbank",
          "water","Clear sea water, prefect for swimming in",
          "sea","A beautiful blue sea",
          "sunlight","The sun's rays dance on the waves",
          "crabs","They seem to want to bite your toes",
          "toes","Your toes will turn to prunes if you stay in the water "+
                 "too long",
          "island","A volcanic island in the sea",
        });

  clone_list=({
    1,1,"blue","/players/emerald/island/obj/blue",0,
    -1,1,"skin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_short","A blue dragonskin",
      "set_long","The excellent armour of the blue volcano Dragon.\n",
      "set_value",2000,
      "set_weight",2,
    }),
    2,1,"red","/players/emerald/island/obj/red",0,
    -2,1,"dragonskin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_short","A red dragonskin",
      "set_long","The excellent armour of the red volcano Dragon.\n",
      "set_value",3000,
      "set_weight",3,
    }),
    3,2,"cancer","obj/monster",({
      "set_name","cancer",
      "set_level",2,
      "set_hp",60,
      "set_race","crustacean",
      "set_short","A big cancer",
      "set_long","You see a big cancer snapping at your legs.\n",
    }),
    -3,1,"claw","obj/weapon",({
      "set_name","claws",
      "set_class",4,
      "set_short","Cancer claws",
      "set_long","The claws of the cancer.\n",
      "set_value",25,
      "set_weight",1,
    }),
  });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("_swim","swim");
}

_swim(arg) {
  call_out("swim1",2);
  return 1;
}

swim1() {
  write("You swim out into the sea.\n");
  call_out("swim2",2);
}

swim2() {
  write("You lose all track of time and swim farther than you intended.\n");
  call_out("swim3",2);
}

swim3() {
  write("The current pulls you around to the south side of the island.\n");
  call_out("swim4",2);
}

swim4() {
  string where;
  where="sw"+(1+random(20));
  write("You suddenly find yourself on a different place!\n");
  TP->move_player("swimming#players/emerald/seaworld/room/"+where+"");
}
