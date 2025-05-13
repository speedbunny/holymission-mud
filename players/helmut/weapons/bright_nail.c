

/* --------------------------------------------------------------------
    filename: thunderblade.c last edit: whisky uni-linz.ac.at 
   -------------------------------------------------------------------- */

inherit "/obj/weapon";

reset(arg)
{
    ::reset(arg);
    set_name("sword");
    set_alt_name("bright-nail");
    set_hit_func(this_object());
    set_short("Bright-Nail");
    set_long(
      "This sword is gleaming in the light so brightly that you almost\n"+
      "cannot look at it.  It seems remarkably light and well balanced in\n"+
      "your hands.  The hilt is plainly adorned with a single nail, and you\n"+
      "get the feeling that this sword is an awesome power on the side of\n"+
      "good.\n");
    set_weight(4);
    set_class(20);
    set_value(50000);
}

weapon_hit(ob)
{
    if (random(10) <=5)
    {
	write(this_player()->query_name()+ "swings Bright-Nail effortlessly through\n"+
	  "the air, cleaving for immense damage.\n");
	if (ob->query_alignment() > 100)
	    return (20+random(30));
	else
	    return (100+random(50));
    }
    return 0;
}









