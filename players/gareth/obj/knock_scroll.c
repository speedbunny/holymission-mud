
inherit "/players/whisky/obj/std_scroll";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name("yellow scroll");
       set_long("A 'knock doors' scroll.\n");
       set_level(4);
       set_value(100);
       set_read_msg("Your environment starts to glow red.\n");
       set_shadow("/players/whisky/obj/knock_shad",1,"knock_shad");
    }
}


