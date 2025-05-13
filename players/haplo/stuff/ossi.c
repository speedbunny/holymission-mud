inherit "/obj/monster";

#define SR "/tools/exsoul/soulroom"
#define TP (this_player())

int inShell;
object *myself;

reset( arg )
{
   object *soul;

   ::reset( arg );

   if ( arg )
      return;

   inShell = 0;
   myself = this_object();

   set_name( "ossi" );
   set_gender( 1 );

   set_race( "turtle" );
   set_level( 1 );

   msgin = "crawls in";
   msgout = "crawls";

   call_out( "do_feeling", 10 );
   call_out( "move_me", 10 );

   move_object( clone_object( "/tools/exsoul/exsoul" ), this_object() );
   command( "hide exsoul" );
}

init()
{
   object *sheep;

   add_action( "do_pet", "pet" );

   sheep = present( "sheep", environment( this_object() ) );
   if ( sheep ) {
      tell_room( environment( this_object() ),
            "As Ossi sees Daisy, he suddenly mutates into a TEENAGE-"+
            "MUTANT-HERO-TURTLE !!!\n" +
            "He draws his katana and BEHEADS Daisy !!!!!\n" +
            "After this, he turns back normal into a neat cuddling pet.\n" );
       sheep->hit_player( 100000 ); 
   }
            
}

long( )
{
   if ( inShell )
      write( "This is the shell of Ossi, Patience's pet.\n" );
   else
      write( "This is Ossi, Patience's pet.\n" +
             "Ossi is a red-cheeck swamp-turtle.\n" );
}

short( )
{
   if ( inShell )
      return( "A shell of a turtle" );
   else
      return( "Ossi" );
}

get( )
{
   write( "You try to get Ossi, but he snaps at you !!!\n" +
          "You think, that he will only allow Patience to get him.\n" );

   ::get();
}

do_pet( arg )
{
   if ( id( arg ) ) {
      if ( inShell ) {
         write( "Ossi is in his shell, you cannot pet him.\n" );
         return( 1 );
      }
      command( "giggle" );
      command( "smile" );
      write( "Yeah, Ossi likes that !\n" );
      say( TP->query_name() + " pets Ossi. Ossi likes this !\n", TP );
      return( 1 );
   }
}

move_me()
{
   string *dirs;
   int    c, i;

   if ( inShell )
      return;

   dirs = environment(this_object())->query_dest_dir();

   if ( !dirs && !sizeof(dirs) )
      return;

   c = 3;
   i = random(sizeof(dirs)/2)*2;
   while( c-->0 && dirs[i] )
      i = random(sizeof(dirs)/2)*2;

   if ( dirs[i] )
      this_object()->move_player( dirs[i+1]+"#"+dirs[i] );

   return;
}

do_feeling( )
{
   int    ret;
   string comm;
   object *ppl;

   if ( inShell ) {
      call_out( "come_out", 60 + random( 60 ) );
      return;
   }

   comm = SR->query_commands()[random(sizeof(SR->query_commands()))];
   ppl = get_ppl();
   if ( ppl ) { 
      if ( command( comm + " " + ppl->query_real_name() ) ) {
         call_out( "do_feeling", 10 );
         return;
      }
   } 

   command( comm );
   call_out( "do_feeling", 10 );
}

come_out()
{
   say( "Ossi lookes out of his shell.\n" );
   inShell = 0;
   call_out( "do_feeling", 20 );
}

get_ppl( )
{
   int   i;
   object *inv;

   inv = all_inventory( environment( this_object() ) );
   for ( i = 0; i < sizeof( inv ); i++ )
      if ( living(inv[i]) && interactive(inv[i]) && !(inv[i]->query_invis()) )
         return( inv[i] );

   return( 0 );
}

hit_player( dam, kind )
{
   if ( dam > 1000 )
      return( ::hit_player( dam, kind ) );

   if ( inShell ) {
      write( "Ossi is in his shell, you cannot hurt him, dude !\n" );
      say( TP->query_name() + " tries to hit Ossi's shell, without effect.\n",
           TP );
      return( 0 );
   }

   write( "You try to hit Ossi, but he quickly leaves into his shell!!!\n" );
   say( TP->query_name() + " tries to hit Ossi,\n"+
        "but Ossi quickly leaves into his shell !!!\n", TP );

   inShell = 1;

   return( 0 );
}
/*
attack( )
{
   write( "You trie to hit Ossi, but he quickly leaves into his shell!!!\n" );
   say( TP->query_name() + " tries to hit Ossi,\n"+
        "but Ossi quickly leaves into his shell !!!\n", TP );

   inShell = 1;

   myself->stop_fight();
   myself->stop_fight();
   if ( myself->query_attack() ) {
      (myself->query_attack())->stop_fight();
   }

   return( 0 );
}*/
