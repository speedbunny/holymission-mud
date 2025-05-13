
/* ############################################################   
   #                                                          #
   #         The mages soul. It's the mage robe too.          #
   #    (most functions are called via the magemaster!!)      #
   #                                                          #
   ###############################################(C) Llort#### */

inherit "obj/armour";

#include "tune.h"	/* include the mage-tuning header */
#include "/obj/descs.h"

#define E		environment
#define MS		"players/llort/guild/magemaster"
#define MED_TITLE 	" is sitting in the lotus position"

int fattack;		/* if true no attack spell */
int meditate;		/* true if meditating */
string spells;		/* the actual spells I have */
object go_mark;		/* the room we left at the last goguild */
object tp_mark;		/* the room we marked for teleport */
string nametmp,timetmp, /* temporary variables for the illusion spell */
       shorttmp,longtmp;
string nextarg,nextverb;/* this is for timing the spells */
object nextpl; 		/* ----- || ----- */
object cast_env;
int notalk;		/* true if the magetalk is turned OFF */
object shadow;

drop() { 
  tell_object(E(),"Do you want to get rid of your robe?\n");
  tell_object(E(),"Sorry, you have to leave the guild for that.\n");
  return 1; 
}

guild_changes() {
  write("Sorry about that! :-(\n");
  if(shadow) {
      if(E()->query_immortal())
          tell_object(E(),"Wizinfo: trying to remove shadow!\n");
      shadow->get_lost();
  }
}

id(arg) {
  return ::id(arg) || arg=="robe";
}

query_weight() {
  return WEIGHT_OF_ROBE;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_id("mage robe"); 
  set_alias(MS->query_id());
  set_short("A mage robe"); /* 170992 Cashimor */
  set_long("A beautifully decorated mage robe.\n");
  set_value(0);
  set_weight(WEIGHT_OF_ROBE);
  set_ac(STD_AC_OF_ROBE);
  set_type(TYPE_OF_ROBE); 
  notalk=0;	/* Magetalk is default ON */
  spells=allocate(0);
  enable_commands();
//set_heart_beat(1); removed moonchild 110893, no reason for this to be here.

  spells=MS->query_spells();
}

heart_beat(e) {
  if(meditate) {
    E()->stop_fight();
    E()->stop_fight();
    E()->stop_hunter(1);
  }
  fattack=0; 
} 

init() {
int i; 

  ::init();
  init_spells();

  add_action("help","help");
  add_action("check","check");
  if(E()->query_immortal() || WAKEUP_FOR_PLAYERS) {
    add_action("wakeup","wakeup");
  }
  shadow=clone_object("/players/llort/guild/mage_shadow"); 
  shadow->cover_it(E()); 
}

vitals() {
  write(show_vitals(this_player()));
  return 1;
}

init_spells() {
  string update_spells;
  int i;

  add_action("no_std_spells","missile");
  add_action("no_std_spells","shock");
  add_action("no_std_spells","fireball");

  update_spells=spells;
  spells=allocate(0);
  for(i=0;i<sizeof(update_spells);i++) {
    if(this_player())
    if(!set_spell(update_spells[i])) 
      write("!! Spell "+update_spells[i]+" is no longer available !!\n");
  }
}  

no_std_spells() { 
  tell_object(E(),"What ??\n");
  return 1;
}

extra_look() {
  if(meditate) return capitalize(E()->query_pronoun())+MED_TITLE;
}

check(arg) {
  return MS->check(arg,E());
}

help(arg) {
  return MS->help(arg,E());
}

do_spell(arg) {
  if(nextpl) {
    write("You are already concentrating on another spell.\n");
    return 1;
  }
  if(MS->query_attack_spell()) {
    nextpl=E();
    nextarg=arg; 
    nextverb=query_verb();
    cast_env=E(nextpl);
    return 1;
  } else return MS->do_spell(arg,E());
}

time_guild_soul() {
  int ret;
  if(cast_env!=E(E())) nextpl=0;
  if(!nextpl) return;
  ret=MS->do_spell(nextarg,nextpl,nextverb);
  fattack=nextpl=nextarg=nextverb=0; // moonchild 110893
  return ret;
}

/* get visible if we are invisible :) */
recognize_fight() {
  if(this_player()->query_invis() &&
    (!this_player()->query_immortal())) command("visible",this_player());
}

/* whats to do if the hold spell i casted ends */
hold_end(ob) {
  return;
}

refresh_invis(cost) {
  remove_call_out("dec_sp");
  call_out("dec_sp",CHK_SP_FOR_INVIS,cost);
}

dec_sp(cost) {
  if(E()->query_spell_points()<cost) return command("visible",E());
  E()->restore_spell_points(-cost);
  call_out("dec_sp",CHK_SP_FOR_INVIS,cost);
  return 1;
}

end_invis() {
  remove_call_out("dec_sp");
}

/* ########	the input comes here if the mage is meditating 	######## */

nil(arg) { 
string tmp;
  if(arg) {
    sscanf(arg,"whisper %s",tmp); 
    if(tmp) {
      input_to("nil");
      command(arg,E());
      return;
    }
    if(meditate) {
      input_to("nil");
      switch(arg) {
        case "who":
        case "look":
        case "l":
        case "score":
        case "i": 
        case "wake_up":
        case "hp":
           command(arg,E());
           break;
        default:
           write("You can't do that while meditating.\n");
      }
      return;
    }
    command(arg,E());
  }
}

/* #########	end meditation	   ######### */

end_meditate() {
  tell_room(E(E()),E()->query_name()+" awakes and rises. "+
     capitalize(this_player()->query_pronoun())+" looks refreshed.\n");
  meditate=0;
}

shield_call_out(tim) {
  call_out("end_shield",tim);
}

/* ###########	end shield 	########## */

end_shield() {

  if(armour_class()==STD_AC_OF_ROBE) {
    write("There is no shield spell active.\n");
    return 1;
  }

  set_ac(STD_AC_OF_ROBE);
  if(query_worn()) {
    E()->recalc_ac();
    tell_room(E(E()),E()->query_name()+"'s aura is gone.\n");  
  }
  return 1;
}

/* ## most of the illusion spell has to be in here becouse of the input_to ## */

start_illusion(name,time) {
  nametmp=name;
  timetmp=time;
  input_to("get_short");
}

/* ######	get short description for the illusion   	###### */

get_short(str) {
  shorttmp=str;
  write("Enter the exact description of your illusion: (end with **)\n>>");
  longtmp=0;
  input_to("get_long");
}

/* #######	get long description for the illusion 		##### */

get_long(str) {
  if(str=="**") { 
    set_ill();
    return;
  }
  if(!str) {if(longtmp) longtmp+="\n"; else longtmp="\n";}
  else {if(longtmp) longtmp+=(str+"\n"); else longtmp=str+"\n";}
  write(">>");
  input_to("get_long");
}

set_ill() {
object ob;

  ob=clone_object("players/llort/guild/obj/illusion");
  move_object(ob,E(E()));
  ob->set_name("illusion");
  ob->set_alias(nametmp);
  ob->set_short(shorttmp);
  ob->set_long(longtmp);
  ob->start(timetmp);
  tell_room(E(E()),"Something in the area has changed.\n");
}

set_spell(arg) {
  if(MS->chk_spell(arg)) add_action("do_spell",arg);
  else return 0;
  spells+=({ arg });
  return 1;
}

set_fattack() { fattack=1; }

set_go_mark(m) { go_mark=m; }

set_tp_mark(m) { tp_mark=m; }

set_meditate(m) { meditate=m; }

set_notalk(t) { notalk=t; }

query_mage_wear() { return 1; }

query_fattack() { return fattack; }

query_meditate() { return meditate; }

query_spells() { return spells; }

query_spell(sp) { return member_array(sp,spells)!=-1; }

query_go_mark() { return go_mark; }

query_tp_mark() { return tp_mark; }

query_notalk() { return notalk; }
