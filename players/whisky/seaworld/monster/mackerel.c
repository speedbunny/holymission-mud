
inherit "/obj/monster";

void reset(int arg) 
{
   ::reset(arg);
   if (arg) return;
     set_name("mackerel");
     set_alias("fish");
     set_race("fish");
     set_short("A little mackerel");
     set_long("You see a little mackerel, it looks harmless.\n");
     set_level(1);
     set_has_gills();
     set_size(1);
}
