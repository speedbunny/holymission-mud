inherit "obj/monster";
#include "/include/defs.h"

void reset(int arg)
{

::reset(arg);

    if (arg) return;
    set_name("bluebird");
    set_alt_name("bird");
    set_race("avian");
    set_short("A small bluebird");
    set_long("This small bird is dark blue on the top, with a lighter\n" 
           + "turquoise blue on the breast along with patches of white.\n\n");
    set_gender(1);
    set_level(2);
    set_hp(60);
    set_ac(0);
    set_wc(6);
    set_dead_ob(TO);
}

monster_died( arg ) {    
	object *corpse;     
	corpse = clone_object( "/players/raindell/areas/IWheel/approach/items/bb_corpse" );    
 	move_object( corpse, environment( arg ) );
   destruct( arg );
 return( 1 ); 
}