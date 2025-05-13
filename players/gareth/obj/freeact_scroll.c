
inherit "/players/whisky/obj/std_scroll";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name("green scroll");
       set_long("A scroll of free action.\n");
       set_level(4);
       set_value(250);
       set_read_msg("You feel rather light and fast.\n");
       set_shadow("/players/whisky/obj/freeact_shad",300,"freeact_shad");
    }
}


