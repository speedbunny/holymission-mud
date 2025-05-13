#define PPATH "/players/patience/smilequest/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define OTH_DOOR (PPATH + "foreroom")

inherit "room/room";

object king;
int    hatIsHere;

reset( arg )
{
   if ( !king ) {
      king = clone_object( PPATH + "king" );
      move_object( king, this_object() );
   }
   
   hatIsHere = 1;

   if ( arg )
      return;
  
   set_light(1);
   short_desc = "In the throneroom";
   long_desc = "You are in the throneroom of the castle of sadness.\n" +
               "The walls seem to meet in the sky and at the north end is a gorgeous\n" +
               "chair. The king of this castle sits in his throne and he looks very sad\n" +
               "to you. To your north is a velvety curtain. @@chk_court@@\n" +
               "Except of these, the room is empty and a lot of dust lying around.\n";
   
   items = ({ "ground","The floor is made of stone",
              "floor","The floor is made of stone",
              "sky","When you look up, you just see walls",
              "walls","They are made of massive stone-boulders",
              "wall","They are made of massive stone-boulders",
              "boulder","A really giant boulder. You can't imagine, how it has moved in here",
              "boulders","Really giant boulders. You can't imagine, how they have moved in here",
              "stone-boulders","Really giant boulders. You can't imagine, how they have moved in here",
              "throne","A gorgeous throne with golden ornaments",
              "ornaments","They are made of white gold. They look like tears and they cast large shadows",
              "ornament","It is made of white gold. It looks like a tear and it casts a large shadow",
              "shadows","There is something wrong with them. At some places they are a bit darker",
              "shadow","There is something wrong with it. At some places it is a bit darker",
              "tears","White gold tears.",
              "dust","You see dust. Dust, and nothing else then dust",
              "curtain","You think, that the velvety curtain is very expensive",
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
   
   add_action("close","close");
   add_action("open","open");
}

destroy( str )
{
   if ( !str )
      return;
      
   if ( str == "throne" ) {
      write( "The throne is much to massive to destroy it.\n" );
      say( TPN + " tries to destroy the massive throne, what a silly attempt.\n" );
      return( 1 );
   }
   else if ( str == "walls" || str == "wall" ) {
      write( "The wall is much to massive to destroy it.\n" );
      say( TPN + " tries to destroy the massive wall. You fall down laughing.\n" );
      return( 1 );
   }

   return( 0 );      
}


search( arg )
{
   object hat;

   if ( !arg )
      return;
      
   if ( arg == "shadow" || arg == "shadows" || arg == "in shadow" || arg == "in shadows"
        || arg == "in the shadows" || arg == "in the shadow" )
   {
      if ( hatIsHere ) {
         write( "You search in the " + arg + " and find a funny hat!!!\n" );
         say( this_player()->query_name()+" found a funny hat.\n" );
         hat = clone_object(PPATH + "hat");
         if (transfer(hat,this_player())) {
            write( "But you can't carry that much.\n" );
            destruct( hat );
            return( 1 );
         }
         hatIsHere = 0;
      }
      else {
         write("You search and search, but find nothing.\n");
         say(this_player()->query_name()+" searches around.\n");
      }
      return( 1 );
   }
   else if ( arg == "the shadow" || arg == "the shadows" )
      write( "But you've already found " + arg + ".\n" );
   else {
      write("You search and search, but find nothing.\n");
      say(this_player()->query_name()+" searches around.\n");
   }
   return 1;
}

push( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "throne" ) {
      write( "You're much to weak, to move the throne.\n" );
      say( TPN + " tries to move the throne, but fails completely.\n" );
      return( 1 );
   }
   else if ( arg=="ornament" || arg=="ornaments" || arg == "tear" || arg == "tears" ) {
      write( "You can't move the " + arg + ".\n" );
      return( 1 );
   }
   else if ( arg == "curtain" || arg == "velvety curtain" ) {
      if ( OTH_DOOR->GetCourtMoved() ) {
         write( "You close the curtain.\n" );
         say( TPN + " closes the curtain.\n" );
         OTH_DOOR->SetCourtMoved( 0 );
      }
      else {
         write( "You move the curtain aside and see the foreroom behind.\n" );
         say( this_player()->query_name() + " moves the curtain aside.\n" );
         OTH_DOOR->SetCourtMoved( 1 );
      }
      return( 1 );
   }
   return( 0 );
}
 

north( )
{
  if ( OTH_DOOR->GetCourtMoved() )
     this_player()->move_player( "north#players/patience/smilequest/foreroom" );
  else {
     write( "You try to go north, but bounces against the door.\n" );
     say( TPN + " tries to go south, but failed." );
  }
  
  return 1;
}    


chk_court( )
{
   if ( OTH_DOOR->GetCourtMoved() )
      return( "Behind it you can see the foreroom." );
   else
      return( "It covers most of the northern wall." );
}


/* ----- door - functions -------------------------------------------------- */

close(str) {
   if ( str == "curtain" || str == "velvety curtain" ) {
      if ( OTH_DOOR->GetCourtMoved() ) {
         write( "You close the curtain.\n" );
         say( TPN + " closes the curtain.\n" );
         OTH_DOOR->SetCourtMoved( 0 );
      }
      else
         write( "But it is already closed!\n" );
      return( 1 );
   }

   return( 0 );
}
     
open(str)
{
   if ( str == "curtain" || str == "velvety curtain" ) {
      if ( OTH_DOOR->GetCourtMoved() )
         write( "But the curtain is already open!\n" );
      else {
         write( "You move the curtain aside and see the foreroom behind.\n" );
         say( this_player()->query_name() + " moves the curtain aside.\n" );
         OTH_DOOR->SetCourtMoved( 1 );
      }
      return( 1 );
   }

   return( 0 );
}
