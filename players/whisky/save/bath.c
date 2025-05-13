#define PPATH "/players/patience/smilequest/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

int costumeIsHere, chestMoved, chestClosed, chestLocked, keyIsHere, clothesHere;
int drinkCount;

reset( arg )
{
   costumeIsHere = 1, chestMoved = 0; chestClosed = 1; chestLocked = 1;
   keyIsHere = 1, clothesHere = 1, drinkCount = 10;

   if ( arg )
      return;
  
   set_light(1);
   short_desc = "In the bathroom";
   long_desc = "Your are in the bathroom of the castle of sadness.\n" +
               "The bathroom also had not been used for a long time and there is\n" +
               "a lot of dust in here too. On the wall is a large, wooden shelf and\n" +
               "to your right stands an old, @@chk_chest@@ iron chest. There is also\n" +
               "a rusty bathtub here. To the north can you see the kitchen.\n";
   
   items = ({ "ground","It is a wooden floor",
              "floor","It is a wooden floor",
              "door","You can't see a door here",
              "walls","They are made of massive stone",
              "wall","They are made of massive stone",
              "dust","You see dust. Dust, and nothing else than dust",
              "shelf","Except of large heaps of dust the shelf is empty",
              "chest","The chest is made of massive iron. You can see something written on it.\n" +
                      "It is @@chk_chest@@ @@inv_chest@@",
              "lock","It is an iron lock",
              "keyhole","It is an iron keyhole",
              "clothes","@@l_clothes@@",
              "bathtub","It is an old, rusty bathtub. @@chk_water@@",
              "tub","@@chk_water@@",
              "water","@@l_water@@",
           });
   
   dest_dir = ({ PPATH + "kitchen", "north",
              });
}


init( )
{
   ::init( );
   add_action("search","search");
   add_action("push","move" );
   add_action("push","push" );
   add_action("destroy","break" );
   add_action("destroy","destroy" );
   add_action("destroy","smash" );
   add_action("get_it","get" );
   add_action("get_it","take" );
   add_action("get_it","pick" );
   add_action("read_it","read" );
   add_action("drink","drink" );
   add_action("enter","enter" );

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
   if ( str == "table" || str == "shelf" ) {      
      write( "You are much too weak to destroy the " + str + ".\n" );
      return( 1 );
   }

   return( 0 );      
}

push( str )
{
   object costu;

   if ( !str )
      return;
      
   if ( str == "chest" ) {
      write( "With great effort you manage to move the chest.\n" );
      say( TPN + " moved the chest.\n" );
      chestMoved = 1;
      if ( costumeIsHere ) {
         write( "You find a clown costume.\n" );
         costu = clone_object(PPATH + "cloak");
         if (transfer(costu,this_player())) {
            write( "But you can't carry that much and so you drop it again.\n" );
            destruct( costu );
            return( 1 );
         }
         costumeIsHere = 0;
         return( 1 );
      }

      return( 1 );
   }

   return( 0 );      
}

search( arg )
{
   if ( !arg )
      return;
      
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
}

get_it( str )
{
   object key;

   if ( !str )
      return;
      
   if ( str == "dust" ) {
      write( "You try to get some " + str + ", but it slips through your fingers.\n" );
      say( TPN + " tries to get some " + str + ".\n" );
      return( 1 );
   }
   else if ( str == "clothes" || str == "clothes from chest" || str == "all from chest" ) {
      if ( clothesHere && !chestClosed ) {
         write( "As you try to get the rotten clothes, they crumble to dust.\n" );
         clothesHere = 0;
      }
      else
         write( "What ?\n" );
      return( 1 );
   }
   else if ( str == "key" || str == "iron key" ) {
      if ( keyIsHere ) {
         write( "You get the key.\n" );
         key = clone_object(PPATH + "ironkey");
         if (transfer(key,this_player())) {
            write( "But you can't carry that much and so you drop it again.\n" );
            destruct( key );
            return( 1 );
         }
         keyIsHere = 0;
         return( 1 );
      }
   }

   return( 0 );
}

read_it( str )
{
   if ( !str )
      return;
      
   if ( str == "chest" || str == "writing" ) {
      write( "Dirty clothes only!\n" );
      return( 1 );
   }
   return( 0 );   
}

drink( arg )
{
   if (!arg)
      return;
      
   if (arg=="water" || arg=="from bathtub" || arg=="some water" || arg=="tub") {
      if ( drinkCount > 0 ) {
         write("You drink some dirty water.\n");
         say(this_player()->query_name()+" drinks dirty water from the bathtub.\n");
         this_player()->drink_soft(1);
         drinkCount--;
      }
      else
         write( "But the bathtub is empty!\n" );
   }
  
   return 1;
}    

enter( str )
{
   if ( !str )
      return;
   
   if ( str == "tub" || str == "bathtub" ) {
      if ( drinkCount > 0 )
         write( "As you look at the dirty water, you decide better not to take a bath.\n" );
      else
         write( "Completely senseless to take a bath in an empty bathtub, isn-t it?\n" );
         
      return( 1 );
   }

   return( 0 );
}

chk_chest( )
{
   if ( chestClosed )
      return( "closed" );
   else
      return( "open" );
}

inv_chest( )
{
   if ( chestClosed )
      return( "now" );
   else {
      if ( clothesHere )
         return( "and in the chest are some clothes" );
      else
         return( "and the chest is empty" );
   }
}

l_clothes( )
{
   if ( clothesHere && !chestClosed )
      return( "Some very old and nearly rotten clothes" );

   return( "There are no clothes here" );
}

chk_water( )
{
   if ( drinkCount >= 10 )
      return( "It is full with water" );
   else if ( drinkCount > 7 )
      return( "It is almost full with water" );
   else if ( drinkCount > 3 )
      return( "It is half full with water" );
   else if ( drinkCount > 0 )
      return( "There is some water in it" );
   else {
      if ( keyIsHere )
         return( "You can see an iron key in it" );
      else
         return( "It is empty" );
   }
}

l_water( )
{
   if ( drinkCount > 0 )
      return( "The water is really dirty. But maybe you can drink it" );
   else
      return( "You can see an iron key." );
}

/* ----- door functions ------------------------------------------------------ */

picklock(str) {
  if ((str=="chest" || str == "iron chest") && present("picklock",TP)) {
     write("You can't open this chest by stupidly using a picklock ...\n");
     say(TPN+" the thief tries to use "+TPPOS+" picklock on the chest.\n" +
     capitalize(TPOBJ)+" fails completely ...\n");
     return 1;
  }

   return( 0 );
}

knock(str) {
   string msg;

  if (str=="chest" || str == "iron chest" ) {
     write( "You knock at door, but there is nobody in, that could answer.\n" );
     say(TPN+" knocks at the chest." );
     return 1;
  }

   return( 0 );
}

close(str) {
   if ( !str )
      return;
   if ( str == "chest" || str == "iron chest" ) {
      if (chestClosed) {
         write("The chest is aready closed!\n");
      }
      else {
         write("You close the chest.\n");
         say(TPN+" closes the chest.\n");
         chestClosed = 1;
      }

      return( 1 );
   }
}
     
open (str) {
  if ( !str )
     return;
     
  if ( str == "chest" || str == "iron chest" ) {
     if ( chestLocked ) {
        write("You can't open the chest, it is locked.\n");
        say(TPN+" tries to open the chest but fails.\n");
     }
     else if ( chestClosed ) {
        write( "You opened the chest.\n" );
        say(TPN+" opened the chest.\n" );
        chestClosed = 0;
     }
     else {
        write( "But it's already open!\n" );
     }
  
     return 1;
  }

  return( 0 );
}

unlock(str) {
   string str1;
   
   if (!str)
      return;
   
   if ( str == "chest with iron key" || str == "iron chest with iron key" ) {
      if ( present( "ikey", TP ) ) {
         if ( chestLocked ) {
            write("You unlock the chest.\n");
            say(TPN+" unlocks the chest.\n");
            chestLocked = 0;
         }
         else
            write("But the chest is already unlocked.\n" );
      }
      else
         write( "But you don't have the proper key for the chest!\n" );
        
      return( 1 );
   }
   else if ( str == "chest" || str == "iron chest" ) {
      write( "With what do you want to unlock the iron chest?\n" );
      return( 1 );
   }
   else if ( str == "chest with key" || str == "iron chest with key" ) {
      write( "Which key do you mean?\n" );
      return( 1 );
   }
   else if ( sscanf( str, "chest %s", str1 ) ) {
      write( "You can't unlock the chest with that item.\n" );
      return( 1 );
   }

   return( 0 );
}

lock(str)
{
   string str1;

   if ( !str )
      return;

   if ( str == "chest with iron key" || str == "iron chest with iron key" ) {
      if ( present( "ikey", TP ) ) {
         if ( chestClosed ) {
            if ( !chestLocked ) {
               write("You lock the chest.\n");
               say(TPN+" locks the chest.\n");
               chestLocked = 1;
            }
            else
               write( "But the chest is already locked.\n" );
         }
         else
            write( "You can't lock an open chest.\n" );
      }
      else
         write( "But you don't have the proper key for this chest.\n" );

      return( 1 );
   }
   else if ( str == "chest" || str == "iron chest" ) {
      write( "With what do you want to lock the iron chest?\n" );
      return( 1 );
   }
   else if ( str == "chest with key" || str == "iron chest with key" ) {
      write( "Which key do you mean?\n" );
      return( 1 );
   }
   else if ( sscanf( str, "chest %s", str1 ) ) {
      write( "You can't lock the chest with that item.\n" );
      return( 1 );
   }

   return( 0 );
}
