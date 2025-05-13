inherit "/room/room";

#include <obj.h>
#include <lw.h>
#include "/players/kryll/quest/quest_defs.h"
#include "/players/kryll/quest/hobbe_defs.h"

static object *quests;
mapping quest_info;

/* PROTOTYPES */
private static setup_quests();
void reset(int arg);
void init();
status quest_info(string str);
status who_solved(string str);
private static void setup_quests();
nomask void reset_quest(int val);
nomask private static string query_hobbe_trouble_location();
nomask private static string query_hobbe_cause(string str);
nomask private static string query_hobbe_cause_desc(string str);
nomask private static string *query_hobbe_cause_ids(string str);
nomask private static string query_hobbe_item(string str);
nomask private static string query_hobbe_item_location();
nomask mixed *query_hobbe_info();
nomask private static void set_hobbe_info();

void make_quests() {
  int i, sz;

  sz = sizeof(QUEST_LIST);
  quests = allocate(sz);
  for(i=0; i<sz; i++) {
    if(!quests[i]) {
      quests[i] = clone_object("/obj/quest_obj");
      quests[i]->set_name(INFO[i][0]);
      quests[i]->set_weight(INFO[i][1]);
      quests[i]->set_killing(INFO[i][2]);
      quests[i]->set_short_hint(INFO[i][3]);
      quests[i]->set_hint(INFO[i][4]);
      quests[i]->add_quest();
    }
  }
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "Kryll's personal questroom";
  long_desc =
    "Welcome to Kryll's personal questroom. This is where all his "+
    "quests are initialized and their randomness determined. To find "+
    "out about his current quests, type \"quest info\". To find out "+
    "more about a specific quest type \"quest <name_of_quest>\". To "+
    "find out who has solved the quest in the past 2 weeks, type "+
    "\"solved <name_of_quest> short\", else for a longer time span "+
    "type \"solved <name_of_quest> long\". Only wiz level and above "+
    "are permitted in this room, and your presence will be logged.\n";

  hidden_dir = ({
    "/players/kryll/workroom", "down",
  }),

  setup_quests();
}

void init() {
  if(!TP->query_wizard())
    write("You are not permitted in Kryll's quest room. Your attempt "+
            "will be logged!!!\n");
    command("vis", TP);
    command("shout I broke the law, and now I'm in prison!!\n", TP);
    command("shout I broke the law, and now I'm in prison!!\n", TP);
    write_file("/players/kryll/log/invasion", ctime() + " : " +
               TP->RNAME + "(" + TP->LVL + ") illegally tried to "+
               "enter the quest room\n");
    TP->MOVEP("into the prison#/room/prison");
    return;
  }

  write_file("/players/kryll/log/invasion", ctime() + " : " +
             TP->RNAME + "(" + TP->LVL + ") decided to "+
             "enter the quest room\n");

  add_action("quest_info", "quest");
  add_action("who_solved", "solved");
}

status quest_info(string str) {
  int i, sz;

  if(!TP->query_wizard())
    return 1;
  switch(member_array(str, QUEST_LIST)) {
    case HOBBE :
      
      break;
    case TROLLSLAYER :
      break;
    case FIRE_QUEST :
      break;
    default :
      if(str == "info") {
        printf("%-15s %6s\n", "Kryll's quest", "Solved");
        for(i=0, sz=sizeof(QUEST_LIST); i<sz; i++)
          printf("%-15s %6s\n", );
      }
      notify_fail("What quest info are you looking for?\n");
      return 0;
  }
}

status who_solved(string str) {
  if(!TP->query_wizard())
    return 1;
  switch(str) {

  }
}

private static void setup_quests() {
  if(!mappingp(quest_info))
    quest_info = ([]);

  set_hobbe_info();
//  set_trollslayer_info();
//  set_fire_quest_info();
}

nomask void reset_quest(int val) {
  if(PO->query_quest_object() || PO->RNAME=="kryll" || PO->query_archwiz()) {
    switch(val) {
      case HOBBE       : set_hobbe_info(); break;
      case TROLLSLAYER : set_trollslayer_info(); break;
      case FIRE_QUEST  : break;
    }
  }
}

// HOBBE QUEST FUNCTIONS
// Private function to randomly determine where the problem is.
nomask private static string query_hobbe_trouble_location() {
  switch(random(10)) {
    case 0    : return HOBBE_LOCATION5;
    case 1..2 : return HOBBE_LOCATION1;
    case 3..4 : return HOBBE_LOCATION2;
    case 5..6 : return HOBBE_LOCATION3;
    case 7    : return HOBBE_LOCATION6;
    case 8..9 : return HOBBE_LOCATION4;
  }
  return 0;
}

// Returns what is causing the problem.
nomask private static string query_hobbe_cause(string str) {
  switch(str) {
    case HOBBE_LOCATION1 :
    case HOBBE_LOCATION2 :
    case HOBBE_LOCATION3 :
      switch(random(5)) {
        case 0..1 : return HOBBE_CAUSE1;
        case 2..3 : return HOBBE_CAUSE2;
        case 4    : return HOBBE_CAUSE6;
      }
    case HOBBE_LOCATION4 :
      switch(random(7)) {
        case 0..1 : return HOBBE_CAUSE3;
        case 2..3 : return HOBBE_CAUSE4;
        case 4..5 : return HOBBE_CAUSE5;
        case 6    : return HOBBE_CAUSE6;
      }
    case HOBBE_LOCATION5 :
    case HOBBE_LOCATION6 :
      switch(random(7)) {
        case 0..1 : return HOBBE_CAUSE1;
        case 2..3 : return HOBBE_CAUSE2;
        case 4..5 : return HOBBE_CAUSE3;
        case 6    : return HOBBE_CAUSE6;
      }
  }
  return 0;
}

nomask private static string query_hobbe_cause_desc(string str) {
  switch(str) {
    case HOBBE_CAUSE1 : return HOBBE_CAUSE1_DESC;
    case HOBBE_CAUSE2 : return HOBBE_CAUSE2_DESC;
    case HOBBE_CAUSE3 : return HOBBE_CAUSE3_DESC;
    case HOBBE_CAUSE4 : return HOBBE_CAUSE4_DESC;
    case HOBBE_CAUSE5 : return HOBBE_CAUSE5_DESC;
    case HOBBE_CAUSE6 : return HOBBE_CAUSE6_DESC;
  }
  return 0;
}

nomask private static string *query_hobbe_cause_ids(string str) {
  switch(str) {
    case HOBBE_CAUSE1 : return HOBBE_CAUSE1_IDS;
    case HOBBE_CAUSE2 : return HOBBE_CAUSE2_IDS;
    case HOBBE_CAUSE3 : return HOBBE_CAUSE3_IDS;
    case HOBBE_CAUSE4 : return HOBBE_CAUSE4_IDS;
    case HOBBE_CAUSE5 : return HOBBE_CAUSE5_IDS;
    case HOBBE_CAUSE6 : return HOBBE_CAUSE6_IDS;
  }
  return 0;
}

nomask private static string query_hobbe_item(string str) {
  switch(str) {
    case HOBBE_CAUSE1 : return HOBBE_ITEM1;
    case HOBBE_CAUSE2 :
    case HOBBE_CAUSE3 : return HOBBE_ITEM2;
    case HOBBE_CAUSE4 : return HOBBE_ITEM4;
    case HOBBE_CAUSE5 : return HOBBE_ITEM3;
    case HOBBE_CAUSE6 : return HOBBE_ITEM5;
  }
  return 0;
}

nomask private static string query_hobbe_item_location() {
  switch(random(100)) {
    case 0 :
    default :
  }
  return 0;
}

nomask mixed *query_hobbe_info() {
  mixed *tmp;
  int   i, sz;

  if(!mappingp(quest_info))
    return 0;

  sz = sizeof(quest_info[QUEST_LIST[HOBBE]]);
  tmp = allocate(sz);
  for(i=0; i<sz; i++)
    tmp[i] = quest_info[QUEST_LIST[HOBBE]][i];
  return tmp;
}

nomask private static void set_hobbe_info() {
  mixed cause, tmp;

  if(!mappingp(quest_info))
    quest_info = ([]);

  quest_info[QUEST_LIST[HOBBE]] = allocate(6);
  tmp = query_hobbe_trouble_location();
  quest_info[QUEST_LIST[HOBBE]][0] = tmp;
  cause = query_hobbe_cause(tmp);
  quest_info[QUEST_LIST[HOBBE]][1] = cause;
  tmp = query_hobbe_cause_desc(cause);
  quest_info[QUEST_LIST[HOBBE]][2] = tmp;
  tmp = query_hobbe_cause_ids(cause);
  quest_info[QUEST_LIST[HOBBE]][3] = tmp;
  tmp = query_hobbe_item(cause);
  quest_info[QUEST_LIST[HOBBE]][4] = tmp;
  tmp = query_hobbe_item_location();
  quest_info[QUEST_LIST[HOBBE]][5] = tmp;
}

// TROLLSLAYER QUEST FUNCTIONS

