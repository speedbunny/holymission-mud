
/* last edit whisky for a better code */

#define PPATH "/players/patience/ezo/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

#define LIQUID "/players/patience/guild/nother/ref_liquid"

int counter;

void reset(int flag )
{
   counter = 10;
   if ( flag == 0 )
   {
   set_light(1);
   short_desc = "At the inner-yard";
   long_desc = 
   "This is the inner-yard of the residence of Matsumae Yoshihiro, the\n" +
   "evil Shogun of the island of Ezo. The ground here consists of grass.\n" +
   "The yard is surrounded with chambers of the residence only to the north\n" +
   "is a free place.\n" +
   "In the middle of the yard is a great fountain.\n" +
   "Do NOT go north if you want to stay alive !\n";
   
   items = ({ 
   "inner-yard", long_desc,
   "yard", long_desc,
   "ground", "The ground is grassy",
   "grass", "It is almosted stamped down but it has a fresh green color",
   "chambers", "These are the cambers of the house. Why not enter one of them?",
   "chamber", "These are the cambers of the house. Why not enter one of them?",
   "fountain", "The fountain is round and made of stone.\n" +
               "There is a strange liquid in it",
   "liquid", "It is a strange, reflecting liquid. You can see yourself in it",
          });
              
   smell = "You smell the odor of grass";
   
   dest_dir = ({ PPATH + "inner-yard", "north",
/*
                 PPATH + "store", "west",
*/
                 "/players/patience/guild/room","east",
                 "/players/patience/ezo/atShogun","south",
              });
   }
}


void init( )
{
   ::init( );
   add_action("search","search");
   add_action("enter","enter");
   add_action("_fill", "fill" );
	add_action( "_jump", "jump" );
/* schaut etwas bescheuert aus .. Ralf
   if (living(this_player()) && !this_player()->query_npc())
   counter = 1;
*/
}

// changed so that the exits are visible, for better code : Whisky

status move(string arg)
{
   object ob;
      if (!arg) arg = query_verb();
      if ( (arg=="west" || arg=="east" || arg=="south") && 
            TP->query_guild()!=18 && TP->query_level() > 9991) 
      {
         write( "You are allowed to enter there.\n" );
         return( 1 );
      }
/*
          ob = present("ninja",this_object());

          if (ob && living(ob))
          {
             write( "The ninja yawns at you.\n" );
             return 1;
          } 
          else if (counter > 0)
          {
          tell_room(this_object(),
               "Suddenly a ninja appears and yawns tiredly.\n" +
               "The ninja say: Good morning ! \n" +
	       "The ninja goes back to his breakfast.\n" );
               counter --;
          return 1;
         }
    }
*/
    return ::move(arg);
}
      
int search(string arg)
{
   object key;
   
   if ( !arg ) return 0;
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return( 1 );
}


int enter(string arg)
{
   if ( !arg ) return 0;
   write( "Give a direction to enter one of the chambers.\n" );
   return( 1 );
}


int _fill(string arg)
{
   object liquid, egg;

   if ( !arg ) return 0;
      
   if ( arg == "egg with liquid" || arg == "liquid in egg" || arg == "liquid into egg" ) {
      egg = present( "'egg'", this_player() );
      if ( egg ) {
         liquid = clone_object( LIQUID );
         if ( transfer( liquid, egg ) ) {
            write( "Sorry, but there is no room for more in the egg.\n" );
            return( 1 );
         }
         write( "You filled some liquid in the egg.\n" );
         return( 1 );
      }
      write( "Sorry, but you don't have an egg.\n" );
   }
   else
      write( "Fill what in what ?\n" );
   
   return( 1 );
}

int _jump( string arg )
{
	if ( arg != "into the fountain" ) {
		return( 0 );
   }

	this_player()->move_player( "out of sight#/players/patience/ezo/inFount" );
	return( 1 );
}
