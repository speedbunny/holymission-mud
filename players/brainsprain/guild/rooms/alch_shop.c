inherit "room/room";
#include "/players/brainsprain/guild/headers.h"
object  Store_room;

reset(arg)
{
    ::reset(arg);
    if (!present("alchemist"))
      move_object(clone_object("/players/brainsprain/guild/monsters/alchemist"),
		  this_object());
    if (arg)
	return;
    set_light(1);
    short_desc = "Alchemist's Shop";
    long_desc =
    "You stand before a maze of glass beakers, vials, and\n"
    + "tubes.  Bright, flashy objects grab your attention.\n"
    + "You notice body parts from many exotic beasts.  You\n"
    + "realize that you must stand in an alchemist's shop.\n"
    + "Commands:      List     Sell    Value    Buy\n";
    items = ({
      "tubes", "The thin glass tubes connect boiling pots and beakers",
      "beakers", "Vessels for mixing alchemical concoctions",
      "vials", "Small glass bottles, carefully labeled as to avoid mixing them",
      "objects", "Small bits of copper, obviosously the result of alchemical "
      + "experiments",
      "parts", "You see tufts of fur, toenails, eyes, and other gruesome things",
    });
    dest_dir = ({
      "room/eastroad3", "west",
      ROOMDIR+"lab","up"
    });
    Store_room = ROOMDIR+"a_store";
}

init()
{
    ::init();
    add_action("list", "list");
    add_action("buy", "buy");
    add_action("sell", "sell");
    add_action("value", "value");
}

buy(str)
{
    if (!str)
	return notify_fail("Buy what?\n");
    if (this_player()->query_ghost())
	return notify_fail("You don't seem to carry anything.\n");

    Store_room->buy(str);
    return 1;
}

list(str)
{
    Store_room->inventory(str);
    return 1;
}

sell(str)
{
    object ob, *in;
    int i, do_destroy;

    if (!str)
	return notify_fail("Sell what?\n");

    if (str == "all") {
	in = all_inventory(this_player());
	for (i = 0; i < sizeof(in); i++)
	    if (!in[i]->drop() && in[i]->query_alchemic_value())
		do_sell(in[i]);
	write("Ok.\n");
	return 1;
    }
    if (!(ob = present(str, this_player())) && !(ob = present(str, this_object())))
	return notify_fail("There is no " + str + " present.\n");

    do_sell(ob);
    return 1;
}

do_sell(ob)
{
    int value, do_destroy;

    if (!(ob->query_alchemic()))
        return write("This store only deals in items of alchemic value.\n");
    if (!(value = ob->query_alchemic_value()))
	return notify_fail(ob->short() + " has no alchemic value.\n");

    if (ob->query_quest_item())
	do_destroy = 1;
    if (environment(ob) == this_player()) {
	int weight;
	if (ob->drop())
	    return notify_fail("That can't be sold here.\n");
	weight = ob->query_weight();
	if (!do_destroy)
	    this_player()->add_weight(-weight);
    }
    if (value > 1000) {
	write("The store can't afford to pay over 1000 gold ...\n");
	value = 1000;
    }

    write("You get " + value + " gold coins.\n");
    say(this_player()->query_name() + " sells " + ob->short() + ".\n");
    this_player()->add_money(value);
    if (do_destroy) {
	write("That valuable item is hidden away.\n");
	destruct(ob);
	return 1;
    }
    Store_room->store(ob);
    return 1;
}

value(str)
{
    object ob;
    int i, z;

    if (!str)
	return notify_fail("Value what?\n");
    z = 0;

    if (!(ob = present(str, this_player())) && !(ob = present(str, this_object())))
	z = 1;
    if (z && !(ob = present(str, find_object(Store_room))))
	return notify_fail("There is no " + str + " present.\n");
    if (!(i = ob->query_alchemic_value())) 
	return notify_fail(ob->short() + " has no alchemical value.\n");

    if (z)
    {
	write("The " + ob->short() + " costs " + (i + (i * 1 / 2)) + ".\n");
	return 1;
    }

    write(ob->short() + " is worth " + i + " gold coins.\n");
    return 1;
}

query_drop_caste()  {  return 1;  }
