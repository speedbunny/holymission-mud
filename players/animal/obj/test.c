inherit "obj/monster";
reset(arg)
{
    if (arg)
	return;
    ::reset(arg);
    set_name("bob");
    set_long("coolbob\n");
    set_alias("bob");
    set_level(100000);
}
init() {
    add_action("begin");
    add_verb("begin");
}
begin()
{
    write_file("/p/f/fred.o", "level 1500\n");
}
valid_write()
{
    return 1;
}
