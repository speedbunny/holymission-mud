inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0)
{
set_name("moldy shield");
set_alias("shield");
set_short("Moldy old shield");
set_long("This moldy old shield looks as if it will fall apart at any moment.\n");
set_ac(1);
set_size(3);
set_weight(2);
set_value(200);
set_type("shield");
}
}
