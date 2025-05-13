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
/* 041194: Shogun Exos: Removed Banana */      
/* 041194: Shogun Exos: Minor bugs removed */
/* 051194: Shogun Exos: Added more tkiss-style functions */
/* 071194: Shogun Exos: Added more romantic functions */

inherit "obj/treasure.c";
#include "/players/exos/defs.h"
#include "/obj/lw.h"

string lname="Someone";
int opened;

query_auto_load() { return XOBJ+"/locket:"+lname; } 
init_arg(a) { lname=a; }

reset(arg) {
   if (arg) return;
   set_value(0);
   set_id("locket");
   set_short(TPN+"'s Locket");
   set_long(lw("This is a lovely locket in the shape of a heart. It hangs"+
               " from a delicate, gold chain. As you study the locket further,"+
               " you see that it has a word engraved on it. You also notice that"+
               " it can be opened.\n"));
   set_weight(0);
   set_read("The engraved word says: 'helplocket'.\n");
   lname="Someone";
   opened=0;
}

init() {
   ::init();
   AA("info","helplocket");
   AA("edname","inscribe");
   AA("open","open");
   AA("close_it","close");
   AA("destroy","destroy");
   AA("linform","linform");
   AA("handle_verb","lhkiss");
   AA("handle_verb","gfoot");
   AA("handle_verb","nape");
   AA("handle_verb","lhair");
   AA("handle_verb","lgaze");
   AA("handle_verb","lshug");
   AA("handle_verb","embrace");
   AA("handle_verb","lhold");
   AA("handle_verb","hgaze");
   AA("handle_verb","lkiss");
   AA("handle_verb","lrlove");
   AA("handle_verb","lhhold");
   AA("handle_verb","lnib");
   AA("handle_verb","lbrush");
   AA("handle_verb","lwhug");
   AA("handle_verb","llean");
   AA("handle_verb","lshiver");
   AA("handle_verb","lmassage");
   AA("handle_verb","bateye");
   AA("handle_verb","peck");
   AA("handle_verb","rubnose");
   AA("handle_verb","ltouch");
   AA("handle_verb","ladmire");
   AA("handle_verb","hf");
   AA("handle_verb","tu");
   AA("handle_verb","lbonk");
   AA("handle_verb","mudwrestle");
   AA("handle_verb","askmarry");
   AA("handle_verb","lwrestle");
   AA("handle_verb","lcaress");
   AA("handle_verb","footsie");
   AA("handle_verb","lheart");
   AA("handle_verb","lfaint");
   AA("user_verb","tempt");
   AA("user_verb","caress");
   AA("user_verb","tkiss");
   AA("user_verb","massage");
   AA("simple_verb","blip");
   AA("simple_verb","lmoan");
   AA("simple_verb","lshow");
}

info() {
   ME("You can use the following commands:\n" +
      "ACTIONS: inscribe <name>   read <locket><inscription>   lshow <locket>\n"+
      "         destroy <locket>  linform <msg> (To report bugs/typos/ideas/etc)"+
      "\n         open <locket>     close <locket>\n"+
      "VARIABLE:tkiss    caress  tempt    lmassage\n"+
      "ROMANTIC:lwrestle lcaress lhold    hgaze     lrlove   lgaze\n"+
      "         lkiss    lhkiss  lhhold   ltouch    lnib     lbrush\n"+
      "         llean    blip    bateye   lmoan     nape     lmassage\n"+
      "         gfoot    lhair   lshiver  lheart    askmarry lfaint\n"+
      "FRIENDLY:embrace  lwhug   lshug    ladmire   peck     \n"+
      "SILLY:   rubnose  hf      tu       lbonk     footsie  mudwrestle\n");
   return 1;
}

search_who(str) {
   object who;

   if (!str) return 0;
   if (!who=HERE(str,ENV(TP))) return 0;
   if (!living(who)) return 0;
   return who;
}

do_text(who,str1,str2,str3) {
   ME(process_string(lw(str1)));
   TELL(who,process_string(lw(str2)));
   say(process_string(lw(str3)),who);
}

handle_verb(str) {
   object who;
   string wrt,tll,sy;

   if (!who=search_who(str)) {
      notify_fail("With who?\n");
      return 0;
   }
   switch(query_verb()) {
      case "lhold":
         wrt="You hold "+who->QNAME+" close, never wanting to let "+who->QOBJ+
             " go.\n";
         tll=TPN+" holds you close, never wanting to let you go.\n";
         sy=TPN+" holds "+who->QNAME+" close, never wanting to let "+
            who->QOBJ+" go.\n";
         break;
      case "lmassage":
         wrt="You tenderly and lovingly massage "+who->QNAME+
             "'s aching muscles.\n";
         tll=TPN+" tenderly and lovingly massages your aching muscles.\n";
         sy=TPN+" tenderly and lovingly massages "+who->QNAME+"'s aching muscles.\n";
         break;
      case "bateye":
         wrt="You seductively bat your eyes at "+who->QNAME+".\n";
         tll=TPN+" seductively bats "+TPOSS+" eyes at you.\n";
         sy=TPN+" seductively bats "+TPOSS+" eyes at "+who->QNAME+".\n";
         break;
      case "lshiver":
         wrt="You shiver with delight.\n";
         tll=TPN+" shivers in delight.\n";
         sy=tll;
         break;
      case "lhhold":
         wrt="You take "+who->QNAME+"'s hand and discreetly entwine your fingers together.\n";
         tll=TPN+" tenderly takes your hand and "+TPRO+
             " discreetly entwines your fingers with "+TPOSS+" own.\n";
         sy=TPN+" tenderly takes "+who->QNAME+
            "'s hand and discreetly entwines their fingers together.\n";
         break;
      case "lkiss":
         wrt="You give "+who->QNAME+" a long, slow, deep, passionate kiss.\n";
         tll=TPN+" gives you a long, slow, deep, passionate kiss.  You flutter\n"+
             "in delight and ecstasy.\n";
         sy=TPN+" gives "+who->QNAME+" a long, slow, deep, passionate kiss.\n";
         break;
      case "askmarry":
         wrt="You gallantly bend down on one knee and ask "+TPN+": 'Wilt thou"+ 
             "@@maiden|"+file_name(who)+"@@ take me to be your loyal "+
             "@@husband@@'?\n";
         tll=TPN+" gallantly bends down on one knee and asks you: 'Wilt thou "+
             "@@maiden|"+file_name(who)+ "@@ take me to be your loyal @@husband@@'?\n";
         sy=TPN+" gallantly bends down on one knee and asks "+who->QNAME+
            ": 'Wilt thou @@maiden|"+file_name(who)+"@@ take me to be your loyal @@husband@@'?\n";
         break;
      case "lrlove":
         wrt="You tell "+who->QNAME+" that your love for "+who->QOBJ+
             " is true and everlasting.\n";
         tll=TPN+" tells you that "+TPOSS+" love for you is true and everlasting.\n";
         sy=TPN+" tells "+who->QNAME+" that "+TPOSS+" love for "+who->QOBJ+
            " is true and everlasting.\n";
         break;
      case "nape":
         wrt="You kiss "+who->QNAME+ " softly and delicately on the nape of "+
             who->QPOSS+" neck.\n";
         tll=TPN+" softly and delicately kisses you on the nape of your neck.\n";
         sy=TPN+" softly and delicately kisses "+who->QNAME+
            " on the nape of "+who->QPOSS+" neck.\n";
         break;
      case "hgaze":
         wrt="You idly hold "+who->QNAME+"'s hand while your gaze is lost somewhere in "+
             who->QPOSS+" eyes.\n";
         tll=TPN+" idly holds your hand while "+TPOSS+
             " gaze is lost somewhere in your eyes.\n";
         sy=TPN+" idly holds "+who->QNAME+ "'s hand while "+TPOSS+
            " gaze is lost somewhere in "+who->QPOSS+" eyes.\n";
         break;
      case "lhair":
         wrt="You run your fingers through "+who->QNAME+"'s hair lovingly.\n";
         tll=TPN+" runs "+TPOSS+" fingers through your hair lovingly.\n";
         sy=TPN+" runs "+TPOSS+" fingers through "+who->QNAME+"'s hair lovingly.\n";
         break;
      case "lhkiss":
         wrt="You take "+who->QNAME+"'s hand and softly kisses each fingertip.\n";
         tll=TPN+" gently caresses your hands, touching each fingertip with a soft "+
             "kiss.\n";
         sy=TPN+" kisses "+who->QNAME+"'s hands.\n";
         break;
      case "lgaze":
         wrt="You gaze soulfully into "+who->QNAME+"'s eyes, almost losing yourself in their deep, penetrating "+
             "stare.\n";
         tll=TPN+" gazes soulfully into your eyes almost losing "+TPOBJ+
             "self there.\n";
         sy=TPN+" gazes soulfully into "+who->QNAME+
            "'s eye, almost losing themselves in their deep, penetrating "+
            "stare.\n";
         break;
      case "lnib":
         wrt="You nibble suggestively on "+who->QNAME+"'s earlobe.\n";
         tll=TPN+" nibbles suggestively on your earlobe.\n";
         sy=TPN+" nibbles suggestively on "+who->QNAME+"'s earlobe.\n";
         break;
      case "lbrush":
         wrt="You lovingly brush a stray lock of hair from "+who->QNAME+
             "'s face.\n";
         tll=TPN+" lovingly brushes a stray lock of hair from your face.\n";
         sy=TPN+" lovingly brushes a stray lock of hair from "+who->QNAME+
            "'s face.\n";
         break;
      case "ltouch":
         wrt="You touch "+who->QNAME+" very tenderly and "+who->QPRO+
             " trembles at your touch.\n";
         tll=TPN+" touches you very tenderly and you tremble at "+
             TPOSS+" touch.\n";
         sy=TPN+" touches "+who->QNAME+" very tenderly and "+who->QNAME+
            " trembles at "+TPOSS+" touch.\n";
         break;
      case "llean":
         wrt="You lean back and close your eyes, letting "+who->QNAME+
             " carress you tenderly.\n";
         tll=TPN+" leans back and closes "+TPOSS+" eyes, letting you caress "+
             TPOBJ+" tenderly.\n";
         sy=TPN+" leans back and closes "+TPOSS+" eyes, letting "+who->QNAME+
            " caress "+TPOBJ+" tenderly.\n";
         break;
      case "gfoot":
         wrt="You give "+who->QNAME+" a slow, luxurious foot massage.\n";
         tll=TPN+" gives you a slow, luxurious foot massage, lingering attentively "+
             "over every inch of your feet... You can feel the stress melting "
             "away.\n";
         sy=TPN+" gives "+who->QNAME+" a luxurious foot massage.\n";
         break;
      case "lwrestle":
         wrt="You grab "+who->QNAME+" and start to wrestle with "+who->QOBJ+
             ".  You roll around, playing with "+who->QOBJ+", until you finally"+ 
             " give in to "+who->QOBJ+".\n";
         tll=TPN+" suddenly grabs you and starts to wrestle!  You roll around"+
             " playing with "+TPOBJ+", until "+TPRO+" finally gives in to you.\n";
         sy=TPN+" grabs "+who->QNAME+" and starts to wrestle with "+who->QOBJ+
            "!  They both roll around, playing with each other, until "+TPRO+
            " finally gives in to "+who->QPRO+".\n";
         break;
      case "lcaress":
         wrt="You softly caress "+who->QNAME+"'s cheeks, staring deep into "+
             who->QOBJ+" eyes.\n";
         tll=TPN+" softly caresses your cheeks, while staring deep into your eyes.\n";
         sy=TPN+" softly caresses "+who->QNAME+"'s cheeks, while staring deep "+
            "into "+who->QPOSS+" eyes.\n";
         break;
      case "lheart":
         wrt="You take "+who->QNAME+"'s hand, and place it over your heart.\n";
         tll=TPN+" takes your hand, and places it over "+TPOSS+" heart.  You\n"+
             "feel it beat faster and faster.\n";
         sy=TPN+" takes "+who->QNAME+"'s hand and places it over "+TPOSS+" heart.\n";
         break;
      case "lfaint":
         wrt="You faint and fall back into "+who->QNAME+"'s strong arms.\n";
         tll=TPN+" faints into your arms.\n";
         sy=TPN+" faints into "+who->QNAME+"'s arms.\n";
         break;

/* Friendly commands */
      
      case "lshug":
         wrt="You sneak up behind "+who->QNAME+" and tap "+who->QPOSS+
             " shoulder.  "+who->QNAME+" turns around, startled at being caught off guard. You give "+
             who->QOBJ+" a real nice, warm hug to calm "+who->QPOSS+" rattled nerves.\n";
         tll=TPN+" sneaks up behind you and taps your shoulder.  You turn around, "+
             "startled at being caught off guard. "+TPN+" gives you a real nice, warm hug to calm your rattled nerves.\n";
         sy=TPN+" sneaks up behind "+who->QNAME+" and taps "+who->QPOSS+" shoulder.  "+
            who->QNAME+" turns around, startled at being caught off guard.  "+
            TPN+" gives "+who->QNAME+" a nice, warm hug too.\n";
         break;
      case "embrace":
         wrt="You give "+who->QNAME+" a big, warm, soul-soothing embrace.\n";
         tll=TPN+" gives you a big, warm, soul-soothing embrace.\n";
         sy=TPN+" gives "+who->QNAME+" a big, warm, soul-soothing embrace.\n";
         break;
      case "ladmire":
         wrt="You admire "+who->QNAME+" appreciatively.  You've never seen anyone as attractive as "+
             who->QOBJ+"!\n";
         tll=TPN+" admires you appreciatively.  "+CAP(TPRO)+
             " has never seen anyone as attractive as you!\n";
         sy=TPN+" admires "+who->QNAME+" appreciatively.  "+CAP(TPRO)+
            " has never seen anyone as attractive as "+who->QNAME+".\n";
         break;
      case "lwhug":
         wrt="You give "+who->QNAME+" a warm, friendly hug.  How sweet!\n";
         sy=TPN+" gives "+who->QNAME+" a warm friendly hug.  How sweet!\n";
         tll=TPN+" gives you a warm, friendly hug.  How sweet!\n";
         break;
      case "peck":
         wrt="You give "+who->QNAME+" a friendly peck on the cheek.\n";
         tll=TPN+" gives you a friendly peck on the cheek.\n";
         sy=TPN+" gives "+who->QNAME+" a friendly peck on the cheek.\n";
         break;

/* Silly commands */      
      
      case "mudwrestle":
         wrt="Suddenly, a large gooey pool of mud appears! You throw "+ 
             who->QNAME+" and yourself into it and start to wrestle. Both of you slip and "+
             "slide around until the two of you are totally covered in mud. Is "+
             "that what being a mud-a-holic is all about?\n";
         tll="Suddenly, a large, gooey pool of mud appears! "+TPN+
             " throws you and "+TPOBJ+ "self into it and starts to wrestle with you. Both of you slip and "+
             "slide around until the two of you are totally covered in mud. Is "+
             "this what being a mud-a-holic is all about?\n";
         sy="Suddenly, a large gooey pool of mud appears! "+TPN+
            " throws "+who->QNAME+ 
            " into it and they start to wrestle. You watch them slip and slide "+ 
            "around until they are both totally covered in mud. Is this what "+ 
            "being a mud-a-holic is all about?\n";
         break;
      case "tu":
         wrt="You stick your thumb up in "+who->QNAME+ "'s direction and say: Alright man!\n";
         tll=TPN+" sticks "+TPOSS+ " thumb up in your direction and says: Alright man!\n";
         sy=TPN+" sticks "+TPOSS+" thumb up in "+who->QNAME+
            "'s direction and says: Alright man!\n";
         break;
      case "lbonk":
         wrt="You dance around "+who->QNAME+" and bonk "+who->QOBJ+
             " on the head for being so silly!  "+who->QNAME+
             " says: Oiiff!\n";
         tll=TPN+ " dances around you and bonks you on the head for being so silly!  "+
             "You say: Oiiff!\n";
         sy=TPN+" runs up to "+who->QNAME+ " and bonks "+who->QOBJ+
            " on the head for being so silly!  "+who->QNAME+ " says: Oiff!\n";
         break;
      case "hf":
         wrt="You run up to "+who->QNAME+" and high-five "+who->QOBJ+
             " with a loud *smack*.\n";
         tll=TPN+" runs up to you and high-fives you with a loud *smack*.\n";
         sy=TPN+" runs up to "+who->QNAME+" and high-fives "+who->QOBJ+" with a loud *smack*.\n";
         break;
      case "rubnose":
         wrt="You rub noses with "+who->QNAME+".\n";
         tll=TPN+" rubs noses with you.\n";
         sy=TPN+" rubs noses with "+who->QNAME+".\n";
         break;
      case "footsie":   /*this needs changed*/
         wrt="You play footsie with "+who->QOBJ+".\n";
         tll=TPN+" plays footsie with you.\n";
         sy=TPN+" plays footsie with "+who->QOBJ+".\n";
         break;
   }
   do_text(who,wrt,tll,sy);
   return 1;
}

user_verb(str) {
   string whos,where,wrt,tll,sy;
   object who;

   if (!str || sscanf(str,"%s"+" "+"%s",whos,where)!=2) {
      notify_fail("Format: <verb> <who> <what>\n");
      return 0;
   }
   if (!(who=search_who(whos))) {
      notify_fail("With who?\n");
      return 0;
   }
   switch(query_verb()) {
      case "tkiss":
         wrt="You plant tender kisses all over "+who->QNAME+"'s "+where+".\n";
         sy=TPN+" plants tender kisses all over "+ who->QNAME+"'s "+where+".\n";
         tll=TPN+" plants tender kisses all over your "+ where+".\n";
         break;
      case "tempt":
         wrt="You tempt "+who->QNAME+" with "+where+".\n";
         tll=TPN+" tempts you with "+where+"!\n";
         sy=TPN+" tempts "+who->QNAME+" with "+where+".\n";
         break;
      case "caress":
         wrt="You sensually caress "+who->QNAME+"'s "+where+".\n";
         tll=TPN+" sensually caresses your "+where+".\n";
         sy=TPN+" sensually caresses "+who->QNAME+"'s "+where+".\n";
         break;
      case "massage":
         wrt="You gently massage "+who->QNAME+"'s "+where+".\n";
         tll=TPN+" gently massages your "+where+".\n";
         sy=TPN+" gently massages "+who->QNAME+"'s "+where+".\n";
         break;
   }
   do_text(who,wrt,tll,sy);
   return 1;
}

simple_verb() {
   string wrt,tll;

   switch (query_verb()) {
      case "blip":
         wrt="You bite your bottom lip seductively. Oooooh!\n";
         tll=TPN+" bites "+TPOSS+" bottom lip seductively. Oooooh!\n";
         break;
      case "lmoan":
         wrt="You close your eyes and moan softly.\n";
         tll=TPN+" closes "+TPOSS+" eyes and moans softly.\n";
         break;
      case "lshow":
         wrt="You show everyone your locket.\n";
         tll=TPN+" opens "+ TPOSS+ " locket and shows it to you. "+ 
             "@@openclose@@";
         break;
   }
   ME(lw(wrt));
   say(process_string(lw(tll)));
   return 1;
}

drop() { 
   if (query_verb()=="drop") {
      ME(lw("Naketa (and some mortal friends) worked very hard to get you "+
            "this locket...  You think twice about dropping it.  If you really "+
            "want to lose it type 'destroy locket'.\n"));
      return 1;
   }
   return 1;   
} 

open(arg) {
   if (!id(arg)) {
      notify_fail("Open what?\n");
      return 0;
   }
   if (opened) {
      notify_fail("But it is already open!\n");
      return 0;
   }
   ME(lw("It seems that you can put your lover's name and picture in here.  "+ 
         "Type 'inscribe <name>'.\n"));
   say(TPN+" opens a locket.\n");
   opened=1;
   return 1;
}

close_it(str) {
   if ((!str)||(str!="locket")) {
      notify_fail("Close what?\n");
      return 0;
   }
   if (!opened) {
      notify_fail("But it is already closed!\n");
      return 0;
   }
   ME("You close the locket.\n");
   say(TPN+" closes a locket.\n");
   opened=0;
   return 1;
}

openclose() {
   if(opened) return "On the right-hand side of the locket, the name "+lname+
                     " is inscribed.  On the left side there is a beautiful"+
                     " picture of "+lname+".\n";
   return "Unfortunately, the locket is closed.\n";
}

maiden(str) {
   object who;

   who=FIND(str);
   if(who->query_gender_string()=="male") return "princely man";
   return "fairest lady";
}

husband() {
   if(TP->query_gender_string()=="male") return "husband";
   return "wife";
}

linform(str) {
   ME("Thank you!\n");
   log_file("exos.rep",ctime(time())+" "+TPN+" Locket: "+str+"\n");
   return 1;
}

edname(arg) {
   if (!arg) {
      notify_fail("inscribe what?\n");
      return 0;
   }
   if (!opened) {
      notify_fail("But the locket is closed!\n");
      return 0;
   }
   lname=arg;
   ME(lw("Much to your amusement, a tiny Cupid suddenly appears! The Cupid "+
         "immediately inscribes your lover's name and draws a complimentary "+
         "picture of "+lname+" on the inside of your locket.\n"));
   return 1;
}

read(str) {
   if (::read(str)) return 1;
   if (str!="inscription") {
      notify_fail("Read what?\n");
      return 0;
   }
   if (!opened) {
      ME("You have to open the locket to read that!\n");
      return 1;
   }
   ME(lw("On the right-hand side of the locket, the name "+lname+
         " is inscribed. On the left side there is a picture of "+lname+".\n"));
   return 1;
}

destroy(arg) {
   if (!id(arg)) return;
   ME("You destroyed your locket, WHY?\n");
   DEST(TO);
   return 1;
}
