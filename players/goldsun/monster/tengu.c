inherit "/obj/monster";
#define TO this_object()

object att;

void reset(int arg)
 {
  ::reset(arg);
if (arg) return;
 set_name("tengu");
 set_alias("dragon");
 set_race("ffdragon");   /* ff=fire flying*/
 set_short("Huge fire dragon Tengu");
 set_long("You see huge flying fire dragon. He is very angry.\n "
         +"Don't desturb him. He can burn you to small heap of ash.\n");
 set_aggressive(0);
 set_level(99);
 set_wc(89);
 set_ac(40);
 set_size(7);
 set_spell_mess1("Tengu raises his WINGS and make terrible storm\n");
 set_spell_mess2("Tengu cast a HUGE FIRE\n");
 set_spell_dam(160);
 set_chance(18);
 move_object(clone_object("players/goldsun/obj/nothungb"),this_object());
 add_money(5000);
}  

heart_beat(){
  ::heart_beat();
 if (TO->query_attack()){
    att=TO->query_attack();
    if (att->query_hp()>10000){ att->hit_player(3300,5);
      tell_room(environment(TO),"Tengu snatch "+att_query_name()+".\n");
      }
    if (TO->query_hp()<5000){
       tell_room(environment(TO),"Fire Dragon flies up to the ski and casts"+
		" fire at "+att-query_name()+" !!!\n");
          att-->hit_player(att->query_hp(),5);
    }
    
 }
 return 1;
}   

init(){
 ::init();
 add_action("fcn_kill","fire");
 }


query_value(){ return 450; }

get(){ return 1; }
int fcn_kill(string whom){

 object mob;

 if (stringp(whom))
  mob=present(whom,environment());
   else{ write("Tengu screams.\n"); return 1;}

  if (mob && living(mob)  && present("goldsun_whistle",this_player()) ){
  attack_object(mob);
  change_attacker(mob);
  return 1;

 }
}
