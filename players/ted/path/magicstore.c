#define MAX_LIST        30
#define MAX_SHOP_VALUE 1000

int value;
string name_of_item;

short() { return "store room for the magic shop"; }

inventory(str) {
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
        ob = next_inventory(ob);
    }
}

list(ob) {
    int value;
    value = call_other(ob, "query_value");
    if (value) {
        write(value*2+value + ":\t" + call_other(ob, "short") + ".\n");
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
    write((value*2)+value); write(" gold_coins.\n");
    return 1;
}

buy(item) {
    name_of_item = present(item);
    if (!name_of_item) {
        write("No such item in the store.\n");
        return;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
        write("Item has no value.\n");
        return;
    }
    value = (value*2)+value;
    if (call_other(this_player(), "query_money", 0) < value) {
        write("It would cost you ");
        write(value); write(" gold coins, which you don't have.\n");
        return;
    }
    if (!call_other(this_player(), "add_weight",
                    call_other(name_of_item, "query_weight"))) {
        write("You can't carry that much.\n");
        return;
    }
    call_other(this_player(), "add_money", 0 - value);
    move_object(name_of_item, this_player());
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " buys " + item + ".\n");
}

fill() {
    if(!present("identify")) {
     move_object(clone_object("players/ted/items/identify"),this_object());
     }
    if(!present("ball")) {
     move_object(clone_object("players/ted/items/crystal_ball"),this_object());
     }
    if(!present("polymorph")) {
     move_object(clone_object("players/ted/items/poly_scroll"),this_object());
     }
#if 0
    if(!present("ash scroll")){
     move_object(clone_object("players/ted/items/summon_scroll"),this_object());
     }
#endif
    if(!present("wand of fire")) {
      move_object(clone_object("players/ted/items/wand_of_fire"),this_object());
     }
    if (!present("bag")) {
        object bag;
        bag = clone_object("players/ted/items/bag_of_holding");
	move_object(bag, this_object());
    }
}

reset(arg) {
  if (!arg) set_light(1);
  call_other("players/ted/random_magic","make_item",this_object(),30);
  call_other("players/ted/random_magic","make_item",this_object(),30);
  call_other("players/ted/random_magic","make_item",this_object(),30);
  fill();
}

long() { write("All things from the magic shop are stored here.\n"); }

store(item) {
    string short_desc;
    object ob;

    short_desc = call_other(item, "short");
    ob = first_inventory(this_object());
    while(ob) {
        if (call_other(ob, "short") == short_desc) {
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
