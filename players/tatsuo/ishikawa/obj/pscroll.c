
inherit "/players/whisky/obj/std_scroll";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name("black scroll");
       set_long("A 'resist poison' scroll.\n");
       set_level(18);
       set_value(2000);
       set_read_msg("You feel you poison resistance raising.\n");
       set_shadow("/players/whisky/obj/pois_shad",300,"pois_shad");
    }
}


