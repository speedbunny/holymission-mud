inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("white slime");
set_alias("slime");
set_short("White slime");
set_long("Some white slime from a BIG slug!\n");
set_ac(2);
set_size(3);
set_weight(2);
set_value(500);
set_type("armour");
}
}
