inherit "/spells/spell";
#include "/spells/spell.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Discord");
    set_syntax("cast 'discord' [opponent]");
    set_kind( AGGRESSIVE );
    set_save_vs( MINDEFFECTIVE );
    set_save_vs_info( "to negate" );
    set_cost( 50 );
    set_speed( NEXT_HB );
    set_guild_allowed( 4, 10 );
    set_player_help(
        "Using the Power of the Force, you can make a living object\n" +
        "in a room panic and start attacking another living object.\n");
}

void release_spell(string arg, int act_skill, int max_skill) {

    object  att, *inv;
    int     i, l, d, m, g, dam, count;
    string  att_name, tp_name;

/*
    att = check_target(arg);
    if(!att) return;
    if(valid_living(att)) return;
*/

    d = TP->query_level();

    if(check_success(act_skill,max_skill)) {
      printf("You begin to sow the seeds of discord.\n");
      inv = all_inventory(environment(TP));
      l = 0;
      m = sizeof(inv);
      tp_name = TPN;
      for( i=0; i<m; i++) {
        att = inv[i];
        if (!valid_living(att) || att == TP) continue;
        switch(att->do_save(Skind,Ssave,0,0,this_object())) {
            case IMMUNE:        dam = 0; break;
            case SAVED:         dam = 1; break;
            default:            dam = 1;
        }
        if (dam) {
          att_name = att->query_name();
          tell_object(att,TPN+" shows you your worst nightmares, causing\n" +
                      "you to panic... you start to feel hatred toward\n" +
                      "everyone in the room...\n");
          while(l!=m) {
              g = random(m);
              if(living(inv[g]) && (inv[g] != TP)
                      && (inv[g]!=att)
                      && (inv[g]->query_invis() < inv[g]->query_level())) {
                  att->attack_object(inv[g]);
                  count += 1;
                  l = m;
              }
          }
          l = 0;
        }
         else  {
            write("You were unable to effect "+att_name+".\n");
         }
      }
    }
    else  {
       write("No one seems to be effected.\n");
    }
}

