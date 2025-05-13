// -------------------------------------------------------------------------
//    generic spell (to be used by inheritance of ANY spell)
//    date: 020495
//    from: do you really think i am dumb enough to tell you my name ?
// -------------------------------------------------------------------------

#include "spell.h"

closure call;

string  Sname;                        // name of the spell
int     Skind;                        // kind of spell (look header)
int     Ssave;                        // save vs. what
int     Scost;                        // mana-cost of the spell
int     Sspeed;                       // speed of this spell
mapping Sallowed;                     // allowed guilds

string  Ssyntax;                      // syntax for the spell to cast
string  Sduration_info;               // duration of the spell (info for help)
string  Sdamage_info;                 // damage info
string  Ssave_vs_info;                // save_vs info (e.g. for half dam)
string  Splayer_help;                 // help string for the player

void reset( int tick )
{
   if ( tick ) return;

   call = #'call_other;

   Sspeed = 5;
   Sallowed = ([]);
}

void init( )
{

}

nomask void set_name( string n )           { Sname = n; }
nomask string name( )                      { return( Sname ); }

nomask void set_syntax( string s )         { Ssyntax = s; }
nomask string syntax( )                    { return( Ssyntax ); }

nomask void set_duration_info( string s )  { Sduration_info = s; }
nomask string duration_info( )             { return( Sduration_info ); }

nomask void set_damage_info( string e )    { Sdamage_info = e; }
nomask string damage_info( )               { return( Sdamage_info ); }

nomask void set_save_vs_info( string e )   { Ssave_vs_info = e; }
nomask string save_vs_info( )              { return( Ssave_vs_info ); }

nomask void set_player_help( string h )    { Splayer_help = h; }
nomask string player_help( string h )      { return( Splayer_help ); }

// ----- guild allowance -------------------------------------------------
nomask void set_guild_allowed( int gn, int lvl )   // guildnumber, level to lrn
{
   if ( gn < 0 || lvl < 1 ) return;
   Sallowed[gn] = lvl;
}

nomask varargs int may_cast( int gn, int lvl )   // is guild# allowed to use it
{
   if ( !gn || gn < 0 || Sallowed[gn] < 1 ) return( 0 );

   if ( lvl && lvl > 0 ) return( lvl >= Sallowed[gn] );
   
   return( 1 );
}

nomask int level( int gn )           // at which lvl is gn allowed to learn it
{
   if ( Sallowed[gn] <= 0 ) return( -1 );

   return( Sallowed[gn] );
}

nomask mapping allowance_data()
{
   return( Sallowed );
}

// ----- kind of the spell -----------------------------------------------
nomask void set_kind( int k )
{
   if ( k < 1 || k > 3 ) return;
   Skind = k;
} 

nomask int kind( )
{
   return( Skind );
}

// ----- save versus ------------------------------------------------------
nomask void set_save_vs( int s )
{
   if ( s < 0 || s > MAX_NO_OF_SAVE ) return;
   Ssave = s;
}

nomask int save_vs( )
{
   return( Ssave );
}

// ----- mana - cost ------------------------------------------------------
nomask void set_cost( int c )
{
   if ( c < 0 ) Scost = 0; 
   Scost = c;
}

nomask int cost( )
{
   return( Scost );
}

// ----- speed of the spell -----------------------------------------------
nomask void set_speed( int s )
{
   Sspeed = s;
}

varargs int speed( int lvl, object who )
{
   return( Sspeed );
}

// ----- release the spell -----------------------------------------------
void release_spell( string arg, int act_skill, int max_skill )
{
   write( "BUG Spell::release_spell(..) must be overridden !!!\n" );
}

void release( string arg, int act_skill, int max_skill )
{
   release_spell( arg, act_skill, max_skill );
}

// ----- get spell info --------------------------------------------------
nomask string spell_help()
{
   string ret;
   mixed  *spell, *g;
   int    i, sp;

   spell = TP->get_spell( Sname );

   ret  = "-----------------------------------------------------------------\n"+
          "Name:            "+Sname+"\n"+
          "Syntax:          "+Ssyntax+"\n"+
          "Kind:            "+KIND_STRING[Skind]+"\n"+
          "Save versus:     "+SAVE_VS_STRING[Ssave];
   if ( Ssave_vs_info ) ret += " "+Ssave_vs_info+"\n";
   else                 ret += "\n";
   if ( Sduration_info )
      ret += "Duration:        "+Sduration_info+"\n";

   sp = -2;
   if ( spell )   sp = spell[3];
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

   if ( Sdamage_info ) ret += "Damage:          "+Sdamage_info+"\n";
   ret += "Spellpoints:     "+Scost+"\n";     
   i = m_sizeof( Sallowed );
   if ( i ) {
      g = m_indices( Sallowed );
      ret += "Guilds:          ";
      for ( --i; i >= 0; i-- ) {
         ret += "/guild/master"->query_name(g[i])+" "+Sallowed[g[i]];
         if ( i > 0 ) ret += ", ";
      }
      ret += "\n";
   }

   if ( Splayer_help )
      ret += "\nDescription:\n"+Splayer_help+"\n";

   ret += "-----------------------------------------------------------------\n";

   return( ret );
}

// ----- "parses" the arg and returns the target or NULL -----------------
object check_target( string arg )
{
   object target;

   // ----- "parse" the argument -----
   if ( !arg ) {
      if ( Skind == AGGRESSIVE ) target = apply( call, TP, "query_attack" );
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
      write( "You cannot cast spells at a ghost.\n" );
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
   if ( (Skind == AGGRESSIVE ) && !apply(call,TP,"allowed_attack",target) ) {
      write( "You must not attack players !\n" );
      return( 0 );
   }
   return( 1 ); 
}

int valid_item( object target )
{
   return( 0 );
}

void display_utter( int lang )
{
   int old_lang;

   old_lang = apply( call, TP, "speaks_in" );
   apply( call, TP, "set_speaks_in", lang );
   lsay( "utters the words:","'"+Sname+"'\n", TP, 0 );
   write( "You utter the words: '"+Sname+"'\n" );
   apply( call, TP, "set_speaks_in", old_lang );
}

int check_success( int act_skill, int max_skill )
{
   if ( apply( call, TP, "query_sp" ) < Scost ) {    // mana-check
      write( "You cannot summon enough energy !\n" );
      return( 0 );
   }
   if ( apply( call, TP, "query_ghost" ) ) {         // ghost ?
      write( "You cannot utter the words in your incorporeal state !\n" );
      return( 0 );
   }

   if ( Skind == AGGRESSIVE ) {
      if ( environment(TP)->query_property( "no_fight" ) ) {
         write( "You feel too peaceful to cast this spell here ...\n" );
         return( 0 );
      }
   }
   else if ( Skind == NO_COMBAT ) {
      if ( TP->query_attack() ) {
         write( "This spell cannot be cast in combat !\n" );
         return( 0 );
      }
   }

   if ( random(100) < act_skill ) {                  // oki, cast it
      apply( call, TP, "restore_spell_points", -1*Scost );
      return( 1 );
   }
   else {                                            // failed, raise skill ?
      write( "You lost your concentration !\n" );
      if ( act_skill < max_skill ) {
         if ( act_skill < (55+apply(call,TP,"query_int")) &&
              random(100) < ((100-act_skill)/(act_skill/25+4))+1 &&
              act_skill < max_skill )
         {
            apply( call, TP, "set_spell_skill", Sname, act_skill+1 );
            write( "But learn from your mistake !\n" );      
         }
      }
      apply( call, TP, "restore_spell_points", -1*(Scost+1)/2 );
      return( 0 );
   }
}

int abort_spell(object pl)
{
   pl->abort_concentration();
   pl->uncheck_input();
   write("You aborted your spell!\n");
}
