inherit "/obj/weapon";
#define TP this_player()
#define NAME query_name()

reset(arg)
{
    ::reset(arg);
    set_name("Ivory Jo");
    set_alias("jo");
    set_hit_func(this_object());
    set_short("The Ivory Jo");
    set_long(
      "This elegant weapon is hewn from the tusk of a fallen giant elephant.\n"+
      "The carvings on it are masterful, and the thick shaft is sturdy as\n"+
      "granite.  Given the Jo's great strength, you are surprised at how\n"+
      "light it is.  In the hands of one well versed in combat of the mind\n"+
      "and the ways of discipline, this could be a fearsome weapon.\n");
    set_weight(6);
    set_class(19);
    set_value(5000);
}

weapon_hit(ob)
{
    int guild;

    guild = this_player()->query_guild();
    if (random(10) <=3)
    {
	printf("You do a deft move with the Ivory Jo, smashing into your\n"+
	  "opponent's teeth.\n");
	say(" "+TP->NAME+" deftly twirls the Ivory Jo in a confusing pattern,\n"+
	  "finishing the move with a smash in the opponent's teeth.\n",TP);
	if (guild == 7)
	    return(10+random(18));
	else
	    return (0+random(5));
    }
    if ( guild !=7)
    {
	write(
	  "You lose control of your fury, and start bashing yourself in\n"+
	  "the foot, smashing through bone and sinew.\n");
	this_player()->hit_player(20 + random(82),4);
	return 0;
    }
    return 1;
}
int query_quest_object() {
    return 1;
}
query_monk_wield() {
    return 1;
}
