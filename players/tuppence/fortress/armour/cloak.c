inherit "/obj/armour";
void reset(int flag)
{
    ::reset(flag);
    if(flag == 0)
    {
	set_name("brown cloak");
	set_alias("cloak");
	set_short("Brown cloak");
	set_long("It's a plain brown cloak.\n");
	set_ac(2);
	set_size(4);
	set_weight(2);
	set_value(500);
	set_type("armour");
    }
}
