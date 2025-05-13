#define OWNERS         "/players/patience/guild/nweap/weap_owners"

inherit "/players/patience/guild/nweap/spec_weapon";

void reset(int arg)
{
    if(!arg)
	set_security_function("is_kat_owner");
    ::reset(arg);
    if (!arg)
    {
	set_name("daito");
	set_short("A daito");
	set_long("A daito is a long, slighty curved, sword. It is a ninja " +
		 "weapon.\nThe daito looks extremely sharp.\n");
	set_class(20);
	set_value(0);
	set_weight(8);

        set_critical_hit_factor(1000);
	set_parry_class(7);
    }
}

