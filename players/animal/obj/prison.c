/*
 * Animal's Prison: VERY, VERY Strict security...
 */
int let_me_out;
 
short(){
  return "Criminal's Prison";
}
 
long(){
  write(
"Welcome to Prison.  This is where you get sent when you\n"+
"been a bad little boy or girl.  I really hope you enjoy your stay here at\n"+
"The Criminal's Prison, because this prison is a maximum security prison.\n"+
"It was made to hold even the strongest GODS on the system, let alone"+
" Wizards, or players...\n\n"+
"There is no obvious exit, There is no exit!\n\n"+
"P.S. It is dark and dreary in here... <Grin!>\n\n"+
"");
  write("> ");
}
 
init(){
  input_to("converse_room");
  let_me_out=0;
  return 1;
}
 
converse_room(str){
  int tmp;
 
  if (str == "!escape" || let_me_out==1) {
call_other(this_player(),"move_player","Quick!#players/animal/workroom.c");
    return 1;
    }
  say(capitalize(call_other(this_player(),"query_name"))+": "+str+"\n");
  write("What?\n");
  tmp = random(12);
  if (tmp==1){
    write("Warden says: Kinda fun in here, isn't it?\n");
    write("Warden smirks.\n");
    }
  if (tmp==3){
    write("Warden says: Don't you hate it when that happens?\n");
    write("Warden smiles happily.\n");
    }
  if (tmp==5){
    write("Warden says: Don't bend over for the soap!\n");
    write("Warden grins evilly.\n");
    }
  if (tmp==7){
    write("Warden says: Boy, you must have been REAL bad!\n");
    write("Warden shrugs.\n");
    }
  if (tmp==9){
    write("Warden says: Think your a bad ass now?\n");
    write("Warden laughs insanely.\n");
    }
  if (tmp==11){
    write("Warden says: My mother warned me about people like you..\n");
    write("Warden points at you.\n");
    }
  write("> ");
  input_to("converse_room");
  return 1;
}
 
get_me_out(){
  let_me_out=1;
}
reset(arg) {
	if(arg) return;
	set_light(1);
}
 
