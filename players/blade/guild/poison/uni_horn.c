
inherit "/players/blade/guild/poison/ingredient";

reset(arg)
{
    ::reset(arg);
    if (arg)
	return;
    set_name("powdered unicorns' horn");
    set_alias("horn");
    set_short("Powdered Unicorns' Horn");
    set_long("A bottle of the most valueable magical ingredient,\n"
      + "powdered unicorns' horn.  The ivory powders glistens with\n"
      + "a sparkling magical radiance.\n");
    set_alchemic_value(600);
}

