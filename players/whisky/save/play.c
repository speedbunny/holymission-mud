#define PPATH "/players/patience/smilequest/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

#define OTH_DOOR (PPATH+"sleep")

inherit "room/room";

object girl;

reset( arg )
{
   if ( !girl ) {
      girl = clone_object( PPATH + "girl" );
      move_object( girl, this_object() );
   }

   if ( arg )
      return;
  
   set_light(1);
   short_desc = "In the playroom";
   long_desc = "You are in the playroom of the little girl. Since her mother\n" +
               "has died, the girl hadn't smiled just for a short time. She has\n" +
               "removed everything in her playroom, except of a picture of her\n" +
               "mother. To the north can you see @@door_state@@ door.\n";
   
   items = ({ "ground","It is a wooden floor",
              "floor","It is a wooden floor",
              "door","The door is made of wood",
              "keyhole","The door doesn't have a keyhole",
              "walls","They are made of wood. The picture of the queen is hanging there",
              "wall","They are made of wood. The picture of the queen is hanging there",
              "picture","You can see the queen on it",
              "queen","The queen is a very beautiful person. But on that picture, " +
                      "she looks very serious",
           });
   
   dest_dir = ({ });
}


init( )
{
   ::init( );
   add_action("north","north" );
   add_action("search","search");
   add_action("push","move" );
   add_action("push","push" );
   add_action("destroy","break" );
   add_action("destroy","destroy" );
   add_action("destroy","smash" );
   
   add_action("lock","lock" );
   add_action("unlock","unlock" );
   add_action("close","close");
   add_action("open","open");
   add_action("knock","knock");
   add_action("picklock","picklock");
}

destroy( str )
{
   if ( !str )
      return;
      
   if ( str == "picture" ) {
      write( "The girls burst into tears, so you stop your attempt.\n" );
      say( TPN + " tries to destroy the picture of the queen.\n" );
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
      
   if ( arg == "picture" ) {
      write( "The girls burst into tears, so you stop your attempt.\n" );
      say( TPN + " tries to destroy the picture of the queen.\n" );
      return( 1 );
   }
   
   return( 0 );
}
 


north( )
{
  if ( OTH_DOOR->GetDoorClosed() ) {
     write( "You try to go south, but bounces against the door.\n" );
     say( TPN + " tries to go south, but failed." );
  }
  else
     this_player()->move_player( "north#players/patience/smilequest/sleep" );

  return 1;
}    


door_state( )
{
     return( OTH_DOOR->door_state() );
}

/* ----- door - functions -------------------------------------------------- */

picklock(str) {
   return( OTH_DOOR->picklock( str ) );
}

knock(str) {
   return( OTH_DOOR->knock( str ) );
}

close(str) {
   if ( str == "door" )
      return( OTH_DOOR->close( str ) );
   return( 0 );
}
     
open(str) {
   if ( str == "door" )
      return( OTH_DOOR->open( str ) );
   return( 0 );
}

unlock(str) {
   return( OTH_DOOR->unlock( str ) );
}

lock(str)
{
   return( OTH_DOOR->lock( str ) );
}
