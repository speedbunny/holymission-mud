inherit "/players/tatsuo/guild/nweap/ninja_weapon";

void reset(int arg)
{
    ::reset(arg);

    if (!arg)
    {
	set_name("nagimaki");
	set_short("A nagimaki");
	set_long("A Nagimaki is a shortened version of the naginata.\n" +
		 "It is a pretty effective two-handed ninja weapon.");
	set_class(7);
	set_value(600);
	set_weight(3);
	set_critical_hit_factor(3);
	set_parry_class(2);
	set_can_throw( );
	set_two_handed();
    }
}
