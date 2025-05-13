inherit "/players/darastor/ninja/obj/ninja_weapon";

void reset (int arg)
{
    ::reset(arg);

    if(!arg)
    {
	set_name("katana");
	set_short("A katana");
	set_long("A 3 foot long sword with a straight blade, used mainly " +
		 " by ninja and samurai.\n");
	set_critical_hit_factor(6);
	set_parry_class(10);
	set_class(15);
	set_value(500);
	set_type(3);
    }
}
