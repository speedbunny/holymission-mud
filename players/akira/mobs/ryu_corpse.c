inherit "/obj/corpse";

#define TP   (this_player())

int isBeheaded;

reset( arg )
{
   ::reset( arg );

   if ( !arg )
      isBeheaded = 0;
}

init()
{
   ::init();

   add_action( "do_behead", "behead" );
}

do_behead( arg )
{
   int i, ok;
   object *inv, *head;

   ok = -1;

   if ( arg == "ryu" || id( arg ) ) {
      if ( isBeheaded ) {
         write( "The corpse is already beheaded !!!\n" );
         return( 1 );
      }

      if ( decay < 2 ) {
         write( "Sorry, but the corpse is already too rotten to behead it!\n");
         return( 1 );
      }

      inv = all_inventory( TP );
      for ( i = 0; i < sizeof( inv ); i++ ) {
         if ( inv[i]->query_weapon() ) {
            ok = i;
            break;
         }
      }

      if ( ok > -1 ) {
         write("You behead the corpse with your "+inv[ok]->query_name()+".\n"); 
         say( TP->query_name() + " beheads the corpse with " + 
              TP->query_possessive() + " " + inv[ok]->query_name() + ".\n" );
         head = clone_object("/players/patience/eastMonst/ryu_head" );
         move_object( head, environment( this_object() ) );
         head->set_owner( TP );
if(!TP->query_immortal())
         isBeheaded = 1;
      }
      else
         write( "You cannot behead the corpse, you don't have a weapon!!!\n" );
   
      return( 1 );
   }
}

decay()
{
   ::decay();

   if ( decay == 1 ) {
      move_object( clone_object("/players/patience/ezo/ryuworld/bone_key"),
                   this_object() );
   }   
}
