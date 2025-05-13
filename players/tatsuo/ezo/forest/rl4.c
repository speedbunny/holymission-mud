#define PPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

string downDir, upDir, jumpDir;

reset( arg )
{
   if ( arg )
      return;
      
   set_light(1);
   short_desc = "At a rock-ledge";
   long_desc = "You are standing at a rock-lege of a steer cliff. The rock-ledge\n" +
               "is very small. You can see some deep scratches in the rock and\n" +
               "you get frightend of the aura here. To the north can you see a tree.\n" +
               "It seems possible to climb up from here.\n";
   
   items = ({ "rock-ledge", long_desc,
              "cliff", "The cliff is very steer",
              "scratches", "You think a very powerful creature has made them",
              "scratch", "You think a very powerful creature has made it", 
              "tree", "It is a very strong tree and it is close to the cliff",
              "sky", "You cannot see the sky, because the leaves block your sight",
              "leaves", "These are fresh green leaves",
              "leave", "This is a fresh green leave",
              });
   
   dest_dir = ({ PPATH + "rl5", "east",
                 PPATH + "rl3", "west",
              });
              
   jumpDir = PPATH + "t32";
   downDir = PPATH + "f32";
   upDir   = PPATH + "valley1";
   
   
   smell = "You smell the odor of death and destruction.";
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   
   add_action( "climb_it", "climb" );
   add_action( "climb_it", "down" );
   add_action( "jump_it",  "jump" );
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
   if ( !arg ) {
      write( "In which direction do you want to climb ?\n" );
      return( 1 );
   }
   
   if ( arg == "down" )
   {
      write( "You try to climb down but loose your halt and fall down.  OUCH !!\n" );
      TP->hit_player( 10 );
      TP->move_player( "down the cliff", downDir );
   }
   else if ( arg == "up" ) {
      if ( upDir && strlen( upDir ) ) {
         write( "With great affort you manage it to climb up the cliff.\n" );
         TP->move_player( "up the cliff", upDir );
      }
      else
         write( "You cannot climb up from here.\n" );
   }
   
   return( 1 );
}

jump_it( arg )
{
   if ( !arg ) {
      write( "You jump around for a while but then feel silly and you decide to stop it.\n" );
      say( TP->query_name() + " jumps around.\n" );
   }
   else if ( arg == "tree" || arg == "to tree" || arg == "into tree" || arg == "at tree" ) {
      write( "You make a big jump to the tree.\n" );
      say( TP->query_name() + " into tree.\n" );
      TP->move_player( "into the tree", jumpDir );
   }
   else
      write( "You cannot jump in that direction.\n" );   
   return( 1 );
}

check_tekagi( )
{
   int    i;

   for ( i = 0; i < sizeof(TP->query_armour()); i++ ) {
      if ( (TP->query_armour())[i] && (TP->query_armour())[i]->id( "tekagi" ) )
         return( 1 );
   }

   return( 0 );
}
