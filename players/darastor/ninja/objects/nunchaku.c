inherit "obj/weapon";

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("nunchaku");
        set_alias("flail");
        set_alt_name("rice flail");
        set_class(8);
        set_type("nin");
        set_weight(2);
        set_value(100);
        set_short("A nunchaku");
        set_long("The nunchaku is a ninja weapon - a rice flail small "+
          "enough to wield one-handed. An expert ninja might be able to "+
          "wield two of these at once, with devastating effects on his or "+
          "her opponents.\n");
    }
}

void init()
{
    ::init();
    write(query_weapon_type()+"\n");
}

