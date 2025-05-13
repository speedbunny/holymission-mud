#define TO this_object()
#define TP this_player()
#define NAME query_name()
inherit "/room/room";

int move(string str) {
  if(!str)
    str=query_verb();
  switch(str) {
    case "north" :
      if(present("cat",TO) && !TP->query_immortal()) {
        write("The alleycat prevents you from going further in.\n");
        say(TP->NAME+" tries to go north, but is stopped by the cat.\n");
        return 1;
      }
  }
  return ::move(str);
}
reset(arg) {

  set_light(0);

  short_desc="The hunting room";
  long_desc="You have entered the hunting territory of a small alleycat.  " +
            "It spends its time looking for mice, one of which has just " +
            "scurried into a hole in the wall.  The passage continues to " +
            "the north and east.\n";


  dest_dir=({"/players/emerald/good/evil/evil9","east",
             "/players/emerald/good/evil/evil17","north",
           });

  items=({"mice","Small grey furry rodents",
          "hole","The mouse lives there",
          "wall","It has a mouse-hole in it",
          "passage","You are in it",
        });

  clone_list=({
    1,1,"alleycat","obj/monster", ({
      "set_name", "alleycat",
      "set_alias", "cat",
      "set_race", "feline",
      "set_level", 3,
      "set_hp", 140,
      "set_al", -100,
      "set_short", "A young and small alleycat",
      "set_ac", 3,
      "set_wc", 9,
    }),
    -1,1,"stone","obj/treasure", ({
      "set_id", "stone",
      "set_alias", "rock",
      "set_short", "A small stone",
      "set_weight", 2,
      "set_value", 300,
    }),
  });

  ::reset();

}
