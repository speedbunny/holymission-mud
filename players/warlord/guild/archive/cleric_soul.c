 

/*#######################################################################
                          CLERIC GUILD  (c) WARLORD
                          
  ############################################################################## */
  
/*  define */

#define TP         this_player()
#define TPN        this_player()->query_name()
#define TPC        TP->query_con()
#define TPD        TP->query_dex()
#define TPST       TP->query_str()
#define TPW        TP->query_wis()
#define TPI        TP->query_int()
#define TPHP       TP->query_hp()
#define TPL        TP->query_level()
#define TPP        TP->query_possesive()
#define TPSP       TP->query_spell_points()
#define INTO       TP->query_intoxination()
#define TPAL       TP->query_alignment()
#define COST       10
#define HIT        (5+random(10))                             
#define WRPRV(x)   tell_object(previous_object(),x)
#define SAY(x)     tell_room(environment(TP),x)
#define E          environment
#define GM         "guild/master"
#define GUILD      "cleric"

/* end define */

 
id(str) { return str=="cleric_soul" || str=="clericsoul"; }

int lev,level,no_flame,j;
int locked;
int gd;          
 
get() { return 1; }
drop() { return 1; }

reset(arg) {
  if(arg) return;
  gd=GM->query_number(GUILD);
 
}

/* the init */ 
init() {
  add_action("restore","restore");
  add_action("hammer","hammer");
  add_action("sanc","sanctuary");
  add_action("no_spell","missile");
  add_action("no_spell","shock");
  add_action("no_spell","fireball");
  add_action("clerics","clerics");
  add_action("chelp","chelp");
  add_action("weather","weather");
  add_action("earth","earthquake");
  add_action("create","create");
  add_action("curse","curse");
  add_action("enlighten","enlighten");
  add_action("freeze","freeze");
  add_action("bless","bless");
  add_action("hold","hold");
  add_action("reincarnate","reincarnate");
  add_action("flamestrike","flame");
  add_action("bolt","bolt");
}
 
/*  simulates the heart beat */

my_heart_beat() {
   locked=0;
  }
 
 
/* the helpdir */

chelp(arg) {
  switch(arg) {
    case "guild":
      TP->more ("/players/warlord/guild/chelp.txt");
      break;
    case "levels":
      GM->list_levels(gd);
      break;
    default:
      return 0;
  }
  return 1;
}

chk_fiz(cost,splev,align) { /* costs , spell-level , alignment */

      if (TP->query_ghost()) {
         write("You can't cast a spell in your inmaterial state.\n");
         }
      else if (splev > (TPW*TPI)) {
        write("You are not wise enough to cast that spell.\n");
        }
      else if (align > TPAL) {
        write("You are not good enough to cast that spell.\n");
        return 1;
        }
      else if (INTO>(10+TPST*2)) {
        write("You are much to drunken to cast that spell.\n");
      }
      else if (TPSP<cost) {
        write("You are too low on power for this spell.\n");
       return 1;
       }
       
    return 0;
 }
      
        
/* ################################ sanc ######################################## */
 
sanc() {

  if (chk_fiz(10,25,10)) return 1; 
   
     write("You use all you mental and physical powers to return to your " +
     "guild.\n\n");
     
    TP->move_player("cleric home#players/warlord/guild/clerichome");
    TP->restore_spell_points(-COST);
  
  return 1;
}
 
/* ################################# flamestrike ############################### */

flamestrike(arg) {
  object attacker;
  
   if (chk_fiz(80,400,400)) return 1;
   
   if (locked) {        /* if the player does a spell before the heart_beat */
     write("You have to wait for a while.\n");
     return 1;
   }
   
  if (!arg) {
    attacker=TP->query_attack();
    if (attacker) arg=attacker->query_name();  /* we say arg=attacker */
    }
   else attacker=present(arg,environment(TP));
 
 if ((!attacker) || (!living(attacker)) || (!present(attacker,environment(TP)))) {
   write("At whom ?\n");
   return 1;
  }
     
   attacker->attack_object(TP);
   write("You summon a flame from your mind and hit "+arg+" very strongly !\n");
   tell_object(attacker,"You are hit by a horrible flame !\n");
   attacker->hit_player(8*HIT);
   TP->restore_spell_points(-(8*COST));
   locked++;
   call_out("my_heart_beat",1);
      
  return 1;
  
  }
 
/* ############################# bolt ##################################### */ 

bolt(arg) {
  object attacker;
  
   if (chk_fiz(20,40,40)) return 1;
   
   if (locked) {        /* if the player does a spell before the heart_beat */
     write("You have to wait for a while.\n");
     return 1;
   }
   
  if (!arg) {
    attacker=TP->query_attack();
    if (attacker) arg=attacker->query_name();  /* we say arg=attacker */
    }
   else attacker=present(arg,environment(TP));
 
 if ((!attacker) || (!living(attacker)) || (!present(attacker,environment(TP)))) {
   write("At whom ?\n");
   return 1;
  }
     
   attacker->attack_object(TP);
   write("You you raise your hands to heaven and summon a bolt of lightning at "+attacker->query_name()+" !\n");
   tell_object(attacker,"You are hit by a spiritual bolt!\n");
   attacker->hit_player(2*HIT);
   TP->restore_spell_points(-(2*COST));
   locked++;
   call_out("my_heart_beat",1);
      
  return 1;
  
  }
  

/* ############################# restore ######################################## */

restore() {

  if (chk_fiz(60,30,30)) return 1;
         
     TP->heal_self(COST*3);
     TP->restore_spell_points(COST*6);
     write("You heal yourself,\n");
     say(TP->query_name() + " heals some of their wounds.\n");
      return 1;
  }
 
 
/* ############################ cleric talk ################################ */

clerics(str) {
  string msg;
  object *u;
  int i;
  u = users();
  if(str) {
    for(i=0;i<sizeof(u);i++)
      if(u[i]->query_guild()==gd)
        tell_object(u[i],"[*"+TPN+"*] "+str+".\n");
        tell_object(TP,"Ok.\n");
        return 1;

     }
    msg = "Cleric's online:\n\n";
    for(i=0;i<sizeof(u);i++)
    if(u[i]->query_guild()==gd)
      if(!u[i]->query_invis()) {
      msg+=u[i]->query_name()+"\n";
      }
    write(msg);
    return 1;
}

/* ################################# earth ###################################### */

earth () {
  object ob;
  int i;
  
 if (chk_fiz(60,400,200)) return 1;
  
 if (locked) {               /* if the player does a spell before the heart_beat */
     write("You have to wait for a while.\n");
     return 1;
   } else {

 ob=all_inventory(environment(this_player()));

 tell_room(environment(this_player()),
         this_player()->query_name()+" casts a mighty fireball into space.\n");
        
 for (i=0;i<sizeof(ob);i++) {
 
    if (ob[i]->query_npc()) {      
        tell_room(environment(this_player()),
        ob[i]->query_name()+" is badly hit by the mighty blow.\n");
        ob[i]->hit_player(3*HIT);
        }
        
     }
    TP->restore_spell_points(-(3*COST));
    locked++;
    call_out("my_heart_beat",1);
   }
  return 1;
}

/* ############################ create ##################################### */

create(str) {
object bread,water;

  if (!str) return;
  
  if (chk_fiz(20,25,20)) return 1;
       
  if (str=="food") {  
  
   bread=clone_object("obj/food");
   
   if(transfer(bread,TP)) {
      write("You carry to much for this spell.\n");
    return 1;
   }
   
   write("You create a loaf of bread.\n");
   say(TPN+" creates a loaf of bread.\n");
   bread->set_name("bread");
   bread->set_short("Loaf of bread");
   bread->set_long("This is a delicious looking loaf of bread.\n");
   bread->set_weight(1);
   bread->set_strength(4);   
   bread->set_eating_mess(" eats a loaf of bread.\n");
   bread->set_eater_mess("Ah, thats tasted good!!\n");
   transfer(bread,TP);
   TP->restore_spell_points(-(2*COST));
   return 1;
  }
    
   if (str=="drink") {   
      
     water=clone_object("obj/soft_drink");
     
     if(transfer(water,TP)) {
       write("You carry to much for this spell.\n");
     return 1;
     }
     
     write("You create a bottle of water.\n");
     say(TPN+" creates a bottle of water.\n");
     
     water->set_name("water");
     water->set_short("Bottle of Mystic water");
     water->set_long("This is a bottle of mystic water in a clear bottle.\n");
     water->set_weight(1);
     water->set_strength(4);
     water->set_drinking_mess(" drinks the water in one quick GULP!\n");
     water->set_drinker_mess("You drink the bottle of water in one GULP!\n");
     water->set_empty_containers("bottle");
     
     transfer(water,TP);
     TP->restore_spell_points(-(2*COST));
     return 1;
    }
  }
/* ############################### hammer ###################################### */

hammer () {
  object ham;
  
     if (chk_fiz(TPL*8,60,40)) return 1;
       
     ham=clone_object("players/warlord/guild/hammer");
          
     if (transfer(ham,TP)) {    /* man transfer */
        write("You carry too much to summon the hammer.\n");
        return 1;
        }
     
     write("You create a hammer from thin air.\n");
     say(TPN+" creates a hammer from thin air.\n");
              
     transfer(ham,TP);     /* ok the player don't carry too much */
     TP->restore_spell_points(-(TPL*8));     
     return 1;
     }
 
/* ################################ curse ##################################### */

curse (arg) {
object attacker;
int a,count;
count=0;

  if (chk_fiz(10+TPL*2,4,100)) return 1;
    
  if (locked) {  /* if the player does a spell before the heart_beat */
     write("You have to wait for a while.\n");
     return 1;
   }
   
 if (!arg) {
    attacker=TP->query_attack();
    if (attacker) arg=attacker->query_name();  /* we say arg=attacker */
    }
   else attacker=present(arg,environment(TP));
 
 if ((!attacker) || (!living(attacker)) || (!present(attacker,environment(TP)))) {
   write("Cursing whom ?\n");
   return 1;
  }

 if (attacker==TP->query_attack()) {
    write("You can only curse the same opponent once.\n");
  return 1;
  }
                             
  a=attacker->query_ac();
  attacker->set_ac(-random(attacker->query_ac()/2));
  TP->restore_spell_points(-(10+TPL*2));
  write("You curse "+attacker->query_name()+"\n");  
  attacker->attack_object(TP);
  call_out("my_heart_beat",1);   
  return 1;
 }

/* ############################## weather ########################################## */

weather (arg) {   /* grin the far spell should be cool */
   object fool,cloud;
   
   if (!arg) return;
 
 
    fool=find_living(arg);
   
   if(TP->query_ghost()) {
     write("If you are dead, you don't need a weather any more.\n");
     return 1;
   }

  if (locked) {  /* if the player does a spell before the heart_beat */
     write("You have to wait for a while.\n");
     return 1;
   }
   
  if (fool) {
  
     if ((TP->query_alignment()<100) || (random(TPL*2) < random(fool->query_level()))) {
        write("The Gods tell you: Oh no, we want a fair fight !\n");
        tell_object(fool,"You feel a strange force in the space.\n"+
                    "You feel like flying as your body gets weightless for a moment.\n");
        write("Suddenly "+arg+" is summond by the Gods.\n");
        move_object(TP,environment(fool));
        fool->attack_object(TP);
        return 1;
        }
  
     tell_object(fool,"You feel suddenly a strong force in the space.\n"+
                 "You feel like crying but nobody is gonna hear you !\n");
  locked++;
  call_out("my_heart_beat",1);
  cloud=clone_object("players/whisky/cloud");
  move_object(cloud,fool);            
  call_out("thunder",4,arg); /* now you are up to hell */
  
  }
  else {
   write("No "+arg+" found.\n");
   }
  return 1;
  }
  
  
  thunder(arg) {   /* ok we make the weather */
     object fool;
     fool=find_living(arg);
    
    if (fool) {
     tell_object(fool,"Suddenly you see a dark cloud !\n"+
                      "You can hear a rumbling noise above you !\n");
    call_out("earth_fool",4,arg);
   }
  }
  
  earth_fool(arg) {
  
    object fool;
     fool=find_living(arg);
    
    if (fool) {
     tell_object(fool,"The wolfes are howling and the earth is shivering !\n"+
                      "Oh God, what have you done ???????\n");
    call_out("hit_fool",4,arg);
   }
  }
  
  hit_fool(arg) {
   object fool;
     fool=find_living(arg);
    
   if (fool) {   
   tell_object(fool,"You hear a big rumbling, a flash strikes from\n"+
                    "the sky ..... RUN FOOL RUN !\n");
   fool->hit_player(random(80));  /* grin */  
     }
   }
   
/* ###########################  freeze  ############################### */

 freeze(arg) {
   object ob,block;

   if (chk_fiz(40,100,800)) return 1;
   
   if (!arg) {
      write("Freezing whom ??\n");
   }
   else 
   ob=present(arg,E(TP));
   
   if ((!ob) || (!living(ob)) || (!present(ob,E(TP)))) {
      write("You can't freeze "+arg+".\n");
      return 1;
   }
      
     TP->restore_spell_points(-(4*COST)); 
      
     block = clone_object("/players/whisky/guild/statue");
     block->set_name(ob->query_name());
     block->set_alias(ob->query_name());
     block->set_short("A frozen block of "+ob->query_name());
     block->set_long("This is a frozen ice block of "+
                     ob->query_name()+".\n");
     block->set_weight(100);
     
     move_object(block,E(TP)); 
     move_object(ob,block);
     
     SAY(TPN+" raises "+TP->query_possessive()+" hands to heaven and suddenly\n\n"+
         "you can hear a mighty voice DAMN THAT CREATURE !!!!\n\n"+
         "Suddenly you feel a cold wind !! "+ob->query_name()+" screams\n\n"+
         "from pain and turns into a block of ice !!!!\n\n");
    return 1;
  }
   
 /* ########################### enlighten ############################# */

    enlighten(arg) {
        object ob;
        
        if (chk_fiz(10,2,10)) return 1;
     
        ob=move_object(clone_object("players/whisky/guild/light"),TP);
        call_out("extinguish",3000);
        write("The Gods can hear your desire !!!!\n\n"+
              "One God means: Hmm we shouldn't, tja its not our problem.\n"+
              "I mean why is this little servant nerving us !!!!\n\n"+
              "Suddenly you can hear 1000 of voices Hmmmm shall we ???\n\n"+
              "But then Father God says: Jep, why not, lets help our\n"+
              "poor servant. I mean he has done a lot of good things.\n"+
              "lets fullify "+TPP+" request, "+TP->query_pronoun()+" is \n"+
              "worth it !\n\n"+
              "Suddenly you feel a strange force and you feel yourself\n"+
              "shining in a bright light !!!\n");
        TP->restore_spell_points(-20);
     return 1;
     }
  
  
  extinguish() {
    object ob;
    ob=present("light",E(this_object()));
    write("\n\nSuddenly you feel  your surrounding getting darker !!!!\n"+
          "Did the Gods forget you ????\n");
    destruct(ob);
  return 1;
  } 


  /*########################## reincarnate ################################ */

    reincarnate() {
 
    if (TP->query_ghost()) {

     if ((TPAL < 100)) {
        write("You knee down to pray to your Gods for your last change,\n"+
        "but the Gods are angry with you, because lived an evil life\n"+
        "without abstinence.\n\n"+
        "You hear an angry voice from the sky: No reincarnation for this one !\n");  return 1;
     } 
    else {
      write("You knee down to pray to your gods for your last change\n"+
           "There is a long silence, but suddenly you can hear a powerful\n"+
           "pleasant voice from the sky:\n\n"+
           "Therefore you lifed your live in abstinence and therefore you did\n"+
           "lots of good things, we give you your last change.\n"); 
           TP->remove_ghost();
           write("Suddenly you feel some strange power, floating through you body !.\n");
     return 1;
     }
    return 1;
    }
   if (!(TP->query_ghost())) {
        write("You knee down to pray for your last change.\n"+
              "The Gods can hear your voice and are asking themselfes\n\n"+
              "REINCARNATION ???? Is "+TP->query_pronoun()+
              " fooling us !!!!!\n\n"+
              "Suddenly the Gods get angry: DEATH FOR THIS ONE !!!!\n\n"+
              "The Gods summon a ball of lightning from the sky !!!!\n");
              TP->hit_player(TP->query_hp()+1);
       return 1;
      }
    }
  
   /* ############################### hold ################################## */

  hold(arg) {
   int spnr,tim;
   object ob;

  if (chk_fiz(20,4,80)) return 1;
  
  if(!arg) {
     ob=TP->query_attack();
     if(ob) arg=ob->query_name();
     else {
       write("Hypnotize whom ?\n");
       return 1;
     } 
    } else ob=present(arg,E(TP));

   if ((!ob) || (!living(ob)) || (ob->query_wizard())) {
      write("You just can't hold "+arg+".\n");
   return 1;
   }    
     tim=(2+random(TPL*3/ob->query_level()));
     
     if (tim>0)
     ob->hold(this_object(),tim);
     SAY(TPN+" raises "+TP->query_possessive()+" hands to heaven\n"+
        "and sends a strong powerfield at "+ob->query_name()+" !\n");
     tell_object(ob,"You feel like your bodyparts are sleeping.\n"); 
     TP->restore_spell_points(-(2*COST));
   return 1;
  }
  
  hold_end(ob) {
  return;
 }
 
  /* ########################### bless ################################# */

    bless(arg) {
      object ob;
      int class;
      
     if (!arg) {
        write("Blessing what ??\n");
        return 1;
      }
        
      if (chk_fiz(200,380,1000)) return 1;
     
      if (!(ob=present(arg,TP))) { 
        write("You don't have that item.\n");
        }
       else if (!ob->weapon_class()) {
          write("That's no weapon.\n");
       }         
       else if (ob->query_info("blessed")) {
          write("This weapon is already blessed.\n");
       return 1;
      }
         
      class = ob->weapon_class();
      ob->set_class(class+((TPW/9)*random(2))); /* ok hmm 1-2 normally */
      ob->set_info("blessed");
      SAY(TPN+" knees down and prays to "+TPP+"'s god !\n" +
          "suddenly a flash of bright light illuminates\n"+
          "the "+arg+" and strength "+TPP+" weapon !!!!\n");
      TP->restore_spell_points(-(20*COST));     
      return 1;
    }
    

