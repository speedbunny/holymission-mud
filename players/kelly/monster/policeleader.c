inherit "obj/monster";

#define TELL_ME(i) tell_object(find_player("kelly"),i+"\n")
 
string directions,criminal,func,match,type;
status walking,found;
int dir_nr,max_nr;
object atta;

reset(arg) {
::reset(arg);
if (arg) return;
  set_name("lieutenant");
  set_size(3);
  set_race("human");
  set_alias("policeman");
  set_alt_name("man");
  set_male();
  set_short("A police lieutenant");
  set_long("A police lietenant. He leads a patrol.\n");
  set_ac(10);
  set_level(15);
  set_al(50);
  set_wc(15);
  set_aggressive(0);
  set_array();
  set_match(this_object(),func,type,match);
  criminal=0;
  walking=0;
  dir_nr=0;
  found=0;
}
 
set_criminal(i) { criminal=i; }

set_direction(i) {
  directions=explode(i,",");
  max_nr=sizeof(directions)-1;
}

start_walking() {
  if(walking) return; 
  walking=1;
  call_out("walk",5);
}

walk() {
  if(!walking || found) return;
  if(dir_nr>=max_nr) {
    finish();
    return;
  }
  check_room();
  if(found) return ;
  men_follow(directions[dir_nr]);
  init_command(directions[dir_nr]);
  dir_nr++;
  call_out("walk",5);
}

finish() {
  say("The policeman says: You called us?\n");
  say("                    Where is the bastard?\n");
  check_room();
}

check_room() {
  string all;
  int i,al;
  
  all=all_inventory(environment(this_object())); 
  while (!found && i<sizeof(all)) {
    if(all[i]->query_real_name()==criminal) {
      found=1; 
      atta=all[i];
    }
    i++;
  }
  if(found) { 
    walking=0;
    say("The lieutenant yells: Here is the bastard. Get him.\n");
    attack_object(atta);
  }
}

handle_arrive(str) {
  check_room();
}

handle_leave(str) {
  string who,dir;
  if(sscanf(str,"%s leaves %s.",who,dir)!=2) {
    say("The lieutenant looks braindamaged.\n");
    return;
  }
  if(lower_case(who)!=criminal) return;
  say("The lieutenant shouts: Follow that wimp, guys.\n");
  init_command(dir);
  check_room();
}

handle_say(str) {
  string who,what;
  sscanf(str,"%s says: %s",who,what);
  if(lower_case(who)==criminal) {
   say("The lieutenant says: Now it's too late to talk, swine.\n");
   return 1;
  }
  say("The lieutenant says: Sorry, we've got a job to do.\n");
} 
     
set_array() {
  func= allocate(3);
  match= allocate(3);
  type= allocate(3);
 
  func[0] = "handle_arrive";
  match[0] = "";
  type[0] = "arrives";
  func[1] = "handle_leave";
  match[1] = "";
  type[1] = "leaves";
  func[2] = "handle_say";
  match[2] = "";
  type[2] = "says";
} 

men_follow(dir) {
  object all;
  int i;

  all=all_inventory(environment());
  for(i=0;i<sizeof(all);i++) {
    if(all[i]->query_leader()==this_object()) {
      all[i]->follow(dir); 
    }
  }
}

