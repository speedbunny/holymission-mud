inherit "obj/npc";
#define TP this_player()
#define TO this_object()
#define SAY(x) say(x)
#define MSGOUT "Merlin leaves in storm and wind.\n"
#define MSGIN  "Merlin leaves in storm and wind.\n"
#define YOURTIME 10 			/* 2*time [sec] */
#define HOME "/players/goldsun/void"
#define MAXPAPERPAGES 10   /* number of scrolls */

object me;
int paper_pages;

no_clen_up();

int is_busy, counter;

int query_is_busy(){ return is_busy; }

int call_me(object where_go){
 if (!is_busy){
   SAY(MSGOUT);
   move_object(TO,where_go);
   SAY(MSGIN);
   return 1;
 }
 return 1; /*  against bug */
}


void leave(){
  SAY("Merlin says: I have to go.\n");
  SAY(MSGOUT);
  transfer(me,HOME);
  counter=0;
}

void reset(int a) 
{
    paper_pages=MAXPAPERPAGES;
    ::reset(a);
    if (a) return 0;
    set_name("powerful wizard Merlin");
    set_alias("merlin");
    set_alt_name("wizard");
    set_short("Wizard Merlin");
    set_long("Powerful wizard Merlin. He can change his form\n"+
  	     "to anything shape. He is immortal.\n");
    is_busy=0;      
    counter=0;
    set_gender(1);
    set_race("halfelf");
    set_attacks_change(40);
    set_attacks(4);
    set_spell_mess1("Merlin calls a huge FIRE STORM.\n");
    set_spell_mess2("Merlin calls a huge FIRE STORM.\n");
    set_spell_dam(266);
    set_chance(10);
    set_size(3);
    set_level(40);
    set_hp(5000);
    me=TO;
    set_dead_ob(this_object());
    move_object(clone_object("/players/whisky/obj/soul.c"),this_object());
    transfer(me,HOME);
}


void init(){
 ::init();
 add_action("do_cmd","merlin");
}

mixed query_property(string str){
  return (str=="no_steal");
}

heart_beat(){
 ::heart_beat();
 counter++;
 if (counter>YOURTIME) leave();
 return 1;
} 

int monster_died(object ob){
  write("Merlin hide his face.\n");
  write("Merlin looks more powerful.\n");
  reduce_hit_point(query_hp()-query_max_hp());
  return 1;
}

hold(caller,time)
{
  write("Merlin laughs at you.\n");
  write("Merlin reflects a lightning at you.\n");
  caller->hit_player(10,5);
  return 1;
}

run_away(){
 write("Merlin grins evilly at you.\n");
 return 1;
}

int add_poison(int amount) {
 add_poison(1);
    return 1;
}

int query_dex(){ return 190; }

int query_str(){ return 190; }

int query_int(){ return 200; }

int query_wis(){ return 150; }

int query_chr(){ return 140; }


void hook(){
   write("Merlin tells you: Well. What do you need to know?\n"); 
 return;
}

void fish(){
 if (paper_pages<1){
  write("Merlin tells you: I am out of paper.\nMerlin shrugs helplessly.\n");
  return ;
 }
 paper_pages--;
 write("Merlin smiles at you.\n");
 write("Merlin tells you: Ok.I write you a scroll for hook.\n");
 SAY("Merlin writes a scroll.\n");
 move_object(clone_object("/players/goldsun/green_island/obj/scroll"),
            environment(TO));
 SAY("Merlin drops a scroll.\n");
 return;
}

void tomb(){
 if (paper_pages<1){
  write("Merlin tells you: I am out of paper.\nMerlin shrugs helplessly.\n");
  return ;
 }
 paper_pages--;
 write("Merlin smiles at you.\n");
 write("Merlin tells you: Ok.I write you a spell.\n");
 SAY("Merlin writes a scroll.\n");
 move_object(clone_object("/players/goldsun/white_tower/obj/scroll"),
		environment(TO));
 SAY("Merlin drops a scroll.\n");
 return;
}

int catch_tell(string str){
  string what, who;

 if (sscanf(str,"%s hook%s",who,what)==2){
   hook();
   return 1;
 }
 if (sscanf(str,"%s tomb%s",who,what)==2){
   tomb();
   return 1;
 }
 
if (sscanf(str,"%s leaves %s",who,what)==2){
   if (who==TP->query_name()) leave();
   return 1;
 }
 if (sscanf(str,"%s disappear%s",who,what)==2){
   if (who==TP->query_name()) leave();
   return 1;
 }
 if (sscanf(str,"%s black force%s",who,what)==2){
   tomb();
   return 1;
 }
 if (sscanf(str,"%s enter cottage%s",who,what)==2){
   fish();
   return 1;
 }
 if (sscanf(str,"%s golden fish%s",who,what)==2){
   fish();
   return 1;
 }
}

int do_cmd(string str){
 string what,whom;

 if (sscanf(str,"tell %s %s",whom,what)==2){
    if (find_player(whom)){
      tell_object(find_player(whom),TO->query_name()+" tells you: "+what+"\n");
      return 1;
    } else write("No player with that name ("+whom+")\n");
 }
 command(str,this_object());
 return 1;
}

