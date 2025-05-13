object newspaper, top_list;

reset(arg) {
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
    if (!newspaper || !present(newspaper)) {
	newspaper = clone_object("obj/newspaper");
	move_object(newspaper, this_object());
    }
    if (arg) return;
    set_light( 1);
}

short() {
    return "The Drunken Squire Pub";
}

init() {
    add_action("move"); add_verb( "south");
    add_action("order"); add_verb("order");
    add_action("order"); add_verb("buy");
}

move() {
    call_other(this_player(),"move_player", "south#players/ted/path/road2");
    return 1;
}

long() {
    write("You are in the Drunken Squire Pub.\n");
    write("You can order drinks here.\n\n");
    write("     Dark Ale         :   7 coins\n");
    write("     Mug O' Mud       :  20 coins\n");
    write("     Shockwave        :  70 coins\n");
    write("     Knight's Doom    : 200 coins\n\n");
    write("The only obvious exit is south.\n");
}

order(str) {
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "ale" || str == "dark") {
	mess = "That's good ale";
	heal = 1;
	value = 7;
	strength = 3;
    }
    else if (str == "shock" || str == "shockwave") {
        mess = "An electric shock jolts you into drunkeness";
	heal = 10;
	value = 70;
	strength = 8;
    } else if (str == "knight's doom" || str == "doom") {
        mess = "As the shot hits you stomach, you almost pass out!";
	heal = 33;
	value = 200;
	strength = 15;
    } else if (str == "mud" || str == "mug") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 20;
	strength = -2;
    } else {
       write("The bartender says: What do you want?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
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
    say(call_other(this_player(), "query_name") + " orders a " + str + ".\n");
if(call_other(this_player(), "query_money") > 12000) {
   write("As the bartender sees you overflowing purse of money,\n");
   write("he remembers the alcohol tax.......\n");
   call_other(this_player(), "add_money", -(value*3));
 }else
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
