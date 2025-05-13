int poison;

reset( arg )
{
   if ( arg )
      return;

   poison = 0;
}

id( str )
{
   return( str == "poison cloud" || str == "cloud" || str == "poison" );
}

query_name()
{
   return( "poison cloud" );
}

short()
{
   return( "You are standing in a green, poisonous looking cloud !!!" );
}

long()
{
   write( "It is a green cloud. You feel that it is poisonous\n" +
          "and you are standing right in it !!! RUN FOOL !!!!\n" );
}

add_poison( p )
{
   poison += p;
   remove_call_out( "do_poison" );
   call_out( "do_poison", 1 );
}

do_poison( )
{
   object *inv;
   int    i;

   if ( !environment() ) return;

   poison--;
   if ( poison < 0 ) {
      destruct( this_object() );
      return;
   }

   inv = all_inventory( environment( this_object() ) );
   if ( !inv )
      call_out( "do_poison", 1 );

   for ( i = 0; i < sizeof( inv ); i++ ) {
      if ( living(inv[i]) && !(inv[i]->poison_immune()) ) {
         if ( inv[i]->query_npc() || interactive( inv[i] ) ) {
            tell_object( inv[i], "You breath POISON !!!\n" );
            inv[i]->hit_player( 80, 9 );
            if (!random(4))
               inv[i]->add_poison(random(20));
         }
      }
   }

   call_out( "do_poison", 1 );
}
