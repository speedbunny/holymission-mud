inherit "/players/whisky/obj/std_dragon";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_colour("steel");
        set_age(2);
     }
}
