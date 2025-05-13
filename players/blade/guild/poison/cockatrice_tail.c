
inherit "/players/blade/guild/poison/ingredient";

reset(arg)
{
    ::reset(arg);
    if (arg)
	return;
    set_name("tail of cockatrice");
    set_alias("tail");
    set_short("Tail of cockatrice");
    set_long("This long, plumed tail is obviously from the highly magical "
      +"creature,\nthe cockatrice.\n");
    set_alchemic_value(430);
}
