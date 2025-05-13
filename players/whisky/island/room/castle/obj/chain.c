
/* chain */

inherit "/obj/weapon";

void reset(int flag)
{

    ::reset(flag);
    if (flag == 0)
    {
       set_name("long chain");
       set_alias("chain");
       set_short("long chain");
       set_long("A long iron chain.\n");
       set_weight(3);
       set_class(15);
       set_type(1);
       set_value(150);
    }
}


