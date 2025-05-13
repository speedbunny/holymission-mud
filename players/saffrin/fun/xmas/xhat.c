inherit "/obj/armour";
void reset(int flag)
{
    ::reset(flag);
    if(flag == 0)
    {
	set_name("A santa hat");
	set_alias("hat");
	set_short("A bright red santa hat");
	set_long("This is a bright red santa hat with a jingle bell on its end.\n");
	set_ac(1);
	set_weight(0);
	set_value(0);
	set_type("helmet");
    }
}
query_auto_load()  {
    return "/players/saffrin/fun/xmas/xhat:";
}
drop() {
    return 1;
}
