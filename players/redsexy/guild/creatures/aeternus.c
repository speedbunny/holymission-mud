inherit "obj/monster";

#include "/players/redsexy/defs.h"
#include "/players/redsexy/guild/text/questions"

int q1, q2;
object taker;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("aeternus");
  set_alias("guildmaster");
  set_short("Aeternus");
  set_long("Aeternus, the ancient Guildmaster of Summoners, is garbed\n" +
	   "entirely in black. He sits silently, a dark hood concealing\n" +
	   "his face in shadow.\n");
  set_race("summoner");
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
    TELLR(ENV(TO), "Aeternus says: Attack me not, Mortal.\n");
    return 1;
  }
  return 1;
}

take(arg) {
  object water, wind, earth, fire;
  if(arg == "test" || arg == "the test") {
    water = present("watertrial", TP);
    wind = present("windtrial", TP);
    earth = present("earthtrial", TP);
    fire = present("firetrial", TP);
    if(TP->query_guild() != SUMM) {
      if(water) {
	if(wind) {
	  if(earth) {
	    if(fire) {
	      do_test();
	      return 1;
	    }
	    write("Aeternus says: You must first complete the " +
		  "Trial of Fire.\n");
	    return 1;
	  }
	  write("Aeternus says: You must first complete the " +
		"Trial of Earth.\n");
	  return 1;
	}
	write("Aeternus says: You must first complete the " +
	      "Trial of Wind.\n");
	return 1;
      }
      write("Aeternus says: You must first complete the " +
	    "Trial of Water.\n");
      return 1;
    }
    write("You do not need to take the Test.\n");
    return 1;
  }
}

do_test() {
  if(taker) {
    write("Someone is already taking the Test.\n");
    return 1;
  }
  write("Aeternus says: You are now ready to take the test.\n");
  write("All that is required is to answer my two questions correctly.\n");
  taker = TP;
  q1 = random(QUIZ_SIZE);
  while(q2 == q1) q2 = random(QUIZ_SIZE);
  write("Aeternus asks:\n" + quiz_list[q1][0] + "\n");
  write("Your answer: ");
  input_to("answer1");
  return 1;
}

answer1(arg) {
  if(arg == quiz_list[q1][1] || arg == quiz_list[q1][2] ||
     arg == CAP(quiz_list[q1][1]) ||
     arg == CAP(quiz_list[q1][2])) {
    write("Aeternus says: That is correct.\n");
    write("Aeternus asks:\n" + quiz_list[q2][0] + "\n");
    write("Your answer: ");
    input_to("answer2");
    return 1;
  }
  write("Aeternus says: That is not the correct answer.\n");
  write("Aeternus says: You must study the Lore more carefully.\n");
  done();
  return 1;
}

answer2(arg) {
  object water, wind, earth, fire;
  if(arg == quiz_list[q2][1] || arg == quiz_list[q2][2] ||
     arg == CAP(quiz_list[q2][1]) ||
     arg == CAP(quiz_list[q2][2])) {
    write("Aeternus says: You have answered both questions correctly.\n");
    write("Aeternus says: You may now join, if you wish.\n");
    water = present("watertrial", TP);
    wind = present("windtrial", TP);
    earth = present("earthtrial", TP);
    fire = present("firetrial", TP);
    destruct(water);
    destruct(wind);
    destruct(earth);
    fire->set_type("power");
    done();
    return 1;
  }
  write("Aeternus says: That is not the correct answer.\n");
  write("Aeternus says: You must study the Lore more carefully.\n");
  done();
  return 1;
}

done() {
  taker = 0;
  q1 = 0;
  q2 = 0;
  return 1;
}
