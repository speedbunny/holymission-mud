monster_died( arg )
{
   return( 0 );

/*
   object corpse;

   corpse = clone_object( "/players/tatsuo/eastMonst/my_corpse" );
   corpse->set_level( arg->query_level() );
   corpse->set_name( process_string(arg->query_name()) );
   corpse->set_race( arg->query_race() );
   corpse->set_weight( arg->query_weight() );
   corpse->set_prev_living( explode(file_name(arg),"#")[0] );

   arg->transfer_all_to( corpse );

   move_object( corpse, environment( arg ) );

   destruct( arg );

   return( 1 );
*/
}
