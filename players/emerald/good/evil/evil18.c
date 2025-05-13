#define TO this_object()
#define NAME query_name()
#define TP this_player()
inherit "/room/room";

int move(string str) {
  if(!str)
    str=query_verb();
  switch(str) {
    case "north" :
      if(present("cat", TO) && !TP->query_immortal()) {
        write("The tomcat prevents you from going further in.\n");
        say(TP->NAME+" tries to go north, but is stopped by the cat.\n");
        return 1;
      }
  }
  return ::move(str);
}
void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="The tomcat's lair";
  long_desc="A giant tomcat makes his home here.  You see the bones of " +
            "small animals scattered about.  The tunnel continues to the " +
            "north and west into darkness.\n";

  dest_dir=({"/players/emerald/good/evil/evil19","north",
             "/players/emerald/good/evil/evil17","west",
           });

  items=({"bones","The bones of mice and rats",
          "tunnel","You are in it",
        });

  clone_list=({
    1,1,"tomcat","obj/monster", ({
      "set_name", "tomcat",
      "set_alias", "cat",
      "set_race", "feline",
      "set_level", 8,
      "set_hp", 230,
      "set_al", -200,
      "set_short", "A fat old tomcat",
      "set_ac", 5,
      "set_wc", 12,
    }),
    -1,1,"claw","obj/weapon", ({
      "set_name", "claw",
      "alt_alias", "claw",
      "set_short", "A wicked cat's claw",
      "set_long","This claw looks sharp, and has seen a lot of use.\n",
      "set_class", 11,
      "set_value", 850,
      "set_weight", 2,
    }),
  });

  ::reset();

}
