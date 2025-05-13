inherit "/obj/weapon";
#define TP this_player()
#define NAME query_name()

reset(arg)
{
    ::reset(arg);
    set_name("Adamantite Dagger");
    set_alias("dagger");
    set_hit_func(this_object());
    set_short("Adamantite Dagger");
    set_long(
      "This dagger is about 20cm long, and incredibly light.  It seems\n"+
      "unbreakable, and the blade feels like it it could cut solid rock.\n"+
      "It gleams dully in the light as you heft it to check the balance.\n"+
      "You get the feeling that there is POTENT magic in this dagger,\n"+
      "and that a mage would be needed to unlock its secrets.\n");
    set_weight(1);
    set_class(9);
    set_value(4500);
}

weapon_hit(ob)
{
    int guild;

    guild = this_player()->query_guild();
    if (random(10) <=3)
    {
	printf("Blue and purple lightning bolts sizzle from the end of the dagger!\n");
	say("The dagger glows blue and purple as "+TP->NAME+" flings\n"+
	  "lightning bolts from the tip.\n",TP);
	if (guild == 5)
	    return(10+random(60));
	else
	    return (0+random(5));
    }
    if ( guild !=5)
    {
	write(
	  "The dagger becomes white hot in your hand, searing flesh\n"+
	  "to the bone in a most excruciating manner.\n");
	this_player()->hit_player(20 + random(80),7);
	return 0;
    }
    return 1;
}
