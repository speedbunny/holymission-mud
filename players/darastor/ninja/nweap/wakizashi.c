inherit "/players/patience/guild/nweap/spec_weapon";

void reset(int arg)
{
    if(!arg)
	set_security_function("is_waki_owner");
    
    ::reset(arg);
    
    if (!arg)
    {
	set_name("wakizashi");
	set_short("A wakizashi");
	set_long("A wakizashi is a medium length, slightly curved, sword. "+
		 "It is one of the favoured weapons of the ninja. It looks " +
		 "very sharp.\n" );
	set_class(18);
	set_value(0);
	set_weight(6);

	set_critical_hit_factor(5);
	set_parry_class(5);
	
    }
}

