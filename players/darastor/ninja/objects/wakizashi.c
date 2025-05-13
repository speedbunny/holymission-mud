inherit "obj/weapon";

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("wakizashi");
        set_class(12);
        set_type(2);
        set_weight(2);
        set_value(500);
        set_short("A wakizashi");
        set_long("The wakizashi is a long ninja sword with a curved blade. "+
          "Should be possible to seriously hurt someone with one of "+
          "these.\n");
    }
}

