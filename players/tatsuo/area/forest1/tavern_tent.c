inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"
#include ROOM_FUNCTS
#define NF     return notify_fail

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_light( 1);
    short_desc= "Inside the Tavern Tent";
long_desc=
"You have entered the Tavern Tent set up outside of the wolfen mine.\n "+
"A wolfen merchant smiles at you from over the counter and points\n"+
"to a menu hanging on the wall.  From the amount of wolfen soldiers\n"+
"in the tent, you surmise that this must be one of the more popular\n"+
"places among those at the mine.  A serving wench comes up to you and\n"+
"asks if you would like to make an order.\n";

    items=({
      "menu","It is written in a language you can fortunately read",
     });
    dest_dir=({	
      F1PATH+"forest33.c", "south",
      F1PATH+"forest_t1.c","east",
      F1PATH+"road7.c",    "north",
      F1PATH+"forest36.c", "west",
  });
}

init() {
    ::init();
    add_action("order","order"); 
    add_action("order","buy"); 
    add_action("read","read"); 
}                 

read(str) {
    if (str=="menu" || str=="sign") {
    write("-----------------------------------------------------\n"+ 
          " The Legionaire's Mess Hall\n"+
	  "-----------------------------------------------------\n"+
          "    Boiled potatoes        (100 coins)\n"+
          "    A slice of mutton      (250 coins)\n"+
          "    A leg of lamb          (400 coins)\n"+
	  "    A glass of water        (30 coins)\n"+
	  "    A shot of whisky        (40 coins)\n"+
	  "    A mug of vodka         (100 coins)\n"+
	  "    A bottle of whisky     (200 coins)\n"+
	  "    Coffee                  (40 coins)\n"+
          "-----------------------------------------------------\n");
          return 1;
         }                                                
	return 0;
  }
     
order(str) {
  string type, mess;
  int value, strength, heal;
  
  if(!str) 
    NF("The cook says: What would you like?\n");
  switch(str) {
  case "boiled potatoes":
  case "potatoes":
    mess = "You smile as you eat a plate of potatoes dripping with butter.";
    heal = 20;
    value = 100;
    strength = 10;
    type = "food";
    break;
  case "slice of mutton":
  case "mutton":  
  case "slice":
    mess = "You rip your teeth into a great tasting slice of mutton.";
    heal = 55;
    value = 250;
    strength = 28;
    type ="food";
    break;
  case "lamb":
  case "leg of lamb":
  case "leg":
    mess = "You stuff yourself full of a perfectly cooked leg of lamb.";
    heal = 90;
    value = 400;
    strength = 40;
    type = "food";
    break;
  case "water":
  case "glass of water":
    mess = "You drink some fresh water and feel hungry.";
    value = 30;
    strength = -3;
    type = "food";
    break;
  case "whisky":
  case "shot of whisky":
    mess = "You down a shot of whisky and feel great.";
    value = 40;
    strength = 5;
    heal = 15;
    type = "alco";
    break;
  case "vodka":
  case "mug":
  case "mug of vodka":
    mess = "You throw back your head and drink a mug full of straight vodka.";
    heal = 30;
    value = 100;
    strength = 10;
    type = "alco";
    break;
  case "bottle of whisky":
  case "bottle":
    mess = "You take the bottle of whisky, and drink the whole thing!";
    heal = 60;
    value = 200;
    strength = 30;
    type = "alco";
    break;
  case "coffee":
    mess = "Your eyes open wide, and you become more awake.";
    value = 30;
    strength = -3;
    type = "alco";
    break;
  default:
    NF("Wolfen merchant says: I will see if I can get that in the future.\n");
    break;
  }
  
  if(TP->query_money() < value)
    NF("Wolfen merchant says:  That costs " + value + " gold coins.  Maybe you should try something less expensive.\n");
  
  if (type=="alco") {
    if(!TP->drink_alcohol(strength))
      NF("Wolfen merchant says: Why don't you have some coffee instead?\n");
    say(TP->query_name()+" asks for a "+str+" but the wolfen merchant refuses.");
    
  }
  
  else if(type=="food") {
    if(!TP->eat_food(strength))
      NF("Wolfen merchant says: You better watch your weight.\n");
    say(TP->query_name()+" asks for "+str+" but the merchant refuses.");
  }
  
  write("You smack "+value+" coins on the counter for a "+str+".\n");
  TP->add_money(-value);
  TP->heal_self(heal);
  write(mess + "\n");
  say(PNAME + " orders something.\n");
  return 1;
}

