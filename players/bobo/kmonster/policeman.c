inherit "obj/monster";

#define TELL_ME(i) tell_object(find_player("kelly"),i) 

string func,match,type,criminal;
object leader;
status found;
 
reset(arg) {
::reset(arg);
  if (arg) return;
  set_name("policeman");
  set_race("human");
  set_size(3);
  set_male();
  set_alias("man");
  set_level(10);
  set_hp(70);
  set_wc(9);
  set_ac(5);
  set_al(50);
  set_short("A policeman");
  set_long("A policeman. He is on duty.\n"); 
  set_aggressive(0);
  set_array();
  set_match(this_object(),func,type,match);
  found=0;
  criminal="XYZXYZ";
}

init() {
::init();
  check_room();
} 

set_leader(i) { 
  leader=i;
} 

query_leader() { return leader; }
 
handle_arrive(str) {
  if(!random(5)) 
    say("The policeman says: Hi, we've gotta job.\n");
  check_room();
}

handle_leave(str) {
  string who,dir;
  if(sscanf(str,"%s leaves %s.",who,dir)!=2) {
    say("The policeman looks braindamaged.\n");
    return;
  }
  if(lower_case(who)!=criminal) return;
  found=0;
  if(!random(5)) 
    say("The policeman runs after the criminal.\n");
  init_command(dir);
}
     
set_array() {
  func= allocate(2);
  match= allocate(2);
  type= allocate(2);

  func[0] = "handle_arrive";
  match[0] = "";
  type[0] = "arrives";
  func[1] = "handle_leave";
  match[1] = "";
  type[1] = "leaves";
} 

set_criminal(i) { criminal=i; }

check_room() {
  object atta;
  string all;
  int i;
  
  found=0;
  i=0;  
  all=all_inventory(environment(this_object())); 
 
  while (!found && i<sizeof(all)) {
    if(all[i]->query_real_name()==criminal) {
      found=1; 
      atta=all[i];
    }
    i++;
  }
  if(found) { 
    if(!random(5))
      say("The policeman yells: Finally we got you.\n");
    attack_object(atta);
  }
}

follow(dir) {
  init_command(dir);
  check_room();
}
