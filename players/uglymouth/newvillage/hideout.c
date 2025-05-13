/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc = "An underground hideout";
  long_desc = "You've entered some kind of cave, dug out in the sand some time ago.\n"
        + "Somebody probably uses this place as a hideout now and then, as you notice\n"
        + "a primitive bed dug in the sand and a small fireplace, with a hole in the\n"
        + "roof to let the smoke out.\n";
  dest_dir = ({ PATH+"alley3","up" });
  items = ({"cave","A hole in the ground. Certainly not up to hobbit standards",
        "sand","At some places the sand is very loose",
        "hideout","It's not used very often, but it's also not been abandoned altogether",
        "bed","A human shaped place dug in the sand. Some threads of blankets are still there",
        "threads","Some wool threads",
        "fireplace","It contains ashes",
        "ashes","Ashes from burned wood",
        "hole","A tiny hole in the ceiling. Just big enough to let the smoke escape",
        });
  }

void init() {
  ::init();
  add_action("search_cave","search");
  add_action("dig_sand","dig");
  }

int search_cave(string str) {
  if(str=="cave" || str=="hideout" || str=="bed") {
    write("You search around, but find nothing.\n");
    say(this_player()->query_name() + " searches around.\n");
    return 1;
    }
  if(str=="fireplace" || str=="ashes") {
    write("You notice that the sand under the fireplace has been dug in a while ago.\n");
    say(this_player()->query_name() + " searches around.\n");
    return 1;
    }
  return 0;
  }

int dig_sand(string str) {
object ob;  
int totalcoins;
  if(str=="sand") {
    write("You dig in the sand.\n");
    say(this_player()->query_name() + " digs in the sand.\n");
    return 1;
    }
  if(str=="fireplace") {
    ob = find_object( PATH+"alley2" );
    totalcoins = ob->query_hidden_coins();
    if(!totalcoins) {
      write("You dig under the fireplace, but all you find is sand and ashes.\n");
      say(this_player()->query_name() + " digs in the sand.\n");
      return 1;
      }
    write("As you dig under the fireplace, you find some coins.\n");
    say(this_player()->query_name() + " digs up something from the sand.\n");
    this_player()->add_money(totalcoins);
    ob->set_coins(0);
    return 1;
    }
  return 0;
  }

