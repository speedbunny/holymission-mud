
/* last edit 12.04.94 Whisky uni-linz.ac.at: managed now that the weapon can
   be droped, without those autoloadbug, same to katana :*) */

#define TP             (this_player())
#define HIT_FACT       (5)
#define MONST_HIT_FACT (5)
#define NEEDED_EXP_FST (800000)
#define NEEDED_EXP_SEC (1500000)
#define RAISE_BLOCK    (90)

inherit "obj/weapon";

string waki_owner;

#include "/players/patience/guild/nweap/crit_hit.h"
#include "/players/patience/guild/nweap/nweap_mess.h"

string query_auto_load()
{
  if (this_player()->query_guild()==8)
     return( explode( file_name( this_object() ), "#" ) )[0] + ":";
}

reset(arg)
{
   ::reset(arg);
   if (arg)
      return;
      
   if ( this_player() && this_player()->query_real_name() )
      waki_owner = this_player()->query_real_name();

   set_name( "shuto" );
   set_short( "A Shuto" );
   set_long(  "A shuto is a short curved sword. It is a ninja-weapon.\n" +
             "The shuto looks very sharp.\n");
   set_class( 16 );
   set_value( 10000 );
   set_weight( 8 );
   set_info( "ninja_weapon" );
   set_hit_func( this_object() );
}

init()
{
  ::init();
  add_action("do_quit","quit");
}

int do_quit()
{
   if (environment()==this_player())
       call_out("self_destruct",2);
   return 0;
}

int self_destruct()
{
   destruct(this_object());
   return 1;
}

wield(str)
{
   if ( !id(str) )
      return;
      
   if ( waki_owner != this_player()->query_real_name() ) {
      write( "This is not your shuto, you cannot wield it !!!\n" );
      return( 1 );
   }
   
   if ( this_player()->query_ghost() ) {
      write("You fail.\n");
      say(this_player()->query_name()+" failed to wield "+short_desc+".\n");
      return 1;
   }
   
   if (environment() != this_player()) {
      return 0;
   }
  
   if (wielded) {
      write("You already wield it!\n");
      return 1;
   }
   
   if (class_of_weapon>20) log_weapon("wield");
   
#ifdef TEST
   if (wield_conflict()) {            /* e.g try to wield a twohander while */
      write(wield_conflict()+"\n");    /* while wearing a shield             */
      return 1;
   
   }
#endif
  
   if(wield_func)
      if(!wield_func->wield(this_object())) 
         return 1;
  
   if ( this_player()->query_exp() < NEEDED_EXP_FST ) {
      write( "As you try to wield this ninja-weapon, you suddenly feel its enormous power.\n" +
             "So you decide to stop your attempt, because you fear to hurt yourself !!!\n" );
      return( 1 );
   }

   wielded_by = this_player();
   
   if(!this_player()->wield(this_object())) 
      return 1;
   
   wielded = 1;
   write("Ok.\n");
   
   return 1;
}

/* !!!!! THE FOLLOWING FOR NINJAS ONLY !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

/* ---- wielded as second weapon -------------------------------------------- */
wield_second( str )
{
   object ns;
   
   if ( !id(str) )
      return;
      
   if ( waki_owner != this_player()->query_real_name() ) {
      write( "This is not your shuto, you cannot wield it !!!\n" );
      return( 1 );
   }

   if ( this_player()->query_ghost() ) {
      write("You fail.\n");
      say( this_player()->query_name()+" failed to wield "+short_desc+".\n" );
      return( 0 );
   }
   
   if ( environment() != this_player() ) {
       return( 0 );
   }
   
   if ( wielded ) {
      write("You already wield it!\n");
      return( 0 );
   }
   
   if ( wield_second_conflict() ) {          /* e.g try to wield a twohander while */
       write(wield_second_conflict()+"\n");  /* while wearing a shield             */
       return( 0 );
   }

/*   if ( wield_func )
      if(!wield_func->wield(this_object())) 
         return 1;
*/
   if ( this_player()->query_exp() < NEEDED_EXP_SEC ) {
      write( "As you try to wield this ninja-weapon, you suddenly feel its enormous power.\n" +
             "So you decide to stop your attempt, because you fear to hurt yourself !!!\n" );
      return( 1 );
   }

   ns = present( "ninja_soul", this_player() );    /* force to unwield the second */
   if ( ns ) {
      if ( ns->query_secWielded() )
         (ns->query_secWielded())->un_wield();
   }
   
   wielded_by = this_player();
   wielded = 1;
   write("Ok.\n");
   
   return( 1 );
}

wield_second_conflict()
{
   object armours;
   int i,j;

   if ( this_player()->query_weapon() )
      if ( (this_player()->query_weapon())->query_two_handed() )
         return( "You have to remove your twohander first, to wield this weapon." );

   if( two_handed )
      return( "You cannot use a twohander as second weapon." );

   if(environment()->query_armour()[environment()->query_arm_types("shield")])
       return "You have to remove your shield first, to wield this weapon.";
}

drop( silently )
{
   object ns;
   
   if ( wielded ) {
      ns = present( "ninja_soul", wielded_by );
      if ( ns ) {
         if ( ns->query_secWielded() == this_object() ) {         /* as second weap */
            wielded = 0;
            ns->unwield_second( this_object() );
            if ( !silently )
               tell_object( wielded_by, "You drop your second wielded weapon.\n" );
         }
      }
   }

  /* thats not necessary whisky  
   write( "As the shuto leaves your hands, the mighty weapon vanishes.\n");
   destruct( this_object() );
   return( 1 );
   */
   return 0;
}

un_wield()
{
   object ns;
   
   if ( wielded ) {
      wielded = 0;
      ns = present( "ninja_soul", wielded_by );
      if ( ns ) {
         if ( ns->query_secWielded() == this_object() ) {
            ns->unwield_second( this_object() );
         }
      }
   }
   
   return( 1 );
}

short()
{
   object ns;
   
   if ( wielded ) {
      if( short_desc ) {
         ns = present( "ninja_soul", environment() );
         if ( ns )
            if ( ns->query_secWielded() == this_object() )
               return( short_desc + " (second wielded)" );
         
         return( short_desc + " (wielded)" );
      }
   }
   return( short_desc );
}

weapon_hit( arg )
{
   return( critical_hit( arg ) );
}

query_waki_owner()
{
   return( waki_owner );
}

query_raise_block()
{
   return( RAISE_BLOCK );
}
