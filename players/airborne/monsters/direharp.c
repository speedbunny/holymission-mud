inherit "/obj/monster";
object claws;
string chats;
get_chats(){
    if(!chats){
	chats = allocate (2);
	chats[0] = "The dire harpy screaches!\n";
	chats[1] = "The dire harpy tries to call more devils to her aid!\n";
      }
   return chats;
}
reset(arg){
	::reset(arg);
	if(arg) return 1;
   set_name("dire harpy");
   set_race("devil");
   set_size(2);
   set_alias("harpy");
   set_level(8);
   set_al(-10);
   set_aggressive(1);
   	load_chat(8, get_chats());
   set_short("A dire harpy");
   set_long("Half vulture, half woman, all hate!\n");

  	claws=clone_object("players/airborne/weapons/direclaws");
	move_object(claws,this_object());
	init_command("wield claws");
  return 1;
}

