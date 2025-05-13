#define NAME   "/players/goldsun/guild/confer/accept_banish"
#define TP     (this_player())

object *accepted;
object *permitted;


reset( arg )
{
   if ( arg ) return;
   restore_object( NAME );

   if ( !accepted )
      accepted = ({ ({}), ({}) });
   if ( !permitted )
      permitted = ({ ({}), ({}), ({}) });
}

do_accept( who, whom )
{
   if ( !who || !objectp(who) || !whom || !stringp( whom ) )
      return;

   if ( accepted && member_array( whom, accepted[1] ) > -1 )
      return;

   accepted[0] += ({ whom });
   accepted[1] += ({ who->query_real_name() });

   save_object( NAME );

   return( 1 );
}

do_banish( who, whom, why )
{
   int idx;
   string str;

   if ( !whom || !stringp(whom) || !who || !objectp(who) )
      return;
   if ( !why || !stringp(why) )
      why = "none";

   if ( !permitted || !sizeof( permitted[0] ) ) {
      permitted[0] = ({ whom });
      permitted[1] = ({ who->query_real_name()+"#" });
      permitted[2] = ({ why+"#" });
   }
   else {
      idx = member_array( whom, permitted[0] );
      if ( idx > -1 ) {
         str = explode( permitted[1][idx], "#" );
         if ( member_array(who->query_real_name(),str) > -1 ) 
            return;
         permitted[1][idx] += (who->query_real_name() + "#");
         permitted[2][idx] += (why + "#");
      }
      else {
         permitted[0] += ({ whom });
         permitted[1] += ({ who->query_real_name() + "#" });
         permitted[2] += ({ why + "#" });
      }
   }

   save_object( NAME );
   return( 1 );
}

query_is_banished( who )
{
   int idx;
   string str;

   if ( !permitted )
      return( 0 );
   idx = member_array( who, permitted[0] );
   if ( idx < 0 )
      return( 0 );
   str = explode( permitted[1][idx], "#" );
   if ( !str || sizeof( str ) < 5 )
      return( 0 );

   return( 1 );
}

query_is_accepted( who )
{
   if ( !accepted )
      return( 0 );

   if ( member_array( who, accepted[0] ) > -1 )
      return( 1 );

   return( 0 );
}

query_permitted()
{
   return( permitted );
}

query_accepted()
{
   return( accepted );
}
