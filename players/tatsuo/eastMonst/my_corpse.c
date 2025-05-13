inherit "/obj/corpse";

string prev_fname;
int    level;

id( arg )
{
   return( arg == "ezo_corpse" || ::id(arg) );
}

set_level( l )          { level = l; }
query_level()           { return( level ); }

set_prev_living( f )    { prev_fname = f; }
query_prev_living()     { return( prev_fname ); }

query_too_rotten()      { return( decay != 3 ); }

tranfer_all_to( dest )
{
   object *ob, *next_ob;

   ob = first_inventory( this_object() );
   while( ob ) {
      next_ob = next_inventory(ob);
      if ( !(ob->drop(1)) && ob )
         move_object( ob, dest );
      ob = next_ob;
   }

   set_weight( 0 );
}   
