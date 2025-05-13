inherit "/players/patience/guild/nweap/ninja_weapon";

void reset(int arg)
{
    ::reset(arg);
    
    if (!arg)
    {
	set_name("nunchaku");
	set_short("a nunchaku");
	set_long("Two handles connected to a chain, specially  made by a " +
		 "weaponmaster for use by the ninja guild.\n");
	set_class(12);
	set_value(2300);
	set_weight(4);
   
	set_critical_hit_factor(3);
	set_parry_class(2);
    }
}
