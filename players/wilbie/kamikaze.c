#include "/players/tatsuo/guild/ndef.h"
#include "/players/tatsuo/guild/nmess.h"
main(arg) {
    object target;
    string target_name;
    int dam_enemy, dam_ninja, life_death;

if((this_player()->query_level()) < 29){
return printf("You are much too inexperienced for such an attack!\n"),1;
   }


if(!arg){
        if(!(this_player()->query_attack()) || !(living((this_player()->query_attack()))) ) {
        write("Kamikaze target??\n");
        return( 1 );
             }
        }


target = (this_player()->query_attack());
dam_enemy =(this_player()->query_dex() +
            this_player()->query_wis() +
            this_player()->query_str())*
            random(25));

life_death = random(2);
    switch(life_death){
          case 0:
                 dam_ninja = (this_player()->query_max_hp()) - random(10);
          break;

          default:
                 dam_ninja = (this_player()query_max_hp()) + random(10);
          break;
          }

target->hit_player(dam_enemy,5);
this_player()->hit_player(dam_ninja,5);
return 1;
}
