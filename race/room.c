
/* 30.07.94 Whisky : installed a racehelp and an example + put in strict
                     types */

inherit "room/room";
#define RM "race/master"
#define TP this_player()
#include "includes.h"

void reset(int flag) 
{
  if(flag == 0) 
  {
     set_light(1);
     short_desc="In the race room";
     long_desc="This is the Race room. Here you can 'choose' a race.\n"+
               "With 'list' you get all races you can 'choose'. When\n"+
               "you are not sure, which race you like you can do 'about\n"+
               "racename'. If you are still a bit helpless just type\n" +
               "'help' or 'example' to get more information.\n";
   property = ({"no_teleport"});
   }
}

void init() 
{
  ::init();
  add_action("do_list","list");
  add_action("do_help","help");
  add_action("do_about","about");
  add_action("do_example","example");
  add_action("do_list","race");
  add_action("do_list","races");
  add_action("do_list","?");
  add_action("do_choose","choose");
}

int do_about(string arg)
{
    if (!arg)
    {
        notify_fail("About what race (example about elf) ?\n");
        return 0;
    }
    else if (file_size("/race/help/"+arg) < 0)
    {
        notify_fail("Sorry but "+arg+" is not a race. Type list \n"+
                    "to get the available races.\n");
        return 0;
    }
    cat("/race/help/"+arg);
    return 1;
}

int do_example()
{
    write(" You type:          what happens:\n\n"+
          " list               you get all the available races\n"+
          " about human        you get raceinfo about the race human\n"+
          " choose human       you are then human and can enter the game\n\n"+
          "This works similar to all other races :*)\n");    
    return 1;
}

int do_help(string arg) 
{
  write("This Mud has now some different kind of races.\n"+
        "You have to choose a race, because it makes sense\n"+
        "only to have several kind of races in case of the\n"+
        "possibilities each race will have in future !\n"+
        "Also if you are an older player of our mud you\n"+
        "have to choose your race new !!!!\n\n"+
        "Just type 'list' to see what kind of races we have got.\n"+
        "And if you found the race you like just type\n"+
        "'choose <your prefered race>', for example choose elf.\n\n"+
        "                                 HAPPY MUDDING !!!!\n");
   return 1;
}

int do_list(string arg) 
{
  if(!arg) 
  {
    RM->race_list();
    write("\nJust type 'choose <race>'.\n\n"+
          "For example 'choose human'.\n");
    return 1;
  }
  if(RM->query_number(arg)!=-1) {
    cat("race/help/"+arg);
    return 1;
  }
}    

int do_choose(string arg) 
{
  int i;

  if(RM->query_number(arg)!=-1) 
  {

    TP->set_race(arg);
    for(i=0;i<NUMBER_OF_STATS;i++) {
      if(TP->query_stats(i)<RM->query_basic_stat(arg,i))
        TP->set_stats(i,RM->query_basic_stat(arg,i));
    }
    TP->set_size(RM->query_size(arg));

    write("As you have chosen a race, you're moved to the church.\n");
    TP->race_updated();  /* Llort */
    TP->move_player("suddenly#"+RM->query_start_room(arg));
    TP->save_me(1); /* Moonchild - 111092 */
/* lets get a soul too! */
    if(!present("racesoul",TP)) {
        move_object(clone_object(RM->query_soul()),TP);
    }
    return 1;
  }
  write("No such race!\n");
  return 1;
}
 

