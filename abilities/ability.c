// -------------------------------------------------------------------------
//    generic ability (to be used by inheritance of ANY ability)
//    date: 05/03/95
//    from: do you really think i am dumb enough to tell you my name ?
// -------------------------------------------------------------------------

#include "/spells/spell.h"

closure call;

string  Aname;                        // name of the ability
int     Akind;                        // kind of ability (look header)
int     Aspeed;                       // speed of this ability
mapping Aallowed;                     // allowed guilds
int     Acost;                        // how much fatigue-points you need
int     Aauto_inc;                    // automatic increase at usage

string  Asyntax;                      // syntax for the ability to use
string  Aplayer_help;                 // help string for the player

void reset( int tick )
{
   if ( tick ) return;

   call = #'call_other;

   Aspeed = 5;
   Aallowed = ([]);
   Aauto_inc = 0;
}

void init( )
{

}

nomask void set_name( string n )           { Aname = n; }
nomask string name( )                      { return( Aname ); }

nomask void set_syntax( string s )         { Asyntax = s; }
nomask string syntax( )                    { return( Asyntax ); }

nomask void set_player_help( string h )    { Aplayer_help = h; }
nomask string player_help( string h )      { return( Aplayer_help ); }

nomask void set_cost( int c )              { Acost = c; }
nomask int cost( )                         { return( Acost ); }

nomask void set_auto_inc()                 { Aauto_inc = 1; }

// ----- guild allowance -------------------------------------------------
nomask void set_guild_allowed( int gn, int lvl )   // guildnumber, level to lrn
{
   if ( gn < 0 || lvl < 1 ) return;
   Aallowed[gn] = lvl;
}

nomask varargs int may_use( int gn, int lvl )   // is guild# allowed to use it
{
   if ( !gn || gn < 0 || Aallowed[gn] < 1 ) return( 0 );

   if ( lvl && lvl > 0 ) return( lvl >= Aallowed[gn] );
   
   return( 1 );
}

nomask int level( int gn )           // at which lvl is gn allowed to learn it
{
   if ( Aallowed[gn] <= 0 ) return( -1 );

   return( Aallowed[gn] );
}

nomask mapping allowance_data()
{
   return( Aallowed );
}

// ----- kind of the ability -----------------------------------------------
nomask void set_kind( int k )
{
   if ( k < 1 || k > 3 ) return;
   Akind = k;
} 

nomask int kind( )
{
   return( Akind );
}

// ----- speed of the ability ---------------------------------------------
nomask void set_speed( int s )
{
   Aspeed = s;
}

varargs int speed( int lvl, object who )
{
   return( Aspeed );
}

// ----- release the ability -----------------------------------------------
void release( string arg, int act_skill, int max_skill )
{
   write( "BUG Ability::release(..) must be overridden !!!\n" );
}

// ----- get ability info ------------------------------------------------
nomask string ability_help()
{
   string ret;
   mixed  *ability, *g;
   int    i, sp;

   ability = TP->get_ability( Aname );

   ret  = "-----------------------------------------------------------------\n"+
          "Name:            "+Aname+"\n"+
          "Syntax:          "+Asyntax+"\n"+
          "Kind:            "+KIND_STRING[Akind]+"\n";
   if ( Aauto_inc ) ret+="Raise on usage:  yes\n";
   else             ret+="Raise on usage:  no\n";
   sp = -2;
   if ( ability ) sp = ability[3];
   else if ( TP ) sp = speed(TP->query_level(),TP->query_legend_level());
   else           sp = speed();
   if ( sp > -2 ) {
      ret += "Speed:           ";
      switch( sp ) {
         case -1: ret += "instant\n"; break;
         case 0:  ret += "next round\n"; break;
         default: ret += sp+" rounds\n";
      }
   }
   ret += "Fatigue-Points:  "+Acost+"\n";
   i = m_sizeof( Aallowed );
   if ( i ) {
      g = m_indices( Aallowed );
      ret += "Guilds:          ";
      for ( --i; i >= 0; i-- ) {
         ret += "/guild/master"->query_name(g[i])+" "+Aallowed[g[i]];
         if ( i > 0 ) ret += ", ";
      }
      ret += "\n";
   }

   if ( Aplayer_help )
      ret += "\nDescription:\n"+Aplayer_help+"\n";

   ret += "-----------------------------------------------------------------\n";

   return( ret );
}

// ----- "parses" the arg and returns the target or NULL -----------------
object check_target( string arg )
{
   object target;

   // ----- "parse" the argument -----
   if ( !arg ) {
      if ( Akind == AGGRESSIVE ) target = apply( call, TP, "query_attack" );
      else                       target = TP;
   }
   else {
      target = present( arg, environment(TP) );
      if ( !target )
         target = present( arg, TP );
   }

   // ----- location ok ? -----
   if ( !target ||
        !(environment(TP)==environment(target) || environment(target)==TP) )
   {
      write( "Never around when needed ...\n" );
      return( 0 );
   }

   return( target );
}

int valid_living( object target )
{
   if ( target == TP )
      return( 1 );
   if ( !living(target) )
      return( 0 );
   if ( apply( call, target, "query_ghost" ) ) {
      write( "You cannot use this ability at a ghost.\n" );
      return( 0 );
   }
   if ( apply( call, target, "is_invis_for", TP ) ) {
      write( "Never around when needed ...\n" );
      return( 0 );
   }
   if ( apply( call, TP, "test_dark" ) ) {
      write( "It is much too dark to see anything !\n" );
      return( 0 );
   }
   if ( (Akind == AGGRESSIVE ) && !apply(call,TP,"allowed_attack",target) ) {
      write( "You must not attack players !\n" );
      return( 0 );
   }
   return( 1 ); 
}

int valid_item( object target )
{
   return( 0 );
}

void display_prepare( object who )
{
   write( "BUG Ability::display_prepare(..) must be overridden !!!\n" );
}

int check_success( int act_skill, int max_skill )
{
   if ( funcall( call, TP, "query_fp" ) < Acost ) {
      write( "You are too tired to use this special ability ...\n" );
      return( 0 );
   }

   if ( apply( call, TP, "query_ghost" ) ) {         // ghost ?
      write( "You cannot use this ability in you incorporal state !\n" );
      return( 0 );
   }

   if ( Akind == AGGRESSIVE ) {
      if ( environment(TP)->query_property( "no_fight" ) ) {
         write( "You feel too peaceful to use this ability here ...\n" );
         return( 0 );
      }
   }
   else if ( Akind == NO_COMBAT ) {
      if ( TP->query_attack() ) {
         write( "You are much too busy fighting !\n" );
         return( 0 );
      }
   }

   if ( random(100) < act_skill ) {                  // oki, cast it
      funcall( call, TP, "reduce_fatigue_points", Acost );
      return( 1 );
   }
   else {                                            // failed, raise skill ?
      if ( act_skill < max_skill ) {
         if ( Aauto_inc && act_skill < (55+apply(call,TP,"query_int")) &&
              random(100) < ((100-act_skill)/(act_skill/25+4))+1 &&
              act_skill < max_skill )
         {
            apply( call, TP, "set_ability_skill", Aname, act_skill+1 );
            write( "You learn from your mistake !\n" );      
         }
      }
      funcall( call, TP, "reduce_fatigue_points", (Acost+1)/2 );
      return( 0 );
   }
}

#if 0
int abort_ability(object pl)
{
   pl->abort_concentration();
   pl->uncheck_input();
   write("You aborted your spell!\n");
}
#endif
