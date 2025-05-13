inherit "obj/monster";
#define NUM_STATS 6
#define KBL "/players/kbl/guild/"
#define KBLI "/players/kbl/instruments/"
#define TPRN this_player()->query_real_name()
#define KBLH "/players/kbl/guild/helpdir/"
#define MAXDIR 58
int j;  /* counter for movement */

string function,match,type,parser,dirs;
string walk;
int gd,place;
int tried;
object notebook;

/* CHK_LEAVE cannot be used from the guild/room */
/* LIST accesses the questroom directly due to numberconversion */

reset(arg) {
object voorwerp;

  ::reset(arg);
  if(!arg) {
    set_name("taliesin");
    set_short("Taliesin the Master Harper (saintly)");
    set_alias("wander");
    set_alt_name("wander");
    set_al(1000);
    set_heart_beat(1);
    set_long("This is Taliesin the 'leader' of the Guild of Bards.\n"
           + "He's wandering around the country, looking for people\n"
           + "who want to become a wandering Bard like he is.\n"
           + "I don't think you could kill him.\n");
    set_size(3);
    set_level(120);
    set_race("human");
    set_ac(80);
    set_wc(90);
    set_male();
    set_whimpy();
    function=({"handle_leaving","handle_tell","handle_gives"});
    tried = allocate(MAXDIR);
    type=({"leaves","tells you:","gives"});
    match=({"","",""});
    set_match(this_object(),function,type,match);
    set_prevent_poison(1);
    load_chat(5,({
      "Taliesin says: The Guild of Bards is for the real players.\n",
      "Taliesin plays a beautiful melody on his harp.\n",
      "Taliesin smiles at you.\n",
      "Taliesin sings the song of king Uther.\n",
      "Taliesin says: Learn to sing as a bird.\n",
      "Taliesin dances with a unseen partner!\n",
      "Taliesin sings in Austrian.\n",
      "Taliesin looks at you.\n",
      "Taliesin says: If you want a tag, just ask me to give one.\n"}));
    walk = ({"north","southeast","northeast","out","exit","west","south",
             "north","southwest","northwest","out","exit","west","south",
             "north","south","east","west","southwest","southeast",
             "north","south","east","west","northwest","northeast",
             "southwest","northeast","southeast","northwest","laugh",
             "southwest","northeast","southeast","northwest","laugh",
             "sing Just like heaven","smile","dance","yawn","giggle",
             "sing Just like heaven","smile","dance","yawn","giggle",
             "east","northeast","southwest","south",
             "read tag","look","portal",
             "sing Civil war","giggle","snicker","smile","dance",
            });
    load_chat(5,({
      "Taliesin says: Don't you know that attacking me is useless?\n",
      "Taliesin plays a fearful melody on his harp.\n",
      "Taliesin pokes his opponent in the ribs.\n",
      "Taliesin sings the song of the death of king Uther.\n",
      "Taliesin estimates you.\n"}));
    gd = "players/kbl/guild/room"->query_guild();
    if(!present("harp",this_object())) {
      voorwerp = clone_object("obj/soul");
      move_object(voorwerp,this_object());
      voorwerp = clone_object(KBLI+"harp");
      voorwerp->set_creator("taliesin");
      move_object(voorwerp,this_object());
      voorwerp=clone_object("players/kbl/guild/tinyharp");
      move_object(voorwerp,this_object());
      notebook = clone_object("players/kbl/guild/notebook");
      move_object(notebook,this_object());
      init_command("wear harp");
      voorwerp = clone_object("players/kbl/objs/tag");
      move_object(voorwerp,this_object());
    }
    enable_commands();
  }
}

init() {
  ::init();
  add_action("say_it","say");
  add_action("say_it","'",1);
}
  
heart_beat()
{
object o;
int i,nowalk;

  ::heart_beat();
  j++;
  o=all_inventory(environment(this_object()));
  for(i=0; i<sizeof(o); i=i+1) {
    if((living(o[i]))&&(o[i]->query_guild()==gd)
      &&(o[i]->query_spend_points())) {
    }
  }
  if(!nowalk && j>10)
  {
    ok_move();
    j=0;
  }
}

ok_move() {
  int dir,ct,flag;

  ct=0;
  while(!flag && ct<90)
  {
    ct++;
    dir = random(MAXDIR);
    while(tried[dir] == 1)
      dir = random(MAXDIR);
    flag = command(walk[dir],this_object());
    if(flag)
     for(dir=0;dir<MAXDIR;dir++)
      tried[dir] = 0;
    else
      tried[dir] = 1;
    ck_zero();
  }
}

ck_zero()
{
  int i;
  int tot;

  for(i=0;i<MAXDIR;i++)
   if(tried[i] == 1)
    tot++;
  if(tot > MAXDIR-5)
   for(i=0;i<MAXDIR;i++)
     tried[i] = 0;
}

set_place(i) {
  place=i;
}

query_place() {
  return place;
}

run_away()
{
  say("Taliesin plays a tune on his Harp. He seems healthier now.\n");
  heal_self(500);
}

handle_tell(str) {
string who,phrase;

  if(sscanf(str,"%s tells you: %s\n",who,phrase)!=2) return;
  if(environment(this_player())!=environment()) {
    tell_object(this_player(),"Taliesin tells you: Please come here if it's important.\n My surroundings are "+lower_case(environment(this_object())->short())+"\n");
    return;
  }
  say_text("Please don't tell me, just say it!");
  return;
}

notify(str) {
object o;
int i;

 o=all_inventory(environment(this_object()));
  for(i=0; i<sizeof(o); i=i+1) {
    if((living(o[i]))&&(o[i]!=this_player())) {
      tell_object(o[i],str);
    }
  }
  return;
}

say_text(str) {
  tell_room(environment(this_object()),"Taliesin says: "+str+"\n");
}

say_it(str) {
int i,number;
string lphrase,bits,split,verb;

  verb=query_verb();
  if(str==0) str="";
  if(verb[0]=="'"[0]) str=extract(verb,1)+" "+str;
  notify(this_player()->query_name()+" says: "+str+"\n");
  write("You say: "+str+"\n");
  log_file("taliesin",this_player()->query_name()+": "+str+"\n");
  lphrase=" "+lower_case(str)+" ";
  if(lphrase=="  ") return 1;
  split=explode(lphrase," ");
  bits="-";
  for(i=0; i<20; i=i+1) {
    bits=clear_bit(bits,i);
  }
  for(i=0; i<sizeof(split); i=i+1) {
    switch(split[i]) {
      case "help": bits=set_bit(bits,0); break;
      case "info": bits=set_bit(bits,0); break;
      case "information": bits=set_bit(bits,0); break;
      case "cost": bits=set_bit(bits,1); break;
      case "advance": bits=set_bit(bits,2); break;
      case "con": bits=set_bit(bits,3); break;
      case "constitution": bits=set_bit(bits,3); break;
      case "dex": bits=set_bit(bits,4); break;
      case "dexterity": bits=set_bit(bits,4); break;
      case "int": bits=set_bit(bits,5); break;
      case "intelligence": bits=set_bit(bits,5); break;
      case "str": bits=set_bit(bits,6); break;
      case "strength": bits=set_bit(bits,6); break;
      case "wis": bits=set_bit(bits,7); break;
      case "wisdom": bits=set_bit(bits,7); break;
      case "chr": bits=set_bit(bits,8); break;
      case "charisma": bits=set_bit(bits,8); break;
      case "level": bits=set_bit(bits,9); break;
      case "list": bits=set_bit(bits,10); break;
      case "quest": bits=set_bit(bits,10); break;
      case "quests": bits=set_bit(bits,10); break;
      case "join": bits=set_bit(bits,11); break;
      case "spend": bits=set_bit(bits,12); break;
      case "points": bits=set_bit(bits,13); break;
      case "hello": bits=set_bit(bits,14); break;
      case "hallo": bits=set_bit(bits,14); break;
      case "hi": bits=set_bit(bits,14); break;
      case "give" : bits=set_bit(bits,15); break;
      case "notebook" : bits=set_bit(bits,16); break;
      case "guild" : bits=set_bit(bits,17); break;
      case "bards" : bits=set_bit(bits,17); break;
      case "tag" : bits=set_bit(bits,18); break;
      case "really" : bits=set_bit(bits,19); break;
    }
    if(!number)
     number = "players/kbl/guild/room"->numberer(split[i]);
  }
  if(test_bit(bits,14)) say_text("Hello, "+this_player()->query_name()+"!");
  if(test_bit(bits,0)) {
    if(test_bit(bits,1)) do_it("do_help","cost");
    if(test_bit(bits,2)) do_it("do_help","advance");
    if(test_bit(bits,10)) do_it("do_help","list");
    if(test_bit(bits,11)) do_it("do_help","join");
    if(test_bit(bits,12)) do_it("do_help","spend");
    if(test_bit(bits,13)) do_it("do_help","points");
    if(test_bit(bits,17)) help_bard();
    if(test_bit(bits,18)) help_tag();
    return 1;
  }
  if(test_bit(bits,1)) do_it("do_cost");
  if(test_bit(bits,2)) {
    if(test_bit(bits,3)) do_it("do_advance","con");
    if(test_bit(bits,4)) do_it("do_advance","dex");
    if(test_bit(bits,5)) do_it("do_advance","int");
    if(test_bit(bits,6)) do_it("do_advance","str");
    if(test_bit(bits,7)) do_it("do_advance","wis");
    if(test_bit(bits,8)) do_it("do_advance","chr");
    if(test_bit(bits,9)) do_it("do_advance","level");
  }
  if(test_bit(bits,10)) do_it("list",number);
  if(test_bit(bits,11)) {
    if(test_bit(bits,19)) do_it("do_join");
    if(!test_bit(bits,19)) {
      say_text("Are you sure? You'll be bound to the guild forever, and it's\n"
             + "not the strongest one. Say that you really want to join if\n"
             + "you really want to join.\n");
    }
  }
  if(test_bit(bits,12)) {
    if(test_bit(bits,3)) do_it("do_spend","con");
    if(test_bit(bits,4)) do_it("do_spend","dex");
    if(test_bit(bits,5)) do_it("do_spend","int");
    if(test_bit(bits,6)) do_it("do_spend","str");
    if(test_bit(bits,7)) do_it("do_spend","wis");
    if(test_bit(bits,8)) do_it("do_spend","chr");    
  }
  if(test_bit(bits,13)) do_it("do_point");
  if((test_bit(bits,15))&&(test_bit(bits,18))) give_tag();
  if((test_bit(bits,15))&&(test_bit(bits,16))) give_notebook();
  return 1;
}

do_it(commando,argument) {
  write("Taliesin whispers to you:\n");
  notify("Taliesin whispers something to "
       + this_player()->query_name()+".\n");
  if(commando=="list") {
    if(!argument) "room/quest_room"->count();
    if(argument) "room/quest_room"->list(argument);
    return;
  }
  call_other("players/kbl/guild/room",commando,argument);
  return;
}

handle_leaving(str) {
string who,rest,x_who;
object walker;

  if(sscanf(str,"%s leaves %s.",who,rest)!=2) return;
  if(who=="Taliesin") return;
  x_who=explode(who," ");
  who=x_who[sizeof(x_who)-1];
  walker=find_living(lower_case(who));
  if(!walker) return;
  if(chk_leave(walker)) init_command(rest);
  return;
}

chk_leave(who) {
int i,mlvl,r;

  r=0;
  mlvl="guild/master"->query_levels(gd);
  if(who->query_spend_points()) {
    for (i=0; i<NUM_STATS; i=i+1) {
	    if (who->query_stats(i)<mlvl) {
	      r=1;
	      break;
	    }
    }
  }
  if(!who->query_wizard() && r) {
    tell_object(who,
      "Taliesin tells you: Come back! You must spend points!\n");
    return 1;
  }
  return 0;
}

handle_gives(str) {
string who,rest,receiver,x_who;
object giver;

  if(sscanf(str,"%s gives %s to %s.",who,rest,receiver)!=3) return;
  if(who=="Taliesin") return;
  if(receiver!="Taliesin") return;
  x_who=explode(who," ");
  who=x_who[sizeof(x_who)-1];
  giver=find_living(lower_case(who));
  if(!giver) return;
  init_command("thank "+lower_case(who));
  init_command("play harp");
  init_command("drink "+lower_case(rest));
}

query_guild() {
  return gd;
}

help_bard() {
  say_text("The Guild of Bards is made for real role-players.\n"
         + "You won't get any very special abilities, you get, however,\n"
         + "the possibility to interact as a Bard. The Bard is primarily\n"
         + "a mind-changer, but also knows a lot about items in this\n"
         + "world.");
  say_text("They are friendly and wise. You can say to me what you\n"
         + "want to do: advance, join, spend, points, cost, or information\n"
         + "information on these commands.");
}

help_tag() {
  say_text("The tag is to see your current xp, the increase of it,\n"
         + "and how much you need for the next level. It's very useful,\n"
         + "and I give it to non-members too!");
}

give_tag() {
object tag;
object tp;

  if(present("tag",this_player())) {
    say_text("But you already have a tag!");
    return 1;
  }
  tp = this_player();
  tag = clone_object("players/cashimor/objects/xp");
  transfer(tag,this_player());
  say_text("Taliesin looks at "+capitalize(tp->query_real_name())+".\n"
         + "Taliesin fetches something from another dimension.\n"
         + "Taliesin gives "+capitalize(tp->query_real_name())+" a tag.");
}

give_notebook() {
  if(this_player()->query_guild()!=gd) {
    say_text("I don't give the notebook to people not of my guild.");
    return 1;
  }
  if(present("notebook",this_object())) {
    move_object(notebook,environment(this_object()));
    say_text("Here you are.\nTaliesin drops the notebook.");
    return 1;
  }
  say_text("I'm sorry, but I don't have the notebook.\n"
         + "Taliesin thinks for a moment.");
  if(!notebook) {
    tell_room(environment(this_object()),
      "Taliesin fetches something from another dimension.\n");
    notebook = clone_object("players/kbl/guild/notebook");
    move_object(notebook,environment(this_object()));
    say_text("Here you are.\nTaliesin drops the notebook.");
    return 1;
  }
  if(present(notebook,this_player())) {
    say_text("But you have it already!");
    return 1;
  }
  if(present(notebook,environment(this_object()))) {
    say_text("It's lying at my feet!");
    return 1;
  }
  say_text("But I know it's near "
         + lower_case(environment(notebook)->short())+".");
}

show_stats() {
  write("Taliesin is the leader of the guild of Bards, and is the\n"
      + "place of communication between the guildroom and the players.\n"
      + "He is a male human bard and he has "+hit_point+" hitpoints.\n");
}
