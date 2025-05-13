inherit "/obj/monster";
#define TO this_object()
#define GUARDROOM "players/goldsun/nottingham/room/barracks"
#define env(x) environment(x)
#define TIME 20           /* time without leader [2*sec] */
object weap,arm, leader;
int counter;

void reset(int arg) {


    ::reset(arg);

    set_random_pick(13);
    load_chat(10,({"The soldier says: Have you seen Orc ? \n",
                   "The soldier says: I am looking for Orc.\n",
                   "The soldier says: Have you been in the Sherwood forest ?\n",
                   "The soldier says: The dark forest is danger. \n",
                   "Nottingham's soldier grins evilly.\n",
                   "Nottingham's soldier grins demonicaly.\n",
                   "Soldier exclaims: I want the head of damn Orc ! \n",
                   "The soldier waves with his sword.\n",
                   "The soldier raises an eyebrow.\n"
                }));
     load_a_chat(32,({"The soldiers grins evilly.\n",
                     "Nottingham's soldier looks at you.\n",
                     "The soldier says: I'll kill you.\n",
                     "The soldier says: You are poor creature !\n",
                     "The soldier says: I'll tell the sheriff about you.\n"
                     }));
  
    if (arg) return;

    set_name("soldier");
    set_alias("knight");
    set_alt_name("nottingham soldier");
    set_race("human");
    set_short("Sheriff's soldier");
    set_long("This is a soldier. He is \"Guard of Nottingham\".\n");
    set_level(6);
    set_hp(600);
    set_al(20);
    enable_commands();
    set_gender(1);
    set_aggressive(0);
    set_wc(16);
    set_ac(5);
    add_money(50);
    weap = clone_object("/players/goldsun/sherwood/obj/solarm");
    arm = clone_object("/players/goldsun/sherwood/obj/solsword");
    set_heart_beat(1);
    counter=0;
    transfer(weap,TO);
    transfer(arm,TO);
    command("wield sword");
    command("wear platemail");
}


heart_beat(){
  ::heart_beat();
  if (present("orc",env(TO)))   attack_object(present("orc",env(TO)));
  if ( leader && !present(leader,environment(TO))){
      counter++;
      if (file_name(env(TO))==GUARDROOM) return;
      if (counter>TIME) disband();
  } else {
      if (!leader) disband();
       else counter=0;
  } 
  return;
}

init(){
 ::init();
set_heart_beat(1);
}


int catch_tell(string str){
 string who, where, pom;

    if (sscanf(str,"%s follow me%s",who,where)==2){
        if (random(4)==0) return 1;   				  /* 75 % */
        if (this_player()->query_npc()) return 1;    /* only players   */
        leader=this_player();
        set_heart_beat(1);
        write("Soldier says: Ok. You are my leader.\n");
    }
    if (leader) pom=capitalize(leader->query_name());
     else pom="";
    if (sscanf(str, "%s leaves %s.\n",who,where)==2){
       if (who != pom && random(1)){  			/* 0 % for this mom*/
           call_out("moven",3,where);
           return 1;
       }
       if (who==pom){
           call_out("moven",2,where);
       }
      return 1;
     }
}

int moven(string where) {
    
    return command(where,this_object());
}

int disband() {
  transfer(TO,GUARDROOM);
  leader=0;
  counter=0;
  set_heart_beat(0);
  return 1;
}


