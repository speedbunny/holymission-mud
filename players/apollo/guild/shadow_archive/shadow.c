/* 05.30.94 Airborne: Edited to work from its new directory. */
/* G: Coded by Moonchild in the time he was with us */
/* G: Changed illegally later */
/* 15-DEC-1993 Galadriel: restored original Moonchild values, 3 locations */

#define TPN     (string)player->query_name()
#define FORT(x) x-x*fortitude/150

object player,last_room;
int melee_skill,speed,speed_counter,fortitude;
string name;
status melee;

public void update_speed();
private int do_attack();
private void get_msg(int dam, object mon);
private int allow_wear(object a);
private int check_name(string str);

public void update_speed() {
  speed=(int)player->get_skill("barbarian_speed")[0];
}

public void start_the_shadow(object tp) {
  player=tp;
  speed_counter=0;
  update_speed();
  shadow(player, 1);
}

public void remove_the_shadow() {
  destruct(this_object());
}

public void start_melee() {
/* 15-DEC-1993 Galadriel: Too strong
  melee_skill=(int)player->get_skill("barbarian_melee")[0]*3;
*/
  melee_skill=(int)player->get_skill("barbarian_melee")[0];
  last_room=environment(player);
  melee=1;
}

public int query_melee() {
  return melee;
}

public int attack() {
  int i;
/* 15-DEC-1993 Galadriel: Original value back (was 33) */
  while((i=do_attack()) && speed_counter>=50)
    speed_counter-=50;
  if(i)
    speed_counter+=speed;
  return i;
}

private int do_attack() {
  object *at;
  int i,j,tmp;
/* 15-DEC-1993 Galadriel: Original value back (was 33) */
  if(speed_counter>=50) {
    speed_counter-=50;
    do_attack();
  }
  if(!melee)
    return (int)player->attack();
  at=filter_array(all_inventory(environment(player)), "fight_filter");
  if(last_room!=environment(player) || !(j=sizeof(at))) {
    write("You return to sanity again.\n");
    say(TPN + " returns to sanity again.\n");
    melee=0;
    last_room=0;
    return 0;
  }
  tmp=j;
  for(i=0;i<j;i++) {
    int dam;
    name=(string)at[i]->query_name();
    dam=(int)at[i]->hit_player(random(10 + melee_skill / 2));
    if(at[i])
      get_msg(dam, at[i]);
    else {
      write("You killed " + name + ".\n");
      say(TPN + " killed " + name + ".\n");
      tmp--;
    }
    player->add_exp(dam);
  }
  if(!tmp) {
    write("You return to sanity again.\n");
    say(TPN + " returns to sanity again.\n");
    melee=0;
    last_room=0;
    return 0;
  }
  return 1;
}

int fight_filter(object ob) {
  return living(ob) && ob->query_npc();
}

private void get_msg(int dam, object mon) {
  string how,much;
  switch(dam) {
    case 0:      how="missed";       much="";                            break;
    case 1..2:   how="struck";       much=" with a glancing blow";       break;
    case 3..5:   how="hit";          much="";                            break;
    case 6..10:  how="hit";          much=" quite hard";                 break;
    case 11..18: how="hit";          much=" solidly";                    break;
    case 19..27: how="slammed into"; much="";                            break;
    case 28..44: how="clobbered";    much=" ferociously";                break;
    default:     how="smashed";      much=" with a bone crushing sound"; break;
  }
  write("You " +  how + " " + name + much + ".\n");
  say(TPN + " " + how + " " + name + much + ".\n", mon);
  tell_object(mon, TPN + " " + how + " you" + much + ".\n");
}

public int wield(object w, int hands) {
  object weap_shad;
  int tmp;
  if(!(tmp=player->wield(w, hands)))
    return 0;
  if(!w->id("axe") && !w->id("club") && !w->id("knife") && !w->id("spear")) {
    weap_shad=clone_object("/players/apollo/guild/shadow_archive/weap_shad");
    weap_shad->start_the_shadow(w);
  }
  return tmp;
}

public mixed wear(object a) {
  if(melee) {
    write("You can't wear armours while in a melee!\n");
    return -1;
  }
  if(present("combat_soul", player)) {
    write("You can't wear armours while in barbarian combat!\n");
    return -1;
  }
  if(allow_wear(a)) {
    write(capitalize((string)a->query_name()
	+ " isn't the sort of armour a Barbarian would wear.\n"));
    return -1;
  }
  return player->wear(a);
}

private int allow_wear(object a) {
  string shrt,name;
  if(a->id("chainmail"))
    return 1;
  if(a->id("platemail"))
    return 1;
  shrt=lower_case((string)a->short());
  name=lower_case((string)a->query_name());
  if(check_name(name))
    return 1;
  return check_name(shrt);
}

private int check_name(string str) {
  if(strstr(str, "metal ")!=-1)
    return 1;
  return 0;
}

public void update_fortitude() {
  fortitude=(int)player->get_skill("barbarian_fortitude")[0];
}

public int remove_ghost() {
  if(!player->query_ghost())
    return 0;
  if(!creator(previous_object())) {
    tell_object(player, "You need to pray in your own temple ....\n");
    return 1;
  }
  player->heal_self(1000);
  return (int)player->remove_ghost();
}

public void run_away() {
  player->run_away();
  if(environment(player)!=last_room) {
    melee=0;
    player->attack();
  }
}

public int drink_alcohol(int strength) {
  return (int)player->drink_alco(FORT(strength));
}

public int drink_alco(int strength) {
  return (int)player->drink_alco(FORT(strength));
}

public int drink_soft(int strength) {
  return (int)player->drink_soft(FORT(strength));
}

public int eat_food(int strength) {
  return (int)player->eat_food(FORT(strength));
}

public int add_intoxination(int i) {
  return (int)player->add_intoxination(FORT(i));
}

public int add_stuffed(int i) {
  return (int)player->add_intoxination(FORT(i));
}

public int add_soaked(int i) {
  return (int)player->add_intoxination(FORT(i));
}

public void add_poison(int i) {
  player->add_poison(FORT(i));
  return;
}
