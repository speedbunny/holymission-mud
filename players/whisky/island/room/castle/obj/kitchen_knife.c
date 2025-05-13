
/* kitchen knife */

inherit "/obj/weapon";

void reset(int flag)
{

    ::reset(flag);
    if (flag == 0)
    {
       set_name("kitchen knife");
       set_alias("knife");
       set_short(query_name());
       set_long("A long bloody kitchen knife.\n");
       set_weight(1);
       set_class(12);
       set_type(2);
       set_value(110);
    }
}


