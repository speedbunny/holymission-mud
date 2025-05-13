/* #################################################################

            T H E  N I N I J A - G U I L D  (c) Patience
                  (ninijas are a kind of fighter)
  
  ##################################################################   */


inherit "obj/armour";

#define FORMULA_WC      (random(15+TPW/2+TPD/2)/2)
#define FORMULA_FEET    (random((TPW+TPD)/3+6))
#define FEET_CON        (40+TPC*4)

#define GM  "guild/master" 
#define GUILD  "Ninija"  
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
 string a_flag;             /* which attack is executed next hb */
 string a_arg;              /* attack argument */
 object sleeper;

/*************************************************************
*   simulate the GM-functions for debug purpose      *
*************************************************************/
 
query_number(str) { return 7; }
query_id(nr) { return "monksoul"; }
query_dir(nr) { return "players/patience/guild"; }
query_room(nr) { return "players/patience/guild/room"; }
list_levels(nr,gen) { return TP->more("/players/patience/guild/ninijatitles.c"); }

 
/* ############## checking if the player is too busy ############## */ 

#define ATT();\
  if ((att=TP->query_attack()) && present(att,E(TP))) {\
  return 1;\
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
  /* gd=GM->query_number(GUILD);
     id=GM->query_id(gd);
     dir=GM->query_dir(gd);  */  
  helpdir="/"+dir+"/helpdir";
    /*  room=GM->query_room(gd);  */
  set_id("headband");           
  set_type("guild");
  set_alias(id);            
  set_short("A red headband");
  set_long("A soft red headband.\n");
  set_weight(0); 
  set_type("headband");
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
    write("You can't remove your headband.\n");
    return 1;
  }
}

/* ######################## init    ########################################## */

init() {
   ::init();
   if (!(TP=environment(this_object()))) return;
   TP->wield(this_object());
   if (!worn && !TP->query_wizard()) command("wear headband",TP);
   n=1;
   
/* ############################ actions ###################################### */

   add_action("help","help");
   add_action("member","member");
   add_action("vitals","vitals");
   add_action("cure","cure");
   add_action("meditate","meditate");
   add_action("do_att","feet");
   add_action("silence","silence");
   add_action("wake_up","wake_up");
   add_action("check","check");
   add_action("perception","perception");
   add_action("missile","missile");
   add_action("shock","shock");
   add_action("fireball","fireball");
   feeter=FEET_CON;
  }
  
/* ############################### extralook ################################# */

  extra_look() {
   string text;
   text=(capitalize(TP->P)+" is a member of the heroic Ninija Guild.\n"); 
   return text;
  }
  
/* ################################ vitals ################################### */

  vitals() {
   string stren;
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
   "Money: "+TP->query_money()+"\n"+
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
 

 
do_att(arg) {
  if (a_flag) {
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

/* ##################### now we check the armour ############################### */

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

/* list_the_levels() { return GM->list_levels(gd,TP->query_gender()); } */

/* ###################### recognize if fighting ############################### */

recognize_fight() {
    object victim;
          
   
        tell_object(TP,"Da hast du noch eins du Schwein.\n");
        TP->attack(); 
    

      if(meditate && sleeper) {
        sleeper->dest_me();
     }
   }

/* #################################### parry  ################################# */

  hit_player(dam) {
      object obn;
      int parry_chance;
      
      if (::hit_player(dam)) {
          ob=this_player()->query_attack();
          }
          
      obn=ob->query_name();
      parry_chance=((10+TPD/2+TPW/2)-(5+(ob->query_level()/4)));
      
    /*  if (random(100)<=parry_chance) {  */
      
         switch(random(9)) {
           
              
            case 0:
            SAY(TPN+" jumps high up in the air and parries "+obn+" attack !\n");
            break;
            
            case 1:
            SAY(TPN+" makes a move west and parries "+obn+" attack !\n");
            break;
            
            case 2:
            SAY(TPN+" makes a move east and parries "+obn+" attack !\n");
            break;
            
            case 3:
            SAY(TPN+" makes a move south and parries "+obn+" attack !\n");
            break;
            
            case 4:
            SAY(TPN+" makes a move west and parries "+obn+" attack !\n");
            break;
            
            case 5:
            SAY(TPN+" raises "+TPP+" left arm and parries "+obn+" attack !\n");
            break;
            
            case 6:
            SAY(TPN+" raises "+TPP+" right arm and parries "+obn+" attack !\n");
            break;
            
            case 7:
            SAY(TPN+" raises "+TPP+" right foot and parries "+obn+" attack !\n");
            break;
            
            case 8:
            SAY(TPN+" raises "+TPP+" left foot and parries "+obn+" attack !\n");
            break;
            
            return 1;
            
      /*     }
         return 1; */
         }
           
     return ::hit_player(dam);
     
    }
           
           
/* ############################# guild talk #################################### */

    
member(str) {
    string msg;
    object *u;
    int i;
    u=users();
    msg="Ninijas online:\n\n";
    if (str) { 
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

/* ############################## feet##################################### */

feet(arg) {

    object ob;
    int i,j;


    if (nofeeter) {   
       write("Your feet are too tired to make a hit.\n");
    return 1;
    }
    if (fattack) return 1; 
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
                                        
/* ###################### meditate ############################################## */

meditate(arg) {

   CHK_GHOST;
   move_object(sleeper=clone_object("players/whisky/guild/sleeper"),TP);
   sleeper->start_meditate(this_object());
   SAY(TPN+" sits down in the lotus-position.\n");
   return 1;
   }

   set_meditate(a) { meditate=a; }
   

/* ############################ cure ############################################ */

cure(arg) {
    object herb;
    
    herb=present("cherb",TP);
   
    if (!arg) return;
    
    if (arg!=TP->query_real_name()) {
       write("Whom are you going to cure, your grandmother ?\n");
       return 1;
       }
     
     if (!herb) {
        write("You can't cure yourself, without the right herb.\n");
        return 1;
       }
      
      SAY(TPN+" puts some of your healing-herbs on "+TPP+" bleeding wounds.\n");
      write("You feel much better now !\n");
      TP->heal_self(10+random(TP->query_max_hp()/2));
      destruct(herb);            

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

 /* ######################## E N  D ################################# */


