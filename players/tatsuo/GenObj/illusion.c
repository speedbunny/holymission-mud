object blocker;
int    local_weight;

set_blocker( ob ) 
{
   blocker = ob;
}

id( str )
{
   object inv;
   
   inv = all_inventory( this_object() );
   if ( inv && sizeof(inv) )
      return( inv[0]->id(str) );
   
   return( str == "_illusion_" );
}

short()
{
   object inv;

   inv = all_inventory( this_object() );
   if ( inv && sizeof(inv) )
      return( inv[0]->short() );
      
   return( "shorg" );
}

mixed query_name()
{
    return short();
}
long()
{
   object inv;

   inv = all_inventory( this_object() );   
   
   if ( inv && sizeof(inv) )
      return( inv[0]->long() );
}

get()
{
   object inv;

   inv = all_inventory( this_object() );
   
   if ( inv && sizeof(inv) ) {
      if ( blocker && present( blocker, environment(this_object()) ) ) {
         write( blocker->short() + " hinders you from getting it !!!\n" );
         return( 0 );
      }
      else {
         if ( inv[0]->get() == 0 ) {
            move_object( inv[0], environment() );
            set_weight( 0 );
            destruct( this_object() );
         }
         else {
            call_out( "destruct_me", 0, inv[0] );
            return( 1 );
         }
      }
   }
   else {
      /* this shouldn-t happen */
      return( 0 );
   }
}

destruct_me( inv )
{
   move_object( inv, environment() );
   set_weight( 0 );
   destruct( this_object() );
}

set_weight( w ) {
    local_weight = w;
}

query_weight( ) { return( local_weight ); }
