inherit "/players/patience/guild/nweap/spec_weapon";

void reset(int arg)
{
    if(!arg)
	set_security_function("is_nt_owner");
    
    ::reset(arg);
    
    if (!arg)
    {
	set_name( "ninja-to" );
	set_short( "A Ninja-to" );
	set_long("The ninja-to is a ninja's standard sword. It is " +
		 "approximately the length of a short sword, making it " +
		 "easier to conceal on the body. The ninja-to looks very " +
		 "sharp.\n");
	set_class(18);
	set_value(0);
	set_weight(6);

	set_critical_hit_factor(5);
	set_parry_class(4);
    }
}


