inherit "/players/patience/guild/nweap/ninja_weapon";

void reset(int arg)
{
    ::reset(arg);
    
    if (!arg)
    {

	set_name("naginata");
	set_short("A naginata");
	set_long("A naginata is a long pole with a curved blade.  It is" +
		 "a two-handed ninja-weapon.  Looks like it could do " +
		 " someone a nasty injury.\n");
	set_class(9);
	set_value(1500);
	set_weight(5);
	set_can_throw( );
	set_two_handed();

	set_critical_hit_factor(3);
	set_parry_class(2);
    }
}
