
inherit "/players/whisky/island/monster/std_gnome";

void reset(int flag)
{
    ::reset(flag);

    if (flag==0)
    {
       set_name("hnzzwnzz");
       set_gender(1);
       set_level(38);
    }
}

