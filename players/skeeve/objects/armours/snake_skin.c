inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("snake skin");
    set_alias ("skin");
    set_type("armour");
    set_ac(6);
    set_short("A snake skin");
    set_long("It's a fantastic armour but something is wrong with it.\n");
    set_value(10);
    set_weight(5);
    set_size(0);
  }
}

wear(str) {
  int i;
  if ((i = ::wear(str)) && worn_by && worn_by->query_player()
    && !(worn_by->query_wizard()) ) 
    poison();
  return i;
}

remove(str) {
  int i;
  object tp;
  tp = worn_by;
  i = ::remove(str);
  if (i && tp->query_player() && !(tp->query_wizard())) 
    remove_call_out("poison");
  return i;
}

poison () {
  int hp;
  string s;  
  if (!worn_by) return;  
  if ( (hp = worn_by->query_hp()) > 10 ) {
    worn_by->hit_player(hp/4,3);
    write("Oh. A strong pain goes through your bones and you feel terribly hurt.\n");
  }
  if (sscanf(file_name(this_object()),"%s#%d",s,hp)==2)
     call_out("poison",40 - (worn_by->query_level()));
}
