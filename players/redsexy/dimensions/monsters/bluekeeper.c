inherit "obj/monster";

#include "/players/redsexy/defs.h"
#include "/players/redsexy/dimensions/defs.h"
#include "/players/redsexy/dimensions/quest/bluetest"

int q1, q2;
object taker;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("The Blue Keeper");
  set_alias("keeper");
  set_short("The Blue Keeper");
  set_long("The Blue Keeper is the ancient master of the blue dimension. Clothed\n" +
	   "entirely in blue, he sits silently, his eyes watching you with suspicion.\n");
  set_race("dimensioneer");
  set_level(80);
  set_gender(1);
  set_no_fight(1);
  set_prevent_poison(1);
}

init() {
  ::init();
  add_action("take", "take");
}

no_clean_up() {
    return 1;
}

hit_player(arg) {
  object att;
  att = TO->query_attack();
  if(att && present(att, ENV(TO))) {
    tell_room(ENV(TO), "The Blue Keeper says: Attack me not, Mortal.\n");
    return 1;
  }
  return 1;
}

take(arg) {
    if(TPL > 5) {
	      do_test();
	      return 1;
    write("You are not knowledgable enough to take the test.\n");
    return 1;
 }
}

do_test() {
  if(taker) {
    write("Someone is already taking the Test.\n");
    return 1;
  }
  write("The Blue Keeper says: You are now ready to take the test of the blue domain.\n");
  write("All that is required is that you answer my questions correctly.\n");
  taker = TP;
  q1 = random(QUIZ_SIZE);
  q2 = random(QUIZ_SIZE);
  while(q2 == q1) q2 = random(QUIZ_SIZE);
  write("The Blue Keeper asks:\n" + quiz_list[q1][0] + "\n");
  write("Your answer: ");
  input_to("answer1");
  return 1;
}

answer1(arg) {
  if(arg == quiz_list[q1][1] || arg == quiz_list[q1][2] ||
     arg == CAP(quiz_list[q1][1]) ||
     arg == CAP(quiz_list[q1][2])) {
    write("The Blue Keeper says: That is correct.\n");
    write("The Blue Keeper asks:\n" + quiz_list[q2][0] + "\n");
    write("Your answer: ");
    input_to("answer2");
    return 1;
  }
  write("The Blue Keeper says: That is not the correct answer.\n");
  write("The Blue Keeper says: You must study the blue domains more carefully.\n");
  lose();
  return 1;
}

answer2(arg) {
  object blueob;
  if(arg == quiz_list[q2][1] || arg == quiz_list[q2][2] ||
     arg == CAP(quiz_list[q2][1]) ||
     arg == CAP(quiz_list[q2][2])) {
     write("The Blue Keeper says: You have answered both questions correctly.\n");
     write("The Blue Keeper says: Well done...\n");
     win();
     return 1;
}
  write("The Blue Keeper says: That is not the correct answer.\n");
  write("The Blue Keeper says: You must study the blue domain more carefully.\n");
  lose();
  return 1;
}


lose() {
  taker = 0;
  q1 = 0;
  q2 = 0;
  return 1;
}

win() {
  object blueobj;
  taker = 0;
  q1 = 0;
  q2 = 0;
  blueobj = clone_object("players/redsexy/dimensions/quest/trial");
  transfer(blueobj, this_player());
  blueobj->set_type("blue");
  return 1;
}