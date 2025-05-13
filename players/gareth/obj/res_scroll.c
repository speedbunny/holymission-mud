
inherit "/players/whisky/obj/std_scroll";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name("golden scroll");
       set_long("A 'magic resistance' scroll.\n");
       set_level(12);
       set_value(6000);
       set_read_msg("You feel your magic resistance raising.\n");
       set_shadow("/players/whisky/obj/res_shad",200,"res_shad");
    }
}


