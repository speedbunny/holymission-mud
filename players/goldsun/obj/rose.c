inherit "/obj/treasure";

status is_open;

void reset(int arg){
 ::reset(arg);

 if (arg) return;
  set_name("red rose");
  set_alias("rose");
  set_short("A red rose");
  set_long("A red rose from Sir Goldsun.\n");
  set_value(100);
  set_weight(0);
}

init(){
 ::init();
add_action("des","destruct");
add_action("mtl","rose");
add_action("smell","smell");
}

int smell(string str){
 if (str=="rose"){
  switch (random(2)){
   case 0: write("The rose smells lovely.\n");
           break;
   case 1: write("The rose smells like morning aurora.\n");
           break;
  }
  return 1;
  }
}

int mtl(string s){
 if (!s){
   write("Tell Goldsun What?\n");
   return 1;
 }
 if (find_player("goldsun")){
  tell_object(find_player("goldsun"),"Keiko tells you by a rose: "+s+"\n");
  write("You tell Goldsun by a rose: "+s+"\n");
  return 1;
 }
 write("Rose cannot find Goldsun, but i try to touch everybody,\n"
          +"maybe he is here.\n");
 shout("A red rose touch you.\n");
 return 1;
}

int des(string str){
 if (str=="rose"){
  write("You destruct your rose.\nGoldsun screams.\n");
  destruct(this_object());
  return 1;
 }
}

query_auto_load(){ return "/players/goldsun/obj/rose:"; }

prevent_insert(){ return 1; }
    
drop(){
 if (this_player()->query_real_name()=="goldsun") return 0;
 write("If you want to destruct this rose, type 'destruct rose'\n");
 return 1;
}
