#define FILE "/masters/wizzes_players"
#define TP   this_player()

inherit "/room/room";

#define  SECURE  (TP->query_archwiz() && interactive(TP)   \
                  && environment(TP)==this_object())

mapping table;                  // idx == wiz_name, value == playername

private int add( string wiz, string player, int forced );

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   restore_object( FILE );
   if ( !table ) table = ([]);

   long_desc = short_desc =
   "                          The 'WWHWP' master !\n\n"+
   "Commands:\n"+
   "   add wizard player [forced-flag]  add a new player for a wizard\n"+
   "   remove wizard                    removes the player for the wizard\n"+
   "   showplayer wizard                shows the player the wizards plays\n"+
   "   showwizard player                show the wiz, the player belongs to\n"+
   "   showall                          shows all *grin*\n";

   set_light( 1 );
   no_obvious_msg = "";
}

void init()
{
   ::init();

   if(!SECURE) {
      TP->move_player( "und tschuess#/room/church" );
      return;
   }

   add_action( "do_add", "add" );
   add_action( "get_player", "showplayer" );
   add_action( "get_wizard", "showwizard" );
   add_action( "show_all", "showall" );
   add_action( "remove", "remove" );
}

static int do_add( string arg )
{
   string w, p;
   int    f;

   if ( !SECURE ) return( 0 );
   if ( !arg ) return( 0 );

   if ( sscanf( arg, "%s %s %d", w,p,f ) != 3 ) {
      if ( sscanf( arg, "%s %s", w,p ) != 2 ) {
         write( "Error on arguments: wizard player [forced]\n" );
         return( 1 );
      }
      else
         f = 0;
   }

   if ( !(master_object()->get_wiz_level(w)) ) {
      write( "No such wizard ("+w+").\n" );
      return( 1 );
   }
   if ( (master_object()->get_wiz_level(p)) ) {
      write( p+" is a wizard !\n" );
      return( 1 );
   }

   add( w, p, f );

   return( 1 );
}

static int show_all( string arg )
{
   int    i, size;
   string res;
   mixed  *ind;

   if ( !SECURE ) return( 0 );

   res = sprintf( "%-19s %-19s %-19s %-19s\n\n",
                  "wizard","player","wizard","player" );

   ind = m_indices( table );
   size = m_sizeof( table );
   for ( i = 0; i < size; i++ ) {
      res += sprintf( "%-19s %-19s", ind[i], table[ind[i]] );
      if ( (i%2) ) res += "\n";
      else         res += " ";
   }
   if ( (i%2) ) res += "\n";

   TP->more_string( res );

   return( 1 );
}

private int add( string wiz, string player, int forced )
{
   if ( !SECURE ) return( 0 );

   wiz = lower_case(wiz);
   player = lower_case(player);

   if ( table[wiz] ) {
      if ( forced ) {
         write( "Player '"+table[wiz]+"' " );
         table[wiz] = player;
         write( "exchanged to '"+player+"' for wizard '"+wiz+"'.\n"+
                "Please delete the old player-file !\n" );
      }
      else
         write( "This wizard already has a player.\n" );
   }
   else {
      table[wiz] = player;
      write( "Player '"+player+"' for wizard '"+wiz+"' added.\n" );
   }

   save_object( FILE );

   return( 1 );
}

static int remove( string wiz )
{
   if ( !SECURE ) return( 0 );

   if ( !table[wiz] )
      write( "This wizard has no player.\n" );
   else {
      write( "Player '"+table[wiz]+"' of wizard '"+wiz+"' removed.\n" );
      m_delete( table, wiz );
      save_object( FILE );
   }

   return( 1 );
}

static int get_player( string wiz )
{
   if ( !SECURE ) return( 0 );

   if ( !wiz ) return( 0 );

   write( "Wizard playing this player: " );
   if ( !table[wiz] ) write( "none\n" );
   else write( table[wiz]+"\n" );

   return( 1 );
}

static int get_wizard( string player )
{
   mixed *val;
   int   idx;

   if ( !SECURE ) return( 0 );

   if ( !player ) return( 0 );

   val = m_values( table );
   idx = member_array( player, val );
   write( "Wizard playing this players: " );
   if ( idx < 0 )
      write( "none\n" );
   else
      write( m_indices(table)[idx]+"\n" );

   return( 1 );
}
