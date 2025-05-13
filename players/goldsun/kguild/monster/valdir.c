inherit "/obj/monster";
#include "../guild.h"
#define env(x) environment(x)

void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
move_object(clone_object("/players/whisky/obj/soul.c"),this_object());
move_object(clone_object("/obj/rsoul"),this_object());
enable_commands();
set_name("valdir");
set_race("human");
set_short("Valdit the treasury administrator");
set_gender(1);
set_long("Valdir the treasury administrator.\n"+
	 "He can allot you a chest for your stuff.\n"+
	 "You can ask him about help for more information.\n"
         );
set_wc(20);
set_ac(9);
set_al(100);
set_level(35);
set_size(3);          
move_object(clone_object("/players/goldsun/guild/obj/valdir_key"),this_object());
}

init(){
 ::init();
add_action("do_help","ask");
add_action("new_chest","chest");
add_action("bring_chest","bring");
add_action("carry_chest","carry");
add_action("do_cmd","cmd");

}

int do_help(string str){
 if (str=="valdir about help" || str=="him about help" ||
	str=="help"){
  write("Valdir gives you a scroll.\n");
  say("Valdir gives a scroll to "+TP->query_name()+".\n");
  move_object(clone_object("/players/goldsun/guild/obj/help_valdir"),this_player());
  return 1;
 }
 notify_fail("Ask whom about what ?\n");
 return 0;
}

int new_chest(){
string n;
object chest;

 n=TP->query_real_name()+"'s chest";
 if (present(n,environment(this_object()))){
  tell_room(env(TO),"Valdir says: "+OPN+", you already has a treasure chest.\n");
  return 1;
 }
 else{   /* bring him a chest */
  chest=clone_object("/players/goldsun/gen/obj/container");
  chest->set_name(n);
  chest->set_alt_name("chest");
  chest->set_can_lock(1,"iron","valdir_code");
  chest->set_can_get(0);
  chest->set_max_weight(20);
  chest->set_long("A "+capitalize(n)+".\n");  
  command("east");
  tell_object(this_player(),"Valdir tells you: Follow me.\n");
  transfer(chest,env(TO));
  return 1;
 }
}
  
int bring_chest(string str){
 string n;
 object chest;

  if (str!="chest") return 0;
  n=TP->query_real_name()+"'s chest";
  if (present(n,env(TO))){
      chest=present(n,env(TO));
      command("east");
      tell_object(this_player(),"Valdir tells you: Follow me.\n");
      transfer(chest,env(TO));
      command("unlock "+n+" with iron key"); 
      return 1;
  }
  tell_room(env(TO),"Valdir says: "+OPN+" , you haven't your chest here.\n");
  return 1;
}

int carry_chest(string str){
 string n;
 object chest;

  if (str!="off chest" && str!="chest") return 0;
  n=TP->query_real_name()+"'s chest";
  if (present(n,env(TO))){
      chest=present(n,env(TO));
      command("lock "+n+" with iron key");	
      command("west");
      tell_object(this_player(),"Valdir tells you: I save your chest. Bye.\n");
      transfer(chest,env(TO));
      return 1;
  }
  write("no chest\n");
 return 1;
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


