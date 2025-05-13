/* Coded by Arthur mainly for New and Appr wizes on Holy Mission */
/* But, it also saves the hassle for those lazy wizes when they wanna change
somthing on themselves :) - Arthur */
inherit "/obj/treasure";
string let,which,what,name;
int amm,invis;
#define TP this_player
#define TPRN this_player()->query_real_name()
#define QN query_name()
#define CP capitalize
#define WR write
#define TO this_object
#define AA add_action
#define PATH "/tools/"

reset(arg) {
  if(arg) return;
  name=TPRN;
    set_id("wizards rock");
    set_alias("rock");
    set_long("This very sturdy looking rock was probably coded by Arthur.\nIt has many neat funtions built into it. To learn more about the set function\nType 'help set', and to learn more about the add function type 'help add'.\n");
    set_value(0);
    set_weight(0);
  }
short() {
    if(invis) return;
    else return environment(TO())->query_real_name()+"'s wiz rock";
    }

init() {
/* This next line is commented because it doesn't work with the mages soul */
/*if(!TP()->query_immortal()) { WR("You're not supposed to have me. BYE!\n");destruct(TO()); return 1; } */
   AA("add","add");
   AA("set","set");
   AA("help","help");
   ::init();
}
help(str) {
 if(str == "set") {
  
  WR("The current functions of Arthurs wiz rock are:\n\n"+
   "set <argument> <number or string>\n"+
    "\nThis is the list of current <argument>'s for the set function.\n"+
     "str <number> - sets the strength to between 1 and 40\n"+
     "wis <number> - sets the wisdom to between 1 and 40\n"+
     "int <number> - sets the intellegence to between 1 and 40\n"+
     "dex <number> - sets the dexterity to between 1 and 40\n"+
     "chr <number> - sets the chrisma to between 1 and 40\n"+
     "con <number> - sets the constitution to between 1 and 40\n"+
     "al <number> - sets your alignment\n"+
     "n_ac <number> - sets your natural armour class\n"+
     "n_wc <number> - sets your natural weapon class\n"+
     "religion <string> - sets your religion to <string>\n"+
     "race <string> - sets your race to <string>\n"+
     "smell <string> - sets your smell to <string>\n"+
     "rock <str> - <str> can be invisible or visible\n");
     return 1;
    }
   if(str =="add") {
    WR("The current add functions for Arthur's Wiz rock are:\n\n"+
   "This is the list of current <argument>'s for the add function.\n\n"+
     "hp <num> - adds <num> ammount of hit-points to you\n"+
     "xp <num> - adds <num> ammount of experience to you\n");
  return 1;}
  if(str == "rock") {
    WR("The wiz rock says: I have two functions, set, and add, you can get\n"+
   "help on either of them.\n");
    return 1;}
    else return 0;
  }
      
add(str) {
   if(!TP()->query_level() > 31) {
   destruct(this_object());
   return 1;
  }
   if(TPRN != name) {
   WR("This is not your rock, you must seek your own!\n");
   destruct(this_object());
   return 1;}
 if(!str) return 0;
 if(sscanf(str,"%s",which) == 1) { amm = 0;}
  sscanf(str,"%s %d",which,amm);

   switch(which) {
         case "xp": 
             if(!amm) {WR("To add xp type 'add xp <number>'.\n");
             return 1;}
             TP()->add_experience(amm);
             done2();
             return 1;  
             break;
         case "hp":
             if(!amm) {WR("To add hp it would be 'add hp <number>'.\n");
             return 1;}
             TP()->reduce_hit_point(-amm);
             done2();
             return 1;
             break;
         default: return 0; break;
   } 
}

set(str) {
  if(!TP()->query_level() > 31) {
    destruct(this_object());
    return 1;
   }
   if(TPRN != name) {
    WR("This is not your wiz rock! Go get your own.\n");
    destruct(this_object());
    return 1;}
  if(!str) {WR("what do you want to set, and to what?\n"); return 1;}
   if(sscanf(str,"%s",which)== 1) {what = 0;}
   sscanf(str,"%s %s",which,what);
      switch(which) {
       case "rock":
             if(!what) {WR("To set the rock invisible type 'set rock invisible', for it to be visible\ntype 'set rock visible'.\n");
             return 1;}
             if(what =="invisible") invis = 1;
             else invis = 0;
             write("Your rock is now "+what+".\n");
             return 1;
             break;
       case "race":
            if(!what) {WR("To set your race type 'set race <string>'.\n");
             return 1;}
            TP()->set_race(what);
            done3();
            return 1;
            break;
       case "religion":
            if(!what) {WR("To set your religion type 'set religion <string>'.\n");
            return 1;}
            TP()->set_religion(what);
            done3();
            return 1;
            break;
       case "smell":
            if(!what) {WR("To set your smell type 'set smell' <string>'.\n");
            return 1;}
             TP()->set_smell(what);
             done3();
             return 1;
            break;
       default:
             break;
   }


   if(sscanf(str,"%s",which) == 1) {amm=0;}
   sscanf(str,"%s %d",which,amm);
     switch(which) {
       case "dex": 
            if(!amm) {WR("To set your dex type 'set dex <number>'.\n");
            return 1;}
            TP()->set_dex(amm);
            done();
            return 1;
            break;
       case "con":
            if(!amm) {WR("To set your con type 'set con <number>'.\n");
            return 1;}
            TP()->set_con(amm);
            done();
            return 1;
            break;
       case "str":
            if(!amm) {WR("To set your str type 'set str <number>'.\n");
             return 1;}
            TP()->set_str(amm);
            done();
            return 1;
            break;
       case "wis":
            if(!amm) {WR("To set your wiz type 'set wiz <number>'.\n");
            return 1;}
            TP()->set_wis(amm);
            done();
            return 1;
            break;
       case "chr": 
            if(!amm) {WR("To set your chr type 'set chr <number>'.\n");
            return 1;}
            TP()->set_chr(amm);
            done();
            return 1;
            break;
       case "int": 
            if(!amm) {WR("To set your int type 'set int <number>'.\n");
            return 1;}
            TP()->set_int(amm);
            done();
            return 1;
            break;
       case "al":
            if(!amm) {WR("To set your al type 'set al <number>'.\n");
            return 1;}
            TP()->set_al(amm);
            done();
            return 1;
            break;
       case "n_ac":
            TP()->set_n_ac(amm);
            if(!amm) {WR("To set your n_ac type 'set n_ac <number>'.\n");
            return 1;}
            done();
            return 1;
            break;
       case "n_wc":
            if(!amm) {WR("To set your n_wc type 'set n_wc <number>'.\n");
            return 1;}
            TP()->set_n_wc(amm);
            done();
            return 1;
            break;
       default:  
            return 0;
            break;
    }
}
done(){
   WR("I set your "+which+" to: "+amm+".\n");
   log_file("arthur.rock",TPRN+" used the rock to set "+
   which+" to: "+amm+".\n");
   return 1;
}
done2() {
   WR("I added "+amm+" to your "+which+".\n");
   log_file("arthur.rock",TPRN+" used the rock to add "+
   amm+" to "+which+".\n");
   return 1;
}
done3() {
   WR("I Changed "+which+" to: "+what+".\n");
   log_file("arthur.rock",TPRN+" used the rock to change "+
   which+" to "+what+".\n");
   return 1;
}
drop() {WR("You would never want a player to get their grubby hands on your wiz rock!\n");
return 1;}
query_auto_load() { return PATH+"wizrock:"+invis;}
init_arg(arg) {invis=arg;}
