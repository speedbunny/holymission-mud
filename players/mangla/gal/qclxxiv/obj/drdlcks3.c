/* Rasta Iversational Channel  copied from Herp  adapted further by Qclxxiv */
/* Deutscher Chat-channel          nach eine Idee von Auslander aka Sentinel */
/* Idee uebernommen und kodiert von Herp		         	     */
#define FILENAME "players/qclxxiv/obj/drdlcks"	/* change if neccessary */

int is_broadcasting;
int prevexp;
int singing;
int curline, maxline;
string songline;
object room;

id(str) { return str=="locks" || str=="dreads" || str =="dreadlocks"; }
short() { return "DreadLocks"; }
long() { 
 write("I&I DreadLocks symbolize I&I Immunicative qualities making I&I Inite.\n"
     + "Isage: patois <mssg 2 brethren&sistren> or\n"
     + "       ii     <mssg 2 brethren&sistren>  to iversate wid all ithren.\n"
	 + "               Ommit mssg to see which ithren are currently on.\n"
	 + "       zion    to go to a place where only rasta's can go.\n"
     + "       whom [obj] to know by whom the room or object was made.\n"
     + "       lookthru [living] to compare stati. "
				+ "<living> not req. in fights.\n"
	 + "       progress  to see stored and current exp. and store current.\n"
	 + "       sing      sing a reggae song.\n"
     + "\nHave Irie Iversations I&I Ithren! Go de. JAH RASTAFARI!!!!!!!!!!!\n");
 return 1;
}

reset() { is_broadcasting=1; }
init() { 
   singing = 0;
	curline = 0;
   add_action("broadcast","patois");
   add_action("broadcast","ii");
/* a few 'guildish/racial' commands are built in dreadlocks to allow */
/* Rasta and Q174 to experiment a bit on this field. VERY restricted access */
/* to this item exists for now and the added func's are just more of what */
/* all can already have. Critical wizzes: give it a change man*/
	add_action("zion","zion");	
	add_action("whom","whom");
	add_action("perception","perception");
	add_action("perception","lookthru");
    add_action("progress","progress");
	add_action("sing","sing");
	songline = ({ 
"Hail mi idrin    love me idrin\n",
"Come take a sup off mi chalwa\n",
"'T is the season,  come mek we reason\n",
"Da-do-do-da-day\n",
"Hail mi sistren    love mi sistren\n",
"Come take a sip of mi ital\n",
"Feel mi feel when I deal mi dealing\n",
"da-do-do-da-da-day\n",
" ",
"Long long time I no see up the I\n",
"Tell I how the runnings a run, man\n",
"Got nuff things fi go tell up the I\n",
"First I'm gonna play you some music\n",
"First I'm gonna play you some music\n",
"First I'm gonna play you some music\n",
"First I'm gonna play you some music\n",
" ",
" ",
"Hail mi idrin    love mi idrin\n",
"Come take a sup off mi chalwa\n",
"'T is the season,  come mek we reason\n",
"Da-do-do-da-day\n",
"Hail mi sistren    love mi sistren\n",
"Come take a sip of mi ital\n",
"Feel mi feel when I deal mi dealing\n",
"da-do-do-da-da-day\n",
" ",
"I give thanks that you trod on yah now\n",
"Behold the powers a pow wow!\n",
"Man a sing man a chant man a dance\n",
"I'm gonna play you some music, I'm gonna play you some music\n",
"I'm gonna play you some of dem musical heavy reggae readings\n",
"Gonna play you some.........\n",
" ",
" ",
"Hail mi idrin    love mi idrin\n",
"Come take a sup off mi chalwa\n",
"Jah love is what I bring, a so me do me thing\n",
"Da-do-do-da-day\n",
"Hail mi sistren    love mi sistren\n",
"Come take a sip of mi ital\n",
"Irie vibes and Ila feeling\n",
"da-do-do-da-day\n"
	});
	maxline = sizeof(songline);
}

get() { return 1; }
drop() { return 1; }
query_broadcast() { return is_broadcasting; }
query_auto_load() { return FILENAME+":"+is_broadcasting; }
 
broadcast(str) {
  object u,r; 
  string pre_msg; 
  int i;
  if (str) {
     if (query_verb()=="ii") pre_msg="[I&I] ";/* wozu soll das gut sein ? */
	else pre_msg="";
     if (str=="on" && !is_broadcasting) {
        is_broadcasting=1;
	write("Yo Dreadlocks Rasta Iversational Channel Is On And Ital.\n");
	return 1;
     }
     if (str=="off" && is_broadcasting) {
	is_broadcasting=0;
	write("Dreadlocks Rasta Iversational Channel Is Off.\n");
	return 1;
     }
     if (!is_broadcasting) {
	write("DreadLocks not Immunicating, Sorry No Iversations.\n");
	return 1;
     } 
     u=users();
     for (i=0; i<sizeof(u); i++)
	 if ((r=present("dreadlocks",u[i])) && r->query_broadcast())
	    tell_object(u[i],pre_msg+capitalize(this_player()->query_name())
		      + " says: "+str+"\n");
     return 1;
  } 

  /* Anzeige wer aller nen Ring hat und ob er aktiv ist. */
  u=users();
  for (i=0;i<sizeof(u);i++)
      if (r=present("dreadlocks",u[i])) {
	 if (r->query_broadcast()) write("I&I:  ");
			      else write("Iversation Off: ");
	 write(u[i]->query_name()+"\n");
      }
  return 1; 
}

zion(str)
{
	move_object(this_player(),"/players/qclxxiv/library");
	write("well we really couldn't provide that, but this is a rastafarian\n" 
	+"library and normally only dreadlocks can come in. So feel at home.\n");
	return 1;
}

whom(str) /* snarfed from padrone's wand and hacked down to the bone */
{
    string what, the_creator;
    object the_thing;
    if (environment(this_object()) != this_player())
		return 0;
    if (!str) {
		the_creator = creator(environment(this_player()));
		if (the_creator)
	    	write("It must have been built by "+capitalize(the_creator)+".\n");
		else write("You get the impression that this place is very old.\n");
		return 1;
    }
    if ( !sscanf(str, "%s", what) )
		return 0;
    the_thing = present(what, this_player());
    if (!the_thing)
		the_thing = present(what, environment(this_player()));
    if (!the_thing) {
		write("There is no " + what + " here.\n");
		return 1;
    }
    the_creator = creator(the_thing);
    if (the_creator)
		write("You guess " + capitalize(the_creator) + " made " + what + ".\n");
    else write("You see nothing.\n");
    return 1;
} /* whom */

perception(arg) 
{
  object attacker, me;
  int perc,perc2,perc3,perc4,perc5;
  string pronoun, possessive;
  write("This is not provided for now anymore. Wait till THE guild will\n"
		+"be there. (Have patience:-). Anyway good luck and go de.\n" );
  return 1;

  me = this_player();
  if (arg) {
      attacker = present(lower_case(arg), environment(me));
      if (!attacker) { 	
	  	write("There is no " + arg + " here.\n");
	  	return 1;
	  }
      else if (!living(attacker)) {
	 	 write(arg + " is no living object!\n");
	  	return 1;
	  }
  }
  else attacker = me->query_attack();
  if (!attacker) {
      write("Nothing to check.\n");
      return 1;
  }
  pronoun = attacker->query_pronoun();
  if (!pronoun) pronoun = "it";
  possessive = attacker->query_possessive();
  if (!possessive) possessive = "its";
  write("The name is " + attacker->query_name() + ".\n");
  if (me->query_level()) perc=attacker->query_level()*100/me->query_level();
  else if (attacker->query_level()) perc = "many"; else perc = "none, like you";
  if (me->query_hp()) perc2= attacker->query_hp()*100/me->query_hp();
  else if (attacker->query_hp()) perc2 = "many"; else perc2 = "none, like you";
  if (me->query_sp()) perc5= attacker->query_sp()*100/me->query_sp();
  else if (attacker->query_sp()) perc5 = "many"; else perc5 = "none, like you";
  if (me->query_ac()) perc3= attacker->query_ac()*100/me->query_ac();
  else if (attacker->query_ac()) perc3 = "many"; else perc3 = "none, like you";
  if (me->query_wc()) perc4= attacker->query_wc()*100/me->query_wc(); 
  else if (attacker->query_wc()) perc4 = "many"; else perc4 = "none, like you";
  write( attacker->query_name() + "'s \n");
  write( "Level : " + perc + " % \n");
  write( "Hitpts: " + perc2 + " % \n");
  write( "Splpts: " + perc5 + " % \n");
  write( "Armour: " + perc3 + " % \n");
  write( "Weapon: " + perc4 + " % \n");
  write( "compared to yours.\n" );
  return 1;
}

progress(str)
{
	write("Previous exp: " + prevexp);
	prevexp = this_player()->query_exp();
	write(" current exp: " + prevexp + "\n");
    return 1;
}

sing(str)
{
	if (singing) {
		write("Your DreadLocks are already busy singing.\n");
		return 1;
	}
	singing = 1;
	curline = 0;
	set_heart_beat(1);
	write( "Your DreadLocks start singing a Reggae song, all by themselves.\n");
	say(
	"Someone's DreadLocks start singing a Reggae song, all by themselves.\n");
	return 1;
}

heart_beat() 
{
    room=environment(environment(this_object()));
	shout(songline[curline++] );
	if (curline>=maxline) {
		singing=0;
		set_heart_beat(0);
	}
}
