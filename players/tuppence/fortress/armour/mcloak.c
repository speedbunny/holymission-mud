inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("green cloak");
set_alias("cloak");
set_short("Green cloak");
set_long("A big dark green cloak.\n");
set_ac(2);
set_size(4);
set_weight(2);
set_value(2000);
set_type("armour");
}
}
int query_mage_wear()
{
return 1;
}
