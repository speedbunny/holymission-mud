inherit "/obj/armour";
void reset(int flag)
{
    ::reset(flag);
    if(flag == 0)
    {
	set_name("boots");
	set_alias("boot");
	set_short("Leather boots");
	set_long("A big pair of leather boots\n");
	set_ac(1);
	set_size(3);
	set_type("boot");
	set_weight(1);
	set_value(100);
    }
}
