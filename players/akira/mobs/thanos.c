inherit "obj/monster";
object staff;

reset(arg){
    ::reset(arg);

    set_name("Thanos");
    set_alias("thanos");
    set_short("Thanos the Evil Timelord");
    set_alt_name("timelord");
    set_long("This is Thanos Evil Timelord of the Vagabonds. He stands\n"+
      "about seven feet tall, and doesn't look human. The hate in\n"+
      "his eyes tells you how evil this man really is. You can tell\n"+
      "that he is gaining great pleasure at seening this world being\n"+
      "taken apart. You don't think it would be smart to start a fight\n"+
      "with this man!\n");
    set_number_of_arms(2);
    set_level(30);
    set_ac(20);
    set_wc(35);
    set_al(-1000);
    set_dead_ob( this_object() );
}



init () {
    ::init();
    add_action("block","timehold");
    add_action("block","timeburn");
}
block(arg){
    if(query_verb()=="timehold"){
	if(arg=="thanos"){
	    write("Thanos says: You'll have to try harder than that!\n");
	    return 1;
	}
    }
    if(query_verb()=="timeburn"){
	if(arg=="thanos"){
	    write("Thanos says: I know all your tricks, and that one will not work!\n");
	    return 1;
	}
    }
}


monster_died(ob) {
    write("As Thanos dies, a clock falls from his body and\n"+
      "lands on the floor and Thanos' evil corpse is sucked into\n"+
      "the clock.\n");
    move_object(clone_object(
	"/players/nylakoorub/4th/quest/clock"),
      environment(ob));
    destruct(ob);
    return 1;
}

