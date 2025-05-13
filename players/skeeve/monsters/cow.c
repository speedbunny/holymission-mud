inherit "/obj/monster";

#include "/players/skeeve/area.h"

status has_milk;
object catcher;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("cow");
    set_alias("milk cow");
    set_short("A milk cow");
    set_long("A beautiful cow. If you could catch it you could probably milk it.\n");
    set_level(5);
    set_sp(0);
    set_al(0);
    set_wc(5);
    set_ac(3); 
    set_aggressive(0);
    set_whimpy(-1);
  }
  catcher = 0;
  has_milk =1;
}

long_msg() {
  return ((!has_milk) ? "An empty "+name+".\n":
    ((catcher) ? "A caught "+name+". Ready for milking.\n" 
    : "A lazy "+name+". If you catch it, you can milk it.\n"));
}

query_stay_garden() { return 1; }  /* must not leave the garden */

init() {
  ::init();
  add_action("catchit", "catch");
  add_action("releaseit","release");
  add_action("milk", "milk");
}

releaseit(str) {
  if(!str || (present(str,environment(this_object())) != this_object()))
    return 0;
  if (this_player() == catcher ){
    write("You release the "+name+" without milking. She runs away.\n");
    say(capitalize(catcher->query_name())+" releases a "+name+" without milking.\n");
    catcher = 0;
  }
  return 1;
}

catchit(str) {
  if(!str || (present(str,environment(this_object())) != this_object()))
    return 0;
  if (catcher == this_player()) {
    write ("You have already caught the "+name+".\n");
  } else if (catcher && present(catcher,environment(this_player()))) {
    write("This "+name+" is caught by "+catcher->query_name()+".\n");
    say(capitalize(this_player()->query_name())
     +" tried to catch the "+name+" of "+catcher->query_name()+".\n");
  } else if ((30 + this_player()->query_dex()) < random(61)) {
    write("The "+name+" is to fast for you!\n");
    say(capitalize(this_player()->query_name())+" failed to catch a "+name+".\n");
    catcher=0;
  } else {
    catcher = this_player();
    write("After a short hunt you catch the "+name+".\n");
    say(capitalize(catcher->query_name())+" catches a "+name+".\n");
  }
  return 1;
}

milk(str) {
  object bottle;
  if(!str || (present(str,environment(this_object())) != this_object()))
    return 0;
    
  if (catcher == this_player()) {
    if (!has_milk) {
      write ("This " + name + " has no milk.\n");
      say(capitalize(catcher->query_name()) 
       + " milks a "+name+" which has no milk.\n");
    } else if (!bottle = present("bottle",catcher)) {
      write ("The milk squirt to the earth because you have no bottle!\n"
          +"As the "+name+" has no more milk, you let her run away.\n");
      has_milk = 0;
      catcher = 0;
    } else if ((30 + catcher->query_dex()) >= random(61)) {
      write("You milk the "+name+".\n"
           +"As the "+name+" has no more milk, you let her run away.\n");
      say(capitalize(catcher->query_name()) + " milks a "+name+".\n");

      destruct (bottle);
   
      bottle=clone_object("obj/soft_drink");
      bottle->set_name("milk");
      bottle->set_alias("fresh milk");
      bottle->set_short("A bottle of milk");
      bottle->set_long("It looks very refreshing.\n");
      bottle->set_value(150);
      bottle->set_strength(16);
      bottle->set_drinking_mess(" drinks some fresh milk.\n");
      bottle->set_drinker_mess("Very tasty indeed!\n");
      bottle->set_empty_container("bottle");
   
     if (transfer(bottle,catcher))
        transfer(bottle,environment(catcher));
   
      has_milk = 0;
      catcher = 0;
    } else {
      write("Before you begin to milk the "+name+" gives you a kick and runs away.\n");
      say("The "+name+" kicks " + catcher->query_name() + ".\n");
      catcher->hit_player(catcher->query_hp() / 10);     
      catcher = 0;
    }
  } else if (catcher) {
    write("This "+name+" is caught by "+catcher->query_name()+".\n");
    say(capitalize(this_player()->query_name())+" tries to milk the "+name+" of "
       + catcher->query_name() +".\n");
  } else {
    write("You must first catch the "+name+".\n");
    say(capitalize(this_player()->query_name())+" tries to milk an uncaught "+name+".\n");
  }
  return 1;
}
