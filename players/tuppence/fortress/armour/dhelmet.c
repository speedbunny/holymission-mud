inherit "obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag ==0)
{
set_name("helmet");
set_alias("helmet");
set_short("Black helmet");
set_long("A black horned helmet\n");
set_ac(2);
set_size(3);
set_type("helmet");
set_weight(2);
set_value(100);
}
}
