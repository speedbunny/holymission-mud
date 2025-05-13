inherit "/players/patience/guild/nweap/ninja_weapon";

void reset(int arg)
{
    ::reset(arg);
    if (arg)
    {
	set_name("bo-staff");
	set_alias("staff");
	set_alt_name("bo");
	set_short("A bo-staff");
	set_long("A heavy combat-staff, made of haselnut. It is a " +
		 "two-handed ninja-weapon.\n");
	set_class(5);
	set_value(200);
	set_weight(1);
	set_two_handed();
	
	set_critical_hit_factor(2);
	set_parry_class(1);
    }
}
