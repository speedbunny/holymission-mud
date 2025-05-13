#include "/players/blade/area/rooms/bar_defs.h"

object cat;
reset(arg) {
  /*   if (!cat)
       cat=clone_object("/players/whisky/hole/monster/cat");
	move_object(cat,this_object()) */
  if (arg) return;
  set_light( 1);
}

short() {
  return "Inside the Legionaire's Mess Hall.";
}

init() {
  add_action ("east"); add_verb("e");
  add_action ("north"); add_verb("n");
  add_action ("order"); add_verb ("order");
  add_action ("order"); add_verb ("buy");
  add_action("kill","kill");
  add_action ("read"); add_verb ("read");
  add_action("look"); add_verb ("look");
}

look(str) {
  if (str=="merchant" || str=="wolfen merchant") {
    write(BS("You see a wolfen merchant standing behind the counter."+
	     "He smiles at you while mixing up drinks for his customers."));
    return 1;
  }
  else {
    return 0;
  }
}
kill(str) {
  if (str=="cook" || str=="wolfen cook") {
    write(BS("Wolfen cook says:  If you don't like the food, just say so!."));
    return 1;
  }
  else {
    return 0;
  }
}
east() {
  object ob;
  call_other(this_player(),"move_player",FPATH+"encampment2.c");
  return 1;
}

long() {
  write(BS("You have entered the Legionaire's Mess hall set up inside of the"+
  "wolfen encampment.  A wolfen cook scowls at you from over a steaming pot"+
  "and grumbles about how he doesn't like cooking.  A menu hangs on the wall."+
  "A few wolfen soldiers are sitting down, poking at lumps on their plates."));
  write(BS("The only obvious exit is west."));
  
}
read(str) {
  if(str == "menu") {
    write("-----------------------------------------------------\n");
    write(BS(" The Legionaire's Mess Hall"));
    write("-----------------------------------------------------\n\n");
    write(BS("    A small plate of slop (100 coins)");
    write(BS("    A medium plate of slop (250 coins)");
    write(BS("    A large plate of slop (400 coins)");
    write("-----------------------------------------------------\n");
	  return 1;
	}
}

order(str){
  string name, short_desc, mess;
  int value, cost, strength, heal;
  
  if (!str) {
    write("The cook says:  What would you like?\n");
    return 1;
  }
  if (str=="small" || str=="small slop" || str=="a small plate of slop") {
    mess = "It doesn't taste so good, but you feel better.";
    heal = 180;
    value = 100;
    strength = 30; 
  }
  else if(str=="medium" || str=="medium slop" || str=="a medium plate of slop"{
    mess = "It doesn't taste so good, but you feel much better.";
    heal= 40;
    value = 25;
    strength = 4;
  }
  else if(str=="large" || str=="large slop" || str=="a large plate of slop"){
    mess = "It doesn't taste so good, but you feel great!";
    heal = 200;
    value = 250;
    strength = 8;
    }
  else {
    write(BS("Wolfen cook says: What, do you think this is a fine restaurant?"));
    return 1;
  }
	  
  if (call_other(this_player(), "query_money", 0) < value) {
    write("Wolfen cook says:  That costs " + value + " gold coins.\n");
    return 1;
  }
  if (strength > (call_other(this_player(), "query_level") + 2)) {
    if (strength > (call_other(this_player(), "query_level") + 5)) {
      say(call_other(this_player(), "query_name", 0) + " orders a " +
	  str + ", and immediately throws it up.\n");
      write("You order a " + str + ", try to drink it, and throw up.\n");
    } 
    else {
      say(call_other(this_player(), "query_name", 0) + " orders a " +
	  str + ", and spews it all over you!\n");
      write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
    }
    call_other(this_player(), "add_money", - value);
    return 1;
  }
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("Cook says:  Why don't you have some coffee?\n");
    say(BS(call_other(this_player(), "query_name", 0) + " asks for a " +
	   str + " but the cook refuses."));
    
    return 1;
  }
  write("You give the cook " + value + " coins for a " + str + ".\n");
  say(call_other(this_player(), "query_name", 0) + " chokes down a " + str + ".\n");
  call_other(this_player(), "add_money", - value);
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
  return 1;
}






