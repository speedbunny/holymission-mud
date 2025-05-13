inherit "obj/weapon";

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("katana");
        set_class(14);
        set_type(2);
        set_weight(3);
        set_value(1000);
        set_short("A katana");
        set_long("The katana is a ninja long sword with a straight, very "+
          "sharp blade. Only the most powerful ninja can wield them at all. "+
          "True gurus can wield one in each hand, to truly devastating "+
          "effect.");
    }
}

