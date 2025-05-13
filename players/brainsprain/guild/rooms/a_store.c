#define TP     this_player()
#define TO     this_object()
#define MOVE   move_object
#define POISON "/players/brainsprain/guild/poison/"
#define MAX_LIST 50

inherit "room/room";

int value, i;
string name_of_item;

void reset(int arg)
{
    ::reset(arg);
    if (!present("eye of newt"))
	for(i=0;i<10;i++) 
	    MOVE(clone_object(POISON + "eye_newt"), TO);
    if (!present("dragons' blood"))
	for(i=0;i<12;i++) 
	    MOVE(clone_object(POISON + "dragon_blood"), TO);
    if (!present("tail of cockatrice"))
	for(i=0;i<5;i++) 
	    MOVE(clone_object(POISON + "cockatrice_tail"), TO);
    if (!present("powdered unicorns' horn"))
	for(i=0;i<2;i++) 
	    MOVE(clone_object(POISON + "uni_horn"), TO);
    if (!present("eye of newt"))
	for(i=0;i<10;i++) 
	    MOVE(clone_object(POISON + "eye_newt"), TO);
    if (arg)
	return;
    set_light(1);
    short_desc = "Store room";
    long_desc = "This is the store room below the Alchemist's Shop.\n";
    dest_dir = ({ POISON + "alch_shop","up" });
}

void init() 
{
    ::init();
}

inventory(str) {
    object ob;
    int max;

    max = MAX_LIST;
    ob = first_inventory(TO);

    if (!ob)
	return notify_fail("The Alchemist's Shop seems to be empty.\n");

    write("Alchemist's Shop\n~~~~~~~~~~~~~~~~\n");
    while(ob && max > 0) {
	if (!str || str == "all") {
	    list(ob);
	    max -= 1;
	}
	if (ob->id(str)) {
	    list(ob);
	    max -= 1;
	}
	ob = next_inventory(ob);
    }
}

void list(object ob) 
{
    int value;
    value = ob->query_alchemic_value();
    if (value) 
	write(value + value * 1/2 +"     "+ ob->short() +"\n");
}

value(item) {
    name_of_item = present(item);
    if (!name_of_item) {
	return notify_fail("Value what?\n");
    }
    value = name_of_item->query_alchemic_value();
    if (!value) {
	return 0;
    }
    write("The "+item+" would cost you "+(value+(value*1/2))+" gold coins.\n");
    return 1;
}

buy(item) {
    name_of_item = present(item);
    if (!name_of_item) {
	write("No such item in the store.\n");
	return;
    }
    value = name_of_item->query_alchemic_value();
    if (!value) {
	write("Item has no alchemical value.\n");
	return;
    }
    value = value + value * 1/2;
    if (this_player()->query_money() < value) {
	write("It would cost you "+value+" gold coins, which you don't have.\n");
	return;
    }
    if (!TP->add_weight(name_of_item->query_weight())) {
	write("You can't carry that much.\n");
	return;
    }
    TP->add_money(-value);
    write("Ok.\n");
    say(this_player()->query_name()+" haggles for "+item+".\n");
    transfer(name_of_item, TP);
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

store(item) {
    string short_desc,name;
    object ob;
    object *all;
    int i;

    short_desc = item->short();
    name = item->query_name();

    ob=0;
    if (name) ob=present(name,TO);
    else if (short_desc) ob=present(short_desc,TO);
    if (!ob) ob=first_inventory(TO);
    while(ob) {
	if (ob->short()==short_desc) {
	    move_object(item, TO);
	    destruct(item);
	    return;
	}
	ob = next_inventory(ob);
    }
    move_object(item, TO);

    all = all_inventory(TO);
    if (sizeof(all) > 40)
	for(i=40; i<sizeof(all); i++)
	    if (!living(all[i])) destruct(all[i]);
}
