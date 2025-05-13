#define NAME   "/players/tatsuo/guild/nweap/weap_owners"
#define TP     (this_player())

string *kat;
string *waki;
string *ninja_to;

reset( arg )
{
   if ( arg ) return;
   restore_object( NAME );

   if ( !kat )       kat = ({});
   if ( !waki )      waki = ({});
   if ( !ninja_to )  ninja_to = ({});
}

int add_waki_owner( string who )
{
   if ( !strlen(who) ) return( 0 );
   waki -= ({who});
   waki += ({who});
   save_object( NAME );
   return( 1 );
}

int add_kat_owner( string who )
{
   if ( !strlen(who) ) return( 0 );
   kat -= ({who});
   kat += ({who});
   save_object( NAME );
   return( 1 );
}

int add_nt_owner( string who )
{
   if ( !strlen(who) ) return( 0 );
   ninja_to -= ({who});
   ninja_to += ({who});
   save_object( NAME );
   return( 1 );
}

int remove_waki_owner( string who )
{
   if ( !strlen(who) ) return( 0 );
   waki -= ({who});
   save_object( NAME );
   return( 1 );
}

int remove_kat_owner( string who )
{
   if ( !strlen(who) ) return( 0 );
   kat -= ({who});
   save_object( NAME );
   return( 1 );
}

int remove_nt_owner( string who )
{
   if ( !strlen(who) ) return( 0 );
   ninja_to -= ({who});
   save_object( NAME );
   return( 1 );
}

int is_waki_owner( string who )
{
   if ( member_array( who, waki ) < 0 )  return( 0 );
   return( 1 ); 
}

int is_kat_owner( string who )
{
   if ( member_array( who, kat ) < 0 )  return( 0 );
   return( 1 ); 
}

int is_nt_owner( string who )
{
   if ( member_array( who, ninja_to ) < 0 )  return( 0 );
   return( 1 ); 
}

string *waki_owners( )
{
   return( waki );
}

string *kat_owners( )
{
   return( kat );
}

string *nt_owners( )
{
   return( ninja_to );
}
