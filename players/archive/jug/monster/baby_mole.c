
inherit "obj/monster";

void reset(int arg)
{
    ::reset(arg);
    if (!arg)
    {
	set_name("baby mole");
	set_alias("mole");
	set_short("baby mole");
	set_long("This tiny mole searches blindly for its parents.\n");
	set_race("rodent");
	set_level(1);
	set_al(30);
	set_hp(30);
	set_wc(1);
	add_money(30);
    }
}

