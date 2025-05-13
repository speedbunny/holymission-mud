inherit "obj/monster";

string function, type, match;

reset(arg) {
   int hp;
   ::reset(arg);
   if(!arg) {
       set_level(3); 
       set_name("bees");
       set_alias("swarm");
       set_short("A swarm of bees");
       set_long("An upset swarm of honey-bees look for the honey-robber.\n");
       set_size(1);
       set_hp(200+random(201));
       set_sp(0);
       set_whimpy(-1);
       set_ac(2);
       set_wc(7);
       set_aggressive(1);
       set_no_ears();
       set_dead_ob(this_object());
       load_chat(20,({
              "Bsss ... bsss ... \n",
              "Bsss ... we hate honey robbers ... bsss ...\n",
              "Bsss ... we will call the beekeeper ... bsss ...\n",
              "Bsss ... the beekeeper will kill you ... bsss ...\n",
              "Bsss ... a honeyrobber is killing us ... bsss ...\n",
              "Bsss ... help ... bsss ...\n",
              "Bsss ... where is the beekeeper? ... bsss ...\n"
       }) );
   } 
  if (!function) {
    setup_arrays();
    set_match(this_object(), function, type, match);
  }
  if(hp = query_hp() < 300 ) set_hp(hp + random(100)+1);
}

setup_arrays() {
  function = allocate(1);
  type = allocate(1);
  match = allocate(1);
  function[0] = "handle_leave"; type[0] = "leaves"; match[0] = "";
}

handle_leaves( arg ) {
  string who, where;
  object vic;
  if((vic=this_object()->query_attack())
    && (sscanf(arg,"%s leaves %s",who,where)==2) 
    && (who==capitalize(vic->query_real_name())) ) {
  command(where); 
} }

short() { return ::short()+" ("+query_hp()+")"; }

long() { return ::long()+" ("+query_hp()+")"; }

attack_object (ob) {
  set_n_wc((ob && ob->query_player() && present("beemail",ob))?1:7);
  ::attack_object(ob);
}

hit_player(arg,k) {
    int dam;
    dam=::hit_player(arg,k);
    if (dam) write("You killed "+dam+" bees.\n");
    return dam;
}

query_stay_garden() { return 1;}

monster_died(ob) {
object beekeeper;
  tell_room (environment(this_object()),"Bsss ... help! A honeyrobber killed us! ... bsss ...\n");
  if (beekeeper=present("beekeeper")) 
    beekeeper->help(ob);
  return 0;
}
