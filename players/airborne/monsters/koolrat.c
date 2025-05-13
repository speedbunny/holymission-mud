inherit "/obj/monster";
/* This was created as a joke between Jake and myself. If asked I will
   delete it. But I think its pretty kool. It will in no way be a part
   of the players MUD.
*/
object shades, sneaks;
string chats;

get_chats(){
   if(!chats){
	chats = allocate(3);
	chats[0] ="Kool Rat says: Airborne is da man!\n";
	chats[1] ="Kool Rat says: Jake is a wiener!\n";
	chats[2] ="Kool Rat says: I am the koolest Rat in the world!\n";
       }
   return chats;
}

reset(arg){
   ::reset(arg);
   if(arg) return 1;
	set_name("kool rat");
	set_race("rat");
	set_alias("rat");
	set_level(100);
	load_chat(20, get_chats());
	set_short("Kool Rat");
	set_long("Kool Rat is the koolest rat in town!\n");
   shades=clone_object("players/airborne/armours/shades");
   sneaks=clone_object("players/airborne/armours/sneaks");
    	move_object(shades,this_object());
	move_object(sneaks,this_object());
	  init_command("wear shades");
	  init_command("wear sneaks");
   return 1;
}
