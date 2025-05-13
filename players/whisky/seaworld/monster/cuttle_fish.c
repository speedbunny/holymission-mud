
inherit "/obj/monster";

void reset(int arg) 
{
   ::reset(arg);

   if (arg) return;
     set_name("cuttlefish");
     set_alias("fish");
     set_short("A little cuttlefish");
     set_race("fish");
     set_long("It is a small pink cuttlefish.\n");
     set_level(1);
     set_has_gills();
     set_size(1);
     move_object(clone_object("players/whisky/seaworld/obj/cartridge"),this_object());
 }
