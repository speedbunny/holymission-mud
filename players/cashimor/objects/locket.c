/* LOCKET.C, Programmed by Naketa */
/* 300992: Heavily modified drop routine */
/* 300693: Ethereal Cashimor: Ported to the Holy Mission */
/* 020793: Ethereal Cashimor: Open/close locket */
/* 070793: Ethereal Cashimor: Bugs removed */
/* 130793: Ethereal Cashimor: More bugs removed */
/* 140793: Ethereal Cashimor: lhold added */
/* 150793: Ethereal Cashimor: lhair changed */
/* 190793: Ethereal Cashimor: Nape command changed */
/* 250893: Ethereal Cashimor: Multiple bugs/typos fixed */
/* 270993: Ethereal Cashimor: Tkiss bug removed */
/* 041093: Ethereal Cashimor: Hf & Lbonk bugs removed */

inherit "obj/treasure.c";

string lname="Someone";
int opened;

#include "/obj/lw.h"

query_auto_load() { 
  return "/players/exosobjects/locket:"+lname;
} 

init_arg(a) {
  lname=a;
}

reset(arg) {
  if(!arg) {
    set_value(0);
    set_id("locket");
    set_short("A Lover's Locket");
    set_long(lw("This is a lovely locket in the shape of a heart. It hangs "
           + "from a delicate, gold chain. As you study the locket further, "
           + "you see that it has a word engraved on it. You also notice that "
           + "it can be opened.\n"));
    set_weight(0);
    set_read("The engraved word says: 'helplocket'.\n");
    lname="Someone";
    opened=0;
  }
}

init() {
  ::init();
  add_action("info","helplocket");
  add_action("edname","inscript");
  add_action("open","open");
  add_action("close_it","close");
  add_action("handle_verb","lhkiss");
  add_action("handle_verb","gfoot");
  add_action("handle_verb","nape");
  add_action("handle_verb","lhair");
  add_action("handle_verb","lgaze");
  add_action("handle_verb","lshug");
  add_action("linform","linform");
  add_action("handle_verb","embrace");
  add_action("handle_verb","lhold");
  add_action("handle_verb","hgaze");
  add_action("handle_verb","lkiss");
  add_action("handle_verb","lrlove");
  add_action("handle_verb","lhhold");
  add_action("handle_verb","lnib");
  add_action("handle_verb","lbrush");
  add_action("handle_verb","lwhug");
  add_action("handle_verb","llean");
  add_action("handle_verb","lshiver");
  add_action("handle_verb","lmassage");
  add_action("handle_verb","bateye");
  add_action("tkiss","tkiss");
  add_action("simple_verb","blip");
  add_action("simple_verb","lmoan");
  add_action("handle_verb","peck");
  add_action("handle_verb","rubnose");
  add_action("destroy","destroy");
  add_action("handle_verb","ltouch");
  add_action("handle_verb","ladmire");
  add_action("simple_verb","lshow");
  add_action("handle_verb","hf");
  add_action("handle_verb","tu");
  add_action("handle_verb","lbonk");
  add_action("handle_verb","lwrestle");
  add_action("handle_verb","askmarry");
  if(this_player()->query_gender_string()=="male") {
    add_action("handle_verb","banana");
  }
}

info() {
  write("You can use the following commands:\n" +
    "ACTIONS: inscript <name>   read <locket><inscription>   lshow <locket>\n"+
    "         destroy <locket>  linform <msg> (To report bugs/typos/ideas/etc)"
+ "\n         open <locket>     close <locket>\n"
  + "ROMANTIC:tkiss <person><where>     lhold     hgaze    lgaze\n"+
    "         lkiss    lhkiss  lhhold   ltouch    lnib     lbrush\n"+
    "         llean    blip    bateye   lmoan     nape     lmassage\n" +
    "         gfoot    lhair   lrlove   lshiver   askmarry\n"+
    "FRIENDLY:embrace  lwhug   lshug    ladmire   peck\n"+
    "SILLY:   rubnose  hf      tu       lbonk     lwrestle\n"+
    "MALE ONLY:\n" +
    "banana <person>     A female (usually ;)\n");
  return 1;
}

search_who(str) {
object who;

  if(!str) return 0;
  if(!(who=present(str,environment(this_player())))) return 0;
  if(!living(who)) return 0;
  return who;
}

do_text(who,str1,str2,str3) {
  write(process_string(lw(str1)));
  tell_object(who,process_string(lw(str2)));
  say(process_string(lw(str3)),who);
}

handle_verb(str) {
object who;
string wrt,tll,sy;

  if(!(who=search_who(str))) {
    notify_fail("With who?\n");
    return 0;
  }
  switch(query_verb()) {
    case "lhold":
      wrt="You hold "+who->query_name()+" close, never wanting to let "
        + who->query_objective()+" go.\n";
      tll=this_player()->query_name()
        + " holds you close, never wanting to let you go.\n";
      sy=this_player()->query_name()+" holds "+who->query_name()
       + " close, never wanting to let "+who->query_objective()+" go.\n";
      break;
    case "lwrestle":
      wrt="Suddenly, a large gooey pool of mud appears! You throw " 
        + who->query_name()
        + " and yourself into it and start to wrestle. Both of you slip and "
        + "slide around until the two of you are totally covered in mud. Is "
        + "that what being a mud-a-holic is all about?\n";
      tll="Suddenly, a large, gooey pool of mud appears! "
        + this_player()->query_name()+" throws you and "
        + this_player()->query_objective()
        + "self into it and starts to wrestle with you. Both of you slip and "
        + "slide around until the two of you are totally covered in mud. Is "
        + "this what being a mud-a-holic is all about?\n";
      sy="Suddenly, a large gooey pool of mud appears! "
       + this_player()->query_name()+" throws "+who->query_name()
       + " into it and they start to wrestle. You watch them slip and slide "
       + "around until they are both totally covered in mud. Is this what "
       + "being a mud-a-holic is all about?\n";
      break;
    case "tu":
      wrt="You stick your thumb up in "+who->query_name()
        + "'s direction and say: Alright man!\n";
      tll=this_player()->query_name()+" sticks "
        + this_player()->query_possessive()
        + " thumb up in your direction and says: Alright man!\n";
      sy=this_player()->query_name()+" sticks "
       + this_player()->query_possessive()+" thumb up in "
       + who->query_name()+"'s direction and says: Alright man!\n";
      break;
    case "lbonk":
      wrt="You dance around "+who->query_name()+" and bonk "
        + who->query_objective()+" on the head for being so silly! "
        + who->query_name()+" says: Oiiff!\n";
      tll=this_player()->query_name()
        + " dances around you and bonks you on the head for being so silly! "
        + "You say: Oiiff!\n";
      sy=this_player()->query_name()+" runs up to "+who->query_name()
       + " and bonks "+who->query_objective()
       + " on the head for being so silly! "+who->query_name()
       + " says: Oiff!\n";
      break;
    case "hf":
      wrt="You run up to "+who->query_name()+" and high-five "
        + who->query_objective()+" with a loud *smack*.\n";
      tll=this_player()->query_name()
        +" runs up to you and high-fives you with a loud *smack*.\n";
      sy=this_player()->query_name()+" runs up to "+who->query_name()
       + "and high-fives "+who->query_objective()+" with a loud *smack*.\n";
      break;
    case "banana":
      wrt="Something grows in your pants when you look at "+who->query_name()
        + ".\n";
      tll="Your attention is suddenly drawn toward "
        + this_player()->query_name()
        + " and you wonder if that's a banana in his pocket or is he just "
        + "happy to see you?\n";
      sy="When "+this_player()->query_name()+" looks at "+who->query_name()
       + " something seems to grow in his pants.\n";
      break;
    case "lshug":
      wrt="You sneak up behind "+who->query_name()+" and tap "
        + who->query_possessive()+" shoulder. "+who->query_name()
        + " turns around, startled at being caught off guard. You give "
        + who->query_objective()+" a real nice, warm hug to calm "
        + who->query_possessive()+" rattled nerves.\n";
      tll=this_player()->query_name()
        + " sneaks up behind you and taps your shoulder. You turn around, "
        + "startled at being caught off guard. "+this_player()->query_name()
        + " gives you a real nice, warm hug to calm your rattled nerves.\n";
      sy=this_player()->query_name()+" sneaks up behind "+who->query_name()
       + " and taps "+who->query_possessive()+" shoulder. "+who->query_name()
       + " turns around, startled at being caught off guard. "
       + this_player()->query_name()+" gives "+who->query_name()
       + " a nice, warm hug too.\n";
      break;
    case "lmassage":
      wrt="You tenderly and lovingly massage "+who->query_name()
        + "'s aching muscles.\n";
      tll=this_player()->query_name()
        + "tenderly and lovingly massages your aching muscles.\n";
      sy=this_player()->query_name()+" tenderly and lovingly massages "
       + who->query_name()+"'s aching muscles.\n";
      break;
    case "bateye":
      wrt="You seductively bat your eyes at "+who->query_name()+".\n";
      tll=this_player()->query_name()+" seductively bats "
        + this_player()->query_possessive()+" eyes at you.\n";
      sy=this_player()->query_name()+" seductively bats "
        + this_player()->query_possessive()+" eyes at "+who->query_name()
        + ".\n";
      break;
    case "lshiver":
      wrt="You shiver with delight.\n";
      tll=this_player()->query_name()+" shivers in delight.\n";
      sy=tll;
      break;
    case "lhhold":
      wrt="You take "+who->query_name()
        + "'s hand and discreetly entwine your fingers together.\n";
      tll=this_player()->query_name()+" tenderly takes your hand and "
        + this_player()->query_pronoun()
        + " discreetly entwines your fingers with "
        + this_player()->query_possessive()+" own.\n";
      sy=this_player()->query_name()+" tenderly takes "+who->query_name()
       + "'s hand and discreetly entwines their fingers together.\n";
      break;
    case "lkiss":
      wrt="You give "+who->query_name()
        + " a long, slow, deep, passionate kiss.\n";
      tll=this_player()->query_name()
        + " gives you a long, slow, deep, passionate kiss.\n";
      sy=this_player()->query_name()+" gives "+who->query_name()
       + " a long, slow, deep, passionate kiss.\n";
      break;
    case "askmarry":
      wrt="You gallantly bend down on one knee and ask "
        + this_player()->query_name()+ ": 'Wilt thou fairest @@maiden|"
        + file_name(who)+"@@ take me to be your loyal @@husband@@'?\n";
      tll=this_player()->query_name()
        + " gallantly bends down on one knee and asks you: 'Wilt thou fairest "
        + "@@maiden|"+file_name(who)
        + "@@ take me to be your loyal @@husband@@'?\n";
      sy=this_player()->query_name()
        + " gallantly bends down on one knee and asks "+who->query_name()
        + ": 'Wilt thou fairest @@maiden|"+file_name(who)
        + "@@ take me to be your loyal @@husband@@'?\n";
      break;
    case "rubnose":
      wrt="You rub noses with "+who->query_name()+".\n";
      tll=this_player()->query_name()+" rubs noses with you.\n";
      sy=this_player()->query_name()+" rubs noses with "+who->query_name()
       + ".\n";
      break;
    case "lrlove":
      wrt="You tell "+who->query_name()+" that your love for "
        + who->query_objective()+" is true and everlasting.\n";
      tll=this_player()->query_name()+" tells you that "
        + this_player()->query_possessive()
        + " love for you is true and everlasting.\n";
      sy=this_player()->query_name()+" tells "+who->query_name()+" that "
       + this_player()->query_possessive()+" love for "+who->query_objective()
       + " is true and everlasting.\n";
      break;
    case "embrace":
      wrt="You give "+who->query_name()
        + " a big, warm, soul-soothing embrace.\n";
      tll=this_player()->query_name()
        + " gives you a big, warm, soul-soothing embrace.\n";
      sy=this_player()->query_name()+" gives "+who->query_name()
       + " a big, warm, soul-soothing embrace.\n";
      break;
    case "nape":
      wrt="You kiss "+who->query_name()
        + " softly and delicately on the nape of "+who->query_possessive()
        + " neck.\n";
      tll=this_player()->query_name()
        + " softly and delicately kisses you on the nape of your neck.\n";
      sy=this_player()->query_name()+" softly and delicately kisses "
       + who->query_name()+" on the nape of "+who->query_possessive()
       + " neck.\n";
      break;
    case "hgaze":
      wrt="You idly hold "
        + who->query_name()+"'s hand while your gaze is lost somewhere in "
        + who->query_possessive()+" eyes.\n";
      tll=this_player()->query_name()+" idly holds your hand while "
        + this_player()->query_possessive()
        + " gaze is lost somewhere in your eyes.\n";
      sy=this_player()->query_name()+" idly holds "+who->query_name()
        + "'s hand while "+this_player()->query_possessive()
        + " gaze is lost somewhere in "+who->query_possessive()+" eyes.\n";
      break;
    case "lhair":
      wrt="You run your fingers through "+who->query_name()
        + "'s hair lovingly.\n";
      tll=this_player()->query_name()+" runs "
        + this_player()->query_possessive()
        + " fingers through your hair lovingly.\n";
      sy=this_player()->query_name()+" runs "+this_player()->query_possessive()
        + " fingers through "+who->query_name()+"'s hair lovingly.\n";
      break;
    case "lhkiss":
      wrt="You take "+who->query_name()
        + "'s hand and softly kisses each fingertip.\n";
      tll=this_player()->query_name()
        + " gently caresses your hands, touching each fingertip with a soft "
        + "kiss.\n";
      sy=this_player()->query_name()+" kisses "+who->query_name()
       + "'s hands.\n";
      break;
    case "lgaze":
      wrt="You gaze soulfully into "+who->query_name()
        + "'s eyes, almost losing yourself in their deep, penetrating "
        + "stare.\n";
      tll=this_player()->query_name()
        + " gazes soulfully into your eyes almost losing "
        + this_player()->query_objective()+"self there.\n";
      sy=this_player()->query_name()+" gazes soulfully into "
       + who->query_name()
       + "'s eye, almost losing themselves in their deep, penetrating "
       + "stare.\n";
      break;
    case "lnib":
      wrt="You nibble suggestively on "+who->query_name()+"'s earlobe.\n";
      tll=this_player()->query_name()
        + " nibbles suggestively on your earlobe.\n";
      sy=this_player()->query_name()+" nibbles suggestively on "
       + who->query_name()+"'s earlobe.\n";
      break;
    case "lbrush":
      wrt="You lovingly brush a stray lock of hair from "+who->query_name()
        + "'s face.\n";
      tll=this_player()->query_name()
        + " lovingly brushes a stray lock of hair from your face.\n";
      sy=this_player()->query_name()
       + " lovingly brushes a stray lock of hair from "+who->query_name()
       + "'s face.\n";
      break;
    case "ltouch":
      wrt="You touch "+who->query_name()+" very tenderly and "
        + who->query_pronoun()+" trembles at your touch.\n";
      tll=this_player()->query_name()
        + " touches you very tenderly and you tremble at "
        + this_player()->query_possessive()+" touch.\n";
      sy=this_player()->query_name()+" touches "+who->query_name()
       + " very tenderly and "+who->query_name()+" trembles at "
       + this_player()->query_possessive()+" touch.\n";
      break;
    case "ladmire":
      wrt="You admire "+who->query_name()
        + "appreciatively. You've never seen anyone as attractive as "
        + who->query_objective()+"!\n";
      tll=this_player()->query_name()+" admires you appreciatively. "
        + capitalize(this_player()->query_pronoun())
        + " has never seen anyone as attractive as you!\n";
      sy=this_player()->query_name()+" admires "+who->query_name()
       + " appreciatively. "+capitalize(this_player()->query_pronoun())
       + "has never seen anyone as attractive as "+who->query_name()+".\n";
      break;
    case "llean":
      wrt="You lean back and close your eyes, letting "+who->query_name()
        + " carress you tenderly.\n";
      tll=this_player()->query_name()+" leans back and closes "
        + this_player()->query_possessive()+ " eyes, letting you caress "
        + this_player()->query_objective()+" tenderly.\n";
      sy=this_player()->query_name()+" leans back and closes "
       + this_player()->query_possessive()+" eyes, letting "
       + who->query_name()+" caress "+this_player()->query_objective()
       + " tenderly.\n";
      break;
    case "lwhug":
      wrt="You give "+who->query_name()+" a warm, friendly hug. How sweet!\n";
      sy=this_player()->query_name()+" gives "+who->query_name()
        + "a warm friendly hug. How sweet!\n";
      tll=this_player()->query_name()
        + " gives you a warm, friendly hug. How sweet!\n";
      break;
    case "peck":
      wrt="You give "+who->query_name()+" a friendly peck on the cheek.\n";
      tll=this_player()->query_name()
        + " gives you a friendly peck on the cheek.\n";
      sy=this_player()->query_name()+" gives "+who->query_name()
       + "a friendly peck on the cheek.\n";
      break;
    case "gfoot":
      wrt="You give "+who->query_name()+" a slow, luxurious foot massage.\n";
      tll=this_player()->query_name()
        + "gives you a slow, luxurious foot massage, lingering attentively "
        + "over every inch of your feet... You can feel the stress melting "
        + "away.\n";
      sy=this_player()->query_name()+" gives "+who->query_name()
       + "a luxurious foot massage.\n";
      break;
  }
  do_text(who,wrt,tll,sy);
  return 1;
}

drop() { 
  if(query_verb()=="drop") {
    write(lw("Naketa (and some mortal friends) worked very hard to get you "
        + "this locket... You think twice about dropping it. If you really "
        + "want to lose it type 'destroy locket'.\n"));
    return 1;
  }
  return 1;   
} 

open(arg) {
  if(!id(arg)) {
    notify_fail("Open what?\n");
    return 0;
  }
  if(opened) {
    notify_fail("But it is already open!\n");
    return 0;
  }
  write(lw("It seems that you can put your lover's name and picture in here. " 
      + "Type 'inscript <name>'.\n"));
  say(this_player()->query_name()+" opens a locket.\n");
  opened=1;
  return 1;
}

close_it(str) {
  if((!str)||(str!="locket")) {
    notify_fail("Close what?\n");
    return 0;
  }
  if(!opened) {
    notify_fail("But it is already closed!\n");
    return 0;
  }
  write("You close the locket.\n");
  say(this_player()->query_name()+" closes a locket.\n");
  opened=0;
  return 1;
}

simple_verb() {
string wrt,tll;

  switch(query_verb()) {
    case "blip":
      wrt="You bite your bottom lip seductively. Oooooh!\n";
      tll=this_player()->query_name()+" bites "
        + this_player()->query_possessive()
        + " bottom lip seductively. Oooooh!\n";
      break;
    case "lmoan":
      wrt="You close your eyes and moan softly.\n";
      tll=this_player()->query_name()+" closes "
        + this_player()->query_possessive()+" eyes and moans softly.\n";
      break;
    case "lshow":
      wrt="You show everyone your locket.\n";
      tll=this_player()->query_name()+" opens "
        + this_player()->query_possessive()
        + " locket and shows it to you. @@openclose@@";
    break;
  }
  write(lw(wrt));
  say(process_string(lw(tll)));
  return 1;
}

openclose() {
  if(opened) return "On the right-hand side of the locket, the name "+lname
                  + " is inscribed. On the left side there is a beautiful "
                  + "picture of "+lname+".\n";
  return "Unfortunately, the locket is closed.\n";
}

maiden(str) {
object who;

  who=find_object(str);
  if(who->query_gender_string()=="male") return "boy";
  return "maiden";
}

husband() {
  if(this_player()->query_gender_string()=="male") return "husband";
  return "wife";
}

tkiss(str) {
string whos,where,wrt,tll,sy;
object who;

  if(!str) {
    notify_fail("Tkiss who where?\n");
    return 0;
  }
  if(sscanf(str,"%s"+" "+"%s",whos,where)!=2) {
    notify_fail("Format: tkiss who where\n");
    return 0;
  }
  if(!(who=search_who(whos))) {
    notify_fail("Tkiss who?\n");
    return 0;
  }
  wrt="You plant tender kisses all over "+who->query_name()+"'s "+where+".\n";
  sy=this_player()->query_name()+" plants tender kisses all over "
   + who->query_name()+"'s "+where+".\n";
  tll=this_player()->query_name()+" plants tender kisses all over your "
    + where+".\n";
  do_text(who,wrt,tll,sy);
  return 1;
}

linform(str) {
  write("Thank you!\n");
  log_file("akasha.rep",ctime(time())+" "+this_player()->query_name()
         + " Locket: "+str+"\n");
  return 1;
}

edname(arg) {
  if(!arg) {
    notify_fail("Inscript what?\n");
    return 0;
  }
  if(!opened) {
    notify_fail("But the locket is closed!\n");
    return 0;
  }
  lname=arg;
  write(lw("Much to your amusement, a tiny Cupid suddenly appears! The Cupid "
      + "immediately inscribes your lover's name and draws a complimentary "
      + "picture of "+lname+" on the inside of your locket.\n"));
  return 1;
}

read(str) {
  if(::read(str)) return 1;
  if(str!="inscription") {
    notify_fail("Read what?\n");
    return 0;
  }
  if(!opened) {
    write("You have to open the locket to read that!\n");
    return 1;
  }
  write(lw("On the right-hand side of the locket, the name "+lname
      + " is inscribed. On the left side there is a picture of "+lname+".\n"));
  return 1;
}

destroy(arg){
  if(!id(arg)) return;
  write("You destroyed your locket, WHY ?\n");
  destruct(this_object());
  return 1;
}










