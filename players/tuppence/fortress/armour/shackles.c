inherit "/obj/armour";
void reset(int flag)
{
    ::reset(flag);
    if(flag == 0)
    {
	set_name("shackles");
	set_alias("shackle");
	set_short("Pair of shackles");
	set_long("A pair of shackles, usually worn by slaves.\n");
	set_ac(1);
	set_size(3);
	set_weight(2);
	set_value(100);
	set_type("bracelet");
    }
}
