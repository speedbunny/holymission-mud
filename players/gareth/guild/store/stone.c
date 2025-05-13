
/* stoneskin scroll */

inherit "/obj/std_scroll";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name("gray scroll");
       set_long("A 'stone skin' scroll.\n");
       set_level(18);
       set_value(900);
       set_read_msg("You feel some layers of stone around you.\n");
       set_shadow("/obj/shadows/stoneskin_shad",600);
    }
}


