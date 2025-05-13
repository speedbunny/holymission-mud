#define Speak(x) write("The innkeeper says: " + x + "\n");

inherit "room/inn";

reset(arg) {
  cm=20;
  mm=10;
  rmm=5;
  if(arg) return;
  set_light(1);
  short_desc="Traveller's Inn";
  long_desc="You are in the Traveller's Inn. You can buy\n"
	+ "food here, but there is not much of a choice.\n";
  dest_dir=({ "players/moonchild/gnome/wroad3", "south" });
  items=({ "menu", "The menu is ...." });
  property=({ "no_teleport" });
}

show_menu() {
  write("\n");
  write(cm||mm||rmm ? "1: Meat stew      "+cm+ " at 25 gp\n"+
	"2: Snails         "+mm+ " at 50 gp\n"+
	"3: Rabbit steak   "+rmm+" at 75 gp\n"+
	"4: Mug of ale           5 gp\n\n"+
	"Use 'buy <number>' to buy the desired food.\n\n" :
	"We have completely sold out...come back later.\n\n");
  return;
}

buy(s) {
  if(!s) {
    Speak("What do you want to buy?");
    return 1;
  }
  switch(s) {
    case "1":
	if(!cm) return no_food();
	if(!pays(25)) return 1;
	cm--;
	return tease(4);
	break;
    case "2":
	if(!mm) return no_food();
	if(!pays(50)) return 1;
	mm--;
	return tease(7);
	break;
    case "3":
	if(!rmm) return no_food();
	if(!pays(75)) return 1;
	rmm--;
	return tease(10);
	break;
    case "4":
	if(!pays(5)) return 1;
	if(!this_player()->drink_alco(3)) {
	  Speak("I don't think you're in a fit state to drink that!");
	  this_player()->add_money(5);
	} else {
	  write("You drink a mug of gnomish ale.\n");
	  say(this_player()->query_name() + " drinks a mug of gnomish ale.\n");
	}
        return 1;
	break;
    default:
	Speak("What do you want to buy?");
	return 1;
	break;
  }
}

tease(n) {
  if(this_player()->eat_food(n))
	write("You just can't manage to eat the food.\n");
  else {
    this_player()->heal_self(n*2);
    write("You wolf the food down.\n");
  }
  return 1;
}
