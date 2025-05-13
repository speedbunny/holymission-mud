inherit "/obj/monster";

reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("orc soldier");
    set_alias("orc");
    set_alt_name("soldier");
    set_short("A large orc soldier");
    set_long("A large orc soldier in this damned orc army.\n");
    set_race("orc");
    set_gender(1);
    load_a_chat(10,({"Large orc soldier says: You stupid intruder!\n",
                     "Large orc soldier laughs with a bone-chilling sound.\n",
                     "Large orc soldier sings: 'I am the strongest in my rank'\n",}));
    set_level(15);
    set_hp(900);
    set_al(-500);
    set_ep(6000);
    set_wc(20);
    set_ac(10);
    set_aggressive(1);
    set_move_at_reset(0);
    add_money(1000+random(1000));
    set_whimpy(-1);
  }
}


attack() {
  object victim;

  if  (::attack()) {

     victim=this_object()->query_attack();
     if (random(100) < 50 )
       { victim->hit_player(random(40));
         message(victim);
             }
     else {
         victim->hit_player(random(20));
         message(victim);
             }
     return 1;
   } /*end of if*/
 return 0;
}



message(victim) {  /* here we call the spell_message */
string attacker_name;

   attacker_name = victim->query_name();
      if (random(10)<5) {
          tell_object(victim,"Large orc soldier smacked you on the floor.\n");
          say("Large orc solder smacked "+attacker_name+" on the floor.\n",victim);
        }
        else  {
          tell_object(victim,"Large orc soldier punched you in the face!\n");
          say("Large orc soldier punched "+attacker_name+" in the face.\n",victim);
         }
 return 1;
}

