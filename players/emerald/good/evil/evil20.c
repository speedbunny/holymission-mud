#define TO this_object()
#define NAME query_name()
#define TP this_player()
inherit "/room/room";

int move(string str) {
  if(!str)
    str=query_verb();
  switch(str) {
    case "east" :
      if(present("cat", TO) && !TP->query_immortal()) {
        write("The bobcat prevents you from going further in.\n");
        say(TP->NAME+" tries to go north, but is stopped by the cat.\n");
        return 1;
      }
  }
  return ::move(str);
}
void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The bobcat guard's outpost";
  long_desc="This looks like a guard outpost.  The guard looks like he " +
            "does a good job, as there are bones lying all over the " +
            "room.  The tunnel continues to the east and west.\n";

  dest_dir=({"/players/emerald/good/evil/evil2","east",
             "/players/emerald/good/evil/evil19","west",
           });

  items=({"outpost","A guard is usually stationed here",
          "bones","Gnawed human bones",
          "room","It is strewn with bones",
          "tunnel","You are in it",
        });

  clone_list=({
    1,1,"bobcat","obj/monster", ({
      "set_name", "bobcat",
      "set_alias", "cat",
      "set_race", "cat",
      "set_level", 12,
      "set_hp", 275,
      "set_al", -400,
      "set_short", "A wily bobcat",
      "set_ac", 6,
      "set_wc", 16,
      "add_money",200,
    }),
    -1,1,"hide","obj/armour", ({
      "set_name", "hide",
      "set_alt_name", "cat hide",
      "set_short", "Cat hide",
      "set_long","This hide looks extremely tough.\n",
      "set_ac", 2,
      "set_type", "armor",
      "set_value", 500,
      "set_weight", 3,
    }),
  });

  ::reset();

}

_east() {
  if (present("bobcat")) {
    if(TP->query_immortal())
    return 0;
  write("The bobcat hisses: Make my day, punk!\n");
  return 1;
  }
}
