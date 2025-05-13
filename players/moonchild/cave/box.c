int a,n;

id(str) {
    return str=="box";
}

short() {
    return "A large box of junk";
}

long() {
    write("This is a large box, full of junk. Perhaps you should search it?\n");
}

reset(arg) {
    if(!arg) move_object(this_object(), "players/moonchild/cave/link");
    a=0;
    n=0;
}

init() {
    add_action("search", "search");
}

search(str) {
    object ob;
    if(!id(str)) return;
    a++;
    switch(random(7)) {
    case 0..1:
	write("You find some money.\n");
	this_player()->add_money(5+random(46));
	break;
    case 2:
	write("You jab your hand on something sharp! Ouch!\n");
	this_player()->misc_hit(5+random(21), 2, 0); 
	break;
    case 3:
	write("Something horrible crawls out of the box!\n");
	ob=clone_object("obj/monster");
	ob->set_name("giant slug");
	ob->set_race("slug");
	ob->set_short("A giant slug");
	ob->set_level(18);
	ob->set_long("A horrid slimy giant slug, six feet tall!\n");
	ob->set_aggressive(1);
	ob->set_chance(20);
	ob->set_spell_dam(40);
	ob->set_spell_mess1("The slug slimes its attacker!\n");
	ob->set_spell_mess2("The slug slimes you!\n");
	ob->misc_hit(0, 0, 0);
	move_object(ob, environment());
	break;
    case 4:
	write("You feel your money draining out of your pocket!\n");
	this_player()->add_money(-10-random(101));
	break;
    case 5:
	write("You feel a horrible whiff of air and wretch violently.\n");
	if(!present("Disease", this_player())) {
	    move_object(ob=clone_object("players/moonchild/cave/disease"),
	      this_player());
	    ob->start();
	}
	break;
    case 6:
	if(!n) {
	    write("You find a small needle.\n");
	    ob=clone_object("obj/treasure");
	    ob->set_id("needle");
	    ob->set_short("A small needle");
	    ob->set_weight(0);
	    ob->set_value(10);
	    ob->set_long("A small needle.\n");
	    move_object(ob, this_player());
	    n=1;
	}
	else write("You find nothing.\n");
	break;
    }
    if( a >= 8 )
    {
	destruct( this_object() );
	write( "The box explodes with a loud concusssion.\n");
    }
    return 1;
}
