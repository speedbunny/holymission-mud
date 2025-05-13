inherit "obj/monster";

#include "/players/redsexy/defs.h"
#include "/players/redsexy/dimensions/defs.h"
#include "/players/redsexy/dimensions/quest/finaltest"

int q1, q2, q3, q4, q5, q6, q7;
object taker;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Sophillicus");
  set_alias("sophillicus");
  set_short("Sophillicus");
  set_long("Sophillicus, the ancient master of the dimensions, is garbed\n" +
	   "entirely in black. He sits silently, a dark hood concealing\n" +
	   "his face in shadow.\n");
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
    TELLR(ENV(TO), "Sophillicus says: Attack me not, Mortal.\n");
    return 1;
  }
  return 1;
}

take(arg) {
  object red, orange, yellow, green, blue, indigo, violet;
  if(arg == "test" || arg == "the test") {
    red = present("redtrial", TP);
    yellow = present("yellowtrial", TP);
    orange = present("orangetrial", TP);
    green = present("greentrial", TP);
    blue = present("bluetrial", TP);
    indigo = present("indigotrial", TP);
    violet = present("violettrial", TP);

    if(TPL > 5) {
      if(red) {
       if(orange) {
	  if(yellow) {
	    if(green) {
           if(blue)  {
            if(indigo) {
             if(violet) {
	      do_test();
	      return 1;
	    }
	    write("Sophillicus says: You must first solve the test of the " +
		  "Violet domain.\n");
	    return 1;
	  }
	    write("Sophillicus says: You must first solve the test of the " +
		"Indigo domain.\n");
	  return 1;
	}
	    write("Sophillicus says: You must first solve the test of the " +
	      "Blue domain.\n");
	return 1;
      }
	    write("Sophillicus says: You must first solve the test of the " +
	    "Green domain.\n");
      return 1;
    }
	    write("Sophillicus says: You must first solve the test of the " +
	    "Yellow domain.\n");
      return 1;
   }
	    write("Sophillicus says: You must first solve the test of the " +
	    "Orange domain.\n");
      return 1;
  }
	    write("Sophillicus says: You must first solve the test of the " +
	    "Red domain.\n");
      return 1;
 } 
    write("You are not knowledgable enough to take the test.\n");
    return 1;
 }
} 


do_test() {
  if(taker) {
    write("Someone is already taking the Test.\n");
    return 1;
  }

  write("Sophillicus says: You are now ready to take the test of the final domain.\n");
  write("All that is required is that you answer my questions correctly.\n");
  taker = TP;
  q1 = random(QUIZ_SIZE);
  q2 = random(QUIZ_SIZE);
  q3 = random(QUIZ_SIZE);
  q4 = random(QUIZ_SIZE);
  q5 = random(QUIZ_SIZE);
  q6 = random(QUIZ_SIZE);
  q7 = random(QUIZ_SIZE);
  while(q2 == q1) q2 = random(QUIZ_SIZE);
  while(q3 == q2) q3 = random(QUIZ_SIZE);
  while(q4 == q3) q4 = random(QUIZ_SIZE);
  while(q5 == q4) q5 = random(QUIZ_SIZE);
  while(q6 == q5) q6 = random(QUIZ_SIZE);
  while(q7 == q6) q7 = random(QUIZ_SIZE);
  write("Sophillicus asks:\n" + quiz_list[q1][0] + "\n");
  write("Your answer: ");
  input_to("answer1");
  return 1;
}

answer1(arg) {
  if(arg == quiz_list[q1][1] || arg == quiz_list[q1][2] ||
     arg == CAP(quiz_list[q1][1]) ||
     arg == CAP(quiz_list[q1][2])) {
    write("Sophillicus says: That is correct.\n");
    write("Sophillicus asks:\n" + quiz_list[q2][0] + "\n");
    write("Your answer: ");
    input_to("answer2");
    return 1;
  }
  write("Sophillicus says: That is not the correct answer.\n");
  write("Sophillicus says: You must study the Domains more carefully.\n");
  done();
  return 1;
}

answer2(arg) {
  if(arg == quiz_list[q2][1] || arg == quiz_list[q2][2] ||
     arg == CAP(quiz_list[q2][1]) ||
     arg == CAP(quiz_list[q2][2])) {
    write("Sophillicus says: That is correct.\n");
    write("Sophillicus asks:\n" + quiz_list[q3][0] + "\n");
    write("Your answer: ");
    input_to("answer3");
    return 1;
  }
  write("Sophillicus says: That is not the correct answer.\n");
  write("Sophillicus says: You must study the Domains more carefully.\n");
  done();
  return 1;
}

answer3(arg) {
  if(arg == quiz_list[q3][1] || arg == quiz_list[q3][2] ||
     arg == CAP(quiz_list[q3][1]) ||
     arg == CAP(quiz_list[q3][2])) {
    write("Sophillicus says: That is correct.\n");
    write("Sophillicus asks:\n" + quiz_list[q4][0] + "\n");
    write("Your answer: ");
    input_to("answer4");
    return 1;
  }
  write("Sophillicus says: That is not the correct answer.\n");
  write("Sophillicus says: You must study the Domains more carefully.\n");
  done();
  return 1;
}

answer4(arg) {
  if(arg == quiz_list[q4][1] || arg == quiz_list[q4][2] ||
     arg == CAP(quiz_list[q4][1]) ||
     arg == CAP(quiz_list[q4][2])) {
    write("Sophillicus says: That is correct.\n");
    write("Sophillicus asks:\n" + quiz_list[q5][0] + "\n");
    write("Your answer: ");
    input_to("answer5");
    return 1;
  }
  write("Sophillicus says: That is not the correct answer.\n");
  write("Sophillicus says: You must study the Domains more carefully.\n");
  done();
  return 1;
}

answer5(arg) {
  if(arg == quiz_list[q5][1] || arg == quiz_list[q5][2] ||
     arg == CAP(quiz_list[q5][1]) ||
     arg == CAP(quiz_list[q5][2])) {
    write("Sophillicus says: That is correct.\n");
    write("Sophillicus asks:\n" + quiz_list[q6][0] + "\n");
    write("Your answer: ");
    input_to("answer6");
    return 1;
  }
  write("Sophillicus says: That is not the correct answer.\n");
  write("Sophillicus says: You must study the Domains more carefully.\n");
  done();
  return 1;
}

answer6(arg) {
  if(arg == quiz_list[q6][1] || arg == quiz_list[q6][2] ||
     arg == CAP(quiz_list[q6][1]) ||
     arg == CAP(quiz_list[q6][2])) {
    write("Sophillicus says: That is correct.\n");
    write("Sophillicus asks:\n" + quiz_list[q7][0] + "\n");
    write("Your answer: ");
    input_to("answer7");
    return 1;
  }
  write("Sophillicus says: That is not the correct answer.\n");
  write("Sophillicus says: You must study the Domains more carefully.\n");
  done();
  return 1;
}

answer7(arg) {
  object red, orange, yellow, green, blue, indigo, violet, reds, oranges, yellows, greens, blues, indigos, violets, scroll;
  if(arg == quiz_list[q7][1] || arg == quiz_list[q7][2] ||
     arg == CAP(quiz_list[q7][1]) ||
     arg == CAP(quiz_list[q7][2])) {
    write("Sophillicus says: You have answered both questions correctly.\n");
    write("Sophillicus says: It is time for the final puzzle.\n");
  if(!present("red_quest_scroll", this_player())) {
      write("Sophillicus gives you a scroll to prove your learning.\n");
      move_object(clone_object("/players/redsexy/dimensions/quest/scroll"), this_player());
     }  
    red = present("redtrial", TP);
    yellow = present("yellowtrial", TP);
    orange = present("orangetrial", TP);
    green = present("greentrial", TP);
    blue = present("bluetrial", TP);
    indigo = present("indigotrial", TP);
    violet = present("violettrial", TP);
    reds = present("red cocoon", TP);
    yellows = present("yellow cocoon", TP);
    oranges = present("orange cocoon", TP);
    greens = present("green cocoon", TP);
    blues = present("blue cocoon", TP);
    indigos = present("indigo cocoon", TP);
    violets = present("violet cocoon", TP);
  if(reds)     {destruct(reds);}
  if(yellows)  {destruct(yellows);}
  if(oranges)  {destruct(oranges);}
  if(greens)   {destruct(greens);}
  if(indigos)  {destruct(indigos);}
  if(violets)  {destruct(violets);}
  if(blues)    {destruct(blues);}
  destruct(red);
  destruct(yellow);
  destruct(orange);
  destruct(green);
  destruct(indigo);
  destruct(violet);
  destruct(blue); 
  this_player()->move_player("knowledgably into another dimension.#/players/redsexy/dimensions/inner/chamber");
  taker = 0;
  q1 = 0;
  q2 = 0;
  q3 = 0;
  q4 = 0;
  q5 = 0;
  q6 = 0;
  q7 = 0;
  return 1;
  }
  write("Sophillicus says: That is not the correct answer.\n");
  write("Sophillicus says: You must study the Domains more carefully.\n");
  done();
  return 1;
}

done() {
object red, orange, yellow, green, blue, indigo, violet;

  red = present("redtrial", TP);
  yellow = present("yellowtrial", TP);
  orange = present("orangetrial", TP);
  green = present("greentrial", TP);
  blue = present("bluetrial", TP);
  indigo = present("indigotrial", TP);
  violet = present("violettrial", TP);
  destruct(red);
  destruct(yellow);
  destruct(orange);
  destruct(green);
  destruct(indigo);
  destruct(violet);
  destruct(blue); 
  taker = 0;
  q1 = 0;
  q2 = 0;
  return 1;
}
