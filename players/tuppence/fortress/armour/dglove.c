inherit "obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("gloves");
set_alias("glove");
set_short("Spiked gloves");
set_long("Pair of spiked gloves\n");
set_ac(1);
set_type("glove");
set_weight(2);
set_value(500);
}
}
