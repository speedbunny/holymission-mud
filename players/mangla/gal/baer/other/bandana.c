inherit "obj/armour.c";

string *Lyrics;
string verb;

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   set_name( "bandana" );
   set_short( "A blue bandana" );
   set_long( "The blue bandana of Patience.\n" );

   set_size( "medium" );
   set_type( "helmet" );
}

init( arg )
{
   ::init( arg );
   
   add_action( "do_sing", "sing" );
   add_action( "do_double", "double" );
}

do_double( arg )
{
   object *obj, *obj1;
   string n1, n2;

   if ( this_player()->query_real_name() != "patience" ) {
      write( "Only Pat can double.\n" );
      return( 1 );
   }

   if ( arg ) {
      if ( sscanf( arg, "%s/%s", n1, n2 ) != 2 ) {
         write( "Error in arg.\n" );
         return( 1 );
      }
   } 
   else {
      n1 = "itzy";
      n2 = "patience";
   }

   if ( !find_living( n1 ) && !find_living( n2 ) ) {
      write( n1 + " or " + n2 + " not on\n" );
      return( 1 );
   }
  
   "/players/patience/nag/level2/double_master"->dest_em();
 
   obj = clone_object( "/players/patience/nag/level2/double" );
   move_object( obj, "/players/patience/nag/level2/1/jct" );
   obj->set_double( find_living( n1 ) );

   obj1 = clone_object( "/players/patience/nag/level2/double" );
   move_object( obj1, "/players/patience/nag/level2/2/jct" );
   obj1->set_double( find_living( n2 ) );

   obj->set_friend( obj1 );
   obj1->set_friend( obj );

   "/players/patience/nag/level2/double_master"->init( 
                  find_living( n2 ), obj1,
                  find_living( n1 ), obj );

   find_living( n2 )->move_player( 
             "???#/players/patience/nag/level2/1/jct" );
   find_living( n1 )->move_player(
             "???#/players/patience/nag/level2/2/jct" );

   write( "Doubling ok.\n" );
   return( 1 );
}

do_sing( arg )
{
   verb = "sing";
   if ( arg == "patience" ) 
      Lyrics = explode( lyrics_patience(), "#" );
   else if ( arg == "mindcrime" )
      Lyrics = explode( lyrics_mindcrime(), "#" );
   else if ( arg == "fadeblack" )
      Lyrics = explode( lyrics_fadeblack(), "#" );
   else if ( arg == "jabber" ) {
      Lyrics = explode( lyrics_jabber(), "#" );
      verb = "recite";
   }
   else if ( arg == "zombie" ) {
      Lyrics = explode( lyrics_zombie(), "#" );
   }
   else {
      write( "You don't know this song.\n" );
      return( 1 );
   }   

   call_out( "sing_song", 5, 0 );

   write( "You "+verb+" " + arg + "....\n" );
   return( 1 );
}

sing_song( arg )
{
   if ( arg >= sizeof( Lyrics ) ) {
      return;
   }

   call_out( "sing_song", 5, arg+1 );
   shout( this_player()->query_name()+" "+verb+"s: "+Lyrics[arg]+"\n" );
}

lyrics_patience()
{
   return(
      "Shed a tear 'cos I'm missing you, I'm still alright to smile#" +
      "Girl I think about you every day now#" +
      "There was a time when i wasn't sure, but you set my mind at ease#" +
      "There is no doubt you're in my heart now#"+
      "Sad woman take it slow, it'll work itself out fine#" +
      "All we need is just a little patience#" +
      "Sad sugar make it slow, and we'll come together fine#" +
      "All we need is just a little patience#" +
      "Patience .... ooohhh....#" +
      "I sit here on the stairs, 'cos I'd rather be alone#" +
      "If I can't have your right now, I'll wait dear#" +
      "Sometimes I get so tense, but I can't speed up the time#" +
      "But you know love there's one more thing to consider#" +
      "Sad woman take it slow, and things will be just fine#" +
      "You and I'll just use a little patience#" +
      "Sad sugar take the time, 'cos the lights are shining bright#" +
      "You and I got what it takes to make it#" +
      "We won't fake it#" +
      "Ahhh, well never break it#" +
      "'Cos i can't take it#" +
      "You hear Sourcer playing a bombastic solo !!!#" +
      "A little patience, oooh yeah, ooh yeah#" +
      "We need a little patience, yeah#" +
      "Just a little patience, yeah#" +
      "Some old patience, yeah#" +
      "I've been walking the streets at night#" +
      "Just trying to get it right#" +
      "It's hard to see with so many around#" +
      "You know I don't like being stuck in a crowd#" +
      "And the streets don't change, but maybe the names#" +
      "I ain't go time for the games#" +
      "'Cos I need you#" +
      "Yeah, but I need you#" +
      "Ooooh, I need you#" +
      "Waaahh, I need you#" +
      "Oooh, this time ..." );
}

lyrics_mindcrime( )
{
   return(  
      "It just takes a minute#" +
      "And you'll feel no pain#" +
      "Gotta make something of your life boy#" +
      "Give me one more vein#" +
      "You've come to see the doctor#" +
      "Cause I'll show you the cure#" +
      "I'm gonna take away the questions#" +
      "Yeah, I'm gonna make you sure#" +
      "A hit man for the order#" +
      "When you couldn't go to school#" +
      "Had a skin job for a hair-do#" +
      "Yeah, you looked pretty cool#" +
      "Had a habit doing mainline#" +
      "Watch the dragon burn#" +
      "No regrets, you've go no goals#" +
      "Nothing more to learn#" +
      "Now I know, you won't refuse#" +
      "Because we've got so much to do#" +
      "And you've got nothing more to lose#" +
      "So take this number and welcome to#" +
      "OPERATION : MINDCRIME#" +
      "We're an underground revolution#" +
      "Working overtime#" +
      "OPERATION : MINDCRIME#" +
      "There's a job for you#" +
      "In the system boy#" +
      "With nothing to sign" );
}


lyrics_fadeblack()
{
   return( 
     "Life it seems, will fade away#" +
     "Drifting further every day#" +
     "Getting lost within myself#" +
     "Nothing matters no one else#" +
     "I have lost the will to live#" +
     "Simply nothing more to give#" +
     "There is nothing more for me#" +
     "Need the end to set me free#" +
     "Things not what they used to be#" +
     "Missing one inside of me#" +
     "Deathly lost, this can't be real#" +
     "Cannot stand this hell I feel#" +
     "Emptiness is filling me#" +
     "To the point of agony#" +
     "Growning darkness taking dawn#" +
     "I was me, but now he's gone#" +
     "No one but me can save myself, but its too late#" +
     "Now I can't think, think why should I even try#" +
     "Yesterday seems as though it never existed#" +
     "Death greets me warm, now I will just say goodbye" ); 
}
lyrics_jabber()
{
   return( 
   "T'was brilling and the slighty toves#"+
   "Did gyre and gimble in the wabe#"+
   "All mimsy were the borogoves#"+
   "And momen rath outgrabe#"+
   "Beware the Jabberwock my son#"+
   "The jaws that bite, the claws that catch#"+
   "Beware the Jubjub-Bird and shun#"+
   "The frumious Bandersnatch#"+
   "He took his vorpal sword in hand#"+
   "Long time the manxiom beast he sought#"+
   "So rested he, by the Tumtum-Tree#"+
   "And stood awhile in though#"+
   "And as he stood in uffish thought#"+
   "The Jabberwock, with eyes of flame#"+
   "Game whiffling through the tulgy wood#"+
   "And burbling as it came#"+
   "One, Two - One, Two - And through and through#"+
   "The vorpal sword went snicker-snack#"+
   "He left it dead, and with its head#"+
   "He went galumping back#"+
   "'And hath'd thou slain the Jabberwock#"+
   "Come to my arms, my beamish boy#"+
   "Oh frabjous day, Calloh, Callay'#"+
   "He cortled in his joy"+
   "T'was brilling and the slighty toves#"+
   "Did gyre and gimble in the wabe#"+
   "All mimsy were the borogoves#"+
   "And momen rath outgrabe"
   );
}

lyrics_zombie()
{
   return( 
   "Another head hangs lowly#"+
   "Child is slowly taken#"+
   "And the violence caused such silence#"+
   "Who are we mistaken#"+
   "But you see, it's not me,#"+
   "it's not my family#"+
   "In your head, in your#"+
   "head. They are fighting#"+
   "With their tanks and their bombs#"+
   "And their bombs and their guns#"+
   "In your head,#"+
   "in your head they are cryin'#"+
   "In your head#"+
   "Zombie#"+
   "What's in your head, in your head#"+
   "Zombie#"+
   "Another mother's breakin'#"+
   "heart is taking over#"+
   "when the violence causes silence#"+
   "We must be mistaken#"+
   "It's the same old theme since 1916#"+
   "In your head,#"+
   "in your head they're still fighting#"+
   "With their tanks#"+
   "In your head head they are dyin'#"+
   "In your head#"+
   "Zombie#"+
   "What's in your head, in your head#"+
   "Zombie"
   );
}

