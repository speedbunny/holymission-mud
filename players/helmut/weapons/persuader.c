inherit "/obj/weapon";
#define TP this_player()
#define NAME query_name()

reset(arg)
{
    ::reset(arg);
    set_name("The Persuader");
    set_alt_name("persuader");
    set_alias("club");
    set_hit_func(this_object());
    set_short("The Persuader");
    set_long(
      "You have never seen a club like this before, and you can't help but\n"+
      "suppress a chortle.  The shaft is hot pink, with bold, green\n"+
      "letters proclaiming that this is, indeed, 'The Persuader'.  The\n"+
      "shaft is topped, however, with the skull of a Velociraptor which\n"+
      "has been dipped in liquid mithril, and painted bright yellow.  The\n"+
      "club is about five feet long, and you think its weight could do\n"+
      "some seriously barbaric damage to an opponent.\n");
    set_weight(10);
    set_class(20);
    set_value(4500);
}

weapon_hit(ob)
{
    int guild;

    guild = this_player()->query_guild();
    if (random(10) <=3)
    {
	printf("You swing The Persuader in a thundering arc, smashing through\n"+
	  "your opponent's pitiful defences and pulverizing flesh and bone\n");
	say(" "+TP->NAME+" brings The Persuader down in a devastating arc,\n"+
	  "pulverizing bones and mashing flesh.\n",TP);
	if (guild == 11)
	    return(25+random(25));
	else
	    return (0+random(5));
    }
    if ( guild !=11)
    {
	write(
	  "The Persuader intones: 'You no allowed to use me!', and\n"+
	  "begins whapping you in the side of the head.\n");
	this_player()->hit_player(30 + random(100),15);
	return 0;
    }
    return 1;
}
int query_quest_object() 
{
    return 1;
}
