#define TP this_player()
inherit "/room/room";
void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="Splash!  You have landed in the sea.  Fortunately, the water "+
            "is warm and deep here, providing a nice landing.  The island "+
            "rises to the south, its volcano centre rumbling and spewing "+
            "forth a cloud of ash.  The water feels so nice here that you "+
            "might try going for a swim.\n";

  items=({"sea","A warm and deep sea, the perfect swimming spot",
          "water","It's nice and warm, wonderful for swimming",
          "island","A large volcanic island",
          "centre","Clouds of ash pour forth from the centre of the volcano",
          "cloud","A large cloud of volcanic ash",
          "ash","A big cloud of volcanic ash",
        });

  clone_list=({
    1,2,"cancer","obj/monster",({
      "set_name","cancer",
      "set_level",2,
      "set_hp",60,
      "set_race","fish",
      "set_short","A big cancer",
      "set_long","You see a big cancer snapping at your legs.\n",
    }),
    -1,1,"claws","obj/weapon",({
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
  write("You go for a swim through the warm, clear water.\n");
  call_out("swim2",2);
}

swim2() {
  write("The current takes you around the western side of the island.\n");
  call_out("swim3",2);
}

swim3() {
  write("You find yourself being pulled eastward...\n");
  call_out("swim4",2);
}

swim4() {
  string where;
  where="sw"+(1+random(20));
  write("You suddenly find yourself in a different place!\n");
  TP->move_player("swimming#players/emerald/seaworld/room/"+where+"");
}

