inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag ==0)
{
set_name("grey ring");
set_alias("ring");
set_short("Grey ring");
set_long("A small grey ring, with a tiny emerald set in the middle\n");
set_ac(1);
set_size(3);
set_weight(1);
set_value(1000);
set_type("ring");
}
}
