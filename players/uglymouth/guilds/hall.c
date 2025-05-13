inherit "room/room";
#include "/sys/levels.h"

string *app_list;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "The Hall of Learning";
  long_desc = "This is the Hall of Learning. It's a high circular hall, built of\n"
    + "red veined white marble. It's the central meeting point for apprentice\n"
    + "wizards. Many doors give access to each apprentice wizard's studyroom,\n"
    + "where (s)he can study in peace and quiet. Don't forget to 'sign out'\n"
    + "before you quit.\n";
  dest_dir = ({
    "/room/wiz/coding_room", "west",
    "/players/uglymouth/guilds/study", "study",
  });
  items = ({
    "hall", "A big impressive hall",
    "marble", "First quality white marble",
    "doors", "Simple wooden doors with a label 'study' on them",
    "label", "It says: 'study'",
  });
  smell = "Fresh air clears your brain.\n";
  app_list = allocate(0);
}

void init() {
  ::init();
  add_action("dump_list", "read");
  add_action("sign_out", "sign");
}

int move(string str) {
  int nr;
  object study;
  if(query_verb() != "study") return ::move(query_verb());
  if(this_player()->query_level() != L_APPR) {
    notify_fail("You are not an apprentice wizard.\n");
    return 0;
  }
  if(!app_list ||
     nr = member_array(this_player()->query_real_name(), app_list) == -1) {
    study = clone_object("/players/uglymouth/guilds/study");
    app_list += ({ this_player()->query_real_name() });
    app_list += ({ explode(file_name(study), "#")[1] });
    write("You sign in for a studyroom. Don't forget to 'sign out' before you quit.\n");
    write("Use 'help study' to list the options of your studyroom.\n");
  }
  else {
  if(!study = find_object("/players/uglymouth/guilds/study#"+app_list[nr+1])) {
    study = clone_object("/players/uglymouth/guilds/study");
    app_list[nr+1] = explode(file_name(study), "#")[1];
  }
  }
  write("Peace and quiet envellop you as you enter your study.\n");
  say(this_player()->query_name()+" enters one of the studyrooms.\n");
  move_object(this_player(), study);
  return 1;
}

int dump_list(string str) {
  int i;
  if(str != "list") return 0;
  if(!sizeof(app_list)) {
    write("No one is using the studyrooms right now.\n");
    return 1;
  }
  for(i=0; i<sizeof(app_list); i+=2) {
    write(capitalize(app_list[i])+"\n");
  }
  printf("%d Aprentice wizard%s using the studyrooms.\n", i/2, i/2==1 ? " is" : "s are");
  return 1;
}

int sign_out(string str) {
  int nr;
  if(str != "out") return 0;
  if(nr = member_array(this_player()->query_real_name(), app_list) == -1) {
    notify_fail("You don't have a studyroom.\n");
    return 0;
  }
  destruct(find_object("/players/uglymouth/guilds/study#"+app_list[nr+1]));
  app_list = del_array(app_list, nr+1);
  app_list = del_array(app_list, nr);
  write("You sign out. Your studyroom is made free again.\n");
  return 1;
}

string query_nr(string app) {
  int nr;
  nr = member_array(app, app_list);
  if(nr == -1) return 0;
  return app_list[nr+1];
}
