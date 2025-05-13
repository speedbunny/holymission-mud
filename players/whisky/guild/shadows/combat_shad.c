/* the combat shadow */

#define _partner "/players/sauron/guild/room"

inherit "/players/whisky/obj/std_shadow";

int mode;
int wchk;   
int meditating;
object *bad_armours;
mixed skill;

 
varargs int start_shadow(object who,int time,string type) {
    ::start_shadow(who,time,type);
    return 1;
}

/* ------------------------ dodge ------------------------------ */
int dodge_bon(object vic) {
// change any 3 rd hit 

    if (random(3))
        return funcall(call,me,"dodge_bon",vic);

    skill = funcall(call,me,"get_skill","monk_dodge");

    if (!skill)
         skill = 1;
    else 
        skill = skill[0];

    if (random(101) > skill) {
        if (!random(skill * skill / 2))
             funcall(call,_partner,"raise_skill",me,"monk_dodge",1);
        return funcall(call,me,"dodge_bon",vic);
    }
// dodged 
    return 1;
}

/* ------------------------ multiattacks ------------------------------ */

varargs mixed attack(object wea, int hands) {
    int attack_boni;
    int lg;
    int i;
    int att_boni;
    object weap;
    int get_attack;
    int formula;


   skill = funcall(call,me,"get_skill","monk_attack");

   if (!skill)
       skill = 1;
   else 
       skill = skill[0];

   if (random(100) < skill)
       get_attack = 1;
   else {
       get_attack = 0;

       if (!random( skill * skill / 2))
           apply(call,_partner,"raise_skill",me,"monk_attack",1);
    }
    att_boni = apply(call,me,"query_dex") / 10;

    if (sizeof(bad_armours)) /* no attack boni */
        return apply(call,me,"attack",wea,hands);

    switch(mode) {
      case 0:
       attack_boni = att_boni;     
       break;
      case 1:
       attack_boni = att_boni + 1;
       break;
      default:
       attack_boni = att_boni + 2;
       break;
     }

     lg = apply(call,me,"query_legend_level")+1;
     formula = (lg + apply(call,me,"query_dex") + 30);
     attack_boni = attack_boni + lg / 6;

     if (wea && !apply(call,wea,"query_monk_weapon")) {
          formula = formula / 3;
          wchk = 1;
     }
     else
        wchk = 0;

     for ( i=0 ; i < attack_boni; i++) {
         if (get_attack && (formula > random(100)) )
             if ( !apply(call,me,"attack",wea,hands) ) return 0;
     }
     return apply(call,me,"attack",wea,hands);
}


/* ----------- recalcing the natural armour --------------------------- */

#define _WC (3 + apply(call,me,"query_dex")/3) /* human: 13  */
#define _AC (1 + apply(call,me,"query_dex")/3) /* human: 11  */

void recalc_fight() {
   if (!intp(mode))
        mode = 1;

    switch(mode) {
     case 0:
      apply(call,me,"set_n_ac",_AC*3/2); /* defensive mode */
      apply(call,me,"set_n_wc",_WC/3*2);
      break;
     case 1:
      apply(call,me,"set_n_ac",_AC);     /* moderate mode */
      apply(call,me,"set_n_wc",_WC);
      break;
     default:
      apply(call,me,"set_n_ac",_AC*2/3); /* aggressive mode */
      apply(call,me,"set_n_wc",_WC*3/2);
      break;
    }
}

/* --------------------- enhanced damage skill ----------------------- */

int enhanced_dam() {

// when the player wields a weapon no enhanced damage

    if (wchk)
        return 0;

    skill = apply(call,me,"get_skill","monk_damage");

    if (!skill)
         skill = 1;
    else 
        skill = skill[0];

   if (random(101) > skill) {
       if (!random(skill* skill / 2))
           apply(call,_partner,"raise_skill","monk_damage",1);
       return 0;
   }
   return (5 + apply(call,me,"query_wis")/3);
}
            
/* ------------------------ setting the combat mode ----------------- */
        
int set_mode(string arg) {
  string *art;
  string ret;
  int i;
  
   art = ({"defensive","moderate","aggressive"});

   if (!intp(mode))
        mode = 1;

   if (!arg || member_array(arg,art)==-1) {
      ret = "Mode set to:\n\n";
      i = 0;
      while (i < 3) {
          ret += art[i];
       if (i == mode)
              ret += " *";
          ret += "\n";
          i++;
      }
      tell_object(me,ret);
      return 1;
    }
    tell_object(me,"Mode now set to: "+arg+"!\n");
    mode = member_array(arg,art);
    recalc_fight(); 
    return 1;
}   

/* --------------------- some queries ------------------------------- */

string query_mode() {  /* just for checking */
  string ret;

  if (mode == 0)
      ret = "defensive";
  else if (mode == 2)
      ret = "aggressive";
  else 
      ret = "moderate";

   return ret;
}

int combat_shad() {
    return 1;
}
     
object combat_object() {
       return this_object();
}

/* ----------------------- the special score ------------------------- */

/* Mangla - Removed this and sauron can fix if he wants it.
 */
#if 0 // Sauron re-added... :)
int score() {
   int sz, ac, got, lg;
   string size, stat, victim, ret, aik, cn, mode_str;
   string religion, prot_msg;
   object att_ob;

   if (me!=this_player())
       return apply(call,me,"score");

   lg = apply(call,me,"query_legend_level");
   sz = apply(call,me,"query_size");
   cn = capitalize(apply(call,me,"query_real_name"));
   mode_str = query_mode();
   ac = apply(call,me,"query_ac");

   switch(ac) {
      case 0:
           prot_msg = "none";
           break;
      case 1..3: 
           prot_msg = "bad";
           break;
      case 4..7: 
           prot_msg = "weak";
           break;
      case 8..11: 
           prot_msg = "nice";
           break;
      case 12..15: 
           prot_msg = "well";
           break;
      case 16..19: 
           prot_msg = "good";
           break;
      case 20..23: 
           prot_msg = "very well";
           break;
      case 24..27: 
           prot_msg = "extremly well";
           break;
      default: 
           prot_msg = "battle tank";
           break;
   }

   if (objectp(att_ob = apply(call,me,"query_attack")))
       victim  =  apply(call,att_ob,"query_name");
   else 
       victim = "none";

   switch(sz) {
     case 0: size = "any"; break;
     case 1: size = "tiny"; break;
     case 2: size = "small"; break;
     case 3: size = "medium"; break;
     case 4: size = "large"; break;
     default: size = "x-large"; break;
   }
   stat = "";

    if (apply(call,me,"query_poisoned"))
        stat = stat + "poisoned ";
    if (apply(call,me,"query_intoxination"))
        stat = stat + "drunken ";
    if (apply(call,me,"query_soaked"))
        stat = stat + "soaked ";
    if (apply(call,me,"query_stuffed"))
        stat = stat + "stuffed ";

    if (stringp(apply(call,me,"query_religion")))
        religion = apply(call,me,"query_religion");
    else
      religion = "Atheist";

     got = apply(call,me,"query_exp_perc_lev");
     if ( got >= 100 )
          got = 0; 
     else
        got = 100 - got;
   
     ret = 
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
     if (apply(call,me,"query_exp_perc_lev") > 99)
         ret = ret +("              "+cn+" IN HOLY MISSION*\n");
     else
         ret = ret +("              "+cn+" IN HOLY MISSION\n");
     ret = ret +(
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "  guild: MONK\t\t\t"+
     "  race: "+apply(call,me,"query_race")+"\n"+
     "  religion: "+religion+"\t\t"+
     "  current weight: "+to_string(apply(call,me,"query_weight"))+"\n"+ 
     "  level: "+to_string(apply(call,me,"query_level"))+"/"+
     (lg > 1 ? to_string( (lg-1) ) : to_string(0))+"\t\t\t"+
     "  money: "+to_string(apply(call,me,"query_money"))+"\n"+
     "  size: "+size+"\t\t\t"+
     "  experience: "+to_string(apply(call,me,"query_exp"))+"\n"+
     "  exp.to.level: "+to_string(got)+"%\t\t"+
     "  comb][quest: "+"["+to_string(apply(call,me,"query_exp_perc_lev"))+
     "%]"+"["+to_string(apply(call,me,"query_qexp_perc_lev"))+"%]\n"+
     "  command for info: help guild\t"+
     "  alignment: "+to_string(apply(call,me,"query_al_title"))+"\n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "  health: \t\t\t  "+to_string(apply(call,me,"query_hp"))+" "+
     "["+to_string(apply(call,me,"query_max_hp"))+"]\n"+
     "  power: \t\t\t  "+to_string(apply(call,me,"query_sp"))+" "+
     "["+to_string(apply(call,me,"query_max_sp"))+"]\n"+
     "  vitals: \t\t\t  "+stat+"\n"+
     "  protection: \t\t\t  "+prot_msg+"\n"+
     "  mood: \t\t\t  "+mode_str+"\n"+
     "  wimpy set to: \t\t  "+to_string(apply(call,me,"query_wimpy"))+"%\n"+
     "  wimpydir is : \t\t  "+apply(call,me,"query_wimpydir")+"%\n"+
     "  attacked by: \t\t\t  "+victim+"\n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "  DEX: "+to_string(apply(call,me,"query_dex"))+"  "+
     "WIS: "+to_string(apply(call,me,"query_wis"))+"  "+
     "CON: "+to_string(apply(call,me,"query_con"))+"  "+
     "INT: "+to_string(apply(call,me,"query_int"))+"  "+
     "STR: "+to_string(apply(call,me,"query_str"))+"  "+
     "CHR: "+to_string(apply(call,me,"query_chr"))+"\n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
     tell_object(me,ret);
   return 1;
}
#endif

/* the poison resistance */
/* removed because caused errors - change to better later
mixed add_poison(int p) {
   int res;
 
   res = ((1 + p) * 100) / ((apply(call,me,"query_con") * 9 + 100));
   return apply(call,me,"add_poison",res);
}
*/

object combat_ob() {
    return this_object();
}

/* checking the allowance to wear an armour */

#define _ARM ({"ring","cloak","robe","amulet","boot","boots","other",\
               "glasses","neck","ear","belt","bracelet","sticker","arm"})

mixed wear(object ob) {
     if (objectp(ob) && apply(call,ob,"armour_class") > 0 && 
        !apply(call,ob,"query_monk_wear") &&
        member_array(apply(call,ob,"query_type"),_ARM)==-1) {
         if (!sizeof(bad_armours))
              bad_armours = ({});
         bad_armours = bad_armours + ({ob});
         call_out("wear_feeling",1,0);
      }
   return apply(call,me,"wear",ob);
}

mixed stop_wearing(object ob,mixed silent) {
     if (objectp(ob) && sizeof(bad_armours) && 
         member_array(ob,bad_armours)!=-1) {
         bad_armours -= ({ob});
         if (!sizeof(bad_armours))
             call_out("wear_feeling",1,2);
         else 
             call_out("wear_feeling",1,1);
      }
      return apply(call,me,"stop_wearing",ob,silent);
}

/* hindering monk abilities, wearing bad armours */
int hinder_abilities() {
   if (sizeof(bad_armours))
       return 1;
   return 0;
}

/* fixing an armour bug */
mixed fix_armours() {
     object *arm_arr;
     int i, sz;
 
     if (!sizeof(bad_armours))
         return ({});

      arm_arr = ({});

      for(sz = sizeof(bad_armours),i = 0;i < sz; i++) {
          if (bad_armours[i] && present(bad_armours[i], me))
              arm_arr += ({ bad_armours[i] });
      }
      bad_armours = arm_arr;
   return bad_armours; 
}

void wear_feeling(int how) {
  if (how == 0) {
     tell_object(me,"You feel a bit unconfortable in your new clothes.\n");
     call_out("check_what",2,bad_armours[0]);
  }
  else if (how == 1) {
     tell_object(me,"You feel still a bit unconfortable in your clothes.\n");
     call_out("check_what",2,bad_armours[(sizeof(bad_armours)-1)]);
  }
  else 
     tell_object(me,"You feel confortable clothes surrounding you again.\n");
}

void check_what(object ob) {
   if (stringp(apply(call,ob,"query_name")))
      tell_object(me,"You feel that your "+ob->query_name()+" hinders you.\n");
   else if (stringp(apply(call,ob,"query_type")))
      tell_object(me,"You feel that your "+apply(call,ob,"query_type")+
      " hinders you.\n");
   else 
      tell_object(me,"You feel that something hinders you.\n");
}
   
object *query_bad_armours() {
    return bad_armours;
}

string *query_ok_armours() {
    return _ARM;       
}
