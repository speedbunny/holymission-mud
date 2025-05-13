#define PPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

#define DART_POISON   "/players/tatsuo/guild/nother/dart_poison"

inherit "room/room";

object ten1, ten2, priest, cup;
int    cupLevel;

reset( arg )
{
   if ( !ten1 ) {
      ten1 = clone_object( "/players/tatsuo/eastMonst/ten" );
      if ( transfer( ten1, this_object() ) )
         destruct( ten1 );
   }
   if ( !ten2 ) {
      ten2 = clone_object( "/players/tatsuo/eastMonst/ten" );
      if ( transfer( ten2, this_object() ) )
         destruct( ten2 );
   }
   if ( !priest ) {
      priest = clone_object( "/players/tatsuo/eastMonst/amidaPriest" );
      if ( transfer( priest, this_object() ) )
         destruct( priest );
   }
   
   if ( arg )
      return;
      
   set_light( 1 );
   cupLevel = 0;
      
   short_desc = "In a temple";
   long_desc = 
    "You are in an old buddhistic temple. The temple is open to all sides\n" +
    "so you can see the clearing and the forest outside. In each corner, and\n"+
    "there are four, is a wooden pillar. The pillars are carrying the roof.\n" +
    "In the middle of the room is a clayey cup.\n";

   items = ({ "temple", long_desc,
              "ground", "The ground is made of cly",
              "roof", "The roof is made of wood",
              "corner", "The corner has an angle of 90 degree and a pillar is standing there",
              "pillar", "Which pillar do you mean: the northeastern, southeastern ...",
              "northeastern pillar", "A wooden pillar. There is something engraved",
              "southeastern pillar", "A wooden pillar. You see nothing special",
              "southwestern pillar", "A wooden pillar. You see nothing special",
              "northwestern pillar", "A wooden pillar. You see nothing special",
              "sky", "The roof blocks your sight",
              "engraving", "Which engraving do you mean ?",
              "northeastern engraving", "You see some nihonese runes",
              "southeastern engraving", "You see some nihonese runes",
              "southwestern engraving", "You see some nihonese runes",
              "northwestern engraving", "You see some nihonese runes",
              "runes", "These are nihonese runes. Maybe you should read them",
              });

   dest_dir = ({ PPATH + "f26",  "out",
              });
   
   smell = "You smell the odor of religious items.";              

   cup = clone_object( "/obj/container" );
   cup->set_name( "cup" );
   cup->set_alias( "clayey cup" );
   cup->set_short( "a clayey cup" );
   cup->set_long( "A clayey cup. Pilgrims sacrifice things in it.\n" );
   cup->set_max_weight( 20 );
   transfer( cup, this_object() );
}


init( )
{
   ::init( );
   
   add_action( "search",   "search" );
   add_action( "climb_it", "climb" );
   add_action( "get_it",   "get" );
   add_action( "get_it",   "take" );
   add_action( "read_it",  "read" );
   add_action( "mumble_it", "mumble" );
   add_action( "dip_it",    "dip" );
}

search( arg )
{
   if ( !arg )
      return;
         
   write("You search and search, but find nothing special.\n");
   say(this_player()->query_name()+" searches around.\n");
   
   return( 1 );
}

climb_it( arg )
{
   if ( !arg || arg == "up" ) {
      write( "Climb what ?\n" );
      return( 1 );
   }
      
   if ( arg == "temple" || arg == "pillar" ) {
      write( "You remember, that the priests don't like this at all, so you stop.\n" );
      return( 1 );
   }
   
   return( 0 );
}

get_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "cup" || arg == "all" ) {
      write( "You think, that the priest could get angry about you, if you steal\n" +
             "the holy item. So you decide to stop your attempt.\n" );
      return( 1 );
   }

   return( 0 );
}

read_it( arg )
{
   if ( TP->query_guild() != 8 ) {
      write( "You see some nihonese rune, but you cannot understand them.\n" );
      return( 1 );
   }

   if ( arg == "runes" || arg == "engraving" ) {
      write( "The runes say: This temple is dedicated to Buddha.\n" );
      return( 1 );
   }
   
   return( 0 );
}

mumble_it( arg )
{
   object *inv, ccup, dp;

   if ( !arg )
      return;
      
   say( this_player()->query_name() + " mumbles something.\n" );
   if ( arg == "kayoto sylabatsi" ) {
      /* ----- check the cup ------------------------- */
      ccup = present( "clayey cup", this_object() );
      if ( !ccup ) {
          write( "Someone has stolen the cup!\n" );
          return( 1 );
      }
      
      if ( sizeof( all_inventory(ccup) ) == 2 ) {
         if ( !((all_inventory(ccup)[0]->id( "birch-bark" ) &&
               all_inventory(ccup)[1]->id( "fugu" )) ||
              (all_inventory(ccup)[0]->id( "fugu" ) &&
               all_inventory(ccup)[1]->id( "birch-bark" ))) ) {
               
            write( "There are not the proper items in the cup!\n" );
            return( 1 );
         }
      }
      else {
         write( "There are not the proper items in the clayey cup!\n" );
         return( 1 );
      }
      
      /* ----- reduce sp and make poison ---------------- */
      if ( this_player()->query_sp() < 50 + 25*(this_player()->query_wis()/10) ) {
         write( "You are too low on power to affect something.\n" );
         return( 1 );
      }
      
      this_player()->restore_spell_points( -(50 + 25*(this_player()->query_wis()/10)) );
      
      while( sizeof( all_inventory( ccup ) ) ) {
         destruct( all_inventory(ccup)[0] );
      }
      
      dp = clone_object( DART_POISON );
      transfer( dp, ccup );
      cupLevel = 1 + this_player()->query_wis()/10;
      
      write( "As you mumble the magic words, you can see smoke coming out of the\n" +
             "clayey cup. Suddenly, with a big flash, the content of the cup changes !\n" );
      say( "You can see smoke coming out of the clayey cup followed by a big flash !\n" );
   }
   else
      write( "Mumbeling " + arg + " will affect nothing.\n" );
      
   return( 1 );
}

dip_it( arg )
{
   object dart, p;

   if ( !arg )
      return;
      
   if ( arg == "dart in poison" || arg == "dart in cup" ) {
      dart = present( "dart", this_player() );
      if ( !dart ) {
         write( "You don't have a dart.\n" );
         return( 1 );
      }
      
      if ( cupLevel > 0 ) {
         dart->add_dart_poison( 100 );
         cupLevel--;
         if ( cupLevel == 0 ) {
            p = present( "clayey cup", this_object() );
            if ( p ) {
               p = present( "dart-poison", p );
               if ( p )
                  destruct( p );
            }
         }
         write( "You dip a dart in the poison.\n" );
         say( this_player()->query_name() + " dipped a dart in the cup.\n" );
      }
      else
         write( "Sorry, but there is nothing in the cup proper for dipping the dart in.\n" );
   }
   else
      write( "What do you want to dip in what ?\n" );
      
   return( 1 );
}
