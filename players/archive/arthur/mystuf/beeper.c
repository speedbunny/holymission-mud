
inherit "/players/whisky/obj/std_scroll";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name("brown scroll");
       set_long("A 'bark skin' scroll.\n");
       set_level(12);
       set_value(2000);
       set_read_msg("You will be beeped when something happens.\n");
       set_shadow("/players/arthur/mystuf/beeper_shad",20,"beep_shad");
    }
}


