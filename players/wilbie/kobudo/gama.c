inherit "/players/patience/guild/nweap/ninja_weapon";

void reset(int arg)
{
    ::reset(arg);
    if (!arg)
    {	
	set_name("kusari-gama");
	set_alias("gama");
	set_short("A kusari-gama");
	set_long("A Kusari-Gama is a Kama with a weighted chain attached " +
		 "to the butt end of the handle. It is a very good ninja " +
		 "weapon.");
	set_class(10);
	set_value(2000);
	set_weight(3);
	set_can_throw( );

	set_critical_hit_factor(4);
	set_parry_class(5);
    }
}
