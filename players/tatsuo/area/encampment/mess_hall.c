inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"
#include ROOM_FUNCTS
#define NF     return notify_fail

reset(arg) {
  int mon_numbers;
    ::reset(arg);
    mon_numbers=(2-(filter_live(this_object(),"wolfen cook")));
    clone_x_of_y(mon_numbers,"/players/tatsuo/area/monsters/wolfen_cook");

    if(arg) return;
    set_light( 1);
    short_desc= "Inside the Legionaire's Mess Hall";
long_desc="You have entered the Legionaire's Mess hall set up inside of the\n"+
"wolfen encampment.  A wolfen cook scowls at you from over a steaming pot\n"+
"and grumbles about how he doesn't like cooking.  A menu hangs on the wall.\n"+
"A few wolfen soldiers are sitting down, poking at lumps on their plates.\n";
    
    items=({
      "menu","It is written in a language you can fortunately read",
      "cook","A wolfen cook that looks at you and scowls",
     });
    dest_dir=({  CAMPPATH+"encampment2.c","east",
		 CAMPPATH+"grain_storehouse.c","north",
  });
}

init() {
    ::init();
    add_action("order","order"); 
    add_action("order","buy"); 
    add_action("read","read"); 
    add_action("north","north");
}                 

int north(){
  object *obj;
  int i;
  obj = all_inventory(this_object());
  i = sizeof(obj);
  i -= 1;
  while(i > -1) {
    if(obj[i]->id("cook")) {
      write("The cook says:  You may not enter the storeroom.\n");
      return 1;
    }
    i--;
  }
  return 0;
}                     

read(str) {
    if (str=="menu" || str=="sign") {
    write("-----------------------------------------------------\n"+ 
          " The Legionaire's Mess Hall\n"+
	  "-----------------------------------------------------\n"+
          "    A small plate of slop  (100 coins)\n"+
          "    A medium plate of slop (250 coins)\n"+
          "    A large plate of slop  (400 coins)\n"+
	  "    Murky water             (30 coins)\n"+
	  "    A small warm beer       (20 coins)\n"+
	  "    A medium warm beer     (100 coins)\n"+
	  "    A large warm beer      (200 coins)\n"+
	  "    Stale coffee            (40 coins)\n"+
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
    case "small slop":
    case "a small plate of slop":
    case "small":
	mess = "It doesn't taste so good, but you feel better.";
	heal = 25;
	value = 100;
	strength = 12;
	type = "food";
	break;
    case "medium slop":
    case "a medium plate of slop":  
    case "medium":
	mess = "It doesn't taste so good, but you feel much better.";
	heal = 62;
	value = 250;
	strength = 30;
	type ="food";
	break;
    case "large slop":
    case "a large plate of slop":
    case "large":
	mess = "It doesn't taste so good, but you feel great!";
	heal = 100;
	value = 400;
	strength = 10;
	type = "food";
	break;
    case "small beer":
    case "a small warm beer":
	mess = "You choke down a small warm beer";
	heal = 5;
	value = 20;
	strength = 2;
	type = "alco";
	break;
    case "medium beer":
    case "a medium warm beer":
	mess = "You choke down a medium warm beer";
	value = 100;
	heal  = 25;
	strength = 12;
	type = "alco";
	break;
    case "large beer":
    case "a large warm beer":
	mess = "You choke down a large warm beer";
	heal = 50;
	value = 200;
	strength = 25;
	type = "alco";
	break;
    case "murky water":
    case "water":
	mess = "You drink the water, and it makes you hungry";
	value = 30;
	strength = -8;
	type = "food";
	break;
    case "stale coffee":
    case "coffee":
	mess = "You drink the coffee and it shocks some sense into you";
	value = 30;
	strength = -8;
	type = "alco";
	break;
    default:
	NF("The cook says: What, do you think this is a fine restaurant?\n");
	break;
    }

    if(TP->query_money() < value)
	NF("Cook says: That costs "+value+" gold coins.\n");

    if (type=="alco") {
	if(!TP->drink_alcohol(strength))
	    NF("The cook says: Why don't you have some coffee instead?\n");
    }

    else if(type=="food") {
	if(!TP->eat_food(strength))
	    NF("Cook says: You better watch your weight.\n");
    }

    write("You give the cook " + value + " coins.\n");
    TP->add_money(-value);
    TP->heal_self(heal);
    write(mess + "\n");
    say(PNAME + " orders something.\n");
    return 1;
}


