/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+= The Thief Soul=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

#define GM             "guild/master"
#define CD             "sys/chatd"

#define TOTAL_HIDDEN   (dex * 45)   /*        max time hidden  */
#define ROOM           "/players/blade/guild/room"
#define ENV            environment
#define AL_STEALMONEY  -10          /*  alignment: steal money */
#define AL_STEALITEM   -50          /*             steal item  */
#define LV_STBAG        20          /* level for stealing bags */

#define CHK_ATT(); \
if ((att=thief->query_attack()) &&\
    present(att,environment(thief))) {\
    write("You are much too busy to do that.\n");\
    return 1;\
}

#include <lw.h>

object   thief, xatt, thrown_weapon;
string   THRNAME;
int      dex, max_stats, in_backstab, no_amb, no_throw, renegade;
int      disguised_as, contest, remain_hidden, dont_hide, xdam;
status   immortal;                                /* immortal or not   */
status   stashed;                                 /* soul hidden       */
string   th_xlook;                                /* extra_look string */
string   gm_id;                                   /* soul id from GM   */
string   dir;                                     /* guild directory   */
int      gd;                                      /* guild number      */
string   helpdir;                                 /* guild helpdir     */
string   hideout;                                 /* guild hideout     */
object   att;                                     /* attacker          */
status   rv_lock;                                 /*    reveal delay   */
status   has_stolen;                              /*      steal delay  */
object   hide;                                    /*  the room we left */

// Predeclarations
int do_disguise(string arg);
int get_guild_params();
int put_guild_params();

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int drop() {
    return 1;
}

int get() {
    return 1;
}

int id(string arg) {
    return arg == gm_id || arg == "tools" || arg == "case";
}

int long() {
  if (!stashed){
    write("This case contains some tools you need.\n");
    return 1;
  }
}

string short() {
  if (!stashed)
    return "A small, slim case";
}

string extra_look() {
  return th_xlook;
}

/*=+=+=-+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+*/

void reset(int arg) {
  if (arg) return;
  
  gd        = GM->query_number("thief");
  dir       = GM->query_dir(gd);
  helpdir   = "/" + dir + "/help";
  hideout   = dir + "/hideout";
  max_stats = GM->query_levels(gd);
  thief     = this_player();
  gm_id     = GM->query_id(gd);
  
  // changed by Llort .. caused Bugs in the startup of the mud
    if(thief) {
      THRNAME   = thief->query_real_name();
      dex       = thief->query_dex();
      immortal  = thief->query_immortal();
    }
}

void init() {
  
  object shad;
  
  if (!thief)
    return 0;
  
  this_player()->set_n_ac(1 + this_player()->query_dex()/4);
  if (!(dont_hide = thief->queryenv("TH_DHIDE")))
    dont_hide = 0;
  else thief->unsetenv("TH_DHIDE");
  
  if (!(remain_hidden = thief->queryenv("TH_RHIDDEN")))
    remain_hidden = TOTAL_HIDDEN;
  else thief->unsetenv("TH_RHIDDEN");
  
  stashed = thief->queryenv("TH_STASHED");
  
  if (!(th_xlook = thief->queryenv("TH_XLOOK"))) {
    th_xlook = capitalize(thief->query_pronoun())
      + " slips through the shadows with a remarkable grace";
    thief->setenv("TH_XLOOK",  th_xlook);
  }
  
  if (!thief->thief_shadow()) {
    shad = clone_object("/players/blade/guild/thief_shadow");
    shad->start_shadow(thief,0,"thief_shadow");
  }
  
  
  add_action("backstab", "backstab");
  add_action("disguise", "disguise");
  add_action("ambush", "ambush");
  add_action("guild_line", "thief");
  add_action("guild_line", "thief/");
  add_action("help", "help");
  add_action("hideout","hideout");
  add_action("leave","leave");
  add_action("hide", "hide");
  add_action("picklock", "picklock");
  add_action("poison", "poison");
  add_action("reveal", "reveal");
  add_action("sneak", "sneak");
  add_action("steal", "steal");
  add_action("unhide", "unhide");
  add_action("appraise","appraise");
  add_action("thief_tell","tell");
  add_action("thief_debug","thief_debug");
  add_action("contest","contest");
  if (thief && !immortal)
    thief->set_vis();
  if(THRNAME=="blade") {
    add_action("test","test");
    add_action("thief_wear","thief_wear");
    add_action("voice","voice");
  }
  else {
    add_action("power_fail","voice");
  }
  if(thief->query_level()>=10) {
    add_action("throw","throw");
  }
  else {
    add_action("power_fail","throw");
  }
  if(thief->query_level()>=25) {
    add_action("mudball","mudball");
    thief->set_infravision();
  }
  else {
    add_action("power_fail","mudball");
  }  
  
  if(!immortal || THRNAME=="blade") {
    get_guild_params();
    call_out("do_disguise",5,GM->query_name(disguised_as));
  }
  if(this_player()->query_immortal()){
    add_action("query_thief_banish","query_banish");
    add_action("thief_banish","thief_banish");
    add_action("mislead","mislead");
  }
}

int do_unhide() {
  
  thief->set_vis();
  move_object(thief, environment(thief));
  tell_room(environment(thief),
	    thief->query_name() + " " +
	    thief->query_msgin() + ".\n");
  return 1;
}

void guild_changes() {    /* if player changes guilds */

  thief->set_n_ac(0);
  
  if (thief->thief_shadow())
    if (immortal) write("Destructing the thief_shadow.\n");
  destruct(thief->thief_object());
  
  if (!immortal) {
    thief->unsetenv("TH_XLOOK");
    thief->unsetenv("TH_STASHED");
  }
  if(get_guild_params()!=2) {    /* if thief file, erase it */
    rm("guild/thieves/"+THRNAME);
    if(immortal) write("Erasing thief parameter file.\n");
  }
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int guild_line(string str) {
  
  object *u;
  int num, i, sz;
  string msg, pret;
  
  if (!str) {
    writelw("=-=-=-=-=-=-=-=-=-=-=-=-=-= "+
	    "Thieves online "+
	    "=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    u=users();
    msg="\n";
    num=0;
    sz=sizeof(u);
    for (i=0;i<sz;i++) {
      if (u[i]->query_guild()==1) {
	pret=u[i]->query_pretitle();
	if (pret=="") {
	  if (u[i]->query_real_name()=="blade")
	    pret="Guild Master";
	  else {
	    switch(u[i]->query_level()) {
	    case 1..5: pret="Neophyte Thief"; break;
	    case 6..10: pret="Rogue"; break;
	    case 11..15: pret="Burglar"; break;
	    case 16..20: pret="Thief"; break;
	    case 21..25: pret="Expert Thief"; break;
	    case 26..29: pret="Shadow Master"; break;
	    default: pret="Visiting Wizard"; break;
	    }
	  }
	}
	msg=msg+sprintf("%20s %s\n",
			pret,
			capitalize(u[i]->query_real_name()));
	num++;
      }
    }
    write(msg+"\nThere are "+num+" thieves online.\n");
    return 1;
  }
  thief->guild_line(str);
  return 1;
}

int help(string arg) {
  
  if (arg == "levels") {
    GM->list_levels(gd);
    return 1;
  }
  
  if (arg == "guild")
    arg = "thief";
  
  /* Clashes with 'help remote soul' because of the space. */
  /* Now it takes the first word before the space, and if  */
  /* its not present in the thief help, returns 0.         */
  if (!arg || !cat(helpdir + "/" + explode(arg," ")[0])) return 0;
  
  return 1;
}

int fail_spell() {
  
  help("spell");
  return 1;
}

void recognize_fight() {
  
  if (thief->query_invis()) {
    write("You come out of the shadows.\n");
    do_unhide();
  }
  
  /* Thieves have a chance at multiple attacks due their natural speed. */
  if (random(60) < dex + thief->query_legend_level())
    thief->attack();
/*  if(thief->query_immortal()&&ambush==2){
    call_out("ambush");
  } */
}

/*=============================== Mislead ==================================*/
int mislead(string arg){
  int counter,i,j;
  object *followers_array;
  object *dest_dir_;
  string mislead_room;

  if(!arg){
    write("What direction?\n");
    return 1;
  }
  dest_dir_=(environment(thief)->query_room("dest_dir"));
  write("sizeof(dest_dir) == "+sizeof(dest_dir_)+"\n");

  if(dest_dir_=(environment(thief)->query_room("dest_dir")) && 
     (j = member_array(arg, dest_dir_))!=-1){
    write("member_array(arg,dest_dir_) == "+j+"\n");
    write("intp(--j) == "+intp(j)+"\n");
    j=j-1;
  }
  else if(dest_dir_=environment(thief)->query_room("hidden_dir") && 
	  (j = member_array(arg,dest_dir_)) != -1){
    j=j-1;
  }
  
  if(!thief->query_invis()){
    tell_room(environment(thief),
	      thief->query_name()+" " +
	      thief->query_msgout()+" "+
	      arg+".\n");
  }
  if(followers_array=thief->query_followers()){
    counter=sizeof(followers_array);
    write(counter+followers_array[0]->query_real_name());    
    for(i=0;i<counter;i++){
      write(i+"\n");
      followers_array[i]->move_player(arg, dest_dir_[3]);
    }
  }
  else write("noone following.\n");
  return 1;
}

/*============================ Guild Banishment ============================*/

void set_thief_banish(int arg){
  renegade = arg;
  return;
}

int return_thief_banish(){ return renegade; }

int query_thief_banish(string arg){
  object player;
  if(player=present(arg,environment(this_player()))&&player->query_guild()==1){
    write(player->query_real_name()+" has banish set to "+
	  present("gm_id",player)->return_thief_banish()+".\n");
  }
  else{
    write("Who would you like to check banishment status of?\n");
  }
  return 1;
}

int thief_banish(string arg){
  object player;
  int num;
  if(player=present(arg,environment(this_player()))){
    num=present("gm_id",player)->return_thief_banish();
    write(num);
    switch(num){
    case 0:{
      write("You brand "+player->query_real_name()+
	    " an outcast among thieves.\n");
      player->set_thief_banish(1);
      tell_object(player,capitalize(THRNAME)+
		  " has branded you an outcast among thieves.\n");
      player->put_guild_params();      
      break;
    }
    case 1:{
      write("You forgive "+player->query_real_name()+", and welcome "+
	    player->query_pronoun()+" back to the Guild of Thieves.\n");
      player->set_thief_banish(0);
      tell_object(player,THRNAME+" forgives you and welcomes you back "+
		  "to the Guild of Thieves.\n");
      player->put_guild_params();
      break;
    }
    }
  }
  else{
    write("Who would you like to banish from the guild?\n");
    return 1;
  }
  return 1;
}
      
    



/*=============================== Power Fail ===============================*/

int power_fail() {
  write("You don't think you are skilled enough for that power just yet.\n");
  return 1;
}

/*============================== Throw Voice ===============================*/
int voice(string arg) {
  
  string who, what;
  
  if (!arg || (sscanf(arg, "%s %s", who, what) != 2) ||
      !present(who,environment(thief)) || 
      !living(present(who,environment(thief))) )
    return help("voice");
  
  // Mangla: do not need present in next statement since chekced before. 
    /*    if(present(who,environment(thief))->query_immortal()) { */
    
    if(who,environment(thief)->query_immortal()) {
      write("You don't want to anger the Gods.\n");
      return 1;
    }
  
  write("You make yourself sound like "+who+" and say:\n("+what+")\n");
  say(capitalize(who)+" says: "+what+"\n");
  return 1;
}


/*============================== Thief Debug ===============================*/
int thief_debug() {
  
  no_amb=0;
  no_throw=0;
  write("Ok.\n");
  return 1;
}

/*============================= Thief Tell =================================*/

int thief_tell() {
  if(thief->query_invis())
    write("You are invisible.  Message sent anyway.\n");
  return 0;
}
/*============================= Write Out ==================================*/

int put_guild_params() {

  rm("guild/thieves/"+THRNAME);
  write_file("guild/thieves/"+THRNAME,
	     "disguised_as= "+sprintf("%d",disguised_as)+"\n");
  write_file("guild/thieves/"+THRNAME,
	     "renegade= "+sprintf("%d",renegade)+"\n");
  return 1;  
} 

int get_guild_params() {

  string file_string;
  
  if(!read_file("/players/blade/guild/thieves/"+THRNAME)){
    return 2;
  }
  sscanf(read_file("/players/blade/guild/thieves/"+THRNAME),
	 "%s",file_string);
  sscanf(file_string,"disguised_as= %d\nrenegade= %d\n",
	 disguised_as,renegade);
  return 1;
}

/*================================ test ====================================*/

int test() {
  write("Remember not to do this is blade's workroom\n");
  /*  clone_object(dir+"/mask_shadow")->start_shadow(thief,60); */
  if(renegade)renegade=0;
  else renegade=1;
  write(renegade+".\n");
  return 1;
}
/*============================== Appraise ==================================*/

int appraise(string arg){

  object appraised_ob;
  float mistake;
  int final, true_value;
  
  if (!(appraised_ob = present(arg, thief))
      && !(appraised_ob = present(arg, environment(thief)))) {
    write("What would you like to appraise?\n");
    return 1;
  }
  
  if(living(appraised_ob)){
    true_value=appraised_ob->query_money();
  }
  else {
    true_value=appraised_ob->query_value();
  }
  mistake=random(40-thief->query_int()) / 100.0;
  final=3*((int)(true_value*mistake));
  final=random(final) - (final / 2);
  final+=true_value;
  
  if(!living(appraised_ob)) {
    write("You think its worth "+final+" coins.\n");
    return 1;
  }
  else {
    printf("You think %s has %d coins.\n",
	   appraised_ob->query_pronoun(),final);
    return 1;
  }
}

/*============================== Wear Mask =================================*/

int thief_wear(string arg) {

  object sh;
  
  if(arg!="thief mask") return 0;
  
  if(present(arg,thief)) {
    sh = clone_object(dir + "/mask_shadow");
    sh->start_shadow(thief,60);
    say(thief->query_name() + " puts on a mask.\n");
    write("Ok.  You put on the mask. (blade)\n");
    return 1;
  }
}

/*================================= Throw ==================================*/

int throw(string arg) {

  object victim;
  string v_name, w_name;
  int hit;
  
  hit=0;
  v_name="";
  w_name="";
  
  if (no_throw || no_amb) {
    write("You have to wait until you complete this one.\n");
    return 1;
  }
  if(sscanf(arg,"%s at %s",w_name,v_name)!=2) {
    write("Throw syntax: throw <weapon> at <monster>.\n");
    return 1;
  }
  if (!(victim = present(v_name, environment(thief)))
      || !living(victim)) {
    write("Throw at whom?\n");
    return 1;
  }
  if(!(thrown_weapon=present(w_name,thief))) {
    write("You don't have a "+w_name+"!\n");
    return 1;
  }
  if(thrown_weapon->query_weight()>2) {
    write(capitalize(w_name)+" is too heavy to throw.\n");
    return 1;
  }
  if(victim==thief) {
    write("You throw "+w_name+" into the air and catch it.\n");
    say(thief->query_name()+" throws "+w_name+" into the air, and "+
	"skillfully catches it.\n",thief);
    return 1;
  }
  if(ENV(thief)->query_property("no_fight")) {
    write("You are not allowed to do that in this sanctuary.\n");
    return 1;
  }
  if(thrown_weapon->query_weapon()) {
    tell_object(thief,"You throw a "+thrown_weapon->query_name()+" at "+
		victim->query_name()+".\n");
    no_throw=1;
  }
  else {
    write(capitalize(w_name)+" is not a weapon.\n");
    return 1;
  }
  
  hit=dex+thief->query_level()+(2*thief->query_legend_level());
  
  if(random(hit)>random(40)) {
    if (victim!=thief->query_attack()) thief->attack_object(victim);
    xatt=victim;  /* natural limit on dam is weight must <2 */
    
    /***********
      What is this?!?!
      xdam=(thief->query_str()+dex+(9*thrown_weapon->weapon_class())+
      random(thief->query_legend_level()*4));
      
      xdam ~= (20 + 20 + 9*8 + random(10*4))
      xdam ~= 40 + 72 + 20
      xdam ~= 132  !!!!
      
      Am I missing something or is this a little bit much?
      PLUS the hit_player function adds in str and dex bonuses of its own
      
      ***********/
    
    xdam = 5 * thrown_weapon->weapon_class()
      + random(thief->query_legend_level() * 4);
    if(THRNAME=="blade") {
      write("You hit monster for "+xdam+" damage.\n");
    }
    no_throw=1;
    
    /**********
      victim->hit_player(hit+thrown_weapon->query_wc(),0);
      thief->add_exp(hit+thrown_weapon->query_wc());
      **********/
    
    return 1;
  }
  else {
    if (victim!=thief->query_attack())
      thief->attack_object(victim);
    xatt=victim;
    xdam=0;
    no_throw=1;
    return 1;
  }
}

/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ Mudball $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ */

int mudball(string arg){
  
  object victim;
  int hit;
  
  if (!(victim = present(arg, environment(thief))) || !living(victim)) {
    write("Mudball whom?\n");
    return 1;
  }  
  if(victim->query_immortal() && THRNAME!="blade") {
    write("You cannot mudball immortals.\n");
    return 1;
  }
  if(victim->query_mudballed()) {
    write(victim->query_name() + " is already covered with mud.\n");
    return 1;
  }
  hit = thief->query_level()+thief->query_legend_level()*3+dex;
  
  if(random(hit) > 25) {
    clone_object(dir+"/mudball_shadow")->start_shadow(victim,hit);
    write("You throw a ball of mud at " + victim->query_name() + "!\n");
    tell_object(victim,thief->query_name() +
		" throws a ball of mud at you!\n");
    say(thief->query_name() + " throws a ball of mud at " +
	victim->query_name() + "!\n");
    return 1;
  }
  else {
    write("You throw a ball of mud at " + victim->query_name() +
	  ", but miss!\n");
    tell_object(victim,thief->query_name() +
		" throws a ball of mud at you, but misses!\n");
    say(thief->query_name() + " throws a ball of mud at " +
	victim->query_name() + " but misses!\n");
    return 1;
  }
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Backstab +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int backstab(string arg) {

  object victim, weapon, check;
  
  weapon = thief->query_wielded();
  
  if (!arg) 
    return help("backstab");
  
  if (!(victim = present(arg, environment(thief))) || !living(victim)) {
    write("Backstab whom?\n");
    return 1;
  }
  
  if (victim == this_player()) {
    write("You should not try to backstab yourself. you might succeed!\n");
    return 1;
  }
  
  if (!(objectp(weapon))) {
    write("Your attack would be more potent with a weapon in hand.\n");
    return 1;
  }
  
  if(environment(victim)->query_property("no_fight")) {
    write("You are not allowed to fight in here.\n");
    return 1;
  }
  
  CHK_ATT();
  
  if (victim->query_attack(thief)) {
    write(victim->query_name() +
	  " is obviously much too wary for that attack.\n");
    if (thief->query_invis())
      return 1;
    else
      victim->attack_object(thief);
  }
  
  if (!thief->query_invis()) {
    write("You move carefully toward " + victim->query_name() +
	  " but " + victim->query_objective() +
	  " notices your approach!\n");
    victim->attack_object(thief);
    victim->attack();
    return 1;
  }
  
  check = present("back_check",victim);
  if (check) {
    if (check->query_stab_it() >= (thief->query_level()+dex)) {
      write(capitalize(victim->query_name()) +
	    " would notice your attempt.\n");
      return 1;
    }
  }
  
  if (in_backstab) {
    write("You are already trying to sneak behind your victim's back.\n");
    return 1;
  }
  
  write("You carefully move behind " + victim->query_name() + ".\n");
  call_out("backstab_it",0,victim);
  in_backstab = 1;
  return 1;
}

int backstab_it(object victim) {

  int dam, experience;
  float levs, divide;
  object checker;
  
  in_backstab = 0;
  enable_interactive(thief);
  
  if (victim && environment(victim)==environment(thief)) {
    checker=clone_object("/players/blade/guild/obj/back_check");
    checker->set_stab_it(thief->query_level()+dex);
    move_object(checker,victim);
    
    write("You find a vulnerable spot and strike swiftly.\n");
    dam = ((dex*thief->query_level()/2) 
	   + ((random(20)+(dex/2)+1)*(random(5)+6)));
    if (dam > 675) dam=675;
    /* 032995 Colossus: Debug for backstab */
    if(dam >= victim->query_hp()) {
      dam = victim->query_hp() - 1;
      /*      victim->attacked_by(victim); */
      write("You plunge your weapon deep into the innards of "+
	    victim->query_name()+", instantly killing "+
	    victim->query_objective()+".\n");
      say(thief->query_name()+" plunges "+
	  thief->query_possessive()+
	  " weapon deep into the innards of "+victim->query_name()+
	  ", instantly killing "+victim->query_objective()+".\n");
      
      /* Extra computations because misc_hit() doesnt award XP for kills */
      /* these computations are straight out of player.c                 */
      /* unfortunately, if you call misc_hit or hit_by_spell             */
      /* it only awards for the damage done to the monster,              */
      /* and not for the kill.                                           */
      victim->misc_hit(dam,7);
      thief->add_exp(dam);
      thief->attack_object(victim);
      levs=(thief->query_level()+thief->query_legend_level());
      divide=40*levs;
      return 1;
    }
    victim->hit_player(dam,7,13);
    thief->add_exp(dam);
    return 1;
  }
  write("You can't backstab someone who is not here!\n");
  return 1;
  }

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Ambush +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int ambush(string arg){

    object victim, weapon, check;

    weapon = thief->query_wielded();

    if(thief->query_ghost()) {
        write("You cannot ambush as a ghost.\n");
        return 1;
    }
    if (!arg) {
        if(victim=thief->query_attack()) {
        }
        else {
            write("Ambush whom?\n");
            return 1;
        }
    }
    else if(!(victim = present(arg, environment(thief)))
                 || !living(victim)) {
        write("Ambush whom?\n");
        return 1;
    }

    if (!(victim->allowed_attack(thief))) {
        write("You are not allowed to attack that player!\n");
        return 1;
    }

    if (!(objectp(weapon))) {
        write("Your attack would be more potent with a weapon in hand.\n");
        return 1;
    }

    if (no_amb || no_throw) {
        write("You have to wait until you complete this one.\n");
        return 1;
    }
    if(ENV(thief)->query_property("no_fight")){
      write("You are not allowed to do that in this sanctuary.\n");
      return 1;
    }
    
    if (victim && (ENV(thief) == ENV(victim)) && living(victim)) {
      if (victim!=thief->query_attack())
	thief->attack_object(victim);
      xatt=victim;
      xdam=(random(11)+dex+(2*weapon->weapon_class()));
      no_amb=1;
      return 1;
    }
    write("There is no one here to ambush!\n");
    return 1;
  }



/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Hideout =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int hideout() {
  
  if(renegade){
    write("The Guild of Thieves has banished you from the hideout.\n");
    return 1;
  }

  if (file_name(environment(thief)) == hideout)  {
    write("Your keen thief senses compel you to examine your "
          + "surroundings.\n");
    return 1;
  }
  
  if (environment(thief)->has_drink(thief)) {
    write("You are not allowed to leave with drinks!\n");
    return 1;
  }
  
  if (environment(thief)->query_property("no_teleport")) {
    write("As you try to leave this place you run into an " +
          "invisible barrier.\n");
    return 1;
  }
  
  hide = environment(thief);
  /* thief->move_object("X#" + hideout); */
  if(!thief->query_invis())
    say(thief->query_name()+" leaves suddenly.\n");
  move_object(thief,dir+"/hideout");
  write("You sneak off to the hideout.\n");
  return 1;
}

int leave() {
  if (file_name(environment(thief)) != hideout) {
    write("You don't want to go quite yet.\n");
    return 1;
  }
  
  if (objectp(hide))
//        thief->move_player("X", hide);
  move_object(thief,hide);
  else   
//        thief->move_player("X#" + GM->query_room(gd));
  move_object(thief,GM->query_room(gd));
  
  write("You have returned.\n");
  return 1;
}


/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Disguise +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int disguise(string arg){

  string option, option2; 
  
  if (thief->query_invis()){
    write("You must be able to see yourself to put on an "
	  + "adequate disguise.\n");
    return 1;
  }
  
  if (!arg || sscanf(arg, "%s %s", option, option2) != 2
      || (option != "appearance" && option != "title"))
    return help("disguise");
  
  if (option == "appearance") {
    th_xlook = option2;
    thief->setenv("TH_XLOOK", th_xlook);
  }
  
  if (option == "title") {
    if(do_disguise(option2)==2)
      return 1;
    put_guild_params();
  }
  
  write("You pull some supplies from your case, then apply some make-up,\n"
	+ "adjust your stance, and change your mannerisms.\n");
  say(lw(thief->query_name() + " applies some make-up and stands "
	 + "differently.  You can barely recognize " 
	 + thief->query_objective()) + ".\n");
  return 1;
}

int do_disguise(string arg) {
  
  int             gn, lev, gender;
  string          pretitle, title;
  
  gn = GM->query_number(arg);
  lev = thief->query_level();
  gender = thief->query_gender();
  
  if (gn==-1 || gn==2 || gn==13){
    write("What guild?\n");
    return 2;
  }
  
  if (!(pretitle = GM->query_pretitle(gn, lev, gender)))
    pretitle = "none";
  if (!(title = GM->query_title(gn, lev, gender)))
    title = "none";
  
  thief->set_pretitle(pretitle);
  thief->set_title(title);
  disguised_as=gn;
  return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Hide =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int hide(string arg) {

  object          ob, en, sh;
  int inv_lvl;
  
  if (arg)  {
/* Hide an object. */
    if (this_object()->id(arg)) {
/* Hide the guild soul. */
      if (stashed)
	write("Your tools are safely hidden already.\n");
      else {
	write("You hide your tools from prying eyes.\n");
	stashed = 1;
	thief->setenv("TH_STASHED", stashed);
      }
      return 1;
    }
    
    if (!(ob = present(arg, thief))
	&& !(ob = present(arg, environment(thief)))) {
      write("Hide what ?\n");
      return 1;
    }
    
    if (living(ob)) {
      /* Don't hide the living. */
      write(ob->short() + " moves too much to be hidden.\n");
      return 1;
    }
    
    if (ob->id("castle") || ob->query_property("no_hide")) {
      write(ob->short() + " is too big to be hidden.\n");
      return 1;
    }
    
    if (environment(ob)==thief && (en=environment(thief)))
      transfer(ob, en);
    
    sh = clone_object(dir + "/hide_shadow");
    sh->start_shadow(ob,0,"hide_shadow",arg);
    
    say(thief->query_name() + " hides something.\n");
    write("Ok.\n");
    return 1;
  }
  
  /* hide yourself */
  
  if (environment(thief)->query_property("no_hide")) {
    write("You can't find a place to hide here.\n");
    return 1;
  }
  
  if (thief->query_invis()) {
    write("You're already hidden in the shadows.\n");
    return 1;
  }
  
  if (thief->query_ghost()) {
    write("You're already pretty well hidden.\n");
    return 1;
  }
  
  CHK_ATT();
  
  if (dont_hide) {
    write("You must wait for a while.\n");
    return 1;
  }
  
  write("You hide in the shadows.\n");
  say(thief->query_name() + " leaves suddenly.\n");
  
  inv_lvl = (thief->query_level() + dex)/2 + random(10) - 5;
  if (inv_lvl < 5)
    inv_lvl = 5;
  if ((!random(60 - inv_lvl)) || (thief->query_legend_level()))
    thief->set_invis();
  else
    thief->set_invis(inv_lvl);
  return 1;
}

int reveal(string arg) {
  
  if (!arg)
    return help("reveal");
  
  if (this_object()->id(arg)) {
    if (!stashed)
      write("Your tools are already in plain sight.\n");
    else {
      write("You put your tools in plain sight.\n");
      stashed = 0;
      thief->setenv("TH_STASHED", stashed);
    }
    return 1;
  }
  
  CHK_ATT();
  
  if (rv_lock) {
    write("You continue searching.\n");
    return 1;
  }
  
  write("You start searching ...\n");
  say(thief->query_name() + " searches the room.\n");
  rv_lock = 1;
  call_out("reveal_item", 3, arg);
  return 1;
  
}

/* with full dexterity, the probabilty to find an item is 50 %, but there's a
  check against charisma (used as luck) also. */

int reveal_item(string arg) {
  
  object          ob, sh;
  int             i, chr;
  
  rv_lock = 0;
  
  ob = present(arg + "__hidden__", environment(thief));
  if (!ob || environment(thief) != environment(ob)) {
    write("You found nothing.\n");
    return 1;
  }
  
  chr = thief->query_chr();
  i = random(2 * max_stats);
  if (i > dex) {
    /* check for luck */
    if (i <= 2) {
      i = random(100);
      /* 30% max chance */
      if (i < chr)
	i = 1;
      else
	i = 0;
    }
    else
      i = 0;
  }
  else
    i = 1;
  
  if (i) {
    if (ob->hide_shadow())
      ob->end_shadow();
    write("You found " + ob->short() + ".\n");
    say(thief->query_name() + " found something.\n");
    return 1;
  }
  
  write("You found nothing.\n");
  return 1;
}

int unhide() {
  if (thief->query_ghost()) {
    write("You try to show yourself to mortal men.\n");
    return 1;
  }
  
  if (!thief->query_invis()) {
    write("You are not hiding.\n");
    return 1;
  }
  
  do_unhide();
  return 1;
}


/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Picklock +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int picklock(string arg) {
  object          pl, door;
  int             i, num_doors;
  string          dest;
  
  if (thief->query_ghost()) {
    write("You could probably move right through that keyhole.\n");
    return 1;
  }
  CHK_ATT();
  
  if (!arg)
    return help("picklock");
  if (arg != "door" && sscanf(arg, "%s door", dest) != 1)
    return 0;
  if (!(pl = present("picklock", thief))) {
    write("You don't have a picklock.\n");
    return 1;
  }
  if (pl->query_broken()) {
    /* It was broken ... get the next one */
    pl = next_inventory(pl);
    while (pl) {
      if (pl->id("picklock") && !pl->query_broken())
	break;                /* unbroken */
      pl = next_inventory(pl);
    }
    if (!pl) {
      write("Your picklock is broken.\n");
      return 1;
    }
  }
  if (!(door = present(arg, environment(thief))))
    return 0;
  if (arg == "door" && (num_doors = door->number_of_doors()) != 1) {
    door->which_door();
    return 1;
  }
  if (!door->query_locked()) {
    write("You wisely decide not to waste your picklock" +
	  " on an unlocked door.\n");
    return 1;
  }
  i = dex * 100 / max_stats;
  if (random(101) >= i) {
    pl->set_broken();
    write("CRACK! You break the picklock with your bumbling fingers.\n");
    return 1;
  }
  write("You work the wire into the lock and after a few moments of"
	+ " careful probing ...\nYou are met with success.");
  door->set_locked(0);
  door->query_partner_door()->set_locked(0);
  if (random(101) >= i) {
    pl->set_broken();
    write("But your picklock broke.\n");
  }
  else write("\n");
  return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Poison =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int poison(string arg) {
  
  string          weap, with, pois;
  object          weap_ob, pois_ob, shad;
  int             i;
  
  if (!arg)
    return help("poison");
  
  if (sscanf(arg, "%s %s %s", weap, with, pois) != 3 || with != "with") {
    write("Poison what with what?\n");
    return 1;
  }
  
  if (!(weap_ob = present(weap))) {
    write("You have no " + weap + ".\n");
    return 1;
  }
  
  if (!(pois_ob = present(pois))) {
    write("You have no " + pois + ".\n");
    return 1;
  }
  
  if (!pois_ob->query_poison()) {
    write("The " + pois_ob->query_name() + " is no poison.\n");
    return 1;
  }
  
  if (weap_ob->poison_shadow()) {
    write("You fumble, and pour the " + pois_ob->query_name() 
          + " on the ground.\n");
    return 1;
  }
  
  if (weap_ob->query_poison_shadow()) {
    write("You fumble, and pour the " + pois_ob->query_name() +
	  " on the ground.\n");
    return 1;
  }
  
  write("You pour " + pois_ob->query_name() +
	" over " + weap_ob->short() + ".\n");
  say(capitalize(thief->query_name()) + " pours " + pois_ob->query_name() +
      " over " + weap_ob->short() + ".\n");
    pois_ob->dec_doses();
  
  if (weap_ob->query_weapon()) {
    i = pois_ob->query_strength();
    shad = clone_object(dir + "/poison_shadow");
    shad->start_shadow(weap_ob, i * 600 / 50, i);
  }
  return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Sneak =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int sneak(string arg) {
  object          ob;
  
  if (thief->query_ghost()) {
    write("You could move through walls, you don't need to sneak.\n");
    return 1;
  }
  
  CHK_ATT();
  
  if (!arg)
    return help("sneak");
  
  switch (arg) {
  case "n":         arg = "north";       break;
  case "s":         arg = "south";       break;
  case "w":         arg = "west";        break;
  case "e":         arg = "east";        break;
  case "u":         arg = "up";          break;
  case "d":         arg = "down";        break;
  case "nw":        arg = "northwest";   break;
  case "ne":        arg = "northeast";   break;
  case "sw":        arg = "southwest";   break;
  case "se":        arg = "southeast";   break;
  }
  
  if (!thief->query_invis()) {
    write("You would be noticed.\n");
    return 1;
  }
  
  if (environment(thief)->move(arg))
    return 1;
  
  ob = present("castle", environment(thief));
  if (ob = present("castle", environment(thief)) && ob->move(arg))
    return 1;
  write("You bang your head.\n");
  thief->reduce_hit_point(random(20) + 1);
  return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Steal +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/


/* begin BLADE code for contest */
int set_contest(int conflag) {
  contest=conflag;
  return 1;
}

int query_contest() { return contest; }
     /* end BLADE code for contest */
     
     int contest() {
       
       object tempobj;
       
       if(contest) {
	 tempobj = find_object("/players/blade/guild/contest/contest_room");
	 tempobj->contest_status();
	 return 1;
       }
       
       else {
	 return 0;
    }
}


int steal(string arg) {
  
  string          what, whom;
  object          obji, objp, vat_cont;
  int             i, j, ddex, no_steal_level;
  int             coins;
  
  if (has_stolen)
    return 1;
  
  if (thief->query_ghost()) {
    write("You are no longer interested in the material world.\n");
    return 1;
  }
  
  CHK_ATT();
  
  if (!arg || !(sscanf(arg, "%s from %s", what, whom) == 2))
    return help("steal");
  if (!(objp = present(whom, environment(thief)))) {
    write("There is no " + whom + " present.\n");
    return 1;
  }
  if (!living(objp)) {
    write("You attempt to steal "+arg+" but aren't very "
          + "effective.\n"); 
    return 1;
  }
  
  if(objp->is_interactive()&&!thief->query_is_pk()){
    write("You must have a pk_license to steal from players.\n");
    return 1;
  }
  
  if (what == "money")
    what == "coins";
  if (what != "coins" && !(obji = present(what, objp))){
    write(capitalize(whom) + " doesn't posses such an item.\n");
    return 1;
  }
  if (objp->query_immortal()){
    write("You cannot steal from wizards.\n");
    return 1;
  }
  if (objp->query_linkdeath()){
    write("You cannot steal from " + objp->query_name() + ", " +
          objp->query_pronoun() + " is stoned.\n");
    return 1;
  }
  if (what == "bag" && dex <= LV_STBAG){ /* ok if high enough */
    write(objp->query_name()+" would notice if you stole that.\n");
    return 1;
  }
  if (environment(thief)->query_property("no_steal")){
    write("Your stealing would be recognized in this room.\n");
    return 1;
  }
  if (no_steal_level=objp->query_no_steal())
    {
      if((thief->query_level()+1)/3<no_steal_level){
        write(objp->short() + 
              " doesn't look like one whom you can steal from.\n");
        return 1;
      }
    }
  
    /*
    * Compute the random value according to the following rules: if two
    * players are of the same level, the thief gets a change of 50:50 that
    * he can success in stealing. if the thief is GM->max_levels - 1
    * dex-levels above his victim, he gets a chance of 99 % that he will
    * succeed in stealing.
    */

  has_stolen = 1;
  ddex = (dex - objp->query_dex()) * 50 / 
    (max_stats - 1) + 50;
  if (random(101) >= ddex){            /* Steal fails */
    say(thief->query_name() + " tried to steal " + what + 
	" from " + objp->query_name() + ".\n", objp);
    write(objp->query_name() + " notices your attempt!\n");
    if (objp->query_npc()){
      write(objp->query_name() + " attacks!\n");
      objp->attack_object(thief);
      return 1;
    }
    tell_object(objp, thief->query_name() + " tried to steal " + 
		what + " from you!\n");
    return 1;
  }
    
/* =+= =+= =+= =+= =+= =+= =+= =+= Coins =+= =+= =+= =+= =+= =+= =+= =+= =+= */
  
  if (what == "coins"){
    coins = objp->query_money();
    if (coins > thief->query_level() * 100 + 
	thief->query_legend_level()* 200)
      coins = thief->query_level() * 100 + thief->query_legend_level() * 200;
    if (!coins){
      write(objp->query_name() + " doesn't posess a single coin.\n");
      return 1;
    }
    
    coins = random(coins) + 1;
    thief->add_money(coins);
    objp->add_money(-coins);
    write("You have stolen " + coins + " coins from " + 
	  objp->query_name() + ".\n");
    i = random(4);
    if (!thief->query_invis())
      switch (i)
	{
	case 0:
	  tell_object(objp, "There is a rustling noise in your purse.\n");
	  break;
	case 1:
	  tell_object(objp, "You feel your purse getting lighter.\n");
	  break;
	case 2:
	  tell_object(objp, "You feel a hand in your pocket.\n");
	  break;
	case 3:
	  tell_object(objp, "You feel a soft touch in your pocket.\n");
	  break;
	}
    thief->add_alignment(AL_STEALMONEY);        /* Thieves are nasty */
    return 1;
  }
    
/* =+= =+= =+= =+= =+= =+= =+= =+= Objects =+= =+= =+= =+= =+= =+= =+= =+= */
    
  if (obji->query_wielded(obji)){
    write("You can't steal wielded stuff.\n");
    return 1;
  }
  
  if (obji->query_worn(obji)){
    write("You can't undress " + objp->query_name() + ".\n");
    return 1;
  }
  
  if (!(j = transfer(obji, thief))){
    i = random(4);
    if (!thief->query_invis())
      switch (i){
      case 0:
	tell_object(objp, "You feel like you might missing something.\n");
	break;
      case 1:
	tell_object(objp, "You seem to have lost a " + what + ".\n");
	break;
      case 2:
	tell_object(objp, "You feel a soft touch on your body.\n");
	break;
      case 3:
	tell_object(objp, "You are missing a " + what + ".\n");
	break;
      }
    write("You have stolen " + what + " from " + objp->query_name() + ".\n");
    
 /* begin CONTEST code */
    if(contest){
      write(what+" dissapears in a puff of smoke.\n");
      vat_cont=present(this_player()->query_real_name()+" barrel",
		   find_object("/players/blade/guild/contest/contest_room.c"));
      move_object(obji,vat_cont);
    }
/* end CONTEST code */

    thief->add_alignment(AL_STEALITEM);/* They ARE nasty ... */
    return 1;
  }
  else{
    if (j == 1)
      write("You can't carry any more.\n");
    else
      write("You cannot steal the " + what + " from " + 
	    objp->query_name() + ".\n");
    return 1;
  }
}

void quit() {
  
  if (dont_hide)
    thief->setenv("TH_DHIDE", dont_hide);
  else
    thief->setenv("TH_RHIDDEN", remain_hidden);
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int dump_vars() {
  
  write(thief);
  write("\n" + 
	"dex:           "           + dex + "\n" + 
	"max_stats:     "     + max_stats + "\n" + 
	"stashed:       "       + stashed + "\n" + 
	"th_xlook:      "      + th_xlook + "\n" + 
	"gm_id:         "         + gm_id + "\n" +    
	"dir:           "           + dir + "\n" +         
	"gd:            "            + gd + "\n" +        
	"helpdir:       "       + helpdir + "\n" + 
	"hideout:       "       + hideout + "\n" + 
	"att:           "           + att + "\n" +                 
	"remain_hidden: " + remain_hidden + "\n" + 
	"dont_hide:     "     + dont_hide + "\n" +  
	"rv_lock:       "       + rv_lock + "\n" +  
	"has_stolen:    "    + has_stolen + "\n");
  return 1;
}

void time_guild_soul() {
  string victim_name;
  
  has_stolen = 0;
  
  if ((!no_amb)&&(!no_throw)) return;
  
  if(!living(xatt)) {
    write("Who would you like to attack?\n");
    return;
  }
  if(no_amb)
    if (xatt && ENV(xatt)==ENV(thief)) {
      victim_name=xatt->query_name();
      write("You ambush "+victim_name+".\n");
      tell_object(xatt,thief->query_name()+" hits you swiftly.\n");
      say(thief->query_name()+" moves quickly to penetrate "+
	  victim_name+"'s defenses.\n",xatt);
      xatt->hit_player(xdam,6);
      thief->add_exp(xdam);
      if(!xatt)
	write("You watch as your ambush sends "+victim_name+
	      "'s corpse falling to the ground.\n");
      no_amb=0;
    }
  
  if(no_throw && (xdam!=0)) {
    transfer(thrown_weapon,xatt);
    victim_name=xatt->query_name();
    write("You hit "+victim_name+" with the "+
	  thrown_weapon->query_name()+"!\n");
    say(thief->query_name()+" hit "+victim_name+" with a "+
	thrown_weapon->query_name()+"\n",thief);
    xatt->hit_player(xdam,6);
    thief->add_exp(xdam);
    if(!xatt) {
      write("You grin as \n");
      no_throw=0;
    }
  }
  
  if(no_throw && (xdam==0)) {
    transfer(thrown_weapon,ENV(thief));
    write("You miss "+xatt->query_name()+" with the "+
	  thrown_weapon->query_name()+"!\n");
    say(thief->query_name()+" misses "+xatt->query_name()+" with a "+
	thrown_weapon->query_name()+"\n",thief);
    no_throw = 0;
    return;
  }
  
  if (dont_hide)
    dont_hide--;
  else {
    if (!immortal && thief->query_invis())
      remain_hidden--;
    if (remain_hidden < 0) {
      remain_hidden = TOTAL_HIDDEN;
      dont_hide = remain_hidden / 20;
      do_unhide();
    }
  }
}








