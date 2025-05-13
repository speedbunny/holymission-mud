inherit "/obj/armour";

#include "/players/skeeve/area.h"

#define REST LAND+"rest"
#define CHURCH "room/church"

reset (arg) {
  ::reset(arg);
  if (!arg) {
     set_name ("seven miles boots");
     set_alias ("boots");
     set_short ("A pair of seven miles boots");
     set_long  ("The emblem of druid Lakmir embellish this fine leather boots.\n"
               +"There is something written on each boot.\n");
     set_read  ("On one boot you can read 'Rest'\n"
               +"on the other 'Church'.\n");
     set_type  ("boot");
     set_size  (0);
     set_ac    (0);
     set_weight(4);
     set_value (500);
  }
}

wear (str) {
  int ret;
  if (ret = ::wear(str))
     write ("You feel that the boots want to run away with you.\n"); 
  return ret;
}
 
init () {
  ::init();
  add_action ("running",     "church");
  add_action ("running",       "rest");
}

running(target) {
  string location;
  int hp,hpmax;
  if (worn_by!=this_player()) return 0;
  if (!target) target=query_verb();
  location = (target=="church")? CHURCH : REST;
  if (environment(worn_by)->query_property("no_teleport")){
     write("The boots vibrate, but they couldn't find the way to the "
       + target + ".\n");
     say (capitalize(worn_by->query_name())+" says: "
      + target +", but his boots only vibrates.\n");
     return 1;
  }
  if (file_name(environment(worn_by)) == location) {
     write("The boots vibrates, but nothing happens.\n");
     say (capitalize(worn_by->query_name())+" says: "
      + target +", but his boots only vibrates.\n");
     return 1;
  }
  if (!worn) {
    write("You wonder how fast this boots run away without you!\n"
         +"Maybe you must wear this boots before you can use it!\n");
     say (capitalize(worn_by->query_name())+" says: "
      + target +", but his boots runs without him away.\n");
    drop(1);
    transfer (this_object(),location);
    return 1;
  }
  hp = worn_by->query_hp();
  hpmax = worn_by->query_max_hp();
  if (hp < hpmax / 2) {
    write("You are to groggy to hold your balance.\n"
         +"As you fall down, you wonder how fast this boots run away without you!\n");
    drop(1);
    transfer (this_object(),location);
    this_player()->reduce_hit_point(hp/5);
    if (hp < hpmax / 10 + random(hpmax/10)) command ("drop all",this_player());
    return 1;
  }  
  write ("As you say the command the boots runs away with you.\n"
        +"You run so fast, that you cannot see, where you are running.\n"
        +"As the boots are stoping with you, you feel so weak,\n"
        +"that you are falling down.\n");
  worn_by->move_player("as fast as the wind",location);
  worn_by->reduce_hit_point(hpmax/5);
  if (hp < hpmax / 10 + random(hpmax/10)) command ("drop all",worn_by);
  return 1;
}
