#define PPATH "/players/patience/smilequest/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

int isClosed, trapClosed, bedMoved;

reset( arg )
{
   if ( arg )
      return;
      
   isClosed = 1; trapClosed = 1; bedMoved = 0;
  
   set_light(1);
   short_desc = "In the bedroom";
   long_desc = "You are standing in the bedroom of the castle. In former times, the king\n" +
               "and the queen had a lot of fun here, but since the queen died, the bed is\n" +
               "mostly unused. @@bed_state@@\n" +
               "To the south you can see @@door_state@@ door with funny paintings on it,\n" +
               "and to the east is the foreroom.\n";
   
   items = ({ "ground","The floor is made of wood",
              "floor","The floor is made of wood",
              "door","It is a wooden door with funny paintings on it",
              "paintings","They show a clown and some other thing, children like",
              "painting","It is the painting of a clown",
              "clown","The clown wears a clown-nose, a funny hat, dancing-shoes and a funny dress",
              "keyhole","But there is no keyhole here",
              "walls","They are made of massive stone",
              "wall","They are made of massive stone",
              "bed","It seems, that the bed wasn't used for a much too long time",
              "trapdoor","@@l_trap@@",
              "ring","@@l_ring@@",
              "iron ring","@@l_ring@@",
           });
   
   dest_dir = ({ PPATH + "foreroom", "east",
              });
}


init( )
{
   ::init( );
   add_action("south","south" );
   add_action("down","down" );
   add_action("search","search");
   add_action("enter","enter");
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
   add_action("picklock","picklock");
}

destroy( str )
{
   if ( !str )
      return;
      
   if ( str == "bed" ) {
      write( "You are much too weak to destroy the large bed!!!\n" );
      say( TPN + " tries to destroy the bed, but fails pitiable!!!\n" );
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
      
   if ( arg == "bed" ) {
      if ( bedMoved ) {
         write( "With great effort you manage to move the bed.\n" );
         say( this_player()->query_name() + " moved the bed.\n" );
         bedMoved = 0;
      }
      else {
         write( "With great effort you manage to move the bed and find a trapdoor!!!\n" );
         say( this_player()->query_name() + " moved the bed.\n" );
         bedMoved = 1;
      }
      return( 1 );
   }
   
   return( 0 );
}
 

enter( arg )
{ 
  if ( !arg )
     return;
     
  if ( arg == "trapdoor" || arg == "wooden trapdoor" ) {
     if ( bedMoved ) {
        if (trapClosed) {
           write("You bang your knees against the closed trapdoor.\n");
           say(TPN+" falls at the trapdoor. Not very effective, though.\n");
        }
        else
           this_player()->move_player( "down#/players/patience/smilequest/cellar_entry" );
        return( 1 );
     }
  }
  else if ( arg == "bed" ) {
     write( "The bed wasn't used for such a long time, so you won't disturb the peace of it.\n" );
     return( 1 );
  }

  return( 0 );
}    

door_state( )
{
   if (isClosed)
      return( "a closed" );
   else
      return( "an open" );
}

bed_state( )
{
   if ( bedMoved )
      return( "Beside the bed you see " + trap_state() + " trapdoor." );
   else
      return( " " );
}

trap_state( )
{
   if ( trapClosed )
      return( "a closed" );
   else
      return( "an open" );
}

l_trap( )
{
   if ( bedMoved )
      return( "It is "+trap_state()+" wooden trapdoor with a very small rusty iron ring" );
   else
      return( "You can't see a trapdoor here" );
}

l_ring( )
{
   if ( bedMoved )
      return( "It is a very small rusty iron ring. It is used to open the door" );
   else
      return( "You can't see a ring here" );
}

/* ----- door - functions -------------------------------------------------- */
south( ) {
  if (isClosed) {
     write("You bang your head against the closed door.\n");
     say(TPN+" runs into the door. Not very effective, though.\n");
  }
  else {
     this_player()->move_player( "south#players/patience/smilequest/play" );
  }
  return 1;
}

down( ) {
  if ( bedMoved ) {
     if (trapClosed) {
        write("You bang your knees against the closed trapdoor.\n");
        say(TPN+" falls at the trapdoor. Not very effective, though.\n");
     }
     else
        this_player()->move_player( "down#players/patience/smilequest/cellar_entry" );
     return( 1 );
  }

  return( 0 );
}

picklock(str) {
  if ((str=="trapdoor" || str=="door" || str=="wooden door") && present("picklock",TP)) {
     write("But the "+str+" has no keyhole!!!\n");
     say(TPN+" the thief tries to use "+TPPOS+" picklock on the trapdoor.\n" +
     capitalize(TPOBJ)+" fails completely ...\n");
     return 1;
  }
}

knock(str) {
  string msg;

  if (str=="door" || str == "trapdoor" ) {
     msg=" at the "+str+". Knock "; 
     switch(random(14)) {
     case 0: msg+="knock ";
     case 1: msg+="knock ";
     case 2: msg+="KNOCK ";
     case 3: msg+="knark ";
     case 4: msg+="knock ";
     case 5: msg+="KNARK ";
     case 6: msg+="knerk ";
     case 7: msg+="KNERK ";
     case 8: msg+="knurk ";
     case 9: msg+="KNURK ";
     case 10: msg+="knork ";
     case 11: msg+="KNORK ";
     case 12: msg+"Knarrrrrrkkkkrrrr ";
     }
     msg+="...\n";
     write("You knock"+msg);
     say(TPN+" knocks"+msg);
     return 1;
  }
}

close(str)
{
   if ( !str )
      return;
      
   if ( str == "door" || str == "wooden door" ) {
      if (isClosed)
         write("The door is aready closed!\n");
      else {
         write("You close the door.\n");
         say(TPN+" closes the door.\n");
         isClosed = 1;
      }
      return( 1 );
   }
   else if ( str == "trapdoor" ) {
      if ( bedMoved ) {
         if ( trapClosed )
            write( "The trapdoor is already closed!\n" );
         else {
            write( "You close the trapdoor.\n" );
            say( TPN+" closes the trapdoor.\n" );
            trapClosed = 1;
         }
      }
      else
         write( "But you can't see a trapdoor!\n" );
      return( 1 );
   }

   return( 0 );
}
     
open( str )
{
  string str1;
  
  if ( !str )
     return;
     
  if ( str == "trapdoor" ) {
     if ( bedMoved ) {
        if ( trapClosed )
           write( "But the ring is much to small, to open the trapdoor with your fingers!!!\n" );
        else
           write( "But it is already open!\n" );
     }
     else
        write( "But you can't see a trapdoor!\n" );
  }
  else if ( str == "trapdoor with hook" || str == "trapdoor with iron hook" ) {
     if ( bedMoved ) {
        if ( trapClosed ) {
           if ( present( "hook", TP ) ) {
              write( "Knaaaaaaarrrrrrrrrrr... The trapdoor opens!\n" );
              say( TPN + " opens the trapdoor.\n" );
              trapClosed = 0;
           }
           else
              write( "But you don't have a hook!\n" );
        }
        else
           write( "But it is already open!\n" );
     }
     else
        write( "But you can't see a trapdoor!\n" );
  }
  else if ( str == "door" || str == "wooden door" ) {
     if ( isClosed ) {
        write( "The door swings wide open.\n" );
        say( TPN + " opens the door.\n" );
        isClosed = 0;
     }
     else
        write( "But it is already open!!!\n" );
  }
  else if ( sscanf( str, "trapdoor %s", str1 ) ) {
     if ( bedMoved )
        write( "But that item won't fit.\n" );
     else
        write( "But you can't see a trapdoor!\n" );
  }
  else if ( sscanf( str, "door %s", str1 ) )
     write( "But the door isn't locked.\n" );
  else
     return( 0 );
     
  return( 1 );
}

unlock( str )
{
   if ( !str )
      return;

   write( "But you can't see a lock here.\n" );
   return( 1 );
}

lock( str )
{
   if ( !str )
      return;
      
   write( "You can't see a lock here.\n" );
   return( 1 );
}


GetDoorClosed( )
{
   return( isClosed );
}

GetTrapClosed( )
{
   return( trapClosed );
}

SetTrapClosed( newState )
{
   trapClosed = newState;
}

GetBedMoved( )
{
   return( bedMoved );
}
