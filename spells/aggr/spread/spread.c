inherit "/spells/spell";
#include "/spells/spell.h"

void reset(int arg)  {

   ::reset(arg);
   if(arg) return;
   set_name("Spread Lightning");
   set_syntax("cast 'spread'");
   set_kind( AGGRESSIVE );
   set_save_vs( ELECTRICITY );
   set_save_vs_info( "for three-quarter damage" );
   set_damage_info( "LVLd5 + 10");
   set_cost( 50 );
   set_speed( 4 );
   set_guild_allowed( 4, 10 );
   set_player_help(
                   "Same as lightning bolt, but the bolt of lightning spreads out,\n" +
                   "damaging everything in the area.\n");
}

void release_spell(string arg, int act_skill, int max_skill)  {

   object  att, *inv;
   int     d,i,m,dam;
   string  tp_name;

   d = TP->query_level();

   if(check_success(act_skill,max_skill))  {
      inv = all_inventory(environment(TP));
      m = sizeof(inv);
      tp_name  = TPN;
      say(tp_name+" stretches out hands that release a stream of lightning\n"+
          "striking the area.\n",TP);
      printf("You stretch forth your hands and release an energy bolt.\n");
      for( i=0; i<m; i++)   {
         att = inv[i];
         if (!valid_living(att)
             || att==TP
             || att->query_guild() == 4) continue;

         switch(att->do_save(Skind,Ssave,0,0,this_object()))  {
          case IMMUNE:        dam = 0; break;
          case SAVED:         dam = (roll_dice(d,5,0)/2) + 5; break;
          case SAVE_FAILED:   dam = (roll_dice(d,5,0)) + 10; break;
          default:            dam = 40;
         }
         tell_object(att,"You are hit by a stream of lightning from " +
                     tp_name+".\n");
         att->hit_by_spell(dam);
      }
   }
}

