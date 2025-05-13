inherit "obj/npc";

void reset(int a) 
{
    ::reset(a);
    if (a) return 0;
    set_name("master monk");
    set_alias("monk");
    set_alt_name("master");
    set_short("Master monk");
    set_long("He is the highest monk of White Tower\n"+
	     "If you go to Moon valley he'll help you.\nJust say it.\n");
    set_gender(1);
    set_race("elf");
    set_attacks_change(40);
    set_attacks(3);
    set_spell_mess1("Master praises Urimuri.\n");
    set_spell_mess2("Master praises Urimuri.\n");
    set_spell_dam(166);
    set_chance(10);
    set_size(3);
    set_level(50);
}

hold(caller,time)
{
  return ::hold(caller,random(4));
}

init()
{
    ::init();
}


run_away(){
 write("Master grins at you.\n");
 return 1;
}

int add_poison(int amount)
{
 add_poison(3);
    return 1;
}

int query_dex(){ return 90; }

int query_str(){ return 90; }

void valley(){
    write(
    "Master tells you: I am from Moon Valley. Two huge Sphinxes guard it.\n"+
    "I can help you.\nMaster praises to Urimuri.\n"+
    "Master tells you: You can enter Moon valley now. But it is not forever.\n"
   );
   if (!present("west_pass_valley_goldsun",this_player()))
    move_object(clone_object("players/goldsun/white_tower/obj/vall_pass"),
	this_player());
   write("Master tells you: If you need help come here again. Maybe I help you.\n"+
	  "Return altar to White Tower, please.\n");
 return;
}

void hook(){
 write("Master looks thoughtful.\nMaster tells you: I think Merlin can help"+
       " you.\n");
 return;
}

void cyclops(){
 write("Master tells you: They arrived from east sea. Maybe from an island.\n"+
       "Find powerful seafarer.\n");
 return;
}

void merlin(){
 write("Master tells you: I don't know where is he now, but .....\n"+
  "Master tells you: Once upon a time powerful Merlin visits his friend\n"+
  "Hern in Sherwood forest. Merlin lost a crystal whistle there. \n");
 return;
}

int catch_tell(string str){
  string what, who;

 if (sscanf(str,"%s hook%s",who,what)==2){
   hook();
   return 1;
 }
 if (sscanf(str,"%s valley%s",who,what)==2){
   valley();
   return 1;
 }
 if (sscanf(str,"%s merlin%s",who,what)==2){
   merlin();
   return 1;
 }
 if (sscanf(str,"%s cyclops%s",who,what)==2){
   cyclops();
   return 1;
 }
 if (sscanf(str,"%s tomb%s",who,what)==2){
   hook();
   return 1;
 }
 if (sscanf(str,"%s black force%s",who,what)==2){
   hook();
   return 1;
 }

 write("Master shrugs helplessly.\n");
write("Master tells you: Try asking it a different way.\n");
 return 1;
}

