inherit "/obj/armour";
void reset(int flag)
{
::reset(flag);
if(flag == 0);
{
set_name("flame belt");
set_alias("belt");
set_short("Flame belt");
set_long("It is a flame belt from a fire spirit. The belt is made out of\n"+
	 "magical flames, and has a large fire opal in the middle.\n");
set_ac(2);
set_size(3);
set_weight(1);
set_value(2000);
set_type("armour");
}
}
