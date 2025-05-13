#define MAX_LIST	30

string SHOPROOM;
string SHOPEXIT;

set_shop_room(arg) { SHOPROOM=arg; }
set_shop_exit(arg) {SHOPEXIT=arg; }
clean_up(arg) { return 0; }

int value;
string name_of_item;

int sold;
query_sold() { return sold; }

short() {
    return "store room for the shop";
}

init() {
    add_action("shop", SHOPEXIT);
}

inventory(str)
{
    object ob;
    int max;
    if (!str)
	str = "all";
    max = MAX_LIST;
    ob = first_inventory(this_object());
    while(ob && max > 0) {
	if (str == "all") {
	    list(ob);
	    max -= 1;
	}
	else if ((str=="weapon" || str=="weapons") && ob->weapon_class()) {
	    list(ob);
	    max -= 1;
	}
	else if ((str=="armour" || str == "armours") && ob->armour_class()) {
	    list(ob);
	    max -= 1;
	}
	else if (ob->id(str)) {
	    list(ob);
	    max -= 1;
	}
	ob = next_inventory(ob);
    }
}

list(ob)
{
    int value;
    
    value = call_other(ob, "query_value", 0);
    if (value) {
	write(value*2 + ":\t" + call_other(ob, "short") + ".\n");
    }
}

value(item) {
    name_of_item = present(item);
    if (!name_of_item) {
	return 0;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
	return 0;
    }
    write("The "); write(item); write(" would cost you ");
    write(value*2); write(" gold coins.\n");
    return 1;
}

/* buy now returns -2, -1, 0, 1 on : too expensive, too heavy, not present, ok*/
buy(item) {
    name_of_item = present(item);
    if (!name_of_item) {
	write("No such item in the store.\n");
	return 0;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
	write("Item has no value.\n");
	return 0;
    }
    value *= 2;
    if (call_other(this_player(), "query_money", 0) < value) {
	write("It would cost you ");
	write(value); write(" gold coins, which you don't have.\n");
	return -2;
    }
    if (!call_other(this_player(), "add_weight",
		    call_other(name_of_item, "query_weight"))) {
	write("You can't carry that much.\n");
	return -1;
    }
    call_other(this_player(), "add_money", -value);
	sold += value;
    move_object(name_of_item, this_player());
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " buys " + item + ".\n");
	return 1;
}

shop() {
    call_other(this_player(), "move_player", "SHOPEXIT#"+SHOPROOM);
    return 1;
}

heart_beat()
{
    object ob, next_ob;
    ob = first_inventory(this_object());
    while(ob) {
	next_ob = next_inventory(ob);
	destruct(ob);
	ob = next_ob;
    }
}

reset(arg) {
    if (!arg)
	set_light(1);
    if (!present("torch")) {
	object torch;
	torch = clone_object("obj/torch");
	call_other(torch, "set_name", "torch");
	call_other(torch, "set_fuel", 2000);
	call_other(torch, "set_weight", 1);
	move_object(torch, this_object());
    }
}

long()
{
    write("All things from the shop are stored here.\n");
}

store(item)
{
    string short_desc;
    object ob;

    short_desc = call_other(item, "short");
    ob = first_inventory(this_object());
    while(ob) {
	if (call_other(ob, "short") == short_desc || item->id("bottle")) {
	    /* Move it before destruct, because the weight
	       has already been compensated for. */
	    move_object(item, this_object());
	    destruct(item);
	    return;
	}
	ob = next_inventory(ob);
    }
    move_object(item, this_object());
}
