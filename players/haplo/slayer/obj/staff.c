
inherit "/obj/treasure";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
        set_name("staff of archanton");
        set_alias("staff");
        set_short("Staff of Archanton");
        set_long("This is the golden Staff of Archanton. It looks extremely \n"+
                 "valuable and has beautiful carvings etched all over it.\n");
        set_value(3000);
        set_weight(4);

return 1;
}
