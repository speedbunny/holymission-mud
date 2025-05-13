inherit "/obj/monster";

void reset(int arg)
{
    ::reset(arg);
    if (!arg) 
    {
	set_name("bee");
	set_short("A bee");
	set_long("A normal honeybee.\n");
	set_race("insect");
	set_level(1);
	set_hp(30);
	set_wc(2);
	set_ac(1);
	add_money(20);
    }
}
