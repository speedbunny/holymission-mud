inherit "/obj/armour";
void reset(int flag)
{
    ::reset(flag);
    if(flag == 0)
    {
	set_name("silver web");
	set_alias("web");
	set_short("Silver web");
	set_long("A big silver web that looks like it would be a good shield.\n");
	set_ac(2);
	set_size(4);
	set_weight(2);
	set_value(1000);
	set_type("shield");
    }
}
