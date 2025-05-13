#define OWNERS         "/players/tatsuo/guild/nweap/weap_owners"

inherit "/players/tatsuo/guild/nweap/spec_weapon";

void reset(int arg)
{
    if(!arg)
    ::reset(arg);
    {
	set_name("daito");
	set_short("A daito");
	set_long("A daito is a long, slighty curved, sword. It is a ninja " +
		 "weapon.\nThe daito looks extremely sharp.\n");
	set_class(20);
	set_value(0);
	set_weight(8);

	set_critical_hit_factor(6);
	set_parry_class(7);
    }
}

