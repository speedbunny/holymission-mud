#define PPATH "/players/patience/smilequest/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

int courtainMoved;

reset( arg )
{
   if ( arg )
      return;
  
   set_light(1);
   short_desc = "In the foreroom";
   long_desc = "You are standing in the foreroom of the castle. A large and very\n" +
               "expensive carpet covers the floor. To the south is a velvety curtain.\n" +
               "@@chk_court@@ To the west,\n" +
               "you can see the sleeping room and to the east is the kitchen.\n" +
               "There is also @@door_state@@ portal to your north.\n";
   
   items = ({ "ground","A large and very expensive carpet covers it",
              "floor","A large and very expensive carpet covers it",
              "carpet","It is really expensive and very beautiful",
              "portal","It is a massive golden portal, with a golden keyhole and a golden frame",
              "keyhole","It is made of white gold",
              "frame","It is made of white gold and its very massive",
              "walls","They are made of massive stone",
              "wall","They are made of massive stone",
              "curtain","You think that the velvety curtain is also very expensive",
           });
   
   dest_dir = ({ PPATH + "sleep", "west",
                 PPATH + "kitchen", "east",
              });
}


init( )
{
   ::init( );
   add_action("north","north" );
   add_action("south","south" );
   add_action("search","search");
   add_action("enter","enter");
   add_action("push","lift" );
   add_action("push","move" );
   add_action("push","push" );
   add_action("destroy","break" );
   add_action("destroy","destroy" );
   add_action("destroy","smash" );
   
   add_action("unlock","unlock");
   add_action("close","close");
   add_action("lock","lock");
   add_action("open","open");
   add_action("knock","knock");
   add_action("north","north");
   add_action("picklock","picklock");
}

destroy( str )
{
   if ( !str )
      return;
      
   if ( str == "portal" || str == "golden portal" ) {
      write( "You are much too weak to destroy the golden portal!!!\n" );
      say( TPN + " tries to destroy the portal, but fails pitiable!!!\n" );
      return( 1 );
   }

   return( 0 );      
}


search( arg )
{
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
}

push( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "curtain" || arg == "velvety curtain" ) {
      if ( courtainMoved ) {
         write( "You close the curtain.\n" );
         say( TPN + " closes the curtain.\n" );
         courtainMoved = 0;
      }
      else {
         write( "You move the curtain aside and see the throneroom behind.\n" );
         say( this_player()->query_name() + " moves the curtain aside.\n" );
         courtainMoved = 1;
      }
      return( 1 );
   }
   
   return( 0 );
}
 

enter( arg )
{
   if ( arg != "thronroom" )
      return;
  
  if (courtainMoved)
     this_player()->move_player( "south#players/patience/smilequest/thronroom" );
  else {
     write( "You try to go south, but bounces against the curtain.\n" );
     say( TPN + " tries to go south, but failed." );
  }

  return 1;
}    

south( )
{
  if (courtainMoved)
     this_player()->move_player( "south#players/patience/smilequest/thronroom" );
  else {
     write( "You try to go south, but bounces against the curtain.\n" );
     say( TPN + " tries to go south, but failed." );
  }

  return 1;
}    


door_state( )
{
     return( (PPATH + "entrance")->door_state() );
}

chk_court( )
{
   if ( courtainMoved )
      return( "Behind it you can see the thronroom." );
   else
      return( "It covers most of the northern wall." );
}

GetCourtMoved( )
{
   return( courtainMoved );
}

SetCourtMoved( newState )
{
   courtainMoved = newState;
}

/* ----- door - functions -------------------------------------------------- */

picklock(str) {
   return( (PPATH + "entrance")->picklock( str ) );
}

north( ) {
  if ( (PPATH + "entrance")->IsClosed() ) {
     write("You bang your head against the closed portal.\n");
     say(TPN+" runs into the portal. Not very effective, though.\n");
  }
  else {
     this_player()->move_player( "north#players/patience/smilequest/entrance" );
  }
  return 1;
}

knock(str) {
   return( (PPATH + "entrance")->knock( str ) );
}

close(str) {
   if ( str == "curtain" || str == "velvety curtain" ) {
      if ( courtainMoved ) {
         write( "You close the curtain.\n" );
         say( TPN + " closes the curtain.\n" );
         courtainMoved = 0;
      }
      else
         write( "But it is already closed!\n" );
      return( 1 );
   }
   else 
    return( (PPATH + "entrance")->close( str ) );
}
     
open(str)
{
   if ( str == "curtain" || str == "velvety curtain" ) {
      if ( courtainMoved )
         write( "But the curtain is already open!\n" );
      else {
         write( "You move the curtain aside and see the thronroom behind.\n" );
         say( this_player()->query_name() + " moves the curtain aside.\n" );
         courtainMoved = 1;
      }
      return( 1 );
   }
   else
     return( (PPATH + "entrance")->open( str ) );
}

unlock(str) {
   return( (PPATH + "entrance")->unlock( str ) );
}

lock(str)
{
   return( (PPATH + "entrance")->lock( str ) );
}
