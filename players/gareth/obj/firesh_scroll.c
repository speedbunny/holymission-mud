
inherit "/players/whisky/obj/std_scroll";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name(({"red","burning","burning red","red scroll","burning scroll",
						"burning red scroll"}));
       set_long("A 'fireshield' scroll.\n");
       set_level(23);
       set_value(3000);
       set_read_msg("A wall of fire envelopes around you.\n");
       set_shadow("/players/whisky/obj/firesh_shad",200,"firesh_shad");
    }
}


