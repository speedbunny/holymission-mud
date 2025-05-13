inherit "obj/monster";
 
object fellow,grin;   
int is_owner;
string fname,cname;
status fol,bur;

query_weight() { return 2; }
 
reset(arg) {
  ::reset(arg);
  if (arg) return;
  if(strstr(file_name(this_object()),"#") == -1) return;
  set_short("A hungry little sailors cat");
  set_name("cat");
  set_alias("cat");
  call_out("dest_me",400);
  set_alt_name("sailors cat");

  set_level(8);set_hp(120);set_wc(12); set_ep(4000); set_al(100);
  set_ac(8);set_aggressive(0);set_heart_beat(1);
  set_long("A hungry little cat 'type <help cat> to get more information\n");
  load_a_chat(20,({"RRRRRROOOOOOOOOOOAAAAAARRRRRRRRRRR\n"}));
  }
 
init() {
 ::init();
 add_action("inspect", "inspect");
 add_action("pet", "pet"); 
 add_action("pet","stroke");
 add_action("name", "name");
}
get() {
  if (!fol || !fellow) {    /* Changed by Herp */
     fellow=this_player();
     is_owner = 1;
     set_fellow();
  }
  this_object()->stop_fight();
  fellow->stop_fight();
  return 1;
}

dest_me() {
 if (is_owner && !fellow) {/* owner quit */
   destruct(this_object());
   return 0;
}
call_out("dest_me",5);
  }
catch_tell(str) {
string a,b;
object tmp;
  ::catch_tell(str);
  if (sscanf(str,"%s died.",a)==1) { call_out("eat", 3); return; }
  if (  (sscanf(str,"%s cuddles you.",a)==1)) {
    tmp=find_living(lower_case(a));
    if (tmp && !fol) { fellow=tmp; set_fellow(); }
    else call_out("purrr",1);
    return;
  }
  if (sscanf(str,"%s kicks you.   OUCH!!",a)==1) {
    tell_room(environment(), "The cat spits at "+a+".\n");
    if(fellow)
     {
       if(fellow=present(a,environment(this_object()))) unset_fellow();
     }
    return;
  }
}
 
purrr() { tell_object(fellow, "Your cat purrs contentedly.\n"); }
 
eat() {
object ob;
if (ob=present("corpse",environment())) {
      if (fellow) tell_room(environment(), capitalize(fellow->query_real_name())+
                                        "'s cat devours the corpse.\n");
      else tell_room(environment(), "The cat devours the corpse.\n");
      tell_room(environment(), "Yummy yummy fauch.\n");
      heal_self(random(80));
      destruct(ob);
      if (!bur) { bur=1; call_out("burp",5); }
      return 1;
  } else return 0;
}
 
set_fellow() {
  fname=capitalize(fellow->query_real_name());
  set_name(fname+"'s cat");
  set_long("It is a cute little fighting cat.\n");
  call_out("purrr",1);
  if (!fol) { fol=1; call_out("follow",2); }
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
  if (!living(ec) && !present(fellow)) {
    e=environment(fellow);
    move_player(", following its owner", e);
  /*
    if (query_exp()>0) {
      fellow->add_exp(query_exp());
      set_ep(0);
    }
      */
  search();
    } else if (!living(ec)) {
      if ((e=fellow->query_attack()) && (e!=fellow) && (e!=this_object())) 
          attack_object(e); 
      else {
        stop_fight(e);stop_fight(fellow);
       }
  /*   if (this_object()->query_attack(fellow))  {
       stop_fight(e);
       stop_fight(fellow);
    }  */

   if ((!living(ec)) && this_object()->query_hp()<=40) {
      write("Your cat cries it hates that fight, it's enemy is too strong\n");
    transfer(this_object(),this_player());write("Your cat jumps into your arms\n");}
  }
  call_out("follow",2);
  }
 
  drop() { call_out("search",3); return 0; }
  search() { if (eat()) call_out("search",1); }
  burp() {
  tell_room(environment(), fname+"'s cat burps rudely.\n");
  bur=0;
  }
 
unset_fellow() {
  fellow=0;
  set_name("cat");
  set_short("A hungry little sailors cat");
  set_alt_name("sailors cat");
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
