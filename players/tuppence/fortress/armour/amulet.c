inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("emerald amulet");
set_alias("amulet");
set_short("Emerald amulet");
set_long("A large emerald amulet with a black aura around it.\n");
set_ac(1);
set_size(3);
set_weight(2);
set_value(2000);
set_type("amulet");
}
}
