inherit "/obj/armour";
void reset(int flag)
{
    ::reset(flag);
    if(flag == 0)
    {
	set_name("metal headband");
	set_alias("headband");
	set_short("Metal headband");
	set_long("This is a metal headband with a large emerald and black pearl in the\n"+
	  "middle of it. Ancient runes cover the headband.\n");
	set_ac(2);
	set_size(3);
	set_weight(1);
	set_value(1000);
	set_type("helmet");
    }
}
int query_mage_wear()
{
    return 1;
}
