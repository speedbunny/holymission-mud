inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("silver crown");
set_alias("crown");
set_short("Silver crown");
set_long("A tiny silver crown.\n");
set_ac(1);
set_size(3);
set_weight(1);
set_value(500);
set_type("helmet");
}
}
