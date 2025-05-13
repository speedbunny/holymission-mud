inherit "/obj/weapon";

reset(arg)
{
    ::reset(arg);
    set_name("sword");
    set_alias("longsword");
    set_alt_name("sword of ultimate annihilation");
    set_hit_func(this_object());
    set_short("Sword of Ultimate Annihilation");
    set_long(
      "Totally black, this sword seems to be crafted of anti-matter.\n"+
      "It looks ominous as hell, and almost cries out at you to wield it.\n"+
      "It is well over 1.8 metres in length, and the blade is about 23 cm\n"+
      "wide.  It looks very deadly, and imbued with magic...\n");
    set_weight(10);
    set_class(0);
    set_value(2000);
}

weapon_hit(ob)
{
    if (random(10) <=5)
    {
	if(ob->query_strength() > 15)
	    write("You massacre your opponent with a devastating blow.\n");
	this_player()->message("massacre's the opponent with a devastating blow\n");
	return (0+random(2));
    }
    return 0;
}
