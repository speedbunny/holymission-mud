// sneeze..... HAPTSCHI !!
// make s.b. sneeze during combat and miss his/her/its attacks
// id: if i would know
// attr-msg: none
// shadows the attack
// non multiple

int old_dex;

inherit "/obj/std_shadow";
start_shadow(who, time)
{
    old_dex = who->query_dex();
    who->set_dex( old_dex / 2 );
    return ::start_shadow(who, time, "sneeze",0);
}

end_shadow(o)
{
    tell_object(me, "Your TEARS finally washed away the PEPPER !\n");
    me->set_dex( old_dex );
    ::end_shadow(o);
}

varargs int attack( object arg )
{
   int    rnd, dam;
   object attacker;
   string shadow_func;
    
   rnd = random(10);

   // ----- BIG sneeze ------
   switch( rnd ) {
      case 3..4:
      write("You abort your hit, because you have the urgent to sneeze ....\n"+
            "..... HAPTSCHI !!!\n" );
      say( this_player()->query_name()+" sneezes loudly ..... HAPTSCHI !!!\n");
      break;

      case 1..2:
       write( "Your eyes fill with TEARS ... you cannot see your opponent !\n");
       say( this_player()->query_name()+"'s eyes fill with TEARS, hinders "+
            this_player()->query_pronoun()+" to attack !\n" );
       break;

      case 0:
       write( "You sneeze and FUMBLE, hitting yourself hard !!!\n" );
       say( this_player()->query_name() + " sneezes and FUMBLES, hitting "+
            this_player()->query_objective() + "self hard !\n" );
       attacker = this_player()->query_attack();
       dam = random(20)+10;
       dam = dam > me->query_hp() ? me->query_hp()-1 : dam;
       dam = me->hit_player( dam );
       attacker->add_exp( dam );
       break;

      default:
       return( apply( call, me, "attack", arg ) );
   }

   return( 1 );
}
