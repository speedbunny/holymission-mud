// -------------------------------------------------------------------------
// GENERIC POTION
// -------------------------------------------------------------------------

#define ANTIDOTES      1
#define HEALING        2
#define CONTENT_NAME   ({"emptyness","antidotes","healing"})
#define TP             this_player()

int    Content;

void reset( int tick )
{
   Content = 0;
}

void init( )
{
   add_action( "do_quaff", "quaff" );
}

int get( )
{
   return( 1 );
}

int drop( )
{
   return( 0 );
}

string query_name( )
{
   if ( Content )
      return( "potion of "+CONTENT_NAME[Content] );
   else
      return( "empty flask" );
}

string short( )
{
   return( query_name() );
}

void long( )
{
   if ( Content )
     write("This is a potion of "+CONTENT_NAME[Content]+
           ".\nYou can quaff it.\n");
   else
      write( "This is an empy flask.\n" );
}

void set_content( int c )         { Content = c; }

int query_value( )
{
   switch( Content ) {
      case ANTIDOTES:  return( 111 );
      case HEALING:    return( 5000 );
      default:         return( 5 );
   }

   return( 5 );
}

int query_weight()     { return( 1 ); }

int id( string str )
{
   return( str == "flask" || str == "potion" || str == CONTENT_NAME[Content]
           || str == query_name() );
}

int do_quaff( string what )
{
   int tmp;

   if ( !id(what) ) return( 0 );

   switch( Content ) {
      case ANTIDOTES: TP->add_poison( -1 * 15+random(6) );
                      write( "You feel poison leaving your veins.\n" );
                      break;
      case HEALING:   tmp = TP->query_max_hp() - TP->query_hp();
                      TP->reduce_hit_point( -1* tmp );
                      write( "You feel life flowing through your body.\n" );
                      break;
      default:        write( "The flask is already empty.\n" );
                      return( 1 );
   }

   Content = 0;
   say( TP->query_name() + " quaffs a potion.\n" );

   return( 1 );
}
