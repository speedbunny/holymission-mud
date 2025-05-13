inherit "obj/monster";
object bad;

#define ENV_PATH   "/players/patience/ezo/ryuworld/"

#define TP  (this_player())
#define TPN (this_player()->query_name())
#define TO  (this_object())
#define E   environment
#define MA  query_attack()
#define MAN (query_attack()->query_name())

int moveCount;

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   set_name( "ryu" );
   set_short("The Great Dragon Ryu");
   set_level( 90 );
   set_race( "ryu" ); 
   set_ac( 15 );

   set_wc(120);
   set_aggressive( 1 );
   set_prevent_poison( 1 );

   /* alignment !!!*/

   moveCount = 60;
   call_out( "my_heart_beat", 2 );

   set_dead_ob( this_object() );

   return( 1 );
}

init()
{
   ::init();

   add_action( "block", "assassinate" );
   add_action( "block", "backstab" );
   add_action( "block", "stinger" );
   add_action( "block", "throw" );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
}

long( )
{
   write( 
     "This is a very huge beast, which looks very mighty and powerful.\n"+
     "As it recognises you looking at him, it turns his head toward you\n"+
     "and opens his mouth. You stare onto its enormous theets, and don't\n"+
     "dare to stay within its range any longer !!!\n" );

   TP->run_away();
}

my_heart_beat()
{
   if ( moveCount < 0 ) {
      if ( !MA )
         random_move();
      else if ( environment(MA) != environment(TO) )
         random_move();
      moveCount = 60;
   }
   else if ( !(moveCount % 25) ) {
      if ( !random(4) )
         poison_next_room();
   }

   moveCount--;

   call_out( "my_heart_beat", 2 );

   return( 1 );
}

poison_next_room()
{
   string *dirs;
   object *cloud;
   int    c, i;

   dirs = environment(TO)->query_room("dest_dir");

   if ( !dirs && !sizeof(dirs) )
      return;

   c = 3;
   i = random(sizeof(dirs)/2)*2;
   while( c-->0 && !dirs[i] )
      i = random(sizeof(dirs)/2)*2;

   if ( dirs[i] ) {
      tell_room( dirs[i], "The ryu blows a POISON-CLOUD in this room !!!\n" );

      cloud = present( "poison_cloud", find_object( dirs[i] ) );
      if ( !cloud ) {
         cloud = clone_object( "/players/patience/eastMonst/poison_cloud" );
         move_object( cloud, dirs[i] );
      }
      cloud->add_poison( random( 30 ) + 15 );
   }
}

run_away() {return;}

attack()
{
   object *nsoul, *obj, *obj1;
   int    i, len;

   if ( !TP || !MA || !present( MA, E(TO) ) ) {
      return( ::attack() );
   }

   switch( random(100 ) ) {
      /* ----- break/drop weapon -------------------- */
      case 0..14:  nsoul = present( "ninja_soul", MA );
                   obj = MA->query_wielded_weapon();
                   if ( nsoul && random(100)<50 && nsoul->query_secWielded() )
                      obj = nsoul->query_secWielded();

                   if ( !obj || obj->query_type() == "guild" )
                      return( ::attack() );

                   if ( random(100) < 30 ) {
                      tell_object( MA,
                          "The ryu SMASHES your weapon with its paw !!!\n" );
                      say( "The ryu SMASHES the weapon of " + MAN + 
                           "...with its paw !!!\n", MAN );
                      destruct( obj );
                   }
                   else {
                      tell_object( MA,
                             "The ryu hits your hand. Because of the pain you"+
                             " cannot hold\n...your weapon and DROP it !!!\n" );
                      transfer( obj, E(MA) );
                   }
                   break;
      case 16..25: return( smash_armour() );
      case 26..40: return( poison_attacker() );
      case 41..50: return( poison_cloud() );
      case 51..60: return( critical_hit() );
      case 61..70: ::attack();
                   return( ::attack() );
                   break;
      default:     return( ::attack() ); 
   }

   return( 1 );
}


smash_armour()
{
   int    i, len;
   string withWhat;
   object *smashedWhat;

   len = 0;
   smashedWhat = 0;

   if( sizeof( MA->query_arm_types() ) )
      len = sizeof( MA->query_arm_types() ); 
   if ( !MA->query_armour() || !sizeof(MA->query_armour()) || !len )
      return( ::attack() );

   for ( i = 0; i < len; i++ ) {
      if ( (MA->query_armour())[i] && 
           (MA->query_armour())[i]->query_type() != "guild" ) 
      {
         smashedWhat = (MA->query_armour())[i];
         break;
      }
   }

   if ( !smashedWhat && MA->query_others() ) {
      for ( i = 0; i < sizeof( MA->query_others() ); i++ ) { 
         if ( (MA->query_others())[i] &&
              (MA->query_others())[i]->query_type() != "guild" ) 
         {
            smashedWhat = (MA->query_others())[i];
            break;
         }
      }
   }

   if ( !smashedWhat && MA->query_rings() ) {
      for ( i = 0; i < sizeof( MA->query_rings() ); i++ ) { 
         if ( (MA->query_rings())[i] &&
              (MA->query_rings())[i]->query_type() != "guild" )
         {
            smashedWhat = (MA->query_rings())[i];
            break;
         }
      }
   }

   if ( smashedWhat ) {
      withWhat = get_withWhat();
      tell_object( MA, "The ryu aims for your " + smashedWhat->query_name() +
                   " with its " + withWhat + "\n...and SMASHES it into small " +
                   "fragments !!!\n" ); 
      say( "The ryu aims for the " + smashedWhat->query_name() + " of " +
           MAN + "\n...and smashes it into small fragments !!!\n",
           MA );
      destruct( smashedWhat );
   }

   return( 1 );
}

poison_attacker()
{
   tell_object( MA, "You see the nose of the ryu enlarge. Suddenly green " +
                    "steam shots\n...out of it, right into your face.\n" +
                    "...SHIT, that was POISON !!!\n" );
   say( "You see the nose of the ryu enlarge. Suddenly green steam shots\n" +
        "...out of it, right at " + MAN + " !!!\n", MA );

   MA->add_poison( random(20)+10 );

   return( 1 );
}

poison_cloud()
{
   object *cloud;

   cloud = present( "poison_cloud", E(TO) );
   if ( !cloud ) {
      cloud = clone_object( "/players/patience/eastMonst/poison_cloud" );
      move_object( cloud, E(TO) );

      say( "The ryu blows a POISON-CLOUD at you !!!\n" );
   }

   cloud->add_poison( random( 60 ) + 60 );

   return( 1 );
}

critical_hit()
{
   string withWhat, toWhere, ext;
   int    dam;

   withWhat = get_withWhat();

   tell_object( MA, "The ryu hits you with its " + withWhat + " CRITICALLY " +
                "at your head !!!\n" );
   say( "The ryu hits " + MAN + " with its " + withWhat + "\n...CRITICALLY " +
        "at " + MA->query_pronoun() + " head !!!\n", MA );

   dam = 100 + random( 100 );
   if ( dam > MA->query_hp()-20 )
      dam = MA->query_hp()-5;

   MA->hit_player( dam );

   if ( !living( MA ) || MA->query_ghost() )
      return( 0 );

   if ( random( 100 ) < 30 ) {
      tell_object( MA, "...Because of the power of the hit, you are thrown "+
                   "out of here !!!\n" );
      say( "..."+MAN+" is thrown out of the here !!!\n", MA );

/*    ext = (random(15)+1);  */
/*     toWhere = ENV_PATH + "c"+ext;  */
/*       while ( toWhere == file_name( E(TO) ) && ext != "7" ) {         */
/*        ext = (random(15)+1);              */
/*       toWhere = ENV_PATH + "c"+(random(15)+1);     */
/*        }  */
          toWhere = "/room/church";
      MA->move_player( "flies away !!!#"+toWhere );
      tell_object( MA,"Suddenly, a solid wall stops your flight!   OUCH !!!\n");
      return( 0 );
   }

   return( 1 );
}

get_withWhat()
{
   switch( random( 4 ) ) {
      case 0: return( "left paw" );
      case 1: return( "right paw" );
      case 2: return( "tail" );
      default: return( "head" );
   }
}

get_it( arg )
{
   write( "The ryu hinders you from getting it !!!\n" );
   return( 1 );
}

poison_immune()
{
   return( 1 );
}

block( arg )
{
   object *obj;

   if ( query_verb() == "assassinate" && query_verb() == "backstab" ) {
      if ( arg == "ryu" ) {
         write( "The ryu laughs at your foolish attempt !!!\n" );
         TO->attack_object( TP );
         if ( TP->query_invis() )
            TP->set_vis();
         return( 1 );
      }
   }
   else if ( query_verb() == "stinger" ) {
      obj = present( "fang", TP );
      if ( obj ) {
         write( "The ryu tears the fang out of your hand and\n" +
                "...STINGERS you with it !!!\n" );
         say( "The ryu tears the fang out of " + TPN + " and\n...stingers " +
              TPN + " with it !!!\n", TP );
         move_object( obj, TO );
         command( "stinger " + TP->query_real_name() );
      }
      return( 1 );
   }
   else if ( query_verb() == "throw" &&
             (arg == "dart at ryu" || arg == "poison dart at ryu" ||
             arg == "poison-dart at ryu") )
   {
      obj = present( "dart", TP );
      if ( !obj )
         return; 
      obj->add_dart_poison( -1000 );
      return( 0 );
   }
}






monster_died(ob){
destruct(ob);
if(this_player()->query_immortal()) return;
shout(this_player()->query_name()+" had killed the Great Dragon Ryu.\n");
if(present("ninja", this_player())) return;
bad = clone_object("players/akira/ninja");
transfer(bad, this_player());
write("A Ninja-To of Hellish Poison appears in your hand!\n");
return 1;
}
