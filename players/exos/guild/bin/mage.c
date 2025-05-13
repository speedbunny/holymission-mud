#include "/obj/lw.h"
#include "/obj/adjust.h"
#include "../levels.h"
#include "mage.h"
#define maxstatuschar 17
#define maxlinechr 5
#define maxnamechr 12
#define maxlevelchr 13
#define maxwherechr 28

string level( object ob ) {
    if( ob->query_incognito() )
	return ( ladjust( "Incognito", maxlevelchr ) );
    switch( ob -> query_level() ) {
    case L_PLAYER:
	if( ob->query_legend_level() > 0 )
	    return ( ladjust( "Legend " + ob->query_legend_level(), maxlevelchr ) );
	else 
	    return ( ladjust( "Mage", maxlevelchr ) );
	break;
    case L_APPR:
	return ( ladjust( "Immortal", maxlevelchr ) );
	break;
    case L_NEWWIZ:
	return ( ladjust( "DemiGod", maxlevelchr ) );
	break;
    case L_WIZ:
	return ( ladjust( "Lesser God", maxlevelchr ) );
	break;
    case L_SAGE:
	return ( ladjust( "God", maxlevelchr ) );
	break;
    case L_RETD:
	return ( ladjust( "Retired God", maxlevelchr ) );
	break;
    case L_ELDER:
	return ( ladjust( "Greater God", maxlevelchr ) );
	break;
    case L_ARCH..L_SPEC:
	return ( ladjust( "Greatest God", maxlevelchr ) );
	break;
    case L_GOD:
	return ( ladjust( "Supreme Being", maxlevelchr ) );
	break;
    default:
	return ( ladjust( "Mage", maxlevelchr ) );
    }
}

string guild_status( object ob ) {
    string name;

    name = ob->query_real_name();
    if( ob->query_real_name() == "exos" )
	return ( ladjust( "Guildmaster", maxstatuschar ) );
    else if( ob->query_real_name() == "llort" )
	return ( ladjust( "Retired Master", maxstatuschar ) );
    else if( ob->query_immortal() )
	return ( ladjust( "Visiting Immortal", maxstatuschar ) );
    else if( ob->query_testchar() )
	return ( ladjust( "Tester", maxstatuschar ) );
    else if( ob->query_legend_level() && ob->query_level() == 29 )
	return ( ladjust( "Archmagus", maxstatuschar ) );
    else switch( ob->query_level() ) {
    case 1..4:   return ( ladjust( "Probationer", maxstatuschar ) );  break;
    case 5..8:   return ( ladjust( "Fochlucan", maxstatuschar ) );    break;
    case 9..12:  return ( ladjust( "MacFuirmidh", maxstatuschar ) );  break;
    case 13..16: return ( ladjust( "Doss", maxstatuschar ) );         break;
    case 17..20: return ( ladjust( "Canaith", maxstatuschar ) );      break;
    case 21..23: return ( ladjust( "Cli", maxstatuschar ) );          break;
    case 24..26: return ( ladjust( "Anstruth", maxstatuschar ) );     break;
    case 27..29: return ( ladjust( "Ollamh", maxstatuschar ) );       break;
    default:     return ( ladjust( "-", maxstatuschar ) );            break;
    }
}

int main( string str ) {
    int i, j, gd;
    string name;
    object *u, robe;

    gd = "guild/master"->query_number( "mage" );
    if( !str ) {
	write( "\n" );
	printf( "%|'='78s\n", " <<< Mage Guild >>> " );
	write( ladjust( "Name", maxnamechr ) +
	  ladjust( "Line", maxlinechr ) +
	  ladjust( "Level", maxlevelchr ) +
	  ladjust( "Guild Status", maxstatuschar ) +
	  ladjust( "Where in HM", maxwherechr ) +
	  "\n" );
	write( sprintf( "%'='78s\n", "=" ) );
	u = sort_array( filter_array( users(), "gd_filter", this_object(), 0 ), "ranksort", 
	  this_object() );
	j = sizeof( u );
	i = 0;
	while( i < j ) {
	    robe = present( "magesoul", u[i] );
	    write( ladjust( capitalize( u[i]->query_real_name() ), maxnamechr ) +
	      ladjust( robe->query_mage_line(), maxlinechr ) +
	      ( level( u[i] ) ) +
	      ( guild_status( u[i] ) ) +
	      ( environment( u[i] )->short() ) +
	      "\n" );
	    i++;
	}
	if( j == 1 )
	    printf( "%|'='78s\n", " There is " + j + " mage on " );
	else
	    printf( "%|'='78s\n", " There are " + j + " mages on " );
	return ( 1 );
    }
    robe = present( "robe", this_player() );
    if( str == "on" ) {
	write( "You turn on the guild channel.\n" );
	robe->set_mage_line( "On" );
	"sys/chatd.c"->set_line( this_player(), gd, 1 );
	return ( 1 );
    }
    if( str == "off" ) {
	write( "You turn off the guild channel.\n" );
	robe->set_mage_line( "Off" );
	"sys/chatd.c"->set_line( this_player(), gd, 0 );
	return ( 1 );
    }
    if( query_verb() == "mage/" ) {
	"sys/chatd.c"->do_chat( gd, 
	  lw( "<#> " + capitalize( this_player()->query_real_name() ) + " " + str + " <#>\n" ) );
	return ( 1 );
    }
    if( query_verb() == "bard=" && this_player()->query_real_name() == "exos" ) {
	"sys/chatd.c"->do_chat( gd, 
	  lw( "<#> GUILD ANNOUNCEMENT <#>\n" + "<#> " + str + " <#>\n" ) );
	return ( 1 );
    }
    "sys/chatd.c"->do_chat( gd, lw( "<#> " + capitalize( this_player()->query_real_name() ) + 
	" says: " + str + " <#>\n" ) );
    return ( 1 );
}

int gd_filter( object ob ) { return ( ( int )ob->query_real_guild() == 6 ); }
int ranksort( object a, object b ) { return ( ( int )a->query_level() < b->query_level() ); }
