inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("blue robe");
set_alias("robe");
set_short("Pale blue robe");
set_long("A pale blue robe that used to belong to a mage guard.\n");
set_ac(1);
set_size(3);
set_weight(1);
set_value(500);
set_type("robe");
}
}
int query_mage_wear()
{
return 1;
}
