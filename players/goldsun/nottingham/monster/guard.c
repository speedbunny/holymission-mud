inherit "/obj/monster";
#define TO this_object()
#define env(x) environment(x)

string s;
object weap,arm;
int    counter;


void reset(int arg) {


    ::reset(arg);

    set_random_pick(13);
    load_chat(19,({"The soldier says: Have you seen Orc ? \n",
                   "The soldier says: I am looking for Orc.\n",
                   "The soldier says: Have you been to Sherwood forest ?\n",
                   "The soldier says: The dark forest is dangerous. \n",
                   "Nottingham's soldier grins evilly.\n",
                   "Nottingham's soldier grins demonically.\n",
                   "Soldier exclaims: I want the head of that damned Orc ! \n",
                   "The soldier waves with his sword.\n",
                   "The soldier raises an eyebrow.\n"
                }));
     load_a_chat(52,({"The soldiers grins evilly.\n",
                     "Nottingham's soldier looks at you.\n",
                     "The soldier says: I'll kill you.\n",
                     "The soldier says: You are poor creature !\n",
                     "The soldier tells: I'll tell the sheriff about you.\n"
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
    set_heart_beat(1);
    set_gender(1);
    set_aggressive(0);
    set_wc(16);
    set_ac(5);
    add_money(50);
    weap = clone_object("/players/goldsun/sherwood/obj/solarm");
    arm = clone_object("/players/goldsun/sherwood/obj/solsword");
    transfer(weap,TO);
    transfer(arm,TO);
    command("wield sword");
    command("wear platemail");
    counter=0;
}


heart_beat(){
  ::heart_beat();
  if (present("orc",env(TO)))   attack_object(present("orc",env(TO)));
 counter++;

 if (counter>20){
   counter=0;
   wandering();
 } 
}

init(){
 ::init();
  set_heart_beat(1);
add_action("do_check","check");
}

void check(){

 if (this_player()){
   if (this_player()->query_immortal()){
       write("DEBUG of Soldier : ");
       write(file_name(this_object())+"\n");
       write("Counter in heart_beat = "+counter+"\n");
   }
 }
}



int catch_tell(string str){
 string who, where;

    if (sscanf(str, "%s leaves %s.\n",who,where)==2){
        call_out("moven",2,where);
     }
    return 1;
}

int moven(string where) {

    return command(where,this_object());
}

int wandering() {

  random_move();
  return 1;
}


