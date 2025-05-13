inherit "/obj/monster";
int busy_catching;

void reset(int arg){ 
  :: reset(arg);
  set_random_pick(9);
  load_chat(19,({"The soldier says: Have you seen Robin? \n",
                 "The soldier says: I am looking for Robin Hood.\n",
                 "The soldier says: Have you been to Sherwood forest?\n",
                 "The soldier says: The dark forest is dangerous. \n",
                 "The soldier says: Have you seen Robin Hood?\n",
                 "The soldier says: If you find Robin, tell me!\n",
                 "Nottingham's soldier grins evilly.\n",
                 "Nottingham's soldier grins demonically.\n",
                 "Soldier exclaims: I want the head of Robin Hood! \n",
                 "The soldier waves his sword.\n",
                 "The soldier raises an eyebrow.\n"
                 }));
   load_a_chat(52,({"The soldier grins evilly.\n",
	           "Nottingham's soldier looks at you.\n",
	           "The soldier says: I'll kill you.\n",
	  	   "The soldier says: You are a pathetic creature!\n",
	           "The soldier tells: I'll say the sheriff about you.\n"
	  	     }));
   
  if (arg) return;
 
 set_name("soldier");
 set_alias("knight");
 set_race("human");
 set_short("Sheriff's soldier");
 set_long("This is a soldier. He is from Nottingham.\n");
 set_level(6);
 set_hp(400);
 set_al(10);
 set_gender(1); 
 set_aggressive(0);
 set_wc(7);
 set_ac(1);
 add_money(50);
 transfer(clone_object("/players/goldsun/sherwood/obj/solarm"),
      this_object());
 transfer(clone_object("/players/goldsun/sherwood/obj/solsword"),
      this_object());
 command("wield sword");
 command("wear platemail");
}  


catch_tell(str){
 string who, where;
 if(busy_catching) return;
 busy_catching = 1;
 if (sscanf(str, "%s leaves %s.\n",who,where)==2)
      call_out("moven",4,where);
  busy_catching = 0;
 }

void moven(string where){
 command(where,this_object());
}

