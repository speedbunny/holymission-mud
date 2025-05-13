#define ENV    environment
#define CAP    capitalize
#define TO     this_object()
 
inherit "/obj/monster";
 
// prototype
void do_shoot(string str);
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_short("Garglesnout");
  set_name("garglesnout");
  set_race("gnome");
  set_long("Garglesnout mans the catapult.\n");
  set_level(15);
 
  enable_commands();
}
 
int catch_tell(string str) {
  string name, words, tmp;
 
  if(sscanf(str, "%s tells you: %s\n", name, words) == 2) {
    tmp = lower_case(name) + "<>" + words;
    call_out("do_shoot", 1, tmp);
    return 1;
  }
  return 0;
}
 
void do_shoot(string str) {
  string str1, str2;
  object who_ob, cat;
 
  if(sscanf(str, "%s<>%s", str1, str2) != 2) 
    return;
  if(!(cat = present("catapult", ENV(TO)))) {
    tell_room(ENV(TO), CAP(TO->query_name()) +
              " looks around for the catapult.\n");
    return;
  }
 
  if(!(who_ob = find_player(str1)) || !interactive(who_ob)) {
    write("Who said that?\n");
    return;
  }
 
  if(!present(who_ob, cat)) {
    tell_object(who_ob, CAP(TO->query_name()) +
                " tells you: You must be in the "+
                "catapult if you wish to go to " + str2 + ".\n");
    return;
  }
 
// what is with all the random checks??
  switch(str2) {
    case "floor 1" :
      if(random(100) < 90) {
        tell_object(who_ob,
          "A Gnome activates the catapult FlINGGGGGGG\n\n"+
          "Suddenly the catapult throws you HIGH UP INTO THE AIR!!!!\n\n"+
          "With a speed of nearly 100 miles/hour, you crash against the "+
          "SECURITY NET!!\n");
        who_ob->move_player(
         "flying through the air#/players/emerald/island/room/g2");
        return;
      }
      if(random(100) < 95) {
        tell_object(who_ob,"A Gnome activates the catapult FlINGGGGGGG\n\n"+
          "Suddenly the catapult throws you HIGH UP INTO THE AIR!!!!\n\n"+
          "But SHIT!  You fly too short with a speed of nearly 100 "+
          "miles/hour.\n"+
          "You crash against the SECURITY NET one floor lower!!\n");
        who_ob->move_player(
          "flying through the air#players/emerald/island/room/g4");
        return;
      }
      tell_object(who_ob,"A Gnome activates the catapult FlINGGGGGGG\n\n"+
        "Suddenly the catapult throws you HIGH UP INTO THE AIR!!!!\n\n"+
         "But SHIT!  You fly too short with a speed of nearly 100 miles/hour\n"+
         "You crash against the SECURITY NET two floors lower!!\n");
      who_ob->move_player(
        "flying through the air#players/emerald/island/room/g8");
      return;
    case "floor 2" :
      if(random(100) < 90) {
        tell_object(who_ob,
          "A Gnome activates the catapult FlINGGGGGGG\n\n"+
          "Suddenly the catapult throws you HIGH UP INTO THE AIR!!!!\n\n"+
          "With a speed of nearly 100 miles/hour you crash against the "+
          "SECURITY NET!!\n");
        who_ob->move_player(
          "flying through the air#players/emerald/island/room/g4");
        return;
      }
      if(random(100) < 95) {
        return;
      }
      tell_object(who_ob,"A Gnome activates the catapult FlINGGGGGGG\n\n"+
        "Suddenly the catapult throws you HIGH UP INTO THE AIR!!!!\n\n"+
        "But SHIT!  You fly too wide with a speed of nearly 100 miles/hour\n"+
        "You crash against the SECURITY NET one floor higher !!\n");
      who_ob->move_player(
        "flying through the air#players/emerald/island/room/g2");
      return;
    case "floor 3" :
      if(random(100) < 90) {
        tell_object(who_ob,"A Gnome activates the catapult FlINGGGGGGG\n\n"+
          "Suddenly the catapult throws you HIGH UP INTO THE AIR!!!!\n\n"+
          "With a speed of nearly 100 miles/hour you crash against the "+
          "SECURITY NET!!\n");
        who_ob->move_player(
          "flying through the air#players/emerald/island/room/g8");
        return;
      }
      if(random(100) < 95) {
        tell_object(who_ob,"A Gnome activates the catapult FlINGGGGGGG\n\n"+
          "Suddenly the catapult throws you HIGH UP INTO THE AIR!!!!\n\n"+
          "But SHIT!  You fly too wide with a speed of nearly 100 miles/hour\n"+
          "You crash against the SECURITY NET one floor higher !!\n");
        who_ob->move_player(
          "flying through the air#players/emerald/island/room/g4");
        return;
      }
      tell_object(who_ob, "A Gnome activates the catapult FlINGGGGGGG\n\n"+
        "Suddenly the catapult throws you HIGH UP INTO THE AIR!!!!\n\n"+
        "But SHIT!  You fly too wide with a speed of nearly 100 miles/hour\n"+
        "You crash against the SECURITY NET two floors higher !!\n");
      who_ob->move_player(
        "flying through the air#players/emerald/island/room/g2");
      return;
 
    default :
      tell_object(who_ob, CAP(TO->query_name()) +
                  " tells you: But I cannot send you "+
                  "to " + str2 + ".\n");
      return;
  }
}
