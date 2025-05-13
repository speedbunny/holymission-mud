
inherit "/obj/monster";

void reset(int arg) 
{
  ::reset(arg);

  if(arg) return;
    set_name("shark");
    set_alias("baby shark");
    set_short("An aggressive baby shark");
    set_race("fish");
    set_aggressive(1);
	set_long("This is small baby shark. It's aggressive as a its father.\n");
    set_al(-10);
    set_wc(8);
    set_level(2);
    set_has_gills();
 }
