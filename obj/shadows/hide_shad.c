// hide
// makes 'who' invis(level 29) for 'time' seconds
// id: hide
// attr-msg: none
// look-info: none
// non multiple

inherit "/obj/std_shadow";

query_invis()   { return 29;   }

start_shadow(who, time)
{
   if( who && apply(#'call_other,who,"query_invis") )
      destruct( this_object() );
   else
      return( ::start_shadow(who, time, "hide",0) );
}

varargs int attack( object o, int i )
{
   end_shadow(this_object());

   return me->attack(o,i);
}
