inherit "/players/goldsun/gen/std/std_dragon";

void reset(int arg){
 ::reset(arg);
  if (arg==0){
   set_colour("white");
   set_age(random(3)+7+random(2));
  }
}

