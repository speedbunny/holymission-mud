inherit "/obj/monster";

#define PPATH ("/players/patience/eastMonst/")

int emb;

reset(arg)
{
   emb = 0;
   set_alt_name( "" );
   
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "statue" );
   set_alias( "shishi" );
   set_level( random(10) + 20 );
   set_size( 2 );
   set_short( "A statue of a sukuto" );
long_desc = "This guardian statue is a small fire serpent that makes its home\n"+
	"in pools of lava.\n";
}

init( )
{
   if ( environment( this_object() ) && environment( this_object() ) != this_object() &&
        this_object() != this_player() )
   {
      if ( present( "alarm_ten", this_player() ) ) {
         if ( present( this_player(), environment( this_object() ) ) ) {
            if ( !emb ) {
               emb = 1;
               tell_room( environment( this_object() ),
                          "Suddenly the statue awakes to live !!!\n" );
            }
            this_object()->attack_object( this_player() );
         }
      }
   }
}

short( )
{
   if ( environment( this_object() ) && environment( this_object() ) != this_object() &&
        this_object() != this_player() )
   {
      if ( present( "alarm_ten", this_player() ) ) {
         if ( present( this_player(), environment( this_object() ) ) ) {
            if ( !emb ) {
               emb = 1;
               tell_room( environment( this_object() ),
                          "Suddenly the statue awakes to live !!!\n" );
            }
            this_object()->attack_object( this_player() );
         }
      }
   }
   
   return( ::short() );
}

long( )
{
   ::long();
   if ( emb )
      write( "This statue is embodied by a ten. A ten is a buddhistic spirit,\n" +
             "a guardian of the faith, its believers, and its temples.\n" );
}

attack()
{
   int attRet;
   
   attRet = (::attack());

   if ( attRet ) {
      set_alt_name( "ten" );
      emb = 1;
   }
   
   return( attRet );
}
