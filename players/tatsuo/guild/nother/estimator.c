inherit "obj/treasure";

#define TP    (this_player())

reset( arg )
{
   if ( arg )
      return;

   set_weight( 0 );
   set_name( "estimator" );
}

init( )
{
   add_action( "est_nothing", "", 1 );
   add_action( "_estimate", "estimate"  );
   add_action( "_wakeup", "wakeup" );
}

est_nothing( arg )
{
   write( "You only can estimate kis or weapons in your meditation state.\n" +
          "If you want to stop, type \"wakeup\".\n" );

   return( 1 );
}

_estimate( arg )
{
   object *nsoul, *weap;
   int    actSkill, maxSkill, raise_block;
   string str;
    
   nsoul = present( "ninja_soul", this_player() );
   if ( !nsoul ) {
      write( "Sorry, but only ninjas can estimate their abilities here.\n" );
      return( 1 );
   }

   weap = present( arg, this_player() );

   switch( arg ) {
      case "bo-staff": case "staff": case "yari": case "naginata":
      case "bisento": case "kama": case "nunchaku":
      case "sa-tja-koen": case "sai": case "shuto": case "daito":
/* Sauron - included new ninja weapons and changed the names for
            the Wakizashi -> Shuto and Katana -> Daito so that players
            can estimate them again. */
         weap = present( arg, this_player() );
         if ( !weap ) {
            write("Susano-O growls at you:\n"+
                  "You don't have this weapon, mortal!\n");
            return( 1 ); 
         }
         raise_block = weap->query_raise_block();

         write( "Susano-O suggerates you:\n" +
                capitalize(get_hint(raise_block - nsoul->query_acc_skill()))+
                " in Kenjutsu and\n" +
                get_hint( raise_block - nsoul->query_thc_skill() ) +
                " in Ni-To-Kenjutsu, mortal !\n" );
         return( 1 );
   }

   if ( arg == "throwing" || arg == "throwing-ki" ) {
      actSkill = nsoul->query_throw_skill();
      maxSkill = nsoul->query_max_throw_skill(); 
   }
   else if ( arg == "karate" || arg == "karate-ki" ) {
      actSkill = nsoul->query_karate_skill();
      maxSkill = nsoul->query_max_karate_skill();
   }
   else if ( arg == "yadomejutsu" || arg == "yadomejutsu-ki" ) {
      actSkill = nsoul->query_parry_skill();
      maxSkill = nsoul->query_max_parry_skill();
   }
   else if ( arg == "kenjutsu" || arg == "kenjutsu-ki" ) {
      actSkill = nsoul->query_acc_skill();
      maxSkill = nsoul->query_max_acc_skill();
   }
   else if ( arg == "ni-to-kenjutsu" || arg == "ni-to-kenjutsu-ki" ) {
      actSkill = nsoul->query_thc_skill();
      maxSkill = nsoul->query_max_thc_skill();
   }
   else if ( arg == "camouflage" || arg == "camouflage-ki" ) {
      actSkill = nsoul->query_camou_skill();
      maxSkill = nsoul->query_max_camou_skill();
   }
   else if ( arg == "assassination" || arg == "assassination-ki" ) {
      actSkill = nsoul->query_assass_skill();
      maxSkill = nsoul->query_max_assass_skill();
   }
   else {
      write( "Susano-O suggerates you: This is not a ninja-ki "+
             "or ninja-weapon, mortal!\n" );
      return( 1 );
   }

   write("Susano-O suggerates you:\n"+capitalize(get_hint(maxSkill-actSkill))
          +", mortal !\n" );

   return( 1 );
}

get_hint( diff )
{
   string str;

   if ( diff < 0 ) diff = 0;

   switch( diff ) {
      case 0:      str = "you have exhausted your learning-range";
                   break;
      case 1..2:   str = "you have almost exhausted your learning-range";
                   break;
      case 3..4:   str = "you are very close to exhaust your learning-range";
                   break;
      case 5..7:   str = "you are close to exhaust your learning-range";
                   break;
      case 8..10:  str = "you are beginning to exhaust your learning-range";
                   break;
      case 11..15: str = "you are far from exhausting your learning-range";
                   break;
      default:     str = "you are very far from exhausting your lerning-"+
                         "range";
   }

   return( str );
}

_wakeup( arg )
{
   write( "You turn back into your physical state.\n" );

   destruct( this_object() );
   return( 1 );
}
