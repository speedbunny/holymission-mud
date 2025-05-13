inherit "obj/treasure";
  
reset( arg ) {
    
  if (arg)
     return;
  
  set_id("gkey");
  set_alias("key");
  set_short("A golden key");
  set_long("A tiny white-gold key.\n");
}

drop( silently )
{
   write( "As the golden key leaves your hands, it suddenly vanishes!\n" );
   destruct( this_object() );
   
   return( 1 );
}
