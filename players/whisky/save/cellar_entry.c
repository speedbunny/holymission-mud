#define PPATH "/players/patience/smilequest/"
#define OTH_DOOR (PPATH + "sleep")
#define TP  this_player()
#define TPN TP->query_name()

inherit "room/room";
   object rat;

 reset(arg) {
   if (!rat) {
      rat=clone_object("obj/monster");
      rat->set_name("rat");
      rat->set_alt_name("brown rat");
      rat->set_short("A little brown rat");
      rat->set_long("You see a little, sweet brown rat.\n");
      rat->set_level(2);
      rat->set_whimpy(90);
      rat->set_aggressive(1);
      move_object(rat,this_object());
      }
      
   ::reset(arg);
   
 if (arg) return;
 
 smell="The air smells very fouly here !";
 set_light(-1);
 short_desc="In a dark cellar";
 long_desc=
            "You have entered the dark cellar of the castle of sadness.\n"+
            "It's cold and wet. The vault smells a bit after bad wood.\n"+
            "There is a small corridor leading further to the east and\n" +
            "above your head is @@trap_state@@ trapdoor.\n";
 items = ({
          "corridor","You see a small dark corridor, leading to the east",
          "bottom","You see a oak-wooden bottom",
          "walls","You see dark brick-walls",
          "vault","You see an oak-wooden vault",
          "wood","You see just oak-wood",
          "trapdoor","It is @@trap_state@@, wooden trapdoor",
          });
          
 dest_dir = ({
             PPATH+"cellar4","east",
             });
      
             
  }
  
  init() {
    if (present("rat",this_object())) {
       call_out("run_rat",2);
     }
    add_action("search","search");
    add_action("close","close");
    add_action("open","open");
    add_action("up","up" );
    ::init();
    }
    
   search(arg) {
     
     if (!arg) 
        return;
     write("You search and search, but find nothing.\n");
     say(this_player()->query_name()+" searches around.\n");
   return 1;
    } 
    
   run_rat() {
      rat->run_away();
      }
   
      
trap_state( )
{
   return( OTH_DOOR->trap_state() );
}

up( ) {
  if ( OTH_DOOR->GetTrapClosed() ) {
     write("You bang your head against the closed trapdoor.\n");
     say(TPN+" bounces into the trapdoor. Not very effective, though.\n");
  }
  else {
     this_player()->move_player( "up#players/patience/smilequest/sleep" );
  }
  return 1;
}

close(str)
{
   if ( !str )
      return;
      
   if ( str == "trapdoor" ) {
      if (OTH_DOOR->GetTrapClosed())
         write("The trapdoor is aready closed!\n");
      else {
         write("You close the trapdoor.\n");
         say(TPN+" closes the trapdoor.\n");
         OTH_DOOR->SetTrapClosed( 1 );
      }
      return( 1 );
   }

   return( 0 );
}

open( str )
{
  if ( !str )
     return;
     
  if ( str == "trapdoor" || "trapdoor with hook" ) {
     if ( OTH_DOOR->GetBedMoved() ) {
        if ( OTH_DOOR->GetTrapClosed() ) {
           write( "You open the trapdoor.\n" );
           say( TPN + " opens the trapdoor.\n" );
           OTH_DOOR->SetTrapClosed( 0 );
        }
        else
           write( "But it is already open!\n" );
     }
     else
        write( "But you can't open the trapdoor, it is blocked!\n" );
  
     return( 1 );
  }
  
  return( 0 );
}
