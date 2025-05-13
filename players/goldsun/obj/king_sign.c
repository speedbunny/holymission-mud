inherit "/obj/treasure";
int i;
reset(arg){
 if (arg) return;
  set_alt_name("knight_king_sign");
  i=1;
  set_alias("ksign");
  set_short("A king sign");
  set_long("You are king of the famous knight guild.\n"
	   +"This sign has only king.\n"
	   +"You can 'hide' or 'search' this sign.\n");
  set_value(0);
  set_weight(0);
  }

init(){
 ::init();
 add_action("hide","hide");
 add_action("search","search");
 }

short(){
 if (i==1){ return 0;}
  return ::short();
}
  
hide(str){
 if (str="sign" || str!="knight sign"){
 if (i==1) {    write("The king sign is hidden already.\n");   }
  else{
  write("You hide your king sign.\n");
  i=1; }
 }
  return 1;
 }
search(str){
 if (str=="sign" || str=="king sign"){
  if (i==0) write("But the king sign isn't hide.\n");
  else{
   write("You find your king sign.\n");
   i=0;
   }
 return 1;
 }
}

drop(){
  return 1;}

query_auto_load(){
 return "/players/goldsun/obj/king_sign:";
 } 

prevent_insert(){
 return 1; }

