inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("goblin helmet");
set_alias("helmet");
set_short("Goblin helmet");
set_long("This goblin helmet is old and worn out.\n");
set_ac(1);
set_size(3);
set_weight(1);
set_value(400);
set_type("helmet");
}
}
