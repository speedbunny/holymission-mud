inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("red cloak");
set_alias("cloak");
set_short("Red cloak");
set_long("A red cloak with a golden cloak pin.\n");
set_ac(2);
set_size(3);
set_weight(2);
set_value(1000);
set_type("armour");
}
}
