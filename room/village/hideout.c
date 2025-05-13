inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc = "An underground hideout";
  long_desc = 
    "You've entered some kind of cave, dug out in the sand some "+
    "time ago. Somebody probably uses this place as a hideout now "+
    "and then, as you notice a primitive bed dug in the sand and "+
    "a small fireplace, with a hole in the roof to let the smoke out.\n";

  dest_dir = ({
    HM_VILLAGE + "alley3", "up",
  });

  items = ({
    "cave","A hole in the ground. Certainly not up to hobbit standards",
    "sand","At some places the sand is very loose",
    "hideout","It's not used very often, but it's also not been "+
      "abandoned altogether",
    "bed","A human shaped place dug in the sand. Some threads of "+
      "blankets are still there",
    "threads","Some wool threads",
    "fireplace","It contains ashes",
    "ashes","Ashes from burned wood",
    "hole","A tiny hole in the ceiling. Just big enough to let the "+
      "smoke escape",
  });
  ::reset(arg);
}

void init() {
  ::init();
  add_action("search_cave","search");
  add_action("dig_sand","dig");
}

status search_cave(string str) {
  switch(str) {
    case "cave" :
    case "hideout" :
    case "bed" :
      write("You search around, but find nothing.\n");
      say(TP->NAME + " searches around.\n");
      return 1;
    case "fireplace" :
    case "ashes" :
      writelw("You notice that the sand under the fireplace has been "+
              "dug in a while ago.\n");
      say(TP->NAME + " searches around.\n");
      return 1;
  }
  notify_fail("Search what?\n");
  return 0;
}

status dig_sand(string str) {
  object ob;  
  int totalcoins;

  switch(str) {
    case "sand" :
      write("You dig in the sand.\n");
      say(TP->NAME + " digs in the sand.\n");
      return 1;
    case "fireplace" :
      ob = find_object(HM_VILLAGE + "alley2");
      totalcoins = ob->query_hidden_coins();
      if(!totalcoins) {
        writelw("You dig under the fireplace, but all you find "+
                "is sand and ashes.\n");
        say(TP->NAME + " digs in the sand.\n");
        return 1;
      }
      write("As you dig under the fireplace, you find some coins.\n");
      say(TP->NAME + " digs up something from the sand.\n");
      TP->add_money(totalcoins);
      ob->set_coins(0);
      return 1;
  }
  notify_fail("Dig what?\n");
  return 0;
}

