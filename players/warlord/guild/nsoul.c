/* #################################################################

            T H E  M O N K S - G U I L D  (c) Whisky
                    new version (c)
                    
   ##################################################################   

                    
   
    Generel: This guild are no european monks. They are a kind of Asiatique
             fighters with psychonic featueres. The tradition of such a 
             kind of guild goes far back as the european culture was far
             behind the most cultures worldwide.
           
             The idea was a kind of Buddism, that means they didn't get
             their powers from gods, they all tried to find their own way
             in their community.
           
             Their ideologie was therefore mostly based on wisdom and 
             dexterity and wisdom for their fight technologies.
             Their psychogenic features mostly conzentrates of healing
             themselves or others and influence their opponent during the   
             fight.

           
  Features: unarmed_combat(depending on wis and dex + strong feetattack),
            natural_armour_class(depending on their wis and dex),
            healing themself and others (depending on their wis),  
            influencing the opponent (depending on their wis and chr), 


   Althought of the new different max_stats of the races, I didn't change
   much my calculation based on the median stats of 30. But I changed it
   so that even races with more con will have disadvantages and races with
   lower con will have some advantages now. I too made it clear that this
   guild is mostly depending on dex, wis and chr.
   
   The idea is in the attack for example of an hobbit max=250 HP and a
   troll max=450 HP. The trolls hits will be now much weaker and the
   hobbits hits much better than the old ones. The median is just the
   same, that the costs are nearly equal to the damage.     */
     
 

inherit "obj/armour";

#define HP_CURE          40 
#define SP_CURE          50
#define SP_CURE_TARGET   30    
#define FORMULA1_N_AC   (2+TPW/12+TPD/12)
#define FORMULA2_N_AC   (4+TPW/6+TPD/6)
#define SP_AIKIDO       (8+TPW/4)  
#define DUR_AIKIDO      (100+TPW*3) 
#define FORMULA_N_WC      (8+(TPD/2))
#define FORMULA_DEATH   ((60+random((TPW+TPD)*3)))   
#define HP_DEATH        (random(10+TPC/2))              

#define SP_DEATH        (30+(TPW+TPD))                  
#define ALLOW_DEATH      30
#define FORMULA_SMASH   (random(45)+TPD)
#define SP_SMASH        (20+TPI)
#define MAX_H_SMASH     (random(4+TPW/6))
#define ALLOW_SMASH      15
#define SP_CHOKE        ((TPD/3)+8)
#define FORMULA_CHOKE   ((TPD/3)+random(20))
#define ALLOW_CHOKE      5
#define SP_CHARM        (8+TPI)
#define MAX_C_CHARM     (TPCH*2)
#define FORMULA_FEET    (random((TPW+TPD)/3+6))
#define FEET_CON        (40+TPC*4)
#define SP_PENTA         60
#define POWER           ((TPW*TPI)/6)
#define MAX_INTO        (TPST*3/2+20)

#define GM  "guild/master" 
#define GUILD  "monk"  
#define TO     this_object()
#define TPN    TP->query_name()
#define TPR    TP->query_real_name()
#define TPL    TP->query_level()
#define TPD    TP->query_dex()
#define TPI    TP->query_int()
#define TPW    TP->query_wis()
#define TPC    TP->query_con()
#define TPCH   TP->query_chr()
#define TPST   TP->query_str()
#define TPP    TP->query_possessive()
#define N      query_name()
#define L      query_level()
#define P      query_pronoun()
#define C      query_chr()   
#define E      environment
#define INTRO  TP->query_intoxination()
#define SAY(x) tell_room(E(TP),x)
#define TPS    TP->query_spell_points()
#define TPH    TP->query_hit_point()
#define RHP    TP->hit_player(x) 

 object TP,block,ob;
 string dir, helpdir, room, id, aik;
 int fattack,counter,feeter;  
 int meditate,nofeeter,count;
 int next, diff,n,s;
 int hb_lock;  
 string a_flag;            /* which attack is executed next hb */
 string a_arg;             /* attack argument */
 object sleeper;

/*************************************************************
*  simulate the GM-functions for debug purpose       *
*************************************************************/
#if 0
/* wer hat das auf 6 gesetzt??? */
query_number(str) { return 7; }
query_id(nr) { return "monksoul"; }
query_dir(nr) { return "players/whisky/guild"; }
query_room(nr) { return "players/whisky/guild/room"; }
list_levels(nr,gen) { return TP->more("/players/whisky/guild/monktitles.c"); }
#endif
 
/* ############## checking if the player is too busy ############## */ 

#define ATT();\
  if ((att=TP->query_attack()) && present(att,E(TP))) {\
     write("You are much to busy to do that.\n");\
  return 1;\
 }
  
/* ################# checking the allowance ################### */

chk_fiz() {  
    int i; 
    object ob;

   if(INTRO >= MAX_INTO) {
     write("You are much to drunken to do that.\n");
   return 1;
   }
   ob=all_inventory(TP);
   for(i=0;i<sizeof(ob);i++)
   if(ob[i]->query_worn()) {
   if(!(ob[i]->query_monk_wear() || (ob[i]->armour_class()==0))) {
     write("The "+ob[i]->N+" hinders your monk abilities.\n");
     return 1;
   }
  }
  if (hb_lock) return 1;
  return 0;
}

/* ################### CHECKING THE GHOST ############################# */

#define CHK_GHOST;\
  if(TP->query_ghost()) {\
    write("You can't do that in your immaterial state.\n");\
  return 1;\
 }

/* ##################    now to the monks robe     ####################### */

 int gd;
 object att;
 object hit_func;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  gd=GM->query_number(GUILD);
  id=GM->query_id(gd);
  dir=GM->query_dir(gd);  
  helpdir="/"+dir+"/helpdir";
  room=GM->query_room(gd); 
  set_id("monk robe");       
  set_type("guild");
  set_alias(id);        
  set_short("monks robe");
  set_long("A beautiful brown monks-robe.\n");
  set_weight(0); /* in case of bugs */
  set_type("robe");
}

drop() { return 1; } 

/*########################## the init ################################## */

query_hit_msg(dam,name,att,def) {
      string how1,how2;
      
      switch(random(6)) {
         case 0:
          how1=" with "+TPP+" right shoulder";
          how2=" with your right shoulder";
          break;
         case 1:
          how1=" with "+TPP+" left shoulder";
          how2=" with your left shoulder";
          break;
         case 2:
          how1=" with "+TPP+" right knee";
          how2=" with your right knee";
          break;
         case 3:
          how1=" with "+TPP+" left knee";
          how2=" with your left knee";
          break;
         case 4:
          how1=" with "+TPP+" right elbow";
          how2=" with your right elbow";
          break;
         case 5:
          how1=" with "+TPP+" left elbow";
          how2=" with your left elbow";
          break;
         default:
          how1="error";
          how2="error";
          break;
         return 1;
         }
                         

   if(dam<1) return ({
      "miss "+name+how2+".",
      "misses you"+how1+".",
      "misses "+name+how1+"." });
   else if (dam<3) return ({
      "tickle "+name+" in the stomach"+how2+".",
      "tickes you in the stomach"+how1+".",
      "tickles "+name+" in the stomach"+how1+"." });
   else if (dam<4) return ({
      "gaze "+name+how2+".",
      "gazes you"+how1+".",
      "gazes "+name+how1+"." });
 else if (dam<5) return ({
      "hit "+name+how2+".",
      "hits you"+how1+".",
      "hits "+name+how1+"." });
 else if (dam<7) return ({
      "hit "+name+" hard"+how2+".",
      "hits you hard"+how1+".",
      "hits "+name+" hard"+how1+"." });
 else if (dam<9) return ({
      "hit "+name+" pretty hard"+how2+".",
      "hits you pretty hard"+how1+".",
      "hits "+name+" pretty hard"+how1+"." });
 else if (dam<11) return ({
      "hit "+name+" very hard"+how2+".",
      "hits you very hard"+how1+".",
      "hits "+name+" very hard"+how1+"." });
 else if (dam<12) return ({
      "hit "+name+" extremly hard"+how2+".",
      "hits you extremly hard"+how1+".",
      "hits "+name+" extremly hard"+how1+"." });
 else if (dam<14) return ({
      "smash "+name+how2+".",
      "smashes you"+how1+".",
      "smashes "+name+how1+"." });
else if (dam<16) return ({
      "smash "+name+" with a bonecrushing sound"+how2+".",
      "smashes you with a bonecrushing sound"+how1+".",
      "smashes "+name+" with a bonecrushing sound"+how1+"." });
else if (dam<18) return ({
      "massacre "+name+how2+".",
      "massacres you"+how1+".",
      "massacres "+name+how1+"." });
else if (dam<20) return ({
      "massacre "+name+" to small fragments"+how2+".",
      "massacres you to small fragments"+how1+".",
      "massacres "+name+" to small fragments"+how1+"." });
else if (dam<30) return ({
      "hit "+name+how2+" ,so hard that it just hurts to see it!",
      "hits you"+how1+" ,so hard that it just hurts to see it!",
      "hits "+name+how1+" so hard that it just hurts to see it!" });
else  return ({
      "give a devasstating blow to "+name+how2+".",
      "gives you a devestating blow"+how1+".",
      "gives "+name+" a devestating blow"+how1+"." });
   }

remove(arg) {
  if(id(arg)) {
    write("You can't remove your monk robe.\n");
    return 1;
  }
}

/* ########################   init  ########################### */

init() {
   ::init();
   if (!(TP=environment(this_object()))) return;
   TP->set_n_ac(FORMULA1_N_AC);
   TP->set_n_wc(2+FORMULA_N_WC);
   TP->wield(this_object());
   if (!worn && !TP->query_wizard()) command("wear robe",TP); /* Moonchild - can't command
                        high level wizards     */
   n=1;
   add_action("help","help");
   add_action("monk","monk");
   add_action("vitals","vitals");
/* add_action("runaway","runaway"); moved out because of senseless feature */
   add_action("charm","charm");    
   add_action("aikido","aikido");
   add_action("do_att","choke");
   add_action("cure","cure");
   add_action("do_att","feet");
   add_action("do_att","death");
   add_action("do_att","smash");
   add_action("silence","silence");
   add_action("pentagram","pentagram");
   add_action("wake_up","wake_up");
   add_action("check","check");
   add_action("perception","perception");
   add_action("mt","mt");
/* add_action("discharge","discharge"); moved out because of senseless feature */
   add_action("missile","missile");
   add_action("shock","shock");
   add_action("song","song");
   add_action("fireball","fireball");
   add_action("meditate","meditate");
   add_action("shuffle","shuffle");
   add_action("sign","sign");
   feeter=FEET_CON;
  }

  extra_look() {
   string text;
    text=capitalize(TP->P)+" is beautiful and sexy.\n"+ 
    capitalize(TPP)+" eyes are glowing like burning diamonds.\n"+ 
    capitalize(TP->P)+" is covered by a bright mystical powerfield "; 
    return text;
    }

  vitals() {
   string stren;
   if (!aik) { aik="You are NOT concentrated on aikido !!!!"; }
    if (INTRO >= (TPL/4+TPW/4+TPI/4+TPC/4+28))  {
       stren=" paralytic";
    }
    else if (INTRO >= (20+TPL*3)) {
       stren=" drunk as a fiddler's bitch";
    }
    else if (INTRO >= (16+TPL*2)) {
       stren=" drunken as a lord";
    }
    else if (INTRO >= (12+TPL)) {
       stren=" drunken";
       }
    else if (INTRO >= (8+TPL/2)) {
       stren=" slightly drunken";
       }
    else if (INTRO >= 1) {
       stren=" a little bit tipsy";
    }
    else {
       stren=" sober";
    }
    
   next="guild/master"->query_exp(TP->query_guild(),TP->query_level()+1);
   diff=next-TP->query_exp();
   tell_object(TP,"Your vitals are:\n\nFeetcon: "+feeter+" of ("+(TPC*10)+")\n"+
   "Experience for the next level: "+diff+"\n"+
   "Power: "+POWER+"\n"+
   "Money: "+TP->query_money()+"\n"+
   "Hitpoints: "+TPH+" of ("+TP->query_max_hp()+")\n"+
   "Spellpoints: "+TPS+" of ("+TP->query_max_sp()+")\n"+
   "Intoxination: "+stren+".\n");
   if (TP->query_wizard()) { write("Intoxination (wizinf.) : "+INTRO+"\n"); } 
    
   return 1;
  }
 
/* ################################  song  ################################## */ 

song(arg) {
  
  if (!arg) return;
  
  if (arg=="one")  {
  
     SAY(
     TPN+" sings a merry song:\n\n"+
     "Oh Water warm oh water hot!\n"+
     "Oh Water boiled in pan and pot!\n"+
     "Oh water blue and water green,\n"+
     "Of bath I sing my song !\n"+
     "Oh praise the steam expectant nose !\n"+
     "Oh bless the tub my weary toes!\n"+
     "Oh happy fingers come and play!\n");
     SAY(
     "Oh arms and legs, you here may stay,\n"+
     "And warm and long!\n"+
     "Put mine away! Forget the clay!\n"+
     "Shut out the night! Wash of the day!\n"+
     "In water lapping chin and knees,\n"+
     "in water kind now lie at ease,\n"+
     "Until the dinner gong.\n\n"); 
        
     }
     
   else if (arg=="two") {
  
     SAY(
      TPN+" sings a merry song:\n\n"+
     "Ho!Ho!HO!\n"+
     "To my bottle I go\n"+
     "To have my sex and drawn my woe!\n"+
     "Rain may fall and wind may blow,\n"+
     "And many miles still to go,\n"+
     "But under the elm-tree i will lie\n"+
     "satiesfy myself and let the clouds go by!\n"+
     "Ho!Ho!Ho!\n\n");
     }
   else if (arg=="three") {
   
     SAY(
     TPN+" sings a merry song:\n\n"+
    "The Road goes on and on\n"+
    "Out from the door where it began.\n"+
    "Now for ahead the Road has gone,\n"+
    "Let others folow it who can!\n"+
    "But I at last with weary feet,\n"+
    "Will turn towards the lighted inn,\n"+
    "and having rest and having sex.\n\n");
    
    }
  else if (arg=="four") {
  write("Ok\n");
  SAY(
   TPN+" sings a merry song:\n\n"+
  "Come on and play between my feet!\n"+
  "You know it's that all we need.\n"+
  "So come and make me hot tonight.\n"+
  "And when i come i love to feel your\n"+
  "sexual organ. So please make me hot tonight!\n\n");
  
   }
  else {
   write("Sorry no such song available at the moment.\n");
   return 1;
   }
 return 1;
 }
  
   
    
       
/* ###################### now to the heart-beat ######################### */

  
      
wield(arg) {
   if (id(arg)) {
      TP->wield(this_object());
      write(TPN+" uses ........\n");
    return 1;
     }
  }

un_wield() {
     return 1;
   }
 

 
do_att(arg) {
  if (a_flag) {
     write("You are busy doing another attack.\n");
     return 1;
  }
  a_flag=query_verb();
  a_arg=arg;
  return 1;
}
 
time_guild_soul() {

  
  if (a_flag) {
     call_other(this_object(),a_flag,a_arg);
     a_flag=0;
  }

  if(meditate && TPH==TP->query_maxhp() && TPS==TP->query_maxsp()) {
    tell_object(TP,"You are completely healed.\n");
    sleeper->dest_me();
   return 1; 
   }

  hb_lock=0;

  feeter++;
  if(nofeeter && feeter>4) nofeeter=0;
  if(feeter>TPC*10) feeter=TPC*10; 

  if(meditate && TPH==TP->query_maxhp() && TPS==TP->query_maxsp()) {
    tell_object(TP,"You are completely healed.\n");
    sleeper->dest_me();
   }
  
   fattack=0;
   if(TP && !TP->query_wielded()) TP->wield(this_object());
}

/* ##################### now we check the armour ######################## */

check(arg) {
    object ob;
     
     if(!arg) {
       write("Check what ?\n");
     return 1;
    }
   
    if(ob=present(arg,TP)) {
      if(!ob->query_type()) {
        write("That's no armour.\n");
     return 1;
    }
    write("You are now sure that you are\n");
    if(!(ob->query_monk_wear() || ob->armour_class()==0))
      write("not allowed to wear these armour.\n"); 
    else
      write("allowed to wear these armour.\n"); 
    }
    else
     write("You dont have that item.\n");
    return 1;
   }
  query_monk_wear(){ return 1; }

/* #################### now to the helpdir ######################### */

help(str) {
string s;
 
  if (!str) return;

  if (str=="level" || str=="levels")   {
   list_the_levels();
   return 1;
  }
  if (sizeof(explode(str," "))==1 && file_size(s=helpdir+"/"+str)>0) {
     cat(s);
     return 1;
  }
  return 0;
 }

list_the_levels() { return GM->list_levels(gd,TP->query_gender()); }

/* ###################### recognize if fighting ###################### */

recognize_fight() {
      set_heart_beat(1);
      if(meditate && sleeper) {
        sleeper->dest_me();
     }
   }

heart_beat() {
   object ob;
   
   if ((ob=TP->query_attack()) && (E(ob)==E(ob))) {
       if ((random(20)+TPD)>=random(60)) { TP->attack(); }
       }
       else {
         set_heart_beat(0);
         }
      }
   
/* ############################ silence ################################# */

   silence(arg) {
      int lev; 

     if (!arg) {
       write("You must give an argument <= your level !\n");
     return 1;
    }
    if (sscanf(arg, "%d", lev)) {
       if (lev>TPL) {
       write("Give an argument <= your own level !\n");
       return 1;
       }
     TP->listen_shout(lev+1);
     write("Your actual silence level is now: "+lev+"\n");
     return 1;
    }
   return 1;
   }
      
/* ############################# guild talk ############################# */

    
monk(str) {
    string msg;
    object *u;
    int i;
    u=users();
    msg="Monks online:\n\n";

   if (TPS < 3) {
      write("You are too low on power.\n");
      return 1;
     }
    if (str) { 
    TP->restore_spell_points(-3);
    for(i=0;i<sizeof(u);i++)
     if (u[i]->query_guild()==gd && u[i]->query_earmuff_level()<TPL) {
       tell_object(u[i],"[*"+TPN+"*] "+str+".\n");
     }
     tell_object(TP,"Ok.\n"); 
     return 1;
    }
     for (i=0;i<sizeof(u);i++)
     if ((u[i]->query_guild()==gd) && (!(u[i]->query_wizard() && u[i]->query_invis())))
          if (u[i]->query_earmuff_level()>=TPL && u[i]->query_level()<30) {
     msg+=u[i]->N+", "+u[i]->query_gender_string()+" "+u[i]->query_race()+
     " "+"("+u[i]->query_level()+")"+" (mortal) (busy).\n";
          }
       else if (u[i]->query_earmuff_level()>=TPL && u[i]->query_level()>=30) {
    msg+=u[i]->N+", "+u[i]->query_gender_string()+" "+u[i]->query_race()+
    " "+"("+u[i]->query_level()+")"+" (immortal).\n";
       }
       else if (u[i]->query_level()<30) {
    msg+=u[i]->N+", "+u[i]->query_gender_string()+" "+u[i]->query_race()+
    " "+"("+u[i]->query_level()+")"+" (mortal).\n";
       }
          else {
    msg+=u[i]->N+", "+u[i]->query_gender_string()+" "+u[i]->query_race()+
    " "+"("+u[i]->query_level()+")"+" (immortal).\n";
         }
     write(msg);
   return 1;
   }

/* ############################# mt ##################################### */

mt(str) {

   string message,whom;
   object who;

     if (chk_fiz()) { return 1; }
     CHK_GHOST;  

     if (TPS < 2) {
        write("You are too low on power.\n");
      return 1;
     }

     if (!str || sscanf(str, "%s %s", whom, message) !=2) {
         write("Whom ?\n");
        return 1;
       }

      who=find_living(lower_case(whom));

     if (!who) {
        write("As strong you concentrate you can't find "+whom+"\n");
       return 1;
     }
    if (who->query_earmuff_level()>=TPL) {
      tell_object(TP,"This player is busy now, try later.\n");
      return 1;
     }

  tell_object(who,":*) "+capitalize(TPR)+" thinks: "+message+"\n");
  write("You conzentrate on "+who->N+".\n");
  TP->restore_spell_points(-2);
  return 1;
}

/* ############################ sign ############################### */

sign(arg) {
  object sign;

 CHK_GHOST;
 if (chk_fiz()) return 1;
 if (!arg) {
    write("Syntax: sign <text>\n");
    }
    
 if (TPS < 80) {
    write("You are too low on mental energie, to build up that spiritual powerfield.\n");
    return 1;
    }
  sign=clone_object("players/whisky/guild/sign");
  sign->set_what(arg);
  move_object(sign,E(TP));
  SAY(TPN+" conzentrates and builds up a spiritual powerfield !\n"); 
  TP->restore_spell_points(-80);
  return 1;
  } 
   
/* ###################### run away ############################### */
    
runaway() {
      object ob;
      int i;
   if (E(TP)->query_property("no_teleport")) {
   write("As strong you concentrate, you are not able to leave this place.\n"); 
   return 1;
   }
   tell_object(TP,"You get into panic, you drop some of your stuff\n"+
                  "and run as fast as you can home to your guild !!\n");
   ob=all_inventory(TP);
   for(i=0;i<sizeof(ob);i++)
      if ((ob[i]->query_weight()>1)) {
         if (random(TPC*2+80)>60) { TP->drop_one_item(ob[i]); }
     }
   TP->move_player("as fast as possible#players/whisky/guild/room/c10");
   return 1;
}
    
/* ####################### aikido ################################## */

aikido() {
   int class;    
   class=FORMULA2_N_AC;   
   CHK_GHOST;
   if (chk_fiz()) return 1;
   if (count > 0) {
     write("You are already concentrated.\n");
   return 1;
   }
   if (TPS < SP_AIKIDO) {
     tell_object(TP,"You are too braindamaged for aikido !\n");
   return 1;
   }
   SAY(TPN+" starts to concentrate on aikido !\n");
   TP->set_n_ac(class);
   TP->recalc_n_ac();
   count=1;
   TP->restore_spell_points(-SP_AIKIDO);
   aik="You are conzentrated on aikido.";
   call_out("noaikido",400+TPW*8);
   return 1;
   }

noaikido() {
    tell_object(TP,"\nYou suddenly loose your conzentration\n"+
                   "and turn back normal.\n");
#if 1
    TP->set_n_ac(FORMULA1_N_AC); /* Done by Herp: why, all others have nac 0 */
#else
    TP->set_n_ac(0);
#endif
    TP->recalc_n_ac();
    aik="You are NOT conzentrated on aikido !!!!";
    count=0;
    return 1;
}

/* ###################### shuffle ################################## */ 

shuffle(arg) {
    object ob,env;
    int i;
    string str1,str2;
    
    env=all_inventory(environment(TP));
    
    CHK_GHOST; 
    if (!arg) {
        write("With whom ?\n");
      return 1;
      }
      
    ob=present(arg,E(TP));    
          
    if (TP->query_gender()==2) {
       str1="sexy pussy";
       }
    else if (TP->query_gender()==1) {
       str1="sexy penis";
       }
    else {
       str1="sexual-organ";
       }
      
    
    if ((!ob) || (!living(ob))) {
       write("At whom ?\n");
     return 1;
     }
     
    if (ob->query_gender()==2) {
       str2="sexy pussy";
       }
    else if (ob->query_gender()==1) {
       str2="sexy penis";
       }
    else {
      str2="sexual-organ";
      }

   for(i=0;i<sizeof(env);i++) {
      if (env[i]!=TP && env[i]!=ob && living(env[i])) {
         tell_object(env[i],TPN+" does the hot shuffle with "+ob->query_name()+"!\n");
         }
       }
   write("You make the  hot guild shuffle with "+ob->query_name()+".\n"+
         "You take "+ob->query_name()+" by "+ob->query_possessive()+" hips and dance around.\n"+
         "You circle with your "+str1+" around "+ob->query_name()+"'s "+str2+".\n"+
         "You get a good feeling and feel somehow satiesfied.\n");
         
   tell_object(ob,TPN+" makes the hot monks guild shuffle with you.\n"+
         TPN+" takes you by your hips and dances around.\n"+
         TPN+" circles with "+TPP+" "+str1+" around your "+str2+".\n"+
         "You get suddenly a good feeling between your legs.\n");
         
   return 1;
   }

 
     
      
/* ###################### feet ##################################### */

feet(arg) {

    object ob;
    int i,j;


    if (nofeeter) {   
       write("Your feet are too tired to make a hit.\n");
    return 1;
    }
    if (fattack) return 1; 
    if(chk_fiz()) return 1;
    if(!arg) {
      ob=TP->query_attack();
      if(ob) arg=ob->N;
     }
     else ob=present(arg,E(TP));
    
    if ((!ob) || (!living(ob)) || (!present(ob,E(TP)))) {
       write("At whom ?\n");
    return 1;
    }            
    CHK_GHOST;
    hb_lock=1;
    ob->attacked_by(TP);

    switch(random(11)) {
     case 0:
     case 1:
      SAY(TPN+" hits "+arg+" with "+TPP+" right foot.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET*2));   
      fattack++;
      break;
      case 2:
      SAY(TPN+" tries to hit "+arg+" with "+TPP+" right foot, but misses.\n");
      fattack++;
      break;
      case 3:
      case 4:
      SAY(TPN+" hits "+arg+" with "+TPP+" left foot.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET*2));   
      fattack++;
      break;
      case 5:
      SAY(TPN+" tries to hit "+arg+" with "+TPP+" left foot, but misses.\n");
      fattack++;
      break;
      case 6:
      SAY(TPN+" hits "+arg+" with "+TPP+" right knee.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET));   
      fattack++;
      break;
      case 7:
      SAY(TPN+" tries to hit "+arg+" with "+TPP+" right knee, but misses.\n");
      fattack++;
      break;
      case 8:
      SAY(TPN+" hits "+arg+" with "+TPP+" left knee.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET));  
      fattack++;
      break;
      case 9:
      SAY(TPN+" tries to hit "+arg+" with "+TPP+" left knee, but misses.\n");
      fattack++;
      break;
      case 10:
      SAY(TPN+" hits "+arg+" on a critical spot.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET*6));
      break;
      return 1;
     }
                                 
    if(feeter<=0) nofeeter=1;
    feeter=feeter-3;
    return 1;
  }

/*  ###########################  charm   ################################## */ 


charm(arg) {
object ob;
int i,j;


    if (fattack) return;
    if (chk_fiz()) return;
    if (!arg) {
       ob=TP->query_attack();
    if (ob) arg=ob->query_name();
    }
    else ob=present(arg,E(TP));
    if ((!ob) || (!living(ob)) || (!present(ob,E(TP)))) {
       write("At whom ??\n");
    return 1;
    }
    if (TPS < (SP_CHARM)) {
      write("You are too low on power, better run away.\n");
     return 1;
    }
    if ((i=TPCH*2)<=(j=ob->C) || random(i) <= random(j*2)) {
       write("You try to charm "+ob->N+" but you fail.\n");
       TP->restore_spell_points(-SP_CHARM);
     return 1;
     }
     if (ob->query_wielded()) { 
       ob->stop_wielding(); 
       tell_object(ob,"You feel "+TPN+" charmingly looking into your eyes.\n");
       tell_object(TP,"You look charmingly into the eyes of "+
                  ob->query_name()+"\n and force "+ob->query_name()+
                 " to remove "+ob->query_possessive()+" wielded weapon.\n");    
    
       TP->restore_spell_points(-SP_CHARM);
      return 1;
    }
    tell_object(TP,""+ob->query_name()+" has no wielded weapon.\n");
    return 1;
}
                                        
/* ###################### meditate ################################# */

meditate(arg) {

   CHK_GHOST;
   move_object(sleeper=clone_object("players/whisky/guild/sleeper"),TP);
   sleeper->start_meditate(this_object());
   SAY(TPN+" sits down in the lotus-position.\n");
   return 1;
   }

   set_meditate(a) { meditate=a; }
   
/* ####################### death ################################# */

death(arg) {

   object ob;
 
   if(chk_fiz()) return 1;
   CHK_GHOST;
   hb_lock=1;

   if (!arg) {
      ob = TP->query_attack();
      if(ob) arg=ob->query_name();
    }
    else ob=present(arg,E(TP));
    if (POWER < ALLOW_DEATH) {
      write("You are too weak for this kind of attack.\n");
    return 1;
    }
   if ((TPS <= (SP_DEATH)) || (TPH <= (HP_DEATH))) {
     write("You are less powerful for this attack.\n");
   return 1;
   }
   
       
  if ((!ob) || (!living(ob)) ||  (ob->query_invis()) ||(!present(ob,E(TP)))) {
      write("At whom ?\n");
   return 1;
  }
  
  else if (TPL < (8+random(8))) {
     SAY(TPN+" conzentrates all "+TPP+" power at "+ob->query_name()+" but misses !\n");
     TP->hit_player(HP_DEATH);
     TP->restore_spell_points(-SP_DEATH);
   return 1;
   }
       
  else {
  ob->attacked_by(TP);
  SAY(TPN+" conzentrates all "+TPP+" power and does an awful hit at "+
  ob->query_name()+".\n");
#if 0
  TP->add_exp(ob->hit_player(FORMULA_DEATH)); 
#endif
  TP->add_exp(ob->hit_player(FORMULA_DEATH));
  TP->hit_player(HP_DEATH); 
  TP->restore_spell_points(-SP_DEATH); 
  if (TP->query_wizard()) { write("Damage (wizinf.): "+FORMULA_DEATH+"\n"); } 
  fattack++;
  return 1;
  } 
 }

/* ############################   smash  ############################### */

smash(arg) {
   object ob;
   string how;

   if (random(100)<50) {
      how="right";
      }
    else {
      how="left";
     }
  
   if(chk_fiz()) return 1;
   CHK_GHOST;
   hb_lock=1;

   if (!arg) {
      ob = TP->query_attack();
      if(ob) arg=ob->query_name();
    }
    else ob=present(arg,E(TP));
  
  if ((!ob) || (!living(ob)) ||  (ob->query_invis()) ||(!present(ob,E(TP)))) {
      write("At whom ?\n");
   return 1;
  }
  if (ob->query_size()>4) {
     write(ob->query_name()+" is too big to do that.\n");
  return 1;
  }
  if (ob->query_size()<2) {
     write(ob->query_name()+" is too small to do that.\n");
  return 1;
  }
   if (POWER < ALLOW_SMASH) {
      write("You are too weak for this kind of attack.\n");
    return 1;
    }
    if (TPS <= (SP_SMASH)) {
     write("You are less powerful for this attack.\n");
   return 1;
   }
   
    else if (TPL < (4+random(6))) {
     SAY(TPN+" tries to holds down the head of "+ob->query_name()+" and raises "+TPP+" knee,\n"+
     "but misses !\n");
     TP->restore_spell_points(-SP_SMASH);
   return 1;
   }

   else {
    ob->attacked_by(TP);
    SAY(TPN+" holds "+ob->query_name()+" down by "+ob->query_possessive()+" neck and raises "+TPP+" "+how+" knee !\n");  
    tell_object(ob,"You feel your head exploding !\n");
    TP->add_exp(ob->hit_player(FORMULA_SMASH));  
    if (ob) { ob->hold(ob,MAX_H_SMASH); 
    TP->restore_spell_points(-SP_SMASH);
    }
    if (TP->query_wizard()) { write("Damage (wizinf): "+FORMULA_SMASH+"\n"); } 
    fattack++;
    return 1;
 }
}
/* ############################## choke ################################  */
choke(arg) {

   object ob;
  
   if(chk_fiz()) return 1;
   CHK_GHOST;
   hb_lock=1;

   if (!arg) {
      ob = TP->query_attack();
      if(ob) arg=ob->query_name();
    }
    else ob=present(arg,E(TP));
   if (POWER < ALLOW_CHOKE) {
      write("You are too weak for this kind of attack.\n");
    return 1;
    }
   if (TPS <= SP_CHOKE) {
     write("You are less powerful for this attack.\n");
   return 1;
   }
  if ((!ob) || (!living(ob)) ||  (ob->query_invis()) ||(!present(ob,E(TP)))) {
      write("At whom ?\n");
   return 1;
  }
  else {
  ob->attacked_by(TP);
  if (ob->query_size()<2) {
  SAY("Argggggggggg "+TPN+" bends over to "+ob->query_name()+" and chokes "+ob->query_possessive()+" neck !\n");
     }
   else if (ob->query_size()<4) {
  SAY("Argggggggggg "+TPN+" knocks "+ob->query_name()+" down and chokes "+ob->query_possessive()+" neck !\n");
     }
   else {
  SAY("Argggggggggg "+TPN+" jumps at "+ob->query_name()+" and chokes "+ob->query_possessive()+" neck !\n");
     }
  tell_object(ob,"You feel your air getting lower !!!!\n");
  TP->add_exp(ob->hit_player(FORMULA_CHOKE)); 
  TP->restore_spell_points(-SP_CHOKE);
  if (TP->query_wizard()) { write("Damage (wizinf): "+FORMULA_CHOKE+"\n"); } 
  fattack++;
  return 1;
  } 
 }
/* ########################## pentagram ############################### */
 
  pentagram(arg) {
   object pent; 
   
   if (TPL < 8 || TPS < SP_PENTA) {
    write("You are too low on power to create a pentagram.\n"); 
   return 1;
   }
   SAY(TPN+" sinks into deep concentration and starts to build a pentagram of earth.\n");
         TP->restore_spell_points(-SP_PENTA);
   pent=clone_object("players/whisky/guild/pentagram");
   if(transfer(pent,TP)) {
     write("Unfortunately, you are carrying too much to hold it.\n");
     SAY(TPN+" drops the pentagram and it disintegrates.\n");
     destruct(pent);
   }
   return 1;
  } 

/* ############################ cure ##############################  */

cure(arg) {

   object ob;

   if(chk_fiz()) return 1;
   if (!arg || !(ob=present(arg,E(E()))) || !living(ob)) {
     write("Cure whom ?\n");
     return 1;
   }
   if (ob==this_player()) {
      write("You can't cure yourself without assistance.\n");
      return 1;
   }
   if (TPS <= SP_CURE_TARGET) {
      write("You are too low on power.\n");
   return 1;
   }
    if (ob->query_spell_points()<=10) {
      write("That's too strong medicine for "+ob->query_name()+" right now.\n");
      return 1;
   }
   SAY(TPN+" lies "+TPP+" hands on "+ob->query_name()+".\n");
   ob->heal_self(HP_CURE);
   ob->restore_spell_points(-SP_CURE);
   TP->restore_spell_points(-SP_CURE_TARGET);
   return 1;
}

/* #################### perception a monster ############################ */
  
perception(arg) {
      object ob;
      int d1, d2, d3, d4;
      string pronoun, possessive;
   
      if (chk_fiz()) return 1;
      if(arg) {
        ob = present(lower_case(arg),E(TP));
      if(!ob) {
         write("There is no "+arg+" present.\n");
      return 1;
      } 
      if (!living(ob)) {
         write("This is not a living thing !\n");
      return 1;
      } 
   }
   else
     ob = TP->query_attack();

   if(!ob) {
     write("Nothing to check !\n");
   return 1;
  }
   pronoun = ob->P;
   
   if(!pronoun) pronoun = "it";
   possessive = ob->query_possessive();
   if(!possessive) possessive = "its";

   write("The name is "+ob->query_name()+".\n");

   d1 = (ob->L - TPL)*100/TP->L;
   d2 = ob->query_hp() - TP->query_hp();
   d3 = ob->query_ac() - TP->query_ac();
   d4 = ob->query_wc() - TP->query_wc();

   if (d1 >= 300) {
      write("After checking "+ob->N+" you are sure that this "+
            "opponent will be your death.\n");
      }
   else if (d1 >= 150) {
      write("After checking "+ob->N+" you are sure that this "+
            "opponent might be your death.\n");
      }
   else if (d1 >= 100) {
      write("After checking "+ob->N+" you think you are miles "+
            "under "+ob->query_possessive()+"'s power.\n");
   }
  
   else if (d1 >= 50) {
      write("After checking "+ob->N+" you think you are "+
            "under "+ob->query_possessive()+" power.\n");
   }

   else if (d1 >= 25) {
      write("After checking "+ob->query_name()+" you think you are a bit "+
            "under "+ob->query_possessive()+" power.\n");
   }
  
   else if (d1 >= 0) {
      write("After checking "+ob->N+" you think you "+
            "have nearly "+ob->query_possessive()+" power.\n");
   }

   else if (d1 >= -25) {
      write("After checking "+ob->N+" you think you "+
            "are a bit above "+ob->query_possessive()+" power.\n");
   }
   else if (d1 >= -50) {
     write("After checking "+ob->N+" you think you "+
           "are high above "+ob->query_possessive()+" power.\n");
   }
   else {
     write("After checking "+ob->N+ " you think you "+
           "are far above "+ob->query_possessive()+" power.\n");
   }

   if (d2 == 0) {
      write(capitalize(pronoun) + " is in the same condition than you.\n");
   }
   else if (d2 > 0) {
      write(capitalize(pronoun) + " is in a better condition than you !\n");
  }
   else {
      write(capitalize(pronoun) + " is in a worse condition than you.\n");
  }
   if (d3 == 0) {
      write(capitalize(possessive) + " armour is as good as yours.\n");
   }
   else if (d3 > 0) {
      write(capitalize(possessive) + " armour is better !\n");
   }
   else {
      write(capitalize(possessive) + " armour is worse.\n");
   }
   if (d4 == 0) {
      write(capitalize(possessive) + " weapon seems to be as good as yours.\n");   }
   else  if (d4 > 0) {
      write(capitalize(possessive) + " weapon seems to be better !\n");
   }
   else {
      write(capitalize(possessive) + " weapon seems to be worse.\n");
   }
   return 1;
 }
           
  /*####################     discharge     ###############################  moved out

discharge(arg) {

   object ob;
   int i,j;
  
   if(chk_fiz()) return 1;
   CHK_GHOST;
   hb_lock=1;
   if (!arg) {
      ob = TP->query_attack();
      if(ob) arg=ob->N;
    }
    else ob=present(arg,E(TP));
  
  if ((!ob) || (!living(ob)) ||  (ob->query_invis()) || (!present(ob,E(TP)))) {
      write("At whom ?\n");
   return 1;
  }

  if (ob->query_spell_points() <= 20) {
   tell_object(TP,""+ob->query_name()+"'s power is already discharged.\n");
   return 1;
  }
  if ((ob->query_player()) && (ob->query_wis() >= (TPW*3/2))) {
  tell_object(TP,"You are too low on wisdom to discharge "+ob->query_name()+".\n");
    tell_object(ob,""+TPN+" tried to discharge you but failed.\n");
  return 1;
  }

  if (E(TP)->try_attack(TP)) 
     return 1;

  i = ob->query_spell_points();
  TP->restore_spell_points(((i+1)/30)*(TPW/8+TPCH/8+1)+random(8)+1);
  ob->restore_spell_points(1-i);  

  SAY(TPN+" conzentrates on "+ob->N+" and discharges "+ob->query_possessive()+
     " power.\n");
  tell_object(TP,ob->N+" gets angry.\n");

 if ((!ob->query_npc() && ob->L< TPL*2)||(ob->L<random(TPL)*2)) {
  tell_object(ob,"\n\nYou feel your power getting lower !!!!\n\n\n");
  
  
  
   if (ob->query_chr()<=(random(TPCH)*2)) { 
    tell_object(ob,"\n\nYou get a shock and run away !!!!\n\n");
    tell_object(TP,ob->query_name()+" runs away in panic !\n");
    ob->run_away();
    }

   }
  ob->attacked_by(TP);
  return 1;
}

 #################### commands which don't work ####################### */

   missile(arg) {
     write("You are no mage !\n");
     return 1;
   }
   shock(arg) {
     write("You are no mage !\n");
     return 1;
   }
   fireball(arg) {
     write("You are no mage !\n");
     return 1;
   }

 /* ######################## F I N ################################# */


