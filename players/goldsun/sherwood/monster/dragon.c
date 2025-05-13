inherit "/players/goldsun/gen/std/std_dragon";

void reset(int arg){
 ::reset(arg);
  if (arg==0){
   set_colour("copper");
   set_age(13);
   set_no_follow();
  }
}

init(){
 ::init();
 add_action("do_block","get");
 add_action("do_block","take");
}

int do_block(string str){
 if (str=="handle" || str=="all"){
  write("The dragon hinders you from getting it !\n");
  return 1;
 }
 return 0;
}

