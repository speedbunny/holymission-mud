inherit "obj/weapon";

void reset(int arg)
{
    ::reset(arg);
    if (!arg)
    {
        set_name("cutlass");
        set_class(4);
        set_short("A steel cutlass");
        set_long("A cutlass with a curved blade and a large hand guard.\n");
        set_value(65);
        set_weight(2);
    }
}
