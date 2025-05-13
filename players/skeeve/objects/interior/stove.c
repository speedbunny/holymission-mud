inherit "/obj/container";

#include "/players/skeeve/area.h"

reset(arg) {
  ::reset(arg);
  if (!arg){
    set_name("stove");
    set_max_weight(10);
    set_short("A black iron cooking stove");
    set_long("The ashes of some branches is in it.\n"
            +"If you burn some branches in it a fire will heat the kettle.\n");
    set_value(0);
    set_can_get(0);
  }
}

init() {
  ::init();
  add_action("burn","burn");
  add_action("burn","light");
}

burn(str) {
  string what,util;
  object outil, branches;
  int i;
  
  if (!str) return 0;
  
  util = "";
  if (!id(str)) {    
    if ((sscanf(str,"%s with %s",what,util)!=2)
     || !id(what))
     return 0;
  }
  
  if ((util!="") && (util!="torch") && (util!="lighted torch")) {
    if (outil=present(util,this_player())) {
      if (!outil->id("lighted_torch")){
        write("Why do you think, you can light the "
            + query_name() + " with a "
            + outil->query_name() + ".\n");
      say(this_player()->query_name()
           +" fail to light the "+query_name()+" with a "
           +util+"!\n");
        return 1;
      }
    } else {
      write("You have no "+util+" to light the "
           +query_name()+".\n");
      say(this_player()->query_name()
           +" fail to light the "+query_name()+" with a "
           +util+"!\n");
      return 1;
    }
  } else {
    if (!present("lighted_torch",this_player())){
      write("You have nothing to light the "+query_name()+"!\n");
      say(this_player()->query_name() + 
            " have nothing to light the "+query_name()+"!\n");
      return 1;
    }
  }

  if (present("branch 3",this_object())) {
    branches=all_inventory(this_object());
    for (i=0;i<sizeof(branches);i++) 
      destruct (branches[i]);
    move_object(clone_object(OBJECTS+"fire"),this_object());
    tell_room(environment(this_object()),
       "The branches catches fire and burns away!\n");
  } else {
    tell_room(environment(this_object()),
       "There are not enough branches in the stove to make a fire!\n");
  } 
  return 1;
}

query_hot_enough() {
  return present ("fire",this_object());
}

