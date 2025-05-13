inherit "/players/patience/guild/nweap/ninja_weapon";

void reset(int arg)
{
    ::reset(arg);
    if (!arg)
    {
	set_name("bisento");
	set_short("A bisento");
	set_long("A bisento is a spear with a long curved blade. It is a " +
		 "twohanded ninja weapon.\n");
	
	set_class(8);
	set_value(1000);
	set_weight(3);
	// set_can_throw( );
	set_two_handed();

	set_parry_class(4);
	set_critical_hit_factor(3);
    }
}
