inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
    
  set_light(1);
  short_desc = "The 'Thirsty Treant' pub";
  long_desc =
    "You are in 'The Thirsty Treant' pub. This is a nice place to "+
    "relax and have a drink. Some locals are sitting talking around "+
    "a small fire in the corner. Behind the counter the waiter "+
    "stands ready to serve you. On the wall behind the waiter hangs "+
    "the pricelist.\n";

  dest_dir = ({
    HM_VILLAGE + "square1", "south",
  });

  items = ({
    "pub","The local pub is a place where you can forget your daily problems",
    "drink","Read the pricelist to see what this pub serves",
    "locals","Some woodsmen, drinking beer and discussing today's business",
    "fire","A small, but nice and warm fire",
    "corner","In the corner a small fire is burning",
    "counter","A wooden counter, carefully kept clean by the waiter",
    "waiter","A former woodsman, who tends this bar since he got crippled",
    "wall","An ordinary wooden wall",
    "pricelist","On it is written what you can order here. Read it"
  });

  property = ({ "has_fire", "no_teleport" });
}

void init() {
  ::init();
  add_action("_read","read");
  add_action("_order", "order");
  add_action("_order", "buy");
}

status _read(string str) {
  switch(str) {
    case "menu" :
    case "list" :
    case "pricelist" :
      write("     *** The Thirsty Treant ***     \n"+
            "   For those who like it we serve:\n\n"+
            "  [1] A bottle of milk         31 coins \n"+
            "  [2] Strong home-brewed ale  122 coins \n"+
            "  [3] Black currant gin       305 coins \n"+
            "  [4] Treesolvent             644 coins \n\n"+
            "   Just type <buy #> or <buy item>\n");
      say(TP->NAME + " reads the pricelist.\n");
      return 1;
    default :
      notify_fail("Read what?\n");
      return 0;
  }
}

status _order(string str) {
  object drink;

  if(!str) {
    notify_fail("Order what ?\n");
    return 0;
  }

  switch(str) {
    case "milk" :
    case "1" :
      if(check_money("milk")) return 1;
      drink = clone_object("/obj/soft_drink");
      drink->set_name("bottle of milk");
      drink->set_alias("milk");
      drink->set_short("A bottle of milk");
      drink->set_drinker_mess("The fresh milk tastes healthy.\n");
      drink->set_drinking_mess(" drinks some white fluid. Is "+
             "it really milk? Yuch!!\n");
      drink->set_empty_container("bottle");
      drink->set_value(31);
      drink->set_strength(2);
      drink->set_heal_amount(4);
      break;
    case "ale" :
    case "2" :
      if(check_money("ale")) return 1;
      drink = clone_object("/obj/alco_drink");
      drink->set_name("home-brewed ale");
      drink->set_alias("ale");
      drink->set_short("A bottle of strong home-brewed ale");
      drink->set_drinker_mess("A warm feeling runs through your gullet.\n");
      drink->set_drinking_mess(" gulps down some strong ale.\n");
      drink->set_empty_container("bottle");
      drink->set_value(122);
      drink->set_strength(4);
      drink->set_heal_amount(20);
      break;
    case "gin" :
    case "3" :
      if(check_money("gin")) return 1;
      drink = clone_object("/obj/alco_drink");
      drink->set_name("black currant gin");
      drink->set_alias("gin");
      drink->set_short("A small bottle of black currant gin");
      drink->set_drinker_mess("Your fingertips glow up as the gin "+
             "invades your body.\n");
      drink->set_drinking_mess("'s fingertips glows up as the gin "+
             "does its work.\n");
      drink->set_empty_container("bottle");
      drink->set_value(305);
      drink->set_strength(10);
      drink->set_heal_amount(50);
      break;
    case "treesolvent" :
    case "solvent" :
    case "4" :
      if(check_money("treesolvent")) return 1;
      drink = clone_object("/obj/alco_drink");
      drink->set_name("tree solvent");
      drink->set_alias("solvent");
      drink->set_short("A tiny bottle of tree solvent");
      drink->set_drinker_mess("You think the sky is falling on "+
             "your head.\n");
      drink->set_drinking_mess(" gets a wooden head, caused by "+
             "the tree solvent.\n");
      drink->set_empty_container("bottle");
      drink->set_value(644);
      drink->set_strength(22);
      drink->set_heal_amount(110);
      break;
    default :
      notify_fail("The waiter tells you: We don't serve that "+
                  "kind of drink here.\n");
      return 0;
  }
  if(transfer(drink, TP))
    MOVE(drink, TO);
  write("You order a "+ str +".\n");
  say(TP->NAME + " orders a "+ str +".\n");
  TP->add_money(-drink->query_value());
  return 1;
}

int check_money(string str) {  
  int value;  

  switch(str) {
    case "milk"        : value =  31; break;
    case "ale"         : value =  122; break;
    case "gin"         : value = 305; break;
    case "treesolvent" : value = 644; break;
    default            : value = 0; break;
  }

  if(!value) {
    write("Error in testing money.\n");
    return 1;
  }

  if(TP->query_money() < value) {
    writelw("The waiter tells you: You can't pay me " + value +
            "coins, so I can't serve you that drink.\n");
    return 1;
  }
  return 0;
}

light_text(string str) {
  write("You put the " + str + " in the fire to light it.\n");
  say(TP->NAME + " lights a " + str + " in the fire.\n");
}

