inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("alligator skin");
set_alias("skin");
set_short("Skin of a alligator");
set_long("This is a tough black skin of a alligator.\n");
set_ac(2);
set_size(4);
set_weight(3);
set_value(2000);
set_type("armour");
}
}
