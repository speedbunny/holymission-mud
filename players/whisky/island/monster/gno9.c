
inherit "/players/whisky/island/monster/std_gnome";

void reset(int flag)
{
    ::reset(flag);

    if (flag==0)
    {
       set_name("zrandrilla");
       set_gender(2);
       set_level(14);
    }
}

