inherit "/players/goldsun/gen/std/std_dragon.c";

void reset(int arg){
  ::reset(arg);
 if (!arg){
  set_colour("ametist");
  set_age(12);
  set_silent(1);
  set_no_follow();
 }
}

