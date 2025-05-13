#include "/sys/defs.h"

int main(string str) {

  object who;

  if ( !str )
    return( TP->show_savings( str ) );

  who = find_living( str );
  if ( who ) {
    write( "Base-saving-throws of "+who->query_name()+".\n\n" );
    write( who->base_savings_info() );
  }
  else
    write( "No such player/monster online.\n" );

  return 1;
}

