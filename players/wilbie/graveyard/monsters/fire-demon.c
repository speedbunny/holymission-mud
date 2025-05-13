inherit "obj/monster";
    object hammer;
    object armor;
#include "/players/wilbie/def.h"
object hammer;
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("flaming spirit");
   set_alias("demon");
   set_alt_name("flaming");
   set_level(30);
   set_al(-999);
   set_gender(2);
   add_money(2000);
   set_race("demon");
   set_short("The Elder Priestess");
   set_long("This flaming spirit seeks to wreck havok to all living things. "+
            "It crackles with glee as it eyes you with hunger!\n");
   set_wc(4);
   set_ac(4);
   set_size(3);
   set_aggressive(0);
   return;
}

   int hitter(){

   int i,j,k,dam;
   string str;
   object *ob;

   ob = all_inventory(ENV(TO));
   j = random(3);
   while (!j){
     i = random(sizeof(ob));
     if(living(ob[i]) && ob[i] != TO &&
        !ob[i]->query_npc()) {
   j-=1;
   k=random(8);
   switch(k) {
       case 0:  str = "a wave of fire at you!\n";
                dam = 50;
                break;
       case 1:  str = "a spear of pure ice into your chest!\n";
                dam = 60;
                break;
       case 2:  str = "a spear of ice against your skull... You are dazed!\n";
                dam = 10;
                ob[i]->hold(TO,2);
                break;
       case 3:  str = "a phantasm of fear into your soul!!\n";
                dam = 0;
                ob[i]->run_away();
                break;
       case 4:  str = "a flame at you...\n";
                dam = 10;
                break;
       case 5:  str = "phantasmal chain around you...  You can't move!!\n";
                dam = 0;
                ob[i]->hold(TO,2);
                break;
       case 6:  str = "a crushing wave of force to trap you!\n";
                dam = 20;
                ob[i]->hold(TO,4);
                break;
       case 7:  str = "a shard of ice into your flesh...\n";
                dam = 10;
                break;
       default:  str = "arcane words of power in your direction.\n";
                 dam = 0;
       }
       TELL(ob[i], "The demon hurls "+str);
       say("The demon hurls her magicks at "+ob[i]->NAME+"\n",ob[i]);
       ob[i]->hit_player(dam);
       }
       }
       return 1;
       }
  int attack() {
   
    if(::attack()) {
      if(TO->query_attack())
      hitter();
    }
    }
