inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("red helmet");
set_alias("helmet");
set_short("Dark red helmet");
set_long("A dark red helmet with silver runes carved into it.\n");
set_ac(2);
set_size(3);
set_weight(1);
set_value(2000);
set_type("helmet");
}
}
