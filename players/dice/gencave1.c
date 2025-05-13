#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     (this_object())

#define MONST_PATH "/players/patience/eastMonst/"

inherit "room/room";

int    caltropsChance, monstChance;
string monster_str;

object monster;

   object caltrops;
   int i;
reset( arg )
{

   ::reset( arg );

   /* removed
   if ( caltropsChance > random( 300 ) ) {
      if ( !present( "caltrops", TO ) ) {
         caltrops = clone_object( "/players/patience/guild/nweap/caltrops" );
            if (objectp(caltrops) )
             move_object(caltrops,TO);
            destruct( caltrops );
      }
   }
   
    end */
   if ( !monster ) {
      for ( i = 0; i < 5; i++ ) {
          if (monstChance > random(100) && stringp(monster_str) ) {
            monster = clone_object( MONST_PATH + monster_str );
            if (objectp(monster))
                move_object( monster,TO);
         }
      }
   }

   if ( arg )
      return;
   
   set_light(0);
   short_desc = "In the vulcano";
   long_desc = "You are in a cave inside the vulcano of the island of Ezo. The walls\n" +
               "in here are black and very dark and seem to oppress you. It is very\n" +
               "hot. From anywhere and nowhere you can hear devil laughter. You can\n" +
               "feel, that creatures staring at you with their dead eyes and tear at\n" +
               "your clothes. You quickly turn around but still can't see something.\n" +
               "You hope, that you get out of here alive.\n";
   
   items = ({ "cave", long_desc,
              "floor", "The floor is deep black and consits of lava",
              "walls", "The walls are deep black and consit of lava",
              "wall", "The wall is deep black and consits of lava",
              "lava", "It is melted stone and deep black",
              "creatures", "You quickly turn around but you only see darkness",
              "creature", "You quickly turn around but you only see darkness",
              "darkness", "You hardly can't see your hand before your eyes. You shiver",
              });
   
   smell = "The air in here stinks fouly and you can smell the sweat of a ryu.";
}


init( )
{
   object caltrops;

   ::init( );
   
   add_action( "search", "search" );
   add_action( "listen", "listen" );
   
   caltrops = present( "caltrops", TO );
   
   if ( caltrops ) {
      if ( TP->query_guild() == 8 ) {
         write( "As you enter the cave, you recognize, that some caltrops are lying on the\n" +
                "ground. So you place your steps cautiosly to avoid to step onto one.\n" );
      }
      else {
         write( "As you enter the cave, you step into some caltrops and hurt yourself badly.\n" );
         if ( TP->query_armour()[TP->query_arm_types("boot")] ) {
            TP->hit_player( TP->query_weight() );
            write( "But your boots can avoid the damage a little bit.\n" );
         }
         else
            TP->hit_player( TP->query_weight() * 2 );
            
         destruct( caltrops );
      }
   }
}


search( arg )
{
   if ( !arg )
      return;
         
   write("You search around in the lava but do not find anything.\n");
   say(this_player()->query_name()+" searches around.\n");
   
   return( 1 );
}

listen( arg )
{
   write( "You listen carefully but only can here the devil laughter of someone.\n" );
   say( TPN + " frowns.\n" );
   return( 1 );
}

set_caltrops_chance( c )
{
   caltropsChance = c;
}

query_caltrops_chance( c )
{
   return( caltropsChance );
}

set_monster( p, m )
{
   monstChance = p;
   monster_str = m;
}
