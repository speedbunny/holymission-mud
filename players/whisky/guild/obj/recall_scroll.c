
inherit "/players/whisky/obj/std_scroll";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name("blue scroll");
       set_long("A scroll of 'recall'.\n");
       set_level(4);
       set_value(20);
       set_read_msg("You read the scroll and vanish.\n");
       set_function("move_player","in a cloud of mushrooms#/players/whisky/guild/room/visit");
    }
}


