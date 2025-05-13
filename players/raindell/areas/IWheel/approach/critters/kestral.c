inherit "obj/monster";
#include "/include/defs.h"

void reset(int arg)
{

::reset(arg);

    if (arg) return;
    set_name("kestral");
    set_alt_name("bird");
    set_race("avian");
    set_short("A small falcon");
    set_long("This small falcon has a reddish back and tail, accented by long\n" 
           + "wings of blue and grey. A pair of black vertical stripes adorn\n"
	     + "its otherwise pure white face\n\n");
    set_gender(1);
    set_level(4);
    set_hp(90);
    set_ac(1);
    set_wc(7);
    set_dead_ob(TO);
}

monster_died( arg ) {    
	object *corpse;     
	corpse = clone_object( "/players/raindell/areas/IWheel/approach/items/k_corpse" );    
 	move_object( corpse, environment( arg ) );
   destruct( arg );
 return( 1 ); 
}

