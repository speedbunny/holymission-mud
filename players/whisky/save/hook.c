inherit "obj/treasure";
  
reset( arg ) {
    
  if (arg)
     return;
  
  set_id("hook");
  set_alias("iron hook");
  set_short("An iron hook");
  set_long("A small and rusty iron hook.\n");
  set_weight( 2 );
}

drop( silently )
{
   write( "As the hook leaves your hand, it suddenly crumbles to dust!\n" );
   destruct( this_object() );
   
   return( 1 );
}
