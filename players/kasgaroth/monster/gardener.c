
inherit "obj/monster";

void reset(int arg)
{
    ::reset(arg);
    if (!arg) 
    {
	set_name("gardener");
	set_short("The gardener");
	set_long("This is the gardener of this garden.\n" +
	  "He looks rather busy, chasing away vermin from his plants.\n");
	set_race("human");
	set_level(15);
	set_ac(99);
	load_chat(10,({
	    "The gardener says: Hello there!\n",
	    "The gardener says: Can you kill some vermin for me?\n",
	    "The gardener says: Those darn moles.\n",
	    "The gardener says: I love my honey.\n",
	    "The gardener says: You know those rabbits breed like...\n",
	    "The gardener scratches his head.\n",
	    "The gardener rakes a bit.\n",
	    "The gardener shrugs.\n",
	    "The gardener blushes.\n",
	  }));
    }
}

void init()
{
    ::init();
    add_action("ask_weapon", "ask");
}

int ask_weapon(string str) 
{
    object shears;
    if (str == "gardener for shears" || str == "gardener for weapon" ||
      str == "for shears" || str == "for weapon")
    {
	write("You ask the gardener for a weapon.\n");
	say(this_player()->query_short_name() + " asks the gardener " +
	  "for a weapon.\n");
	if(!present("shears", this_player()))
	{
	    write("Gardener says: Ahh, now you can help me keep my garden " +
	      "clean.\n");
	    say("Gardener says to " + this_player()->query_short_name() +
	      ": Now you can help me keep my garden clean.\n");
	    write("The gardener gives you some pruning shears.\n");
	    say("The gardener gives "+this_player()->query_name()+" some pruning shears.\n");
	    shears = clone_object("/players/jug/obj/p-shears");
	    transfer(shears, this_player());
	    return 1;
	}
	write("Gardener says: I have already given you a weapon.\n");
	tell_room(environment(this_object()),
	  "'Go away!!!, the gardener shouts.\n");
	return 1;
    }
    write("Ask for what?\n");
    return 1;
}

enter_inventory(ob)
{
    if(ob->id("honey"))
    {
	destruct(ob);
	tell_room(environment(this_object()),"The gardener proclaims,'Honey! "
	  +"My favorite!'\n");
	this_player()->add_money(50);
	write("The gardener rewards you with a few coins and a big smile.\n");
	return 1;
    }
}
