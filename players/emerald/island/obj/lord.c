inherit "/obj/monster";
 
//prototypes for new functions
int area_spell(int dam, string kind);
 
 
void reset(int arg) {
  ::reset(arg);
  if(arg != 0) return;
 
  set_name("garschmirak");
  set_alt_name("dragon");
  set_short("garschmirak, the five-headed cromatic dragon");
  set_long(
    "Garschmirak is a huge, five-headed chromatic dragon.  It stares with "+
     "red eyes at you!\n");
  set_race("dragon");
  set_aggressive(1);
  set_level(80);
  set_hp(10000);
  set_ac(40);
  set_wc(150);
  set_gender(1);
  set_dead_ob(this_object());
}

int monster_died(object ob) {
  object m;
 
  m = clone_object("/obj/money");
  m->set_money(5000+random(10000));
  move_object(m, environment());
 
  if(!this_player()->query_immortal())
    shout(capitalize(this_player()->query_real_name())+
          " killed Garschmirak the Lacerator.\n");
  tell_object(this_player(), "Oh, the Gods praise your deed and it "+
              "begins to rain gold coins.\n");
  return 0;
}
 
//overwrites the attack function
int attack() {
  if(::attack()) {
    if(!random(2) && find_call_out("cast_spell")==-1) {
      tell_room(environment(), capitalize(query_name()) +
                               " takes a DEEP BREATH.\n");
      call_out("cast_spell", 3);
    }
    if(!random(2))
      ::attack();
    if(!random(3))
      ::attack();
    return 1;
  }
  return 0;
}
 
// overwrites the query_hit_msg function which gives the type of attack
query_hit_msg(dam, name, att, def) {
  string how, hit_art;
 
  switch(random(8)) {
    case 0:
      how = "with his right foreleg";
      hit_art = "claws";
      break;
    case 1:
      how = "with his left foreleg";
      hit_art = "claws";
      break;
    case 2:
      how = "with his tail";
      hit_art = "sweeps";
      break;
    case 3:
      how = "with his red head";
      hit_art = "bites";
      break;
    case 4:
      how = "with his white head";
      hit_art = "bites";
      break;
    case 5:
      how = "with his black head";
      hit_art = "bites";
      break;
    case 6:
      how = "with his green head";
      hit_art = "bites";
      break;
    default:
      how = "with his blue head";
      hit_art = "bites";
      break;
  }
 
  return ({ "",
            hit_art + " you " + how + ".",
            hit_art + " " + name + " " + how + "." });
}
 
mixed cast_spell() {
  switch(random(5)) {
    case 0: return area_spell((40+random(16)), "CONE OF FIRE");
    case 1: return area_spell((60+random(26)), "CONE OF COLD");
    case 2: return area_spell((50+random(21)), "STREAM OF ACID");
    case 3: return area_spell((90+random(31)), "LIGHTNING BOLT");
    case 4: return area_spell((20+random(11)), "GAS CLOUD");
  }
}
 
/* spelldamage kind of spell resistance */
int area_spell(int dam, string kind) {
  int    i, sz;
  object *inv;
 
  inv = all_inventory(environment());
 
  for(i=0, sz=sizeof(inv); i<sz; i++) {
    if(living(inv[i])) {
      tell_object(inv[i], "You are hit by a " + kind + "!\n");
      if(inv[i] != this_object()) {
        if(kind == "GAS CLOUD") {
          inv[i]->hit_player(1 + random(dam) , 5);
          inv[i]->add_poison((dam/2)+random(dam));
        }
        else
          inv[i]->hit_player(dam + random(dam) , 5);
      }
    }
  }
  return 1;
}
 
// overwrites the hold function
hold(caller, time) {
 if(time > 8)
   return ::hold(caller, random(8));
 return ::hold(caller, time);
}
