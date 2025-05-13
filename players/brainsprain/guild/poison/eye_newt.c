
inherit "/players/brainsprain/guild/poison/ingredient";

reset(arg)
{
    ::reset(arg);
    if(arg)
	return;
    set_name("eye of newt");
    set_alias("eye");
    set_short("Eye of Newt");
    set_long("Within the thick glass bottle is an eye of a newt.\n"
      +"You think you are being watched.\n");
    set_alchemic_value(175);
}
