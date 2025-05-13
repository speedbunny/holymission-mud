#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if (arg) return;
    set_light( 1);
}

short() {
    return "Inside the Tavern Tent";
}

init() {
    add_action("move"); add_verb ("north");
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
	return;
    }
}
kill(str) {
    if (str=="merchant" || str=="wolfen merchant") {
	write(BS("Wolfen merchant whistles for his bouncer."+
	    "Bouncer says:  Come back when you have some manners!"));
	return 1;
    }
    else {
	return;
    }
}
move() {
    object ob;
    call_other(this_player(),"move_player",FPATH+"road7.c");
    return 1;
}


long() {
    write(BS("You have entered the Tavern Tent set up outside of the wolfen "+
       "mine. "+
       "A wolfen merchant smiles at you from over the counter and points "+
       "to a menu hanging on the wall.  From the amount of wolfen soldiers "+
       "in the tent, you surmise that this must be one of the more popular "+
       "places among those at the mine.  A serving wench comes up to you and "+
	"asks if you would like to make an order."));
    write(BS("The only obvious exit is north."));

}
read(str) {
    if(str == "menu") {
	write("-----------------------------------------------------\n");
	write(BS(" Welcome to the Tavern Tent"));
	write("-----------------------------------------------------\n\n");
	write(BS("    A howler (100 coins)"));
	write(BS("    A "));
	write(BS("    A blood line (25 coins)    "));
	write(BS("    A Dr. Pepper (100 coins)    "));
	write(BS("    Soul Suck (250 coins)    "));
	write(BS("    Doom (300 coins)    "));
	write("-----------------------------------------------------\n");
	return 1;
    }
}
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
	write("The wolfen merchant stares at you blankly.\n");
	return 1;
    }
    if (str == "howler") {
	mess = "You feel so good you let out a great howl!";
	heal = 180;
	value = 100;
	strength = 30; 
    }
    else if (str == "line" || str =="blood line") {
	mess = "AHH Straight off the tap and very fresh";
	heal= 40;
	value = 25;
	strength = 4;
    }
    else if (str == "shot" || str=="shot-gun") {
	mess = "WOW, that has some blast to it";
	heal = 200;
	value = 250;
	strength = 8;
    }
    else if (str == "pool" || str=="dead pool") {
	mess = "Has a funny water taste but goes down smooth";
	heal = 300;
	value =500;
	strength = 1;
    }
    else if (str == "doom" ) {
	mess = "You feel like you just went to hell and back !!";
	heal = 200;
	value = 300;
	strength = 4;
    }
    else if (str == "soul" || str == "soul suck" ) {
	mess = "You can hear the cries of a lost soul";
	heal = 170;
	value = 250;
	strength = 2;
    }
    else {
	write(BS("Wolfen merchant says:  Though our selection is extensive, we do not have that."));
	return 1;
    }

    if (call_other(this_player(), "query_money", 0) < value) {
      write("Wolfen merchant says:  That costs " + value + " gold coins.  Maybe you should try something less expensive.\n");
	return 1;
    }
    if (strength > (call_other(this_player(), "query_level") + 2)) {
	if (strength > (call_other(this_player(), "query_level") + 5)) {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
	      str + ", and immediately throws it up.\n");
	    write("You order a " + str + ", try to drink it, and throw up.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
	      str + ", and spews it all over you!\n");
	    write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
	}
	call_other(this_player(), "add_money", - value);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("Wolfen merchant says:  Why don't you have some coffee?\n");
	say(BS(call_other(this_player(), "query_name", 0) + " asks for a " +
	    str + " but the wolfen merchant refuses."));

	return 1;
    }
    write("You smack " + value + " coins on the counter for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " enjoys a " + str + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}

























