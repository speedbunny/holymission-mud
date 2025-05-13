inherit "obj/monster";

#define TO     this_object()

reset (arg) {
  ::reset(arg);
  if (!arg) {
    set_name("karbane");
    set_alias("wizard");
    set_race("kobold");
    set_size(2);
    set_level(15);
    set_short("Karbane, the destructive");
    set_long("This is Karbane, the destructive. Being a kobold\n" +
             "archmage has made him unique among his kind. It is\n" + 
             "because of him that the landscape looks as it does,\n" +
             "hence they named him the destructive.\n");
    set_wc(1);
    set_ac(1);
    set_gender(1);
    set_hp(300 + random(100));
    set_al(-550);
    set_aggressive(1);
    add_money(5000 + random(2000));
    set_dead_ob(TO);
    move_object(clone_object("/players/kryll/obj/bracers"),TO);
    command("wear bracers");
  }
}


int attack() {

  object victim, *pllist;
  string v_name;
  int i;

  if (::attack()) {
    victim=TO->query_attack();
    v_name=victim->query_name();
    switch(random(100)) {
      case 0..20: {
         say("Karbane, the destructive, shoots a lightning bolt at "+v_name+"!\n");
         victim->reduce_hit_point(12*(random(5)+1));
         break;
      }
      case 21..38: {
         say("Karbane, the destructive, creates an earthquake and the area trembles!!!!\n");
         pllist = all_inventory(environment(TO));
         for(i=0;i<sizeof(pllist);i++)
            if (living(pllist[i]) && pllist[i]!=TO)
               victim->hit_player(40+random(13));
         break;
      }
      case 39..60: {
         say("Karbane, the destructive, casts a hold person on "+v_name+".\n");
         victim->hold(TO,(1+(random(11)/2)));
         break;
      }
      case 61..80: {
         if ((victim->query_con())*2 > random(35)) {
            say("Karbane, the destructive, drains life from "+v_name+
                "and gives it to himself!\n");
            victim->reduce_hit_points(victim->query_con());
            TO->reduce_hit_points(-(victim->query_con()));
            }
         else {
            say("Karbane, the destructive, attempts to drain life from "+
                v_name+", but fails.\n");
         }
         break;
      }
      case 81..95: {
         if ((victim->query_wis())*2 > random(45)) {
            if (victim->query_sp() < 0) {
               say("Karbane, the destructive, shoots "+v_name+" with a magic missile.\n");
               victim->hit_player(20+random(13));
               break;
            }
            else if (victim->query_sp() < (victim->query_int()+victim->query_wis())) {
               say("Karbane, the destructive, drains magic from "+v_name+"!\n");
               victim->restore_spell_points(-(victim->query_sp()));
               break;
            }
            else {
               say("Karbane, the destructive, drains magic from "+v_name+"!\n");
               victim->restore_spell_points(-(victim->query_int()+victim->query_wis()));
               break;
            }
         }
         else {
            say("Karbane, the destructive, attempts to drain magic from "+v_name+", but fails.\n");
            break;
         }
      }
      default: {
         say("Karbane, the destructive, gates in some help!!!\n");
//         gate();
         break;
      }
    }
   return 1;
   }
  return 0;
}

monster_died(ob) {

   tell_room(environment(TO),"\nKarbane vows revenge as he falls!\n\n");
}

