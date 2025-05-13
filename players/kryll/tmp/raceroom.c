
inherit "/room/room";

#include "/sys/defs.h"
#include "includes.h"

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "Race room";
  long_desc =
    "This is the Race room. Here you can 'choose' a race. "+
    "With 'list' you get all races you can 'choose'. When "+
    "you are not sure which race you like, you can do 'about "+
    "racename'. If you are still a bit helpless just type " +
    "'help' or 'example' to get more information.\n";

  property = ({ "no_teleport", "no_fight" });
}

void init() {
  ::init();
  add_action("do_list", "list");
  add_action("do_help", "help");
  add_action("do_about", "about");
  add_action("do_example", "example");
  add_action("do_list", "race");
  add_action("do_list", "races");
  add_action("do_list", "?");
  add_action("do_choose", "choose");
}

int do_about(string str) {
  if(!str) {
    notify_fail("About what race?\n");
    return 0;
  }
  else if(file_size("/race/help/" + str) < 0) {
    notify_fail(lw("Sorry but " + str + " is not a race. Type <list> "+
                   "to get the available races.\n"));
    return 0;
  }
  cat("/race/help/" + str);
  return 1;
}

int do_example() {
  write(
    " Command            Description\n"+
    " -----------------  ---------------------------------------------\n"+
    " list               you get all the available races\n"+
    " about human        you get a description about the race human\n"+
    " choose human       you are then human and can enter the game\n\n"+
    "This works for all other races.\n");    
  return 1;
}

int do_help(string str) {
  write(
    "This mud now has not only new races but a new way to handle "+
    "guilds and statistics. Both of these are interlaced with "+
    "races and so all players must now choose a new race, whether "+
    "you are a new player or an older player. You may type <list> "+
    "to get a complete list of available races, <about [race]> "+
    "to find out more information about a specific race, <choose "+
    "[race]> to select the race you wish your character to be. "+
    "Enjoy mudding, and don't forget to check out the <help> "+
    "command to get you started.\n");
   return 1;
}

int do_list(string str) {
  if(!str) {
    RM->race_list();
    write("\nJust type <choose [race]> or <about [race]>.\n\n"+
          "For example 'choose human'.\n");
    return 1;
  }
  if(RM->query_number(str) != -1) {
    cat("race/help/" + str);
    return 1;
  }
}    

int do_choose(string str) {
  int i;

  if(TP->check_has_race() == 1) {
    writelw("You already have chosen a race. You cannot change it now. "+
            "If you want something different, delete this character, "+
            "and start over.\n");
    return 1;
  }
  if(RM->query_number(arg) != -1) {
    TP->set_race(str);
    for(i=0; i<NUMBER_OF_STATS; i++) {
      if(TP->query_stats(i) < RM->query_basic_stat(str, i))
        TP->set_stats(i, RM->query_basic_stat(str, i));
    }

    TP->set_size(RM->query_size(str));
    TP->race_updated();
    TP->move_player("suddenly#" + RM->query_start_room(str));
    TP->save_me(1);
    return 1;
  }
  write("No such race!\n");
  return 1;
}
 

