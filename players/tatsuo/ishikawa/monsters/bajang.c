#define PPATH ("/players/patience/forestMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "bajang" );
   set_level( 10 + random( 5 ) );
   set_size( 3 );
    set_short(" an evil bajang" );
   set_long( "A bajang is an evil and malignant creature found in tropical\n"+
	     "jungles. It is a stunted humanoid with bird like feet.\n");
   
   set_chance( 60);
   set_spell_mess1( "The Bajang bestows a curse on you !!!");
   set_spell_mess2(" The Bajang bestows a curse on you !!!");
   set_ep(20000);
   set_spell_dam( 20 );
   set_hp(1500);
   add_money( 500+random(100));

}
