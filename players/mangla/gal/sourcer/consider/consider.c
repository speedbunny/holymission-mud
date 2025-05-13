/*
 * Consider ability
 * built primary for the druids as they need the know the
 * alignment of the opponent but usable by every other guild
 * too
 * (c) Sourcer
 */

inherit  "/abilities/ability";
#include "/spells/spell.h"

void do_consider( string arg );

void reset( int tick )
{
   ::reset(tick);
   if ( tick ) return;

   set_name( "consider" );
   set_syntax( "consider [target]" );
   set_speed( INSTANT );
   set_guild_allowed( 2, 1 );
   set_kind( NO_COMBAT );
   set_cost( 5 );
   set_player_help( 
	"Depending on your level you get rather detailed information\n"+
    "about a monster.");
}

void display_prepare( object who )
{
   ;
}

void release( string arg, int act_skill, int max_skill )
{
   if ( !arg )
      write( "Consider what ?\n" );
   else if ( check_success( act_skill, max_skill ) )
      do_consider( arg );
   else
      write( "You don't examine anything useful\n" );
}

string level_string(diff)
{
	switch(diff)
	{
	case -100..-10: return "You could do it with a needle.";
	case   -9..-2 : return "That's an easy kill.";
	case   -1..5  : return "The perfect match.";
	case    6..15 : return "You would need some luck.";
	case   16..25 : return "You will need some HELP.";
	case   26..50 : return "You are MAD!";
	case   51..200: return "Death will thank you for your gift.";
	default       : ERR("Level out of range "+diff);
                    return "You don't know anything.";
	}
}

string ac_string(int ac)
{
	switch(ac)
	{
	case 0..5  : return " is hardly armored.";
	case 6..10 : return " is somewhat armored.";
	case 11..20: return " is good armored.";
	case 21..25: return " is extremely well armored.";
	case 26..30: return " is armored like a TANK!";
	case 31..100: return " is INVINCIBLY armored!";
	default: ERR("AC out of range "+ac);
             return " is STRANGE armored.";
	}
}

string dam_string(int dam)
{
	switch(dam)
	{
	case 0..5: return "nearly no";
	case 6..10: return "little";
	case 11..13: return "some";
	case 14..16: return "a lot";
	case 17..19: return "a good ammount of";
	case 20..25: return "a TON of";
	case 26..40: return "an INCREADABLY ammount of";
	case 41..60: return "a ** TON ** of";
	case 61..99: return "an ** INCREADABLE ammount of";
	default: ERR("Damage out of range "+dam);
             return("a strange");
	}
}
	

string hp_string(int hp)
{
	switch(hp)
	{
	case 1..50: return "few";
	case 51..100: return "some";
	case 101..500: return "a few";
	case 501..999: return "a lot";
	case 1000..2000: return "a whole lot";
	case 2001..5000: return "dammned much";
	case 5001..9999: return "a TON of hp";
	case 10000..50000: return "an INCREADABLE ammount of";
	case 50001..999999: return "an UNBEATABLE ammount of";
	default: ERR("HP more than 1Mio "+hp);
	}
}



void do_consider( string arg )
{
object targ;
int diff,level,hp,att,dam,ac;

	if(!targ=present(arg,environment(TP)))
	{
		write("You don't see a "+arg+" here.\n");
		return;
	}
	if(!living(targ))
	{
		write("You eye a "+arg+" closly.\n");
		return;
	}
	level = targ->query_level()+targ->query_legend_level();
	hp = targ->query_max_hp();
	att = targ->query_number_of_arms();
	dam = targ->query_n_wc();
	ac = targ->query_ac();

	return;
}

