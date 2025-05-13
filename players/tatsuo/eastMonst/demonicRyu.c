inherit "obj/monster";

#define TP           (this_player())
#define TPN          (this_player()->query_name())
#define TPRN         (this_player()->query_real_name())
#define TO           (this_object())

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "ryu" );
   set_alias( "demonic ryu" );
   set_level( 70 );
   set_size( 3 );
   set_short( "a demonic ryu" );
   set_long( "A demonic ryu.\n" );
   
}

attack( )
{
   string name_of_attacker;
   object att_obj, obj;

   if ( !TP || !TP->query_attack() )
      return( ::attack() );

   name_of_attacker = capitalize( (TP->query_attack())->query_real_name() );
   att_obj = TP->query_attack();

   switch( random( 100 ) ) {
                   /* ----- right hand weapon breakes -------------------------- */
      case 0..30:  obj = att_obj->query_wielded();
                   say( "---------------------\n" );
                   if ( obj ) {
                      tell_object( att_obj,
                         "The Ryu hits your " + obj->query_name() + "with his left claw" +
                         "\nand smashes it to small fragments !!!\n" );
                      say( "The Ryu hits the " + obj->query_name() + " of " +
                         name_of_attacker + " with his left claw\n" +
                         "and smashes it to small fragments.\n", att_obj );
                      destruct( obj );
                   }
                   break;
      default:     return( ::attack() );
   }

   return( 1 );   
}

