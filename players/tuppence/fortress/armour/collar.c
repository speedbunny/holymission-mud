inherit "/obj/armour";
void reset(int flag)
{
    ::reset(flag);
    if(flag == 0)
    {
	set_name("control collar");
	set_alias("collar");
	set_short("Control collar");
	set_long("A control collar usually worn by the hounds at the Fortress Haden.\n");
	set_type("amulet");
	set_size(3);
	set_ac(1);
	set_weight(1);
	set_value(500);
    }
}
