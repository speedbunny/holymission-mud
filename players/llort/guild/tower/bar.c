#define TP	this_player()

inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Knort's pub";
  long_desc="It's Knort's famous pub.\n"+
	    "They have got: beer, milk and sandwiches\n";

  dest_dir=({ "players/llort/guild/tower/hallway","north" });
}

init() {
  ::init();
  add_action("buy","buy");
}

buy(str) {

switch(str) {
  case "sandwich":   	/* strength = 10, cost = 10 coins, heal = 5 */
    if(TP->query_money()<10) {
      write("You don't have the money for the sandwich,"+
	    " come back if you've enough coins.\n");
      return 1;
    } 
    TP->add_money(-10);
    write("You pay 10 coins for a very tasty looking sandwich.\n");
    if(TP->eat_food(10)) {
      write("The sandwich tasted very good.\n");
      TP->heal_self(5);
    }
    return 1; 
  case "beer":   	/* strength = 2, cost = 5 coins, heal = 1 */
    if(TP->query_money()<5) {
      write("You don't have the money for the beer,"+
	    " come back if you've enough coins.\n");
      return 1;
    } 
    TP->add_money(-5);
    write("You flip 5 bucks on the counter.\n");
    if(TP->drink_alcohol(2)) {
      write("AHHHHHH ..., the beer cooled you down a little.\n");
      TP->heal_self(1);
    }
    return 1; 
  case "milk":   	/* strength = 20, cost = 15 coins, heal = 10 */
    if(TP->query_money()<15) {
      write("You don't have the money for the milk,"+
	    " come back if you've enough coins.\n");
      return 1;
    } 
    TP->add_money(-15);
    write("You deposit 15 coins on the table.\n");
    if(TP->drink_soft(20)) {
      write("After you get big draught of milk you feel better.\n");
      TP->heal_self(10);
    }
    return 1; 
  default:
    write("We don't sell "+str+" here.\n");
    return 1;
  }
}
