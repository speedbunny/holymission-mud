
inherit "obj/treasure";

reset(arg) {
    ::reset(arg);
    if(arg)
	return;
    set_name("blackthorn bush");
    set_alias("bush");
    set_alt_name("blackthorn");
    set_short("A blackthorn bush");
    set_long("This is the legendary blackthorn bush, whose roots yield the most powerful\n"
      + "potions know to Holy Mission.  Perhaps you can dig one up.\n");
}

query_alchemic()       {  return 1;  }

get() {  return 0;  }

init() {
    ::init();
    add_action("dig_root","dig");
}

dig_root(str) {
    object root;
    int i;

    if (!str || str!="root")
	return notify_fail("Dig what?\n");
    root = clone_object("/guild/master"->query_dir(1)+"/poison/root");
    write("You dig into the soil beneath the blackthorn bush and find a root.\n");
    say(this_player()->query_name() + " digs up a blackthorn root.\n");
    transfer(root,environment(this_object()));
    i = 7+random(20);
    if(i < 2) {
	write("The bush seems to wilt then dies.\n");
	destruct(this_object());
    }
    return 1;
}
