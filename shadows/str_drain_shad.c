// strenght drain
// shadows query_str
// id: str_drain
// attr-msg: none
// non-multiple

inherit "/obj/std_shadow";

int str_drained, time_remaining;

start_shadow( who, time, strd )     // amount is: how much strength to drain
{
   object *shad;

   shad = who->shad_obj("str_drain");
   if ( shad ) {
      shad->update_my_shadow(time,strd);
      destruct( this_object() );
      return( 0 );
   }
   update_my_shadow(time,strd);
   
   return( ::start_shadow( who, 0, "str_drain", 0 ) );
}

update_my_shadow( t, s )
{
   time_remaining = t > time_remaining ? t : time_remaining;
   str_drained += s;
}

chk_all_shadows()
{
   time_remaining--;

   if ( time_remaining <= 0 )
      end_shadow(this_object());
}

query_stats( int which )
{
   int actStr;

   if ( which != 0 )
      return( me->query_stats(which) );

   actStr = me->query_stats(0) - str_drained;
   return( actStr < 1 ? 1 : actStr );
}
