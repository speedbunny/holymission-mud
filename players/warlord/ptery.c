inherit "/obj/monster";

reset(arg)
{
    ::reset(arg);
    if (arg)
	return 1;
    set_name("pterodactyl");
    set_alias("ptery");
    set_short("Pterodactyl");
    set_long("This creature is among the largest winged dinosaur in existence\nShe is looking for food for her young..\n");
    set_level(20);
    set_wc(25);
    set_ac(12);
    set_hp(1000);
    add_money(2000);
    set_al(-100);
    set_aggressive(0);
    return 1;
}

query_moncreator()
{
    return "warlord";
}

query_monmaker()
{
    return 1;
}
