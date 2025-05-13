inherit "obj/monster";
#include "/include/defs.h"

void reset(int arg)
{

::reset(arg);

    if (arg) return;
    set_name("swallow");
    set_alt_name("bird");
    set_race("avian");
    set_short("A small cliff swallow");
    set_long("You see a small bird with dark wings and tail accented by a\n" 
           + "rusty coloured tail. The forehead and front, however, are white.\n\n");
    set_gender(1);
    set_level(3);
    set_hp(75);
    set_ac(1);
    set_wc(6);
    set_dead_ob(TO);
}

monster_died( arg ) {    
	object *corpse;     
	corpse = clone_object( "/players/raindell/areas/IWheel/approach/items/s_corpse" );    
 	move_object( corpse, environment( arg ) );
   destruct( arg );
 return( 1 ); 
}






