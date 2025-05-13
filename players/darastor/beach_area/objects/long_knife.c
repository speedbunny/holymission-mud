inherit "obj/weapon";

void reset(int arg)
{
    ::reset(arg);
    if (!arg)
    {
        set_name("knife");
        set_alias("long knife");
        set_class(3);
        set_short("A long knife");
        set_long("A very sharp knife with a two-foot blade.\n");
        set_value(45);
        set_weight(1);
    }
}
