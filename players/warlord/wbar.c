

reset(arg) {
    if (arg) return;
    set_light( 1);
}

short() {
    return "In Warlord's bar";
}

init() {
    add_action("move"); add_verb("west");
    add_action ("order"); add_verb ("order");
    add_action ("order"); add_verb ("buy");
    add_action ("read"); add_verb ("read");
}

move() {
    object ob;
    this_player()->move_player("west#players/warlord/road2");
    return 1;
}


long() {
    write("You have entered the famous bar of Warlord. There is a barkeeper\n" +
      "standing behind a wooden desk and there are some barstools around.\n" +
      "The air is full of the smell of the famous Warlord's beer.\n" +
      "There is the menu written on a wooden sign behind the bar.\n" +
      "Just type <read menu> to see what we've got.\n" +
      "There is an exit to the west.\n");

}
read(str) {
    if(str == "menu"|| str == "shield" || str == "sign") {
	write("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	write("    Ambrosia (8000 coins)                            \n");
	write("    Undead Slammer (200 coins)                       \n");
	write("    Zombie Juice (100 coins)                         \n");
	write("    Wakeup (400 coins)                                \n");
	write("    Beer (20 coins)                                  \n\n");
	write("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	return 1;
    }
}
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
	write("You might feel the chaos in this world..order what??\n");
	return 1;
    }
    if (str == "wakeup") {
	mess = "Ahhhhh you feel refreshed again";
	heal = 1;
	value = 400;
	strength = -2;
    }
    else if (str == "beer") {
	mess = "A H H H H  you are enjoying the taste of a really good beer";
	heal = 6;
	value = 20;
	strength = 2;
    }
    else if (str == "slammer") {
	mess = "A h h h, that warms your body"; 
	heal = 30;
	value = 200;
	strength = 10;
    }
    else if (str == "ambrosia") {
	mess = "Yep, you are enjoying the best AHHHHH";
	heal = 100;
	value = 8000;
	strength = 4;
    }
    else if (str == "juice") {
	mess = "Well, such a zombie juice tastes fine";
	heal = 8;
	value = 100;
	strength = 8;
    } 
    else {
	write("The bartender laughs at you: Huuuu Huu HI HI we don't have that.\n");
	return 1;
    }

    if (call_other(this_player(), "query_money", 0) < value) {
	write("Alois says: That would cost you " + value + " gold coins,\nwhich you don't have.\n");
	return 1;
    }
    if (strength > (call_other(this_player(), "query_level") + 2)) {
	if (strength > (call_other(this_player(), "query_level") + 5)) {
	    /* This drink is *much* too strong for the player */
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
	write("The bartender says: I think you've had enough.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
	  str + " but the bartender refuses.\n");

	return 1;
    }
    write("You pay " + value + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " enjoys a " + str + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
