inherit "/players/whisky/obj/std_dragon";

void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
       set_colour("golden");
       set_age(12);
    }
}
