/* #################################################################

            T H E  M O N K S - G U I L D  (c) Whisky
                    new version (c)
  
  ##################################################################   */


inherit "obj/armour";

#define HP_CURE		40	
#define SP_CURE		50
#define	SP_CURE_TARGET	30		
#define FORMULA1_N_AC	(2+TPW/10)
#define FORMULA2_N_AC	(2+TPW/3)
#define	SP_AIKIDO       (8+TPW/2) 	
#define DUR_AIKIDO      100+TPW*3 
#define FORMULA_WC      random(5+(TPW+TPD)/4)   
#define FORMULA_DEATH   (TPW+TPD)/2+random((TPW+TPD)*3)  
#define HP_DEATH        TPC*2/3
#define SP_DEATH        10+(TPW+TPD+TPI/3)
#define ALLOW_DEATH     6
#define FORMULA_SMASH   (random(20)+TPD)
#define SP_SMASH        25+TPD
#define MAX_H_SMASH     random(2+TPD/9)
#define ALLOW_SMASH     6
#define SP_CHARM        TPI*2
#define MAX_C_CHARM     TPCH*3
#define FORMULA_FEET    random((TPW+TPD)/3+5)
#define FEET_CON        30+TPC*3
#define SP_PENTA        60
#define MAX_INTO        TPST+20

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
 string dir, helpdir, room, aik;
 int fattack,counter,feeter;  
 int meditate,nofeeter,count;
 int next, diff, n, s;
 int hb_lock;	
 object sleeper;
/*************************************************************
* 	simulate the GM-functions for debug purpose	     *
*************************************************************/
#if 0
query_number(str) { return 6; }
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
  
/* ################# checking if a spell fizzels ################### */

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
  set_alias(GM->query_id(gd));
  dir=GM->query_dir(gd);  
  helpdir="/"+dir+"/helpdir";
  room=GM->query_room(gd); 
  set_id("monk robe");
  set_short("monks robe");
  set_long("A beautiful brown monks-robe.\n");
  set_weight(1);
  set_type("robe");
}

drop() { return 1; }	

/*########################## the init ################################## */

weapon_class() {
   return;  
   }    

hit(attacker) { 
  int i;
  string enemie;
    
    i = random(8);
    enemie=attacker->N;
 if (i==0) {
    SAY(TPN+" tries to hit "+enemie+" with "+TPP+" right fist.\n");
    return (2*FORMULA_WC);            
  }
 else if (i==1) {
    SAY(TPN+" tries to hit "+enemie+" with "+TPP+" left fist.\n");
    return (2*FORMULA_WC);            
  }
 else if (i==2) {
    SAY(TPN+" tries to hit "+enemie+" with "+TPP+" right elbow.\n");
    return (FORMULA_WC);            
  }
 else if (i==3) { 
    SAY(TPN+" tries to hit "+enemie+" with "+TPP+" left elbow.\n");
    return (FORMULA_WC);            
  }
 else if (i==4) {
    SAY(TPN+" tries to hit "+enemie+" with "+TPP+" right shoulder.\n");
    return (FORMULA_WC);            
 }
 else if (i==5) {
    SAY(TPN+" tries to hit "+enemie+" with "+TPP+" left shoulder.\n");
    return (FORMULA_WC);            
  }
  else if (i==6) {
   SAY(TPN+" runs against "+enemie+".\n");
   return (3*FORMULA_WC);            
  }
  else {
   SAY(TPN+" tries to hit "+enemie+" on a critical spot.\n");
   return (5*FORMULA_WC);            
  }
 return 1;    
} 
remove(arg) {
  if(id(arg)) {
    write("You can't remove your monk robe.\n");
    return 1;
  }
}

/* ########################	init	########################### */

init() {
   ::init();
   if (!(TP=environment(this_object()))) return;
   TP->set_n_ac(FORMULA1_N_AC);
   TP->wield(this_object());
   if (!worn)
   command("wear robe",TP);  
   n=1;
   add_action("help","help");
   add_action("monk","monk");
   add_action("vitals","vitals");
   add_action("runaway","runaway");
   add_action("charm","charm");    
   add_action("aikido","aikido");
   add_action("cure","cure");
   add_action("feet","feet");
   add_action("death","death");
   add_action("smash","smash");
   add_action("pentagram","pentagram");
   add_action("wake_up","wake_up");
   add_action("check","check");
   add_action("perception","perception");
   add_action("mt","mt");
   add_action("discharge","discharge"); 
   add_action("missile","missile");
   add_action("shock","shock");
   add_action("fireball","fireball");
   add_action("meditate","meditate");
   feeter=FEET_CON;
  }

  extra_look() {
   string text;
    text=capitalize(TP->P)+" is beautiful and sexi.\n"+ 
    capitalize(TPP)+" eyes are glowing like burning diamonds.\n"+ 
    capitalize(TP->P)+" is covered by a bright mystical powerfield "; 
    return text;
    }

  vitals() {
   string stren;
   if (!aik) { aik="You are NOT conzentrated on aikido !!!!"; }
    if (INTRO >= (TPL/4+TPW/4+TPI/4+TPC/4+28))  {
       stren=" paralytic";
    }
    else if (INTRO >= 40) {
       stren=" drunk as a fiddler's bitch";
    }
    else if (INTRO >= TPS/2) {
       stren=" drunken as a lord";
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
   "Hitpoints: "+TPH+" of ("+TP->query_max_hp()+")\n"+
   "Spellpoints: "+TPS+" of ("+TP->query_max_sp()+")\n"+
   "Intoxination: "+stren+"  ("+INTRO+" "+"%. blood-alcohol).\n"+
   aik+"\n\n");
    
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
   
time_guild_soul() {
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
  int i;
  string mhelp;
  mhelp = ({ "/players/whisky/guild/helpdir" });
 
  if (!str) return;

  if (str=="level" || str=="levels")   {
   list_the_levels();
   return 1;
  }
  str= "/"+str;
  i=0;
  while(i<sizeof(mhelp)) {
   if (file_size(mhelp[i]+str) > 0) {
    cat(helpdir+"/"+str);
   return 1;
    }
   i++;
   }
  return;
 }
/*
  list_the_levels() { return GM->list_levels(gd,TP->query_gender()); }
  */

/* ###################### recognize if fighting ###################### */

recognize_fight() {

    if (TP->query_invis()) {
       write("You come out from your hidden state.\n");
       TP->set_vis();
      } 
      if(meditate && sleeper) {
        sleeper->dest_me();
     }
   }

/* ############################# guild talk ############################# */

monk(str) {
    string msg;
    object *u;
    int i;
    u=users();
    msg="Monks online:\n\n";
    if (str) { 
    for(i=0;i<sizeof(u);i++)
     if (u[i]->query_guild()==gd && u[i]->query_earmuff_level()<=TPL) {
       tell_object(u[i],"[*"+TPN+"*] "+str+".\n");
     }
     tell_object(TP,"Ok.\n"); 
     return 1;
    }
     for (i=0;i<sizeof(u);i++)
     if (u[i]->query_guild()==gd && !u[i]->query_wizard())
          msg+=u[i]->N+".\n";
     write(msg);
   return 1;
   }

/* ############################# mt ##################################### */

mt(str) {

   string message,whom;
   object who;

     if (chk_fiz()) { return 1; }
     CHK_GHOST;  

     if (TPS < 1) {
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
     if (who->query_wizard() && who->query_invis()) {
        write("No player with that name.\n");
     return 1;
     }
        
     if (who->query_earmuff_level()>TPL && who->query_vis()) {
        write("That wizard is busy right now, try again later.\n");
      return 1;
     }

  tell_object(who,"[*"+TPN+" thinks *]:"+" "+message+"\n");
  write("You conzentrate on "+who->N+".\n");
  TP->restore_spell_points(-1);
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
      if ((ob[i]->query_weight()>=1)) {
         if (random(TPC*3+40)>60) { TP->drop_one_item(ob[i]); }
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
     write("You are already conzentrated.\n");
   return 1;
   }
   if (TPS < SP_AIKIDO) {
     tell_object(TP,"You are too braindamaged for aikido !\n");
   return 1;
   }
   tell_object(TP,"You start to conzentrate on aikido.\n");
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

    switch(random(9)) {
     case 0:
      SAY(TPN+" hits "+arg+" with "+TPP+" right foot.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET*2));   
      fattack++;
      break;
      case 1:
      SAY(TPN+" tries to hit "+arg+" with "+TPP+" right foot, but misses.\n");
      fattack++;
      break;
      case 2:
      SAY(TPN+" hits "+arg+" with "+TPP+" left foot.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET*2));   
      fattack++;
      break;
      case 3:
      SAY(TPN+" tries to hit "+arg+" with "+TPP+" left foot, but misses.\n");
      fattack++;
      break;
      case 4:
      SAY(TPN+" hits "+arg+" with "+TPP+" right knee.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET/2));   
      fattack++;
      break;
      case 5:
      SAY(TPN+" tries to hit "+arg+" with "+TPP+" right knee, but misses.\n");
      fattack++;
      break;
      case 6:
      SAY(TPN+" hits "+arg+" with "+TPP+" left knee.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET/2));  
      fattack++;
      break;
      case 7:
      SAY(TPN+" tries to hit "+arg+" with "+TPP+" left knee, but misses.\n");
      fattack++;
      break;
      case 8:
      SAY(TPN+" hits "+arg+" on a critical spot.\n");
      TP->add_exp(ob->hit_player(FORMULA_FEET*4));  
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
    if (MAX_C_CHARM < random(ob->C*3)) {   
       write("You try to charm "+ob->N+" but you fail.\n");
       TP->restore_spell_points(SP_CHARM);
     return 1;
    }
     if (ob->query_wielded()) { 
       ob->stop_wielding(); 
       tell_object(ob,"You feel "+TPN+" charmingly looking into your eyes.\n");
       tell_object(TP,"You look charmingly into the eyes of "+
                  ob->query_name()+"\n and force "+ob->query_name()+
                 " to remove "+ob->query_possessive()+" wielded weapon.\n");    
      TP->restore_spell_points(-(SP_CHARM));
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
   if (TPL <=10 )  {     
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
  else {
  ob->attacked_by(TP);
  SAY(TPN+" conzentrates all "+TPP+" power and does an awful hit at "+
  ob->query_name()+".\n");
  TP->add_exp(ob->hit_player(FORMULA_DEATH)); 
  TP->restore_spell_points(-SP_DEATH); 
  TP->hit_player(HP_DEATH); 
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
   if (TPL < 5)  {     
      write("You are too weak for this kind of attack.\n");
    return 1;
    }
    if (TPS <= (SP_SMASH)) {
     write("You are less powerful for this attack.\n");
   return 1;
   }
   else {
    ob->attacked_by(TP);
    SAY(TPN+" holds "+ob->query_name()+" down by "+ob->query_possessive()+" neck and raises "+TPP+" "+how+" knee !\n");  
    tell_object(ob,"You feel your head exploding !\n");
    TP->add_exp(ob->hit_player(FORMULA_SMASH));  
    ob->hold(ob,MAX_H_SMASH); 
    TP->restore_spell_points(-SP_SMASH);
    fattack++;
    return 1;
 }
}
/* ########################## pentagram ############################### */
 
  pentagram(arg) {
   
   if (TPL < 8 || TPS < SP_PENTA) {
    write("You are too low on power to create a pentagram\n"); 
   return 1;
   }
   SAY(TPN+" sinks into deep concentration.\n"+
      "Bright balls of lighning flashes out from "+TPN+"'s eyes.\n"+
      "The earth seems to move as suddenly a small item appears into\n"+
       TPN+"'s hands.\n");
   TP->restore_spell_points(-SP_PENTA);
   move_object(clone_object("players/whisky/guild/pentagram"),TP);
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
   if (TPS <= SP_CURE) {
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
           
  /*####################     discharge     ############################### */

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
  TP->restore_spell_points(((i+1)/20)*(TPW/4+1)+random(8)+1);
  ob->restore_spell_points(1-i);  

  SAY(TPN+" conzentrates on "+ob->N+" and discharges "+ob->query_possessive()+
     " power.\n");
  tell_object(TP,ob->N+" gets angry.\n");

 if ((!ob->query_npc() && ob->L< TPL*2)||(ob->L<random(TPL)*2)) {
  tell_object(ob,"\n\nYou feel your power getting lower !!!!\n\n\n");

   if(random(ob->query_chr())<=random(TPCH)) { 
    tell_object(ob,"\n\nYou get a shock and run away !!!!\n\n");
    tell_object(TP,ob->query_name()+" runs away in panic !\n");
    ob->run_away();
    }

   }
  ob->attacked_by(TP);
  return 1;
}

 /* #################### commands which don't work ####################### */

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


