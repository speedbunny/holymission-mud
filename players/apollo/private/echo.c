
inherit "/obj/thing";

#define AA add_action
#define CHAT "/sys/chatd"->do_chat
#define NAME this_player()->query_name()

//string m_prefix, m_postfix;

reset( arg ) {
   ::reset( arg );
   if( !arg ) {

     set_name( "Echoer" );
     set_short( "An all-purpose Echoer" );
     set_long( "	\n" +
	"This is object can be used to echo on the various guild \n" +
	"lines as well has have conversations as needed with guild \n" +
	"members. For help on this Echoer, type 'help echoer'. \n" +
	"	\n" );

  }
 }

void init() {
  ::init();

  if( environment() == this_player() ) {
    if( this_player()->query_immortal() == 1 ) {

    AA( "help_echoer", "help echoer" );
    AA( "line_say", "barbarian" );

    }
  }

}

status line_say( arg str ) {

  if( arg == "barbarian" ) {
//	m_prefix = "|=|";
//	m_postfix = "|=|";

	return CHAT( 11, "|=| Barbarian " + NAME + " |=| " +
		str + "\n" );
	return 1;
  }

  notify_fail( "I'm sorry but that line doesn't exist!\n" );

}

