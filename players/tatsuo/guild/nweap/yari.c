inherit "/players/tatsuo/guild/nweap/ninja_weapon";

void reset(int arg)
{
    ::reset(arg);
    if (!arg)
    {
	set_name("yari");
	set_short("A yari");
	set_long("A yari is a spear with a long straight blade. It is a " +
		 "two-handed ninja-weapon and looks reasonably effective.\n");
	set_class(6);
	set_value(500);
	set_weight(3);
	set_two_handed();

	set_critical_hit_factor(2);
	set_parry_class(2);
    }
}
