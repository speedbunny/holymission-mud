/*
 * Author : Uglymouth
 * Date   : 6-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
    
  set_light(1);
  short_desc = "The 'Thirsty Treant' pub";
  long_desc = "You are in 'The Thirsty Treant' pub. This is a nice place to relax and have\n"
	+ "a drink. Some locals are sitting talking around a small fire in the\n"
	+ "corner. Behind the counter the waiter stands ready to serve you.\n"
	+ "On the wall behind the waiter hangs the pricelist.\n";
  dest_dir=({
	   PATH+"square1","south" });
  items = ({
	  "pub","The local pub is a place where you can forget your daily problems",
	  "drink","Read the pricelist to see what this pub serves",
	  "locals","Some woodsmen, drinking beer and discussing today's business",
	  "fire","A small, but nice and warm fire",
	  "corner","In the corner a small fire is burning",
	  "counter","A wooden counter, carefully kept clean by the waiter",
	  "waiter","A former woodsman, who tends this bar since he got crippled",
	  "wall","An ordinary wooden wall",
	  "pricelist","On it is written what you can order here. Read it" });
  property = ({ "has_fire", "no_teleport" });
  }

void init() {
  ::init();
  add_action("south","south");
  add_action("read","read");
  add_action("order", "order");
  add_action("order", "buy");
  }

south() {
object ob;
int count;
  count = 0;
  ob = first_inventory(this_player());
  while(ob) {
    if(ob->query_drink() && !ob->id("bottle")) count ++;
    ob = next_inventory(this_player());
    }
  if(count) {
    write("You are not allowed to leave with drinks!\n");
    return 1;
    }
  return 0;
  }

read(string str) {
  if(str!="pricelist" && str!="list") return 0;
  write("     *** The Thirsty Treant ***     \n"
      + "   For those who like it we serve:\n\n"
      + "  A bottle of milk         11 coins \n"
      + "  Strong home-brewed ale   22 coins \n"
      + "  Black currant gin        55 coins \n"
      + "  Treesolvent             144 coins \n\n");
  say(this_player()->query_name() + " reads the pricelist.\n");
  return 1;
  }

order(string str) {
object drink;
  if (!str) {
    write("Order what ?\n");
    return 1;
    }
  if(str) {
   if(str=="milk") {
    if(check_money(str)) return 1;
    drink = clone_object("/obj/soft_drink");
    drink->set_name("bottle of milk");
    drink->set_alias("milk");
    drink->set_short("A bottle of milk");
    drink->set_drinker_mess("The fresh milk tastes healthy.\n");
    drink->set_drinking_mess(" drinks some white fluid. Is it really milk? Yuch!!\n");
    drink->set_empty_container("bottle");
    drink->set_value(11);
    drink->set_strength(2);
    }
   if(str=="ale") {
    if(check_money(str)) return 1;
    drink = clone_object("/obj/alco_drink");
    drink->set_name("home-brewed ale");
    drink->set_alias("ale");
    drink->set_short("A bottle of strong home-brewed ale");
    drink->set_drinker_mess("A warm feeling runs through your gullet.\n");
    drink->set_drinking_mess(" gulps down some strong ale.\n");
    drink->set_empty_container("bottle");
    drink->set_value(22);
    drink->set_strength(4);
    }
   if(str=="gin") {
    if(check_money(str)) return 1;
    drink = clone_object("/obj/alco_drink");
    drink->set_name("black currant gin");
    drink->set_alias("gin");
    drink->set_short("A small bottle of black currant gin");
    drink->set_drinker_mess("Your fingertips glow up as the gin invades your body.\n");
    drink->set_drinking_mess("'s fingertips glows up as the gin does its work.\n");
    drink->set_empty_container("bottle");
    drink->set_value(55);
    drink->set_strength(10);
    }
   if(str=="treesolvent") {
    if(check_money(str)) return 1;
    drink = clone_object("/obj/alco_drink");
    drink->set_name("tree solvent");
    drink->set_alias("solvent");
    drink->set_short("A tiny bottle of tree solvent");
    drink->set_drinker_mess("You think the sky is falling on your head.\n");
    drink->set_drinking_mess(" gets a wooden head, caused by the tree solvent.\n");
    drink->set_empty_container("bottle");
    drink->set_value(144);
    drink->set_strength(22);
    }
   transfer(drink,this_player());
   write("You order a "+ str +".\n");
   say(this_player()->query_name() + " orders a "+ str +".\n");
   this_player()->add_money(- drink->query_value());
   return 1;
   }
  write("The waiter tells you: We don't serve that kind of drink here.\n");
  return 1;
  }

check_money(string str) {  
int value;  
  switch(str) {
    case "milk":           value =  11;
      break;
    case "ale":            value =  22;
      break;
    case "gin":            value =  55;
      break;
    case "treesolvent":    value = 144;
      break;
    default:               value = 0;
      break;
    }
  if(!value) {
    write("Error in testing money.\n");
    return 1;
    }
  if(this_player()->query_money() < value) {
    write("The waiter tells you: You can't pay me "+ value +"coins, \n"
      + "so I don't serve you that drink.\n");
    return 1;
    }
  return 0;
  }

light_text(string str) {
  write("You put the "+str+" in the fire to light it.\n");
  say(this_player()->query_name()+" lights a "+str+" in the fire.\n");
}

