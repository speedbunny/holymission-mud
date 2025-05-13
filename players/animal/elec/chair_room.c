inherit "room/room";
 
#define this_room "players/animal/elec/chair_room.c"
int strap;
int monsu;
int empty;
int already;
int check;
int level;
string this, this_dies;
int a, aa;
 
reset(arg) {
  if(arg) return;
  set_light(1);
  set_outdoors(1);
  short_desc ="The Room";
  long_desc = 
     "The Room\n\n"+
     "    This is the electrocution room. There is an ominous looking chair\n"+
     "    sitting in the room here. It is stained with the blood of past\n"+
     "    victims, and is patiently awaiting it's next victim.\n"+
     "    There is a note and a piece of paper here.\n\n";
  items = ({ 
              "chair","This is the CHAIR, is is not a nice device",
              "switch", "Pulling the switch fries the person in the chair", 
              "paper", "There is some text on it. Try to read it",
              "note","This a small note, read it"});
  dest_dir = ({"players/animal/workroom", "up"});
  enable_commands();
  if(!(present("warden"))) {
    move_object(clone_object("/players/animal/elec/warden"), this_object());
  }
}
 
init() {
  ::init();
  add_action("do_pull", "pull");
  add_action("do_push", "push");
  add_action("do_read", "read");
  add_action("do_gag", "gag");
  add_action("do_strap", "strap");
  add_action("undo_strap", "remove");
  add_action("undo_gag", "ungag");
  }
 
do_pull(str) {
  object ob, ob1, ob2;
  string someone_dies_now;
 
  if(str!="lever") return;
 
  if(!empty) {
    write("Nothing happens.\n");
    return 1;
  }
 
  else {
    if(a!=0 && already==1) {
      write("Wait your turn!\n");
      return 1;
    }
 
    write("You pull the lever.\n");
    say(this_player()->query_name() + " pulls the lever.\n",this_player());
    tell_room(this_room, "The chair gets one hell of a charge!\n");
 
    ob = first_inventory(this_object());
    while(ob) {
      ob1 = first_inventory(ob);
      while(ob1) {
        if(ob1->query_info()=="will_die") {
          someone_dies_now = 1;
          ob2 = ob;
        }
        ob1 = next_inventory(ob1);
      }
      ob = next_inventory(ob);
    }
 
    if(someone_dies_now) {
      a = 0;
      empty = 1;
      aa = random(3);
      this_dies = ob2->query_name();
      level = ob2->query_level();
      if(!(ob2->query_npc())) {
        log_file("animal_fried", this_player()->query_real_name() + 
     " pulled the lever");
    monsu = 0;
      }
 
      else monsu = 1;
      tell_room(this_room,this_dies + " is jolted terribly.\n");
      remove_call_out("ele");
      call_out("ele", 1, ob2);
      return 1;
    }
 
    else {
     empty = 1;
      return 1;
    }
  }
  return 1;
}
 
ele(who) {
  call_out("ele", 3, who);
  already = 1;
  a += 1;
 
  if(a==1) {
    tell_object(who, "You realize that you are being fried!!\n");
    say(who->query_name() + " is starting to fry!\n",who);
    /*    shout("The world senses an execution, there is a loud roar.\n"); */
  }
 
  if(a==2) {
    say("The chair starts to glow brightly.\n");
  }
 
  if(a==3) {
 
    if(random(7)==6) {
      tell_room(this_object(), "There is a loud BANG! The circuit breaker "+
 "could not handle\nthe electricity required to fry "+who->query_name()+
          "!\n");
      already = 0;
      check = 1;
      call_out("warden_saves", 1, who);
      a = 71;
      return;
    }
 
    else {
 
      if(aa==1) {
        tell_object(who, "You feel terrible burning throughtout yer body!\n");
        say(this_dies + "'s face becomes crooked with pain and horror.\n",who);
      }
 
      if(aa==0) {
        tell_object(who, "You try hard to block the pain, but it grows"+
          " stronger by the second.\n");
        say(this_dies + "'s body is straining hard against the pain."+
            " Through\n" +who->query_possessive()+ 
                  " compressed lips you hear funny hissing.\n",who);
      }
 
      if(aa==2) {
 
        if(random(2)==1) {
          tell_object(who,"Your body is jerking violently.\n");
          say(this_dies + "'s body jerks violently.\n",who); 
        }
 
        else {
          say(this_dies + "'s eye's bulge grotesquely.\n",who);
          tell_object(who,"Your eye's are going to pop out!\n");
        }
        tell_object(who, "\n\n\n                              POP!\n\n");
        say(this_dies+"'s eye go POP! They fly across the room, and"+
          " stick to the other wall.\n",who);
        who->hit_player(100000);
        call_out("double_check", 1, who);
      }
    }
  }
 
  if(a==4 && aa==1) {
    tell_object(who, "Your whole body is frying. There is no"+   
          " longer fear for death. You know death is coming.\n");
    say(this_dies + " cries out " +who->query_possessive()+ " death "+     
      "plea.\n",who);
  }
 
  if(a==4 && aa==0) {
    tell_object(who, "You cannot even think straight. Your face is"+ 
          " melting, and sliding down your skull!\n");
    say(this_dies+ "'s face starts to melt and " +who->query_pronoun()+ 
          " body shakes violently.\n",who);
  }
 
  if(a==5 && aa==1) {
    tell_object(who, "Panic fills your body. You can no longer control"+
          " your bodily functions.\n");
    say(this_dies+ " loses control of " +who->query_possessive()+
          " bodily functions.\n",who);
  }
 
  if(a==5 && aa==0) {
    tell_object(who, "You feel like your eyes are exploding.\n");
    say(this_dies+ "'s eyeballs are ready to POP!\n",who);
  }
 
  if(a==6 && aa==0) {
    tell_object(who, "You are loosing your consciousness and"+
          " you begin to hallucinate. You see little pink elphants.\n");
    say(this_dies+ " mumbles something about pink elephants.\n",who);
  }
 
  if(a==7 && aa==0) {
    if(present("warden") && random(4)==3) {
      a = 71;
      already = 0;
      check = 2;
      call_out("warden_saves", 1, who);
      return;
    } 
 
    else {
      tell_object(who, "Everything shimmers and, finally, you die,"+
          " ending the agony.\n");
      say(this_dies + "'s dead body sinks into the chair.\n",who);
      who->hit_player(100000);
      call_out("double_check", 1, who);
    }
  }
 
  if(a==6 && aa==1) {
    tell_object(who, "Your desire to live and the terrible pain makes"+
          " you cry out.\n");
    say("Tears of despair fill "+who+"'s eyes.\n",who);
  }
 
  if(a==7 && aa==1) {
    if(present("warden") && random(4)==3) {
      a = 71;
      already = 0;
      check = 2;
      call_out("warden_saves", 1, who);
      return;
    }
 
    else {
      tell_object(who, "You lose your conciousness.\n");
      say(this_dies + " suddenly stops shaking.\n",who);
      who->hit_player(100000);
      call_out("double_check", 1, who);
    }
  }
 
  if(a==8 && who->query_ghost() && monsu!=1) {
    log_file("animal_fried", " and killed " +this_dies+ "(" +level+").\n");
  }
 
  if((a==9 || a==13 || a==16 || a==21) && ((query_ip_number(who) &&
          who->query_ghost()) || who->query_npc())) {
    tell_room(this_room, "The dead body of " +this_dies + 
          " is slowly rotting in the chair, it smells BAD!\n");
  } 
 
  if(a==22) {
    already = 0;
    remove_call_out("ele");
    return;
  }
}
 
 
warden_saves(saved) {
 
  if(check==2) {
    tell_room(this_room, "The warden suddenly recieves a call from the"+
          " governor and turns the machine off!\n");
   say(saved->query_name() + " breathes a sigh of relief.\n",saved);
    tell_object(saved, "You are hurt badly, but you are alive and more"+
     " experienced now.\n");
  }
 
  saved->reduce_hit_point(1000);
 
  if(check==2) {
    if(saved->query_exp() < 1000) {
      saved->add_exp(random(600));
    }
 
    else {
      saved->add_exp((saved->query_exp())/4);
    }
  }
 
  if(check==1) {
    if(saved->query_exp() < 1000) { 
      saved->add_exp(random(400));
    }
 
    else {
      saved->add_exp((saved->query_exp())/5);
    }
  }
 
  if(!monsu && check == 2) {
    log_file("animal_fried", " but was pardoned, "+
          saved->query_name()+ " gained some experience.\n");
  }
 
  if(!monsu && check == 1) {
    a = 71;
    log_file("animal_fried", "\n but the circuit breaker couldn't fry "
     +saved->query_name()+ " and so " +saved->query_pronoun()+ " gained"+
          " some experience.\n");
  }
 
  check = 0;
  remove_call_out("ele");
  a = 0;
  aa = 0;
  call_out("double_check", 1, saved);
  return;
}
 
 
 
double_check(place) {
  object ob, ob1, ob2;
  ob = first_inventory(place);
 
  while(ob) {
 
    if(ob->query_info()=="will_die") {
      ob1 = ob;
    }
 
     if(ob->query_info()=="this_person_is_gagged") {
       ob2 = ob;
    }
    ob = next_inventory(ob);
  }
 
  if(ob1) destruct(ob1);
 
  if(ob2) destruct(ob2);
 
  return;
}
 
 
do_push(str) {
 
  if(str!="breaker") return;
  
  if(empty) {
    write("Nothing happens.\n");
    say(this_player()->query_name()+ " pushes the breaker to check the charge"+
     " on the chair.\n");
    return 1;
  }
  
  else {
    if(a!=0 && a < 20 ) {
      write("Wait your turn!\n");
      return 1;
    }
 
    else {
      write("You push the switch that charges the system.\n");
      say(this_player()->query_name() + " bares "
   +this_player()->query_possessive()+ " teeth and pushes the breaker.\n",
          this_player());
      tell_room(this_room, 
          "The chair is ready for a victim.\n");
      empty = 1;
    }
  }
 
  return 1;
}
 
undo_gag(str) {
  string who, who1, who2, what;
  object ob, ob1, ob2;
  int gag;
 
  if(this_player()->query_level() < 20 && !(this_player()->query_npc())) {
    write("The gag is way too tight for you to undo.\n");
    return 1;
  }
  
  if(sscanf(str, "%s", who)!=1) {
    write("Try 'ungag <victim>'.\n");
    return 1;
  }
 
  else {
    who1 = lower_case(who);
    who2 = find_living(who);
 
if(this_player()->query_real_name()==who && 
     this_player()->query_level() < 20 &&
       !(this_player()->query_npc())) {
      write("GET REAL!!!\n");
      return 1;
    }
 
    if(!(present(who1, this_object())) || !find_living(who)) {
      write("There is no such living here.\n");
      return 1;
    }
 
 
    who2 = find_living(who);
    ob1 = first_inventory(who2);
    while(ob1) {
      if(ob1->query_info()=="this_person_is_gagged") {
        ob2 = ob1;
        gag = 1;
      }
      ob1 = next_inventory(ob1);
    }
 
    if(gag) {
      destruct(ob2);
      write("Done.\n");
	command("sigh",this_player());
      say(this_player()->query_name() + " ungagged " +capitalize(who)+".\n");
      return 1;
    }
    
    if(!gag) {
      write(who2->query_pronoun() + " wasn't gagged.\n");
      return 1;
    }
  }
}
 
      
do_gag(str) {
  string what, who;
  string who1, who2;
  object ob, ob1, ob2;
  int done;
 
  if(this_player()->query_level() < 20 && !(this_player()->query_npc())) {
    write("You can't do that!\n");
    return 1;
  }
  
  if(sscanf(str, "%s", who)!=1) {
    write("Try 'gag <victim>'.\n");
    return 1;
  }
 
  else {
    if(this_player()->query_real_name()==who ||
       this_player()->query_name()==who) {
      write("GET REAL!!!!\n");
      say(this_player()->query_name() + " tried to gag "
          +this_player()->query_objective()+"self but failed.\n");
      return 1;
    }
 
    who1 = lower_case(who);
    who2 = find_living(who);
 
    if(!(present(who1, this_object())) || !find_living(who)) {
      write("There is no such living here.\n");
      say(this_player()->query_name() + " get the gag ready with a smile "
          +this_player()->query_possessive()+ " face.\n");
      return 1;
    }
 
    if(who2->query_level() > 19 && !(who2->query_npc())) {
      write("WHO DO YOU THINK YOU ARE???\n");
	command("blush",this_player());
      return 1;
    }
    
    ob1 = first_inventory(who2);
    while(ob1) {
      if(ob1->query_info()=="this_person_is_gagged") {
        done = 1;
      }
      ob1 = next_inventory(ob1);
    }
 
    if(done) {
      write(who2->query_pronoun() + " was already gagged!\n");
      say(this_player()->query_name() + " checks that " +capitalize(who)+ 
     " really is gagged, and cackles with glee.\n");
      return 1;
    }
 
    else {
      move_object(clone_object("players/animal/elec/gag"), who2);
      write("You gag " +who+ ".\n");
      say(this_player()->query_name() + " grins evilly"+
          " and gags " +capitalize(who)+ ".\n");
      return 1;
    }
  }
}
 
 
do_read(str) {
 
  if(str=="note") {
    cat("/players/animal/elec/fry_note");
    say(this_player()->query_name() + " reads the note.\n");
    return 1; }
 
  if(str=="paper") {
    cat("/log/animal_fried");
    say(this_player()->query_name() + " reads the paper.\n");
    return 1; }
 
  return;
}
 
 
dead_man() {
  string ob_name;
  int will_be_fried;
  object victim, ob1, ob2, ob;
  
  ob1 = first_inventory(this_object());
  while(ob1) {
    if(living(ob1)) {
      ob2 = first_inventory(ob1);
      while(ob2) {
        if(ob2->query_info()=="will_die") {
          ob = ob2;
          will_be_fried = 1;
        }
        ob2 = next_inventory(ob2);
      }
    }
    ob1 = next_inventory(ob1);
  }
 
  if(will_be_fried && empty != 1) {
    write("This has already been done.\n");
    write(ob->query_name() + " is waiting to be fried.\n");
    return 1;
  }
}
 
 
undo_strap(str) {
  string who, who1, who2, strap;
  object ob, ob1, ob2;
  int done;
  
  if(sscanf(str, "%s from %s", strap, who1)!= 2) {
    write("Try 'remove straps from <victim>'.\n");
    return 1;
  }
  
  else {
    who2 = lower_case(who1);
    who = find_living(who1);
    who1 = capitalize(who1);
 
    if(!who || !(present(who2, this_object()))) {
      write("What do you think, you are doing? There is no such living"+
          " here.\n");
      say(this_player()->query_name() + " tried to remove the straps from "
+capitalize(who1)+".\n");
      return 1;
    }
    
    if(this_player()->query_level() < 20 && !(this_player()->query_npc()) &&
       (who1 != this_player()->query_real_name() ||
       who1 != this_player()->query_name())) {
      write("You are too weak to do that!\n");
      say(this_player()->query_name()+ " tried to remove the straps but"+
          "couldn't lift it more than an inch.\n",this_player());
	command("sulk",this_player());
      return 1;
    }
    
    ob = first_inventory(who);
    while(ob) {
      if(ob->query_info()=="will_die") {
        done = 1;
        ob1 = ob;
      }
      ob = next_inventory(ob);
    }
 
    
    if(done) {
      destruct(ob1);
 
      if(who1!=this_player()->query_name() ||
          who1->this_player()->query_real_name()) {
        write("You feel sorry for " +capitalize(who1)+ " and free "
+who->query_objective()+ " from the chair.\n");
        say(this_player()->query_name()+ " feels sorry for " +capitalize(who1)+
          " and frees " +who->query_objective()+
           " from the chair.\n",this_player());
 
        if(random(2)==1) {
          who->force_us("spit " +lower_case(this_player()->query_name()));
          who->force_us("say I should try and kill you now, asshole!!!\n");
        }
        
        else {
          who->force_us("hug" +lower_case(this_player()->query_name()));
          who->force_us("say Thanks " +this_player()->query_name()+ "!\n");
      }
 
        return 1;
      }
 
      else {
        write("You remove the straps.\n");
        say(who->query_name() + " removes the straps.\n");
        return 1;
      }
    }
  }
}
 
 
do_strap(str) {
  string who, who1, who2, rope;
  object ob, ob1, ob2;
  int done;
  
  if(sscanf(str, "%s to %s", rope, who1) != 2) {
    write("Try 'strap straps to <victim>'.\n");
    return 1;
  }
  
  else {
    who2 = lower_case(who1);
    who = find_living(who1);
    if(!empty) { 
      write("Energize the chair first by pushing the breaker.\n");
      return 1; 
    }
    
    if(!find_living(who1) || !(present(who2, this_object()))) {
      write("What are you doing? There is no " +capitalize(who1)+ " here.\n");
      say(this_player()->query_name() + " tried to strap in "
     +this_player()->query_possessive()+ " mother-in-law.\n");
      return 1;
    }
    
    if(who->query_level() > 19) {
      write("You might hate "+capitalize(who1)+ ", but you still ");
      write("don't have the heart to do that!\n");
      say(this_player()->query_name() +" look at "+ capitalize(who1)+
          " with a look of hate and wants to fry "+capitalize(who1)+".\n"+
      "But, " +this_player()->query_possessive() + " decides not to do it "+
      " and "+this_player()->query_pronoun()+"  refuses to strap "   
          +who->query_name()+" in the chair.\n");
      return 1;
    }
 
    if(this_player()->query_npc()!=1 && this_player()->query_level() < 20 &&
       !((who1 == this_player()->query_real_name()) ||
         who1 == this_player()->query_name())) {
      write("You are not allowed to do that!!\n");
      say(this_player()->query_name() + " tried to fry " +capitalize(who1)+
 ". But the thought of death gets "+this_player()->query_objective()+
     " to change "+this_player()->query_possessive()+ " mind.\n");
      return 1;
    }
 
    ob = first_inventory(this_object());
    while(ob) {
      ob1 = first_inventory(ob);
      while(ob1) {
        if(ob1->query_info()=="will_die") {
          done = 1;
          ob2 = ob;
        }
        ob1 = next_inventory(ob1);
      }
      ob = next_inventory(ob);
    }
    
    if(done) {
      write("This has already been done?\n");
      write(ob2->query_name() + " is waiting to be fried.\n");
      say(this_player()->query_name()+ " secured the straps to "
          +ob2->query_name() + "'s body.\n");
      return 1;
    }
    
    else {
      move_object(clone_object("players/animal/elec/to_be_fried"), who);
 
      if(ob2==this_player() || who1 == this_player()->query_name() ||
         this_player()->query_real_name()== who1) {
        write("You sigh heavily and strap yourself to the chair.\n");
        say(this_player()->query_name()+ " moans about something, and straps "
    +this_player()->query_possessive()+ "self to the chair.\n",this_player());
      }
 
      else {
	command("grin",this_player());
        write("You strap " +capitalize(who1)+ " to the CHAIR.\n");
        say(this_player()->query_name() + " straps " +capitalize(who1)+
          " to the CHAIR.\n",this_player());
 
        if(random(2)==1) {
          who->force_us("cry");
         who->force_us("say Why me? Please forgive me! I am wimp and"+
          " a no good mortal, but I promise to be good from now on!\n");
        }
 
        else {
          who->force_us("say Make my day. Burn in hell, scum!\n");
          who->force_us("spit " +lower_case(this_player()->query_name()));
        }
      }
    }
 
    if(random(2)==1) {
      tell_object(who, "You fear you are in deep SH*T!\n");
    }
 
    else {
      tell_object(who, "Maybe you should grovel like a pig?\n");
    }
    
    return 1;
  }
}
 
