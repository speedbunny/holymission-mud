/* cats are trying to make muds more nicer (genesies!) */
inherit "obj/monster";
 
object fellow,grin;   
int counter;
string fname,cname;
status fol,bur;
object store;
 
reset(arg) {
counter = 0;
  ::reset(arg);
  if (arg) return;
  store=find_object("room/store");
set_short("A hungry little sailors cat"); set_alias("cat"); set_race("cat");
set_level(8); set_hp(120);set_wc(8); set_ep(4000); set_al(100);
set_ac(12); set_heart_beat(3); set_aggressive(0);
add_money(400); /* damit die player mit der cat in die sauna koennnen */
set_long("A hungry little sailors-cat 'type <help cat> to get more information\n");
load_chat(4,({"MIAAAAAAAAAOOOOOOOOOWWWWWWWW\n"}));
load_a_chat(40,({"RRRRRROOOOOOOOOOOAAAAAARRRRRRRRRRR\n"}));
}
 
init() {
 ::init();
 add_action("inspect", "inspect");
 add_action("pet", "pet");  add_action("pet", "stroke");
add_action("help","help");
 add_action("name", "name");
}
help(str) {
if(str!="cat") return;
write("++++++++++++sailors-cat++++++++++++++++++++++++++++++\n");
write("Congratulation, you have now got the latest version\n");
write("of Whisky's sailor-cat. But there are a few things to\n");
write("learn to get an optimal use of these cats:\n");
write("<get cat> and the cat is yours....\n");
write("<pet cat>,<name cat (name)> to give the cat a name\n");
write("<drop cat> and the cat will follow you, helping you by your fights\n");
write("<kick cat> the cat will leave you\n\n");
write("But please notice:\n");
write("Your cat isn't very strong and the idea is not to\n");
write("attack bigger monsters as low level player\n");
write("and your isn't able to heal itself buy drinking alcohol\n");
write("therefore the only heal funktion is to take care of your\n");
write("cat or bring it a corpse to eat <heal_self>\n");
write("It's possible in reason of the alt_attack() funktion\n");
write("that your cat sometimes don't work how it should.\n");
write("Then type <get cat>,<stop>,<drop cat> and it will work again.\n");
write("Please report any bugs via the post-office to Whisky\n");
write("+++++++ and have much fun with your personal cat ++++\n");
return 1; }
 
get() {
counter = counter + 1;
if ((!fol)&& (counter < 3)){ fellow=this_player();set_fellow();} return 1; 
if ((!fol)&& (counter >= 3)){ 
write("Sorry, but a single person only can have 2 cats.\n"+
"If it further happens that there are people with more\n"+
"cats, we must banish them from mud <please be nice to the others>.\n");
} return 0; }
// query_npc() { return 0; }  /* for fooling monsters */
 
catch_tell(str) {
string a,b;
object tmp;
  ::catch_tell(str);
  if (sscanf(str,"%s died.",a)==1) { call_out("eat", 3); return; }
  if (  (sscanf(str,"%s cuddles you.",a)==1)
      ||(sscanf(str,"%s fondles you.",a)==1)) {
    tmp=find_living(lower_case(a));
    if (tmp && !fol) { fellow=tmp; set_fellow(); }
    else call_out("purrr",1);
    return;
  }
  if (sscanf(str,"%s kicks you.   OUCH!!",a)==1) {
    tell_room(environment(), "The cat spits at "+a+".\n");
    if (fellow && a==fname) unset_fellow();
    return;
  }
}
 
purrr() { tell_object(fellow, "Your cat purrs contentedly.\n"); }
 
eat() {
object ob;
if (ob=present("corpse",environment())) {
      if (fellow) tell_room(environment(), capitalize(fellow->query_name())+
                                        "'s cat devours the corpse.\n");
      else tell_room(environment(), "The cat devours the corpse.\n");
      tell_room(environment(), "Yum yum yum.\n");
    heal_self(100);
      destruct(ob);
      if (!bur) { bur=1; call_out("burp",5); }
      return 1;
  } else return 0;
}
 
set_fellow() {
object alf;
if (alf=present("alf",environment())) { 
write("Your cat snaps after alf.\n");write("Your cat burps happily.\n");
destruct(alf); return 1; }
  fname=capitalize(fellow->query_name());
  set_name(fname+"'s cat");
  set_long("It is a cute little fighting cat.\n");
  load_chat(3,({"MEOW!\n"}));
  call_out("purrr",1);
  if (!fol) { fol=1; call_out("follow",7); }
}
 
name(str) {
string n;
  if (!str) return 0;
  if (sscanf(str, "cat %s", n)!=1) return 0;
  if (this_player()!=fellow) {
    notify_fail("It is not your cat!\n"); return 0;
  }
  cname=capitalize(n);
  set_name(cname+" ("+fname+"'s cat)");
  set_alt_name(lower_case(n));
  set_long("It is a cute little fighting cat.\n");
  return 1;
}
 
follow() {
object ec, e;
  ec=environment();
  if (ec==store || !fellow) { unset_fellow(); return; }
  if (!living(ec) && !present(fellow)) {
    e=environment(fellow);
    move_player("", e);
    if (query_exp()>0) {
      fellow->add_exp(query_exp());
      set_ep(0);
    }
    search();
  } else if (!living(ec)) {
if ((e=fellow->query_attack()) && (e!=fellow) && (e!=this_object())) attack_object(e);
else { stop_fight(e);stop_fight(fellow);}
if ((!living(ec)) && this_object()->query_hp()<=20) {
write("Your cat cries it hates that fight, it's enemie is too strong\n");
move_object(this_object(),this_player());write("Your cat jumps into your arms\n");}
  }
  call_out("follow",7);
}
 
drop() { call_out("search",3); return 0; }
search() { if (eat()) call_out("search",1); }
burp() {
  tell_room(environment(), fname+"'s cat burps rudely.\n");
  bur=0;
}
 
unset_fellow() {
  fellow=0;
  set_name("A cat");
  cname=0;
  set_alt_name(cname);
  set_long("It is a cute little fighting cat.\n");
  fol=0;
}
 
inspect(str) {
  if (!str) { notify_fail("Ispect what?\n"); return 0; }
  if (present(str,environment())!=this_object()) return 0;
  write(query_hp()+" (100) HPs\n"); return 1;
}
 
pet(str) {
object tmp;
  if (!str) { notify_fail("Pet what?\n"); return 0; }
  if (present(str,environment())!=this_object()) return 0;
  tmp=this_player();
  if (tmp) say(tmp->query_name()+" "+query_verb()+"s cat.\n",this_player());
  if (tmp && !fol) { fellow=tmp; set_fellow(); }
  else call_out("purrr",1);
  return 1;
}
 
query_value() {
object env;
  store=find_object("room/store");
  env=environment();
  if (living(env)) {
    if (env!=fellow) return 0;
    env=environment(env);
  }
  if (find_object("room/shop")==env) return 50;
  else if (store==env) return 500;
  else return 0;
}
 
/*
query_real_name() {
  return query_name();
}
*/
