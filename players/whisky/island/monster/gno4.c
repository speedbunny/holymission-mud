
inherit "/players/whisky/island/monster/std_gnome";

void reset(int flag)
{
    ::reset(flag);

    if (flag==0)
    {
       set_name("cinze");
       set_gender(2);
       set_level(18);
    }
}

