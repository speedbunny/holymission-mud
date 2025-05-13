inherit "/room/room";

void reset(int arg) {
  ::reset();

  if(arg) return;

  set_light(1);
  short_desc="The pond at the top of the hill";
  long_desc="You are at the edge of a small pond on top of the hill.  The " +
            "water looks cool and calm on this hot and sunny day.  To the " +
            "southeast you can see the outlet of the pond; a small creek " +
            "trickling down the hill to join the river at the valley floor.\n";

  dest_dir=({"/players/emerald/country/12","north",
           });

  items=({"pond","A small pond.  You could probably drink from it",
          "water","Still water without a trace of algae",
          "creek","It carried the overflow from the pond to the river",
          "river","It drains the excess water from the valley",
        });

  property=({ "has_water" });

  clone_list=({
    1,1,"sunworshipper","obj/monster", ({
      "set_name","sun worshipper",
      "set_alias","worshipper",
      "set_race","human",
      "set_level",34,
      "set_short","A crazed sun worshipper",
      "set_long","A fanatical sun worshipper, jealous of his pond.\n",
      "set_ac",14,
      "set_wc",16,
      "add_money",450,
      "set_al",-1000,
    }),
  });

  ::reset();

}

init() {

  ::init();

  add_action("drink","drink");
  add_action("fill", "fill");

}
drink(str) {

  if(present("sun worshipper")) {
    write("The sun worshipper won't let anyone near the water.\n");
    return 1;
  }

  if(str=="water" || str=="from pond") {
    write("You feel refreshed by the cool water of the pond.\n");
    return 1;
  }
}
fill(str) {
object bucket;

  if(present("sun worshipper")) {
    write("The sun worshipper won't let anyone near the water.\n");
    return 1;
  }
 
  if (!bucket = present ("bucket",this_player())) {
    write ("You have no bucket for the water!\n");
    return 1;
  }
}
