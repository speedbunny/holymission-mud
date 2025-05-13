inherit "/players/patience/guild/nweap/ninja_weapon";

void reset(int arg)
{
    ::reset(arg);
    
    if (!arg)
    {
	set_name("kyoketsu-shogi");
	set_short("A kyoketsu-shogi");
	set_alias("shogi");
	set_long("A kyoketsu-shogi is a long winding rope with a sharp " +
		 "piercing blade attached on the end.  This is a ninja "+
		 "weapon that takes years of practice and honor to learn " +
		 "how to handle.\n");
	set_class(14);
	set_value(4000);
	set_weight(5);
	set_can_throw();

	set_critical_hit_factor(3);
	set_parry_class(3);
    }
}
