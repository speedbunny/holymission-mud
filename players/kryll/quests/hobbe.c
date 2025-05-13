inherit "/obj/monster";

#define MILL "/players/kryll/quest/hobbe/path4";

static mixed *quest_info;
static string cause_alias, item_alias;
static string last_solver, *current_questor;

// PROTOTYPES
private static void reset_quest();
private static void set_quest();

private static void reset_quest() {
  quest_info[0]->set_has_cause(0);
  quest_info[0]->set_cause_desc("");
  quest_info[0]->set_cause_ids(0);
  quest_info[5]->set_has_item(0);
  quest_info[5]->set_item_desc(0);
  current_questor = ({});
}

private static void set_quest() {
  string *tmp;

  quest_info[0]->set_has_cause(1);
  quest_info[0]->set_cause_desc(quest_info[2]);
  quest_info[0]->set_cause_ids(quest_info[3]);
  quest_info[5]->set_has_item(1);
  quest_info[5]->set_item_desc(quest_info[4]);
  tmp = explode(quest_info[1], ":");
  cause_alias = tmp[0];
  item_alias = tmp[1];
}

void reset(int arg){
  ::reset(arg);

  if(file_name(ENV(TO)) != MILL)
    call_out("go_home", 5);

  if(!quest_info) {
    quest_info = QUEST_ROOM->query_hobbe_info();
    set_quest();
  }

  if(MILL->query_has_solved()==1) {
    MILL->set_has_solved(0);
    quest_info = QUEST_ROOM->query_hobbe_info();
    set_quest();
  }

  if(arg) return;

  set_name("Hobbe, the miller");
  set_alias_list(({ "hobbe", "Hobbe", "miller" }));
  set_race("hobbit");
  set_short("Hobbe, the miller");
  set_long("Hobbe is an old, nearly blind hobbit. He looks quite feeble "+
    "and you wonder how he could run his mill. If you want to know "+
    "something, just ask him about it.\n");
  set_gender(1);
  set_level(15);

  last_solver = 0;
}
   
void init() {
  ::init();
  add_action("_ask", "ask");
  add_action("_show", "show");
  add_action("_give", "give");
}

int catch_tell(string str) {
  string name, words;

  if(sscanf(str, "%s says: cause is %s", name, words)==2)
     || sscanf(str, "%s says: the cause is %s", name, words)==2) {
    answer2(name, words);
    return 1;
  }
  return 0;
}

status _ask(string str) {
  string what;

  if(sscanf(str, "Hobbe about %s", what)!=1 &&
     sscanf(str, "hobbe about %s", what)!=1) {
    notify_fail("Ask who about what?\n");
    return 0;
  }

  what = lower_case(what);
  TELLR(ENV(TO), TP->NAME + " asks Hobbe about " + what + ".\n", TP);
  answer(what);
  return 1;
}

status _show(string str) {
  string what;
  object ob;

  if(sscanf(str, "hobbe the %s", what)!=1 &&
     sscanf(str, "hobbe %s", what)!=1) {
    notify_fail("Show hobbe the what?\n");
    return 0;
  }

  if(!(ob=present(what,TP)) {
    command("say But you do not have a " + what + ".", TO);
    return 1;
  }

  if(ob->id("Hobbe_quest_item") && lower_case(creator(ob))=="kryll" &&
     ob->id(item_alias) && ob->query_quest_item() &&
     !TP->query_quest("hobbe")) {
    command("say Congratulations " + TP->NAME + "! And thank you "+
      "for fixing my mill! Now here is the reward I promised you.", TO);
    write("Hobbe hands you some money.\n");
    say("Hobbe hands " + TP->NAME + " some money.\n", TP);
    MILL->set_has_solved(1);
    last_solver = CAP(TP->RNAME);
    TP->add_quest("hobbe");
    TP->add_exp(1500);
    TP->add_money(4000);
    reset_quest();
    return 1;
  }

  command("say I have no interest in your " + what + ".", TO);
  return 1;
}

private static void answer(string str) {
  switch(str) {
    case "quest" :
      if(file_name(ENV(TO)) != MILL)
        command("say I need to be at the mill before I can tell "+
          "you about it.", TO);
      else if(MILL->query_has_solved()) {
        if(last_solver)
          command("say My quest was last solved by " + last_solver + 
            ". I'm so happy my mill works now!", TO);
        else 
          command("say I'm so happy my mill works now!", TO);
      }
      else {
        command("say My quest is to help my mill work again.", TO);
        switch(cause_alias) {
          case "boulder" :
          case "tree" :
            command("say Something seems to have blocked the water "+
              "upstream somewhere. Could you find out what is causing "+
              "it and then come back here and say what \"the cause "+
              "is\"?", TO);
            break;
          case "branch" :
          case "rope" :
          case "rust" :
            command("say The millstone isn't working. Either something "+
              "is wrong with it or the wheel. Could you find out what "+
              "is wrong and come back here and say what \"the cause "+
              "is\"?", TO);
            break;
          case "spell" :
            command("say Something very odd is wrong here. I am not sure "+
              "what it is but can you see if you find anything and then "+
              "come back and say what \"the cause is\"?", TO);
            break;
        }
      }
      break;
    case "mill" :
      command("say My grandfather built the mill many years ago.", TO);
      break;
    case "wheel" :
      if(file_name(ENV(TO)) != MILL)
        command("say I do not believe I am at the mill.", TO);
      else if(MILL->query_has_solved()) {
        if(last_solver)
          command("say Isn't it working nicely? " + last_solver + 
            " fixed it quite nicely, don't you think?", TO);
        else
          command("say Isn't it working nicely?", TO);
      }
      else
        command("say It is not working. Will you help fix it?", TO);
      break;
    case "daughter" :
      switch(random(5)) {
        case 0 :
          command("say Why are you looking for her? I won't let you "+
            "hurt her!", TO);
          break;
        case 1 :
          command("say She is the spitting image of her mother. I miss "+
            "her very much.", TO);
          break;
        case 2 :
          command("say My daughter is not married as of yet. I hope "+
            "she finds someone before she gets TOO old.", TO);
          break;
        case 3 :
          command("say Have you seen a picture of her? She's quite "+
            "beautiful, isn't she?", TO);
          break;
        case 4 :
          command("say My daughter hasn't lived here in quite some time. "+
            "The last I heard was that she moved to Calanport.", TO);
          break;
      }
      break;
    case "hobbe" :
      command("say I am nothing special. I've lived here all my life.", TO);
      break;
  }
}

private static void answer2(string name, string what) {
  if(member_array(what, quest_info[0]->query_cause_ids()) == -1) {
    write("You don't believe that is the correct answer after all.\n");
    return;
  }
  commmand("say So the problem has to do with " + cause_alias +
    ", eh? Then if you could get my special " + item_alias +
    " and take care of the problem, i'll reward you my friend. "+
    "Just come back to me and \"show me the item\".", TO);
  current_questor += name;
}

unhappy() {
   SAY( "Hobbe scratches his head thinking.\n" );
   call_out("unhappy1", 3);
}

unhappy1() {
   SAY( "Hobbe says: Do you understand why the wheel doesn't turn?\n" );
   call_out("unhappy2", 2);
}

unhappy2(){
   SAY("Hobbe bursts into tears!\n");
   call_out("unhappy3", 4);
}

unhappy3(){
   SAY("Hobbe says: I wish that I could find somebody to help me.\n");
}


happy(){
   SAY("Hobbe smiles brightly.\n");
   call_out("happy1", 3);
}

happy1(){
   SAY("Hobbe flips head over heels.\n");
   call_out("happy2", 2);
}

happy2(){
   SAY("Hobbe takes your hands and dances around with you.\n");
}

solved(){
   SAY("Hobbe says: I see, there is someone who helped me.\n");
   call_out("solved1", 3);
}

solved1(){
   SAY("Hobbe flips head over heals.\n");
   call_out("solved2", 2);
}

solved2(){
   SAY("Hobbe scratches himself thinking.\n");
   call_out("solved3", 4);
}

solved3(){
   SAY( "Hobbe says: I wish that the person who helped me could show me the tool\n" +
        "            with which the mill was repaired.\n" );
}

