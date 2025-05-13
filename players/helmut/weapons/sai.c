inherit "/obj/weapon";
#define TP this_player()
#define NAME query_name()

reset(arg)
{
    ::reset(arg);
    set_name("Silver Sai");
    set_alias("sai");
    set_hit_func(this_object());
    set_short("A Silver Sai");
    set_long(
      "This beautifully crafted weapon sits well in your palm.  The\n"+
      "guards sparkle sharply in the light, and the center blade\n"+
      "comes to an exceedingly piercing point.  Although this weapon\n"+
      "seems quite powerful, it can easily be hidden in a cloak\n"+
      "or other garment.  Stealthy fighters could make good use of\n"+
      "this sai.\n");
    set_weight(2);
    set_class(13);
    set_value(5000);
}

weapon_hit(ob)
{
    int guild;

    guild = this_player()->query_guild();
    if (random(17) <=4) 
    {
	printf("You lunge forward, and deeply imbed the three prongs\n"+
	  "of The Silver Sai into your opponent's flesh.\n");
	say("The Silver Sai whistles softly as "+TP->NAME+" slices and\n"+
	  "dices the opponent.\n",TP);
	if (guild == 8)
	    return(12+random(17));
	else
	    return (0+random(5));
    }
    if ( guild !=8)
    {
	write(
	  "You are overcome with the sudden urge to hurt yourself,\n"+
	  "and you begin sawing your arm off.\n");
	this_player()->hit_player(20 + random(80),7);
	return 0;
    }
    return 1;
}
int query_quest_object() {
    return 1;
}
