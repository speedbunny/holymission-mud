inherit "obj/monster";

string chats;

get_chats(){
 if(!chats){
 chats=allocate(3);
  chats[0]="Grouchy smurf says: Get the hell outta here!\n";
  chats[1]="Grouchy smurf says: Smurfette is a slut!\n";
  chats[2]="Grouchy smurf says: F**K OFF!\n";
}
return chats;
}

 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Grouchy smurf");
  set_race("smurf");
  set_alias("smurf");
  set_level(5);
   load_chat(30, get_chats());
  set_aggressive(1);
  set_short("Grouchy smurf");
  set_long("This is Grouchy smurf.  He hates everything.\n");
  add_money(100);
return 1;
}
