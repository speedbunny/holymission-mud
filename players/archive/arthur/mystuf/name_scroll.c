
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
       set_read_msg("Your skin takes a barklike look.\n");
       set_shadow("/players/arthur/mystuff/name_shad",300,"name_shad");
    }
}


