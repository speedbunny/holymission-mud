inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset(tick);
   if ( tick ) return;

   set_name( "enchant mace" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'enchant mace' [target]" );
   set_save_vs( NO_SAVE );
   set_guild_allowed(2,2);
   set_cost( 65 );
   set_duration_info( "permanent" );
   set_speed( 2 );
   set_player_help(
	"This spell enchants blunt-weapon with a powerful magic\n"+
	"that increases the damage.\n"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, shad;
   string oppo_name, tp_name;
   int    do_it;

	if(!oppo=present(arg,TP))
	{
		write("You don't have that weapon.\n");
		return;
	}

   if ( check_success( act_skill, max_skill ) ) {
         do_it = 1;
      }

	 oppo_name = oppo->query_name();
      tp_name = apply( call, TP, "query_name" );

      if ( do_it ) 
	{
/*
 Anm: das object heisst shad, weil ich zu faul war die
      Variablen-liste oben unzuaendern das ist nunmal KEIN
      shadow!!! ok, und dass ich dich bereits um eine
      Funktion angesudert habe damit ich die hit_func in weapon
      afragen kann. Tja im moment ist es nicht moeglich das
      damage-object zu destructen da ich nicht wissen kann
      ob es vorhanden ist :-((
*/
		if(oppo->query_weapon_type() == 1)
		{
			shad = clone_object("/spells/no_combat/enchant_weapon/damage");
			move_object(shad,TP);
			shad->set_value(TP->query_level()/3+10);
			oppo->set_hit_func(shad);
			oppo->set_short(oppo->short()+" (green)");
			write("Your "+oppo_name+" starts glowing green.\n");
		}
		else
		{
			write("You can't enchant a "+oppo_name+"\n");
		}
	}
      else {
         write(capitalize(oppo_name)+" seems to be uneffected by the spell.\n");
         tell_object( oppo,"You feel uneffected\n" );
      }         
}
