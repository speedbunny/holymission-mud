#define TO this_object()
#define TP this_player()
#define TPN TP->query_name()
inherit "/room/room";

int move(string str) {
  if(!str)
    str=query_verb();
  switch(str) {
    case  "up" :
      if(present("cat", TO) && !TP->query_immortal()) {
        write("The manx hisses:  Make my day, punk!\n");
        say(TPN+" tried to go up, but is stopped by the manx.\n");
        return 1;
      }
  }
  return ::move(str);
}

reset(arg) {

  set_light(0);

  short_desc="The lair of the manx";
  long_desc="This room is filled with bones of dead adventurers!  It must " +
            "be the home of the dreaded Manx!  You have been warned...\n";

  dest_dir=({"/players/emerald/good/evil/evil4","south",
             "/players/emerald/good/evil/evil8","up",
           });

  items=({"room","Rather bony",
          "bones","Human bones, covered with fang marks",
          "adventurers","They are long dead and devoured",
        });

  clone_list=({
    1,1,"manx","/players/emerald/good/obj/manx",0,
    -1,1,"gem","obj/treasure", ({
      "set_name","emerald",
      "set_alias", "gem",
      "set_short", "A giant emerald",
      "set_weight", 3,
      "set_value", 500,
    }),
  });

  ::reset();

}

