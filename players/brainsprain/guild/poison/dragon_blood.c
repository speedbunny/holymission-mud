
inherit "/players/brainsprain/guild/poison/ingredient";

reset(arg)
{
    ::reset(arg);
    if(arg)
	return;
    set_name("dragons' blood");
    set_alias("blood");
    set_short("Dragons' blood");
    set_long("The thick red liquid is so obviously magical a barbarian "
      +"would detect it.\n");
    set_alchemic_value(290);
}

