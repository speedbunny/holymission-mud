inherit "/obj/armour";
void reset(int flag)
{
    ::reset(flag);
    if(flag == 0)
    {
	set_name("firey leggings");
	set_alias("leggings");
	set_short("Firey leggings");
	set_long("These leggings look like good armour.\n");
	set_ac(2);
	set_size(3);
	set_weight(2);
	set_value(3000);
	set_type("leg");
    }
}
int query_monk_wear()
{
    return 1;
}
