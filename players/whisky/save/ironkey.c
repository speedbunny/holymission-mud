inherit "obj/treasure";
  
reset( arg ) {
    
  if (arg)
     return;
  
  set_id("ikey");
  set_alias("key");
  set_short("An iron key");
  set_long("An old, rusty, dirty iron key.\n");
}

drop( silently )
{
   write( "As the rusty iron key leaves your hands, it suddenly crumbles to dust!\n" );
   destruct( this_object() );
   
   return( 1 );
}
