inherit "obj/monster";

#define TP       this_player()
#define TO       this_object()
#define OBJ      "/players/kryll/obj/"
#define CW(x)     clone_object("/players/kryll/weapons/"+x)
#define MW(x)     move_object(x,TO)

void now_wait();

string w_name;
object weap;
int i;

int attack() {

 object victim;

 victim = TO->query_attack();
 if (objectp(victim))
    i++;
 if (!random(4) && i) {
    TO->stop_fight();
    TO->set_name("");
    victim->stop_fight();
    victim->set_follower(TO);
    call_out("now_wait",1);
    return 0;
  }
  else
     ::attack();
}


void now_wait() {

object victim;

victim=TO->query_follow_whom();
tell_object(victim,"The kobold stabber appears as he backstabs you!\n");
victim->reduce_hit_points(10+random(10));
TO->set_name("Kobold Stabber");
TO->attack_object(victim);
victim->rem_follower(TO);
return;
}


reset (arg) {
 ::reset(arg);
 if (!arg) {

  set_name("Kobold Stabber");
  set_level(8);
  set_hp(115+random(20));
  set_alt_name("stabber");
  set_short("Kobold Stabber");
  set_race("kobold");
  set_size(2);
  set_al(-10);
  set_ac(1);
  if (!random(2))
    set_gender(2);
  else
    set_gender(1);
  set_wc(7);
  set_no_steal(1);
  set_whimpy(30);
  set_long("This is a cowardly, sadistic humanoid that is\n" +
           "3 feet tall with scaly dark brown hide. With\n" +
           "their rat-like tail and raggedly garb, they\n" +
           "don't look like much of a threat.\n");
  add_money(300+random(200));
  weap=CW("kobStabber");
  w_name=weap->query_name();
  MW(weap);
  command("wield "+w_name);
  i=0;
 }
}




void init() {
   ::init();

     switch(TP->query_race()) {
       case "troll":
       case "orc":
       case "giant":
        this_object()->attack_object(TP);
       default: break;
    }
}

