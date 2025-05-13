inherit "/obj/monster";
string function,match,type,solver;

reset(arg) {
  ::reset(arg);
  if (arg) return ;
  set_name("monk");
  set_short("Monk");
  set_long("This is a very old but experienced monk. He is a great master\nof all the martial arts.. Very few can vanquish him..\nDon't kill him.. he is VERY tough..\n");
  set_level(80);
load_chat(20,({
"Monk mumbles: Hmmmm how will I do it?\n",
"Monk mumbles: There must be someone ?\n",
}));
  set_al(300);
  set_hp(8000);
  set_wc(random(160));
  set_ac(20);
  set_gender(1);
  add_money(3000);
  set_chance(3);
  set_spell_dam(120);
  set_spell_mess1("Monk hits you with the power of mind");
  set_spell_mess2("Monk knocks you on your ass with his mind");
  set_aggressive(0);  

}

catch_tell(arg) {
  string str1;
  object ob,ob2;
  ob=present("quest_object_warlord",this_player());
  ob2=present("quest_object_warlord",this_object());
  
 if (sscanf(arg,"%s arrives.",str1)==1) { 
    if (!ob) {   
 
    write("Monk says: HUH?!?!\n"
          +"Monk says: Hmmmmm you don't look strong?\n"
          +"Monk says: But I guess you'll have to do.....\n"
          +"Monk says: Please retrieve the Black orb from the awful dragon and\n"
          +"bring it to me.\n");
    }
   else {

       write("Monk says: Great, please could you give me the orb now "+this_player()->query_name()+".\n"); 
        return 1;
    }
  return 1;
  }
  
    
if (sscanf(arg, "%s gives orb to Monk.",str1)==1) {
    if (ob2) {
        write("The monk says: Thank you "+this_player()->query_name()+", you have done well!!\n");
        this_player()->add_money(1000);
       this_player()->set_quest("orb_quest");
        destruct(ob2);
        }
        else {
        write("You don't have that item.\n");
        return 1;
        }
      return 1;
      }
   return 1;
   }
        
