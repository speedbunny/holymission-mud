/* 4-9-96 Darastor: Totally redid this room to include new coding style
   and legend levels. */


#include "/players/darastor/guild/barb.h"

inherit "guild/guild_room";

object board;
object conan;

void reset(int arg) {
    if(arg) return 0;

    set_light(1);
    set_guild(11);

    short_desc="Barbarians' Guild Hall";

    long_desc = "		\n" +
    "This is the hall of the Barbarians' Guild. It's built, not \n" +
    "unsurprisingly, entirely out of stone, and is actually a rather \n" +
    "imposing structure. There are a number of messages and pictures \n" +
    "carved on the wall that are depict parts of barbarian history. \n" +
    "You see several torches on the wall that are used to light this \n" +
    "hall room. \n" +
    "	\n" +
    "Commands: advance, join, start, guildinfo, list, list [number]\n" +
    "          list all, and list long. \n" +
    "	\n" +
    "GUILD MEMBERS! Please type 'resoul' to update your player character\n"+
    "and obtain the new changes. Thank you. \n" +
    "	\n";

    dest_dir=({
      "/players/darastor/guild/rooms/camp6", "east",
//      "/players/darastor/guild/rooms/training", "west",
    });

    property = ({
      "has_fire", "no_sneak", "no_steal", "no_fight",
    });

    if( !present ( "board", TO ) ) {
	MO( CO( "/boards/guilds/barb_guild" ), TO );
    }


}

void init() {
    ::init();

    AA( "guild_info", "guildinfo" );
    AA( "startroom", "start" );
    AA( "test_join", "join" );
    AA( "update_player", "resoul" );
    AA( "go_house", "house" );

}

go_house() {

    TP->move_player( "to a lovely house#room/church" );
    command( "house", TP );

}

int update_player() {

    if( TP->query_guild() != 11 ) {
	write( "Sorry, but you cannot resoul if you are not a member!\n" );
	return 1;
    }

    TP->set_n_ac( 10 );
    TP->set_n_wc( 10 );

    write( "Your player character has been updated with the most resent " +
      "changes. \n" + "(even if slow .... *laugh*)\n" );

    return 1;

}

int do_advance(string arg) {

    if( ::do_advance( arg ) < 2 ) return 1;

    if( arg == "legend" ) {

	"sys/chatd"->do_chat( 11, "<= Barbarian => " +
	  CAP(TP->RNAME) + " in now Legend Level " +
	  TP->query_legend_level() + ".\n");

        write_file( GLOGS + "ADVANCEMENT", CAP( TP->RNAME ) + " advanced to " +
		"legend level " + TP->query_legend_level() + " at " +
		ctime( time() ) + ".\n" );

	return 1;
    }

    "sys/chatd"->do_chat( 11, "<= Barbarian => " +
      CAP(TP->RNAME) + " is now level " + TP->LEVEL + ".\n");

    write_file( GLOGS + "ADVANCEMENT", CAP( TP->RNAME ) + " advanced to " +
	"level " + TP->query_level() + " at " + ctime( time() ) + ".\n" );


    return 1;
}

int do_join() {

    if(::do_join()) return 1;

/*
    "sys/chatd"->do_chat( 11, "<= Barbarian => " +
      CAP((string)TP->RNAME) + " joins the Barbarian Horde!\n");
*/

    TP->set_n_wc( 10 );
    TP->set_n_ac( 10 );

    TP->set_guild(11);

    "sys/chatd"->do_chat( 11, "<= Barbarian => Darastor welcomes " +
      CAP((string)TP->RNAME) + " to the Barbarian Guild!\n");

    LF("GUILD.JOIN", (string)TP->NAME + "joined the Barbarian guild at \n" +
      ctime(time()) + "\n");

    write_file( GLOGS + "JOIN", CAP( TP->RNAME ) + " joined the Barbarian " +
	"guild at " + ctime( time() ) + ".\n" );

    return 1;
}

int test_join() {

    if( TP->query_guild() == 11 ) {
	write("You are already a barbarian though!\n");
	return 1;
    }

    if( TP->query_level() > 10 ) {
	write("Your level is currently to high to join this guild!\n");
	return 1;
    }

    if( TP->RACE == "gnome" || TP->RACE == "elf" || TP->RACE == "hobbit" ) {
	write("Sorry, but you are of too wimpy a race to become a barbarian.\n");
	return 1;
    }

#if 0
// 040598: Sauron: Removed old barb religion.
    if( RELIGION != "Alitist" && RELIGION != "Crom" ) {
#else
    if( RELIGION != "Crom" ) {
#endif

	write("You have to worship a barbarian religion to join the " +
	  "Barbarians' Guild. \n");
	return 1;
    }

    do_join(); return 1;

}

int guild_info() {
    TP->more_string(read_file("/players/darastor/guild/TEXT/help.txt"));
    return 1;
}

startroom( arg ) {

    if( TP->query_guild()!=11 ) {
	write("You have to go to your own guild.\n");
	return 1;
    }

    if( !arg ) {
	write("Where do you want to start? church or guild ?\n");
	return 1;
    }

    switch( arg ) {
    case "guild":
	TP->start_in_guild(1);
	write("You will start in the guild from now on.\n");
	TP->save_me(1);
	break;
    case "church":
	TP->start_in_guild(0);
	write("You will start in the church from now on.\n");
	TP->save_me(1);
	break;
    default:
	write("You have to start in the guild or the church!\n");
    };
    return 1;
}

int query_maxsp( int level, int leg_lev ) {
    int retval;

    retval = (( level * 5 ) + 30 + ( leg_lev * 8 ));
    if( retval > 175 ) retval = 175 + ( leg_lev * 8 );
    return retval;
}

int query_maxhp( int level, int leg_lev ) {
    int retval;

    retval = (( level * 34 ) + 230 + ( leg_lev * 20 ));
    if( retval > 1200 ) retval = 1200 + ( leg_lev * 20 );
    return retval;
}

