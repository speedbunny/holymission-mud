/* --------------------------------------------------------------------
   Filename: /obj/soul.
   Creator: Padrone
   Last edit:  26.3.94 whisky uni-linz.ac.at for a better code 
			   and own adverblist and some extra features.
   Comment: be careful this file is cloned in any player. Please,
			don't add new code just for fun.
   -------------------------------------------------------------------- */

string *extra; 
mapping adverbs, funs;
closure call, pres;     /* now we make speed */
int new;

#define FILE "/obj/soul:"
#define MAX_ABBR 10 

/* prototyping */
public string check_member(string arg);

void reset(int flag)
{
  if (flag == 0)
  {  
    call = #'call_other;
    pres = #'present;
    extra = ({});
    adverbs = ([ 'a': 
	      ({ "absentmindedly","affectionately","aimlessly","amazedly",
		 "amusedly","angrily","annoyedly","anxiously","apologetically",
		 "appreciatively","astonishedly"}),
		 'b':
	      ({ "badly","bashfully","bitterly","boredly","bouncily","briefly",
		 "brightly","broadly","busily" }),
                 'c':
	      ({ "carefully","charmingly","childishly","cluelessly","coldly",
		 "completely","confidently","confusedly","contemptuously",
		 "contendedly","crazily","cunningly","curageously","cutely",
		 "curiously","cynically" }),
		 'd':
	      ({ "dangerously","deeply","demonically","depressively",
		 "desperately","devilishly","dirtily","disappontedly",
		 "disgustedly","dreamily","doubtfully","drunkily" }),
		 'e':
              ({ "eagerly","egocentrically","egoisitically",
                 "endearingly","enthuisiastically","erotically",
                 "evilly","excitedly","exhaustedly" }),
		 'f':
	      ({ "fanatically","fatherly","fiercefully","firmly",
  		 "flirtatiously","fondly","foolishly","friendly",
		 "funnily","furtively" }),
		 'g':
	      ({ "gently","gigglishly","gleefully","gracefully","graciously"}),
		 'h':
	      ({ "happily","harmonically","heartbrokenly","heavily",
		 "helpfully","helplessly","honestly","hopefully","hornily",
		 "hungrily","hysterically" }),
	         'i':
	      ({ "ignorantly","impatiently","inanely","innocently",
		 "inquiringly","insanely","instantly","intently",
		 "interestedly","inwardly","irritatedly",
		 "ironically" }),
	         'j':
	      ({ "jealously","joyfully" }),
		 'k':
	      ({ "kindly","knowingly" }),
		 'l':
	      ({ "lazily","longingly","loudly","lovingly","lustfully" }),
		 'm':
	      ({ "madly","maniacally","melancholically","merrily",
		 "masterfully","mischievously","musically" }),
		 'n':
	      ({ "nastily","naughtily","nervously","nicely","noisily",
		 "nonchalantly" }),
		 'o':
	      ({ "obviously" }),
		 'p':
	      ({ "painfully","passionately","patiently","patronizingly",
		 "perfectly","personally","petulantly","physically",
		 "playfully","politely","proudly","professionally",
		 "profoundly","profusely" }),
		 'q':
	      ({ "questinoningly","quickly","quietly" }),
		 'r':
              ({ "randomly","rapidly","really","rebelliously","relievedly",
                 "roguishly","rudely" }),
		 's':
	      ({ "sadly","sadistically","sarcastically","satanically",
	 	 "scornfully","searchingly","secretly","seductively",
		 "sensually","sensuously","seriously",
		 "sexily","shamelessly","sheepishly","shyly","sickly",
		 "silently","skilfully","sleepily","slightly","slowly","slyly",
		 "smilingly","smoochily","softly","solemnly","speechlessly",
		 "strangely","stupidly","suggestively","suddenly",
		 "sweetly" }),
		 't':
	      ({ "tearfully","teasingly","tenderly","terribly","thankfully",
		 "theoretically","thoughtfully","tightly","tiredly",
		 "tragically","truly","trustfully" }),
		 'u':
	      ({ "unexpectedly","unhappily","unknowingly" }),
		 'v':
	      ({ "viciously","vigorously","virtually" }),
		 'w':
	      ({ "warmly","weakly","wearily","wholeheartedly","wickedly",
		 "wildly","wisely","wistfully","wryly" }),
		 'x':
	      ({ }),
		 'y':
	      ({ }),
		 'z':
	      ({ }),
		]);
  }
}

/* here after defining the closure */
#define pl this_player()
#define pn apply(call,pl,"query_name_true")
#define pp apply(call,pl,"query_possessive")

/*
public string 
query_auto_load()
{
  int i, sz;

   string verb_load;

   verb_load = "";

   if (sz = sizeof(extra))
   {
     for (i = 0; i < sz; i++)
     {
       if (i < (sz-1))
	  verb_load = verb_load + extra[i]+"#";
      else 
	  verb_load = verb_load + extra[i];
      }
     return FILE+verb_load;
   }
   return FILE;
}
*/

public void
init_arg(string arg)
{
   if (stringp(arg))
       extra =  explode(arg,"#");
}

int reboot() {
    return "obj/tick"->qry_timer();
}

int get()
{
  object *inv;
  int i, sz;

  inv = all_inventory(this_player());

  
  for(sz = sizeof(inv),i = 0; i < sz; i++)
  {
     if (apply(call,inv[i],"query_command_soul") && new!=1 && 
               inv[i]!=this_object())
     {
         destruct(inv[i]);
     }
   }
  return 1;
}

int drop() 
{ 
  return 1; 
}

id(str) 
{ 
   return str == "soul" || str == "command_soul";
}

void long() 
{
     write("It is transparent.\n");
}


void init() 
{
   string *actions;
   int i, sz;

    if(this_player()==environment()) get();

/*
   Yes it is possible to add a player extrafunctions by using an
   add_property("extra_soulfuns":(["function":"filename"])).
   But just adding the property would remove old properties so you
   have to code:

   mapping old_props, new_props;

   old_props = this_player()->query_property("extra_soulfuns");

   if (mappingp(old_props))
       new_props = old_props + (["myfunction":"myfile"]);
   else
       new_props = (["myfunction":"myfile"]);

   this_player()->add_property("extra_soulfuns":new_props);

   * the myfunction is the action which the player types to use your
     function. Examples: bubble, turn, sleep, rest. 

   * the myfile is the file where your function is defined.

   The soul will than call the function in your file by calling
   myfile->myfunction(arg).

   Please don't change the dir of the file if once coded. And look
   that the function sure works. Please check the code carefully
   before adding this property. Unless the player gets bugs :*)

   Please note that existing playerfunctions can't be overwritten
   by this property, btw timefactors have to be handled in the file
   itself !
                     
                                                                  */
       
    if (mappingp(funs=apply(call,pl,"query_property","extra_soulfuns")))
    {
        actions = m_indices(funs);
        for(sz = sizeof(actions),i = 0; i < sz; i++)
            add_action("extra_function",actions[i]);
    }
        
/* a */
    add_action("ack","ack");
    add_action("applaud", "applaud");
    add_action("agree","agree");
/* b */
    add_action("beg","beg");
    add_action("brighten","brighten");
    add_action("blush", "blush");
    add_action("bounce", "bounce");
    add_action("bow", "bow");
    add_action("burp", "burp");
/* c */
    add_action("cackle", "cackle");
    add_action("cheer","cheer");
    add_action("chuckle", "chuckle");
    add_action("clap", "clap");
    add_action("comfort", "comfort");
    add_action("confused","confused");
    add_action("congratulate","congratulate");
    add_action("cough", "cough");
    add_action("cry", "cry");
    add_action("cuddle", "cuddle");
    add_action("curse", "curse");
    add_action("cringe","cringe");
    add_action("curtsey", "curtsey");
/* d */
    add_action("dance", "dance");
    add_action("dream","dream");
    add_action("die","die");
    add_action("duh","duh");
/* e */
    add_action("eyebrow","eyebrow");
    add_action("eeks","eeks");
    add_action("excuse","excuse");
/* f */
    add_action("fart", "fart");
    add_action("flip", "flip");
    add_action("fondle", "fondle");
    add_action("french", "french");
    add_action("frown", "frown");
    add_action("fume","fume");
/* g */
    add_action("gasp", "gasp");
    add_action("giggle", "giggle");
    add_action("glare", "glare");
    add_action("greet","greet");
    add_action("grin", "grin");
    add_action("groan", "groan");
    add_action("grope", "grope");
    add_action("growl", "growl");
/* h */
    add_action("hiccup", "hiccup");
    add_action("hug", "hug");
    add_action("hop","hop");
/* i */
/* j */
//    add_action("fcn_exits","ex");
/* k */
    add_action("kick", "kick");
    add_action("kiss", "kiss");
    add_action("knee", "knee");
/* l */
    add_action("laugh", "laugh");
    add_action("lick", "lick");
    add_action("love", "love");
/* m */
    add_action("moan", "moan");
    add_action("mount","mount");
/* n */
    add_action("nibble", "nibble");
    add_action("no", "no");
    add_action("nod", "nod");
    add_action("nuzzle","nuzzle");
/* o */
    add_action("oops","oops");
/* p */
    add_action("panic","panic");
    add_action("point","point");
    add_action("ponder","ponder");
    add_action("poke", "poke");
    add_action("pout", "pout");
    add_action("puke", "puke");
    add_action("purr", "purr");
/* q */
/* r */
    add_action("ruffle", "ruffle");
    add_action("rolleyes","rolleyes");
/* s */
    add_action("scream", "scream");
    add_action("scratch","scratch");
    add_action("shake", "shake");
    add_action("shiver", "shiver");
    add_action("shrug", "shrug");
    add_action("sigh", "sigh");
    add_action("sing", "sing");
    add_action("slap", "slap");
    add_action("smirk", "smirk");
    add_action("smile", "smile");
    add_action("snap", "snap");
    add_action("sneeze", "sneeze");
    add_action("snicker", "snicker");
    add_action("sniff", "sniff");
    add_action("snore", "snore");
    add_action("snuggle", "snuggle");
    add_action("spit", "spit");
    add_action("squeeze", "squeeze");
    add_action("stare", "stare");
    add_action("strut", "strut");
    add_action("sulk", "sulk");
    add_action("steam","steam");
    add_action("stomp","stomp");
    add_action("stretch","stretch");
/* t */
    add_action("tap","tap");
    add_action("tongue","tongue");
    add_action("thank", "thank");
    add_action("twiddle", "twiddle");
    add_action("tickle","tickle");
    add_action("think","think");
/* u */
/* v */
/* w */
    add_action("wave", "wave");
    add_action("whistle", "whistle");
    add_action("wiggle", "wiggle");
    add_action("wink", "wink");
    add_action("worship","worship");
/* x */
/* y */
    add_action("yawn", "yawn");
    add_action("yodel","yodel");
/* z */
    add_action("fcn_me","me");
    add_action("fcn_adverblist","adverbs");
    add_action("fcn_addadverb","adverb");  /* max 20 */
    add_action("fcn_newsoul","newsoul");
}

/* ---------------------  is member (efun buggy !) ------------------- */

public int
is_member(string elem,string *arr)
{
  return member_array(elem,arr);
}

/* ---------------------  adding a new abbrevation ------------------- */

 public int
 fcn_addadverb(string arg)
 {

    if (!stringp(arg))
    {
      write("Syntax: adverb <adverbname> to add or remove an adverb.\n");
      return 1;
    }
    else if (strlen(arg) < 6)
    {
      write("The stringlength of your adverb is too short (min 5).\n");
      return 1;
    }
    else if (is_member(arg,extra)!=-1)
    {
       write(arg+" removed from the adverblist.\n");
       extra = extra - ({ arg });
       return 1;
    }
    else if  (sizeof(extra) >= MAX_ABBR)
    {
       write("Adding new adverbs means removing old ones.\n");
       return 1;
    } 
    else {
       write(arg+" added to the adverblist.\n");
       extra = extra + ({ arg });
    }
   return 1;
 }
       

/* ----------------- checking if the verb is an abbrevation ----------- */

public string
check_member(string arg)
{
  int fchar, sz;
  string *list;
  closure ext,strl;

  if (strlen(arg) <= 3)  
      return arg;

  ext = #'extract;
  strl = #'strlen;

  sz = sizeof(extra);

   while(sz)
   {
       if (arg== funcall(ext,extra[sz-1],0,funcall(strl,arg)-1)) 
           return extra[sz-1]; 
       sz --;
   }

  fchar = arg[0]; 
  list = adverbs[fchar];
  sz = sizeof(list);

   while(sz)
   {
      if (arg== funcall(ext,list[sz-1],0,funcall(strl,arg)-1))  
          return list[sz-1];
      sz--;
   }
  return arg;
}
   
/* ------------------------ verblist --------------------------- */

public int
fcn_adverblist(string arg)
{
  int fchar, i, sz, cut;
  string *list, alist;

if (!stringp(arg))
{
  write("Self defined adverbs:\n\n");

  for(sz = sizeof(extra),i=0 ; i< sz; i++)
  {
         if (stringp(extra[i]))
             write(extra[i]+"\n");
  }
  write("\n\n");
  write("You can use any of your defined or predefined adverbs\n"+
        "in your feelings, by typing the first four letters.\n"+
        "By typing adverbs <letter> you get the predefined list.\n");
  write("If you have any troubles with your soul type: newsoul :*)\n");
  return 1;
 } 

 fchar = arg[0];
 alist = "";

 if (sz = sizeof(adverbs[fchar]))
 {
   cut = 60;
   write("Predefined adverbs under "+arg+":\n\n");
   for (i=0;i < sz; i++)
   {
      if (i < (sz - 1) )
          alist = alist + adverbs[fchar][i]+", ";
      else 
          alist = alist + adverbs[fchar][i]+".\n";

      if (strlen(alist) > cut)
      {
         cut = cut + 60;
          alist = alist +"\n";
       }
   }
   write(alist);
  return 1;
 }  
  write("\n\nNo predefined adverbs under "+arg+" found.\n");
  return 1;
}
   

/* say func */

void _say(string name, string what, object o1, object o2,int inv) 
{
    if (o2 && inv)
        say(name + what, o1, o2, "Someone"+what);
    else 
        say(name + what, o1);
}
   
/* -------------------------- applaud ------------------------------ */

public int applaud(string arg) 
{
    if (!stringp(arg))
	{
      write("You applaud wholeheartedly.\n");
      _say(pn," gives a round of applause.\n",0,pl,1);
      return 1;
    }
    write("You applaud "+check_member(arg)+".\n");
    _say(pn," applouds "+check_member(arg)+".\n",0,pl,1);
	return 1;
}

/* -------------------------- agree ------------------------------ */

public int agree(string arg) 
{
    if (!stringp(arg))
	{
      write("You agree wholeheartedly.\n");
      _say(pn," agrees wholeheartly.\n",0,pl,1);
      return 1;
    }
    write("You agree "+check_member(arg)+".\n");
    _say(pn," agrees "+check_member(arg)+".\n",0,pl,1);
	return 1;
}

/* -------------------------- ack ------------------------------ */

public int ack()
{
  write("ACK !\n");
  _say(pn," goes ack.\n",0,pl,1);
  return 1;
}
/* -------------------------- blush ------------------------------ */

public int blush(string arg) 
{
  if (!stringp(arg))
  {
    write("Your cheeks are burning.\n");
    say(pn + " blushes.\n",0,pl,"");
    return 1;
  }
    write("You blush "+check_member(arg)+".\n");
    say(pn + " blushes "+check_member(arg)+".\n",0,pl,"");
    return 1;
}

/* -------------------------- beg ------------------------------ */

public int beg(string arg) 
{
    object who;
  if (!stringp(arg))
  {
    write("Your fall on your knees beging for fortune.\n");
    say(pn + " falls on "+pp+
			 " knees beging for fortune.\n",0,pl,
    "Someone whines innocently.\n");
    return 1;
  }
    who = apply(pres,arg, environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " begs you for fortune.\n",pl);
       write("You beg " + apply(call,who,"query_name") +".\n");
       say(pn + " begs " + apply(call,who,"query_name") + 
           " for fortune.\n", who, pl,
       "Someone whines innocently.\n");
       return 1;
    }
    write("Beg whom ?.\n");
    return 1;
}
/* -------------------------- bounce ------------------------------ */
public int bounce(string arg) 
{
  if (!stringp(arg))
  {
    write("B O I N G !!\n");
    _say(pn," bounces around.\n",0,pl,1);
    return 1;
  }
    write("You bounce "+check_member(arg)+".\n");
    _say(pn," bounces "+check_member(arg)+".\n",0,pl,1);
    return 1;
}

/* -------------------------- brighten ------------------------------ */

public int brighten() 
{
    write("You think about it, then it dawns you. You face brightens !\n");
    say(pn + " Thinks hard, then it dawns on "+pp+
		", "+pp+" face brightens !.\n",0,pl,"");
    return 1;
}

/* -------------------------- bow ------------------------------ */

public int bow(string arg) 
{
    object who;

    if (!stringp(arg)) 
	{
    write("You bow to your audience.\n");
	 say(pn + " bows gracefully.\n",0,pl,"");
	return 1;
    }
    who = apply(pres, arg, environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " bows before you.\n",pl);
       write("You bow to " + apply(call,who,"query_name") +".\n");
       say(pn + " bows to " + apply(call,who,"query_name") + ".\n",who,pl,"");
       return 1;
    }
    write("You bow "+check_member(arg)+".\n");
	 say(pn + " bows "+check_member(arg)+".\n",0,pl,"");
	return 1;
}

/* -------------------------- burp ------------------------------ */

public int burp(string arg) 
{
  if (!stringp(arg))
  {
    write("You burp loudly.\nExcuse yourself!\n");
    _say(pn," burps rudely.\n",0,pl,1);
    return 1;
  }
    write("You burp "+check_member(arg)+".\n");
    _say(pn," burps "+check_member(arg)+".\n",0,pl,1);
    return 1;
}

/* -------------------------- cackle ------------------------------ */

public int cackle(string arg) 
{
  if (!stringp(arg))
  {
    write("You cackle gleefully.\n");
    say(pn + " throws " + pp +
	" head back and cackles with glee!\n",0,pl,
   "Someone cackles with glee.\n");
    return 1;
  }
    write("You cackle "+check_member(arg)+".\n");
    _say(pn," cackles " +check_member(arg)+".\n",0,pl,1);
    return 1;
}

/* -------------------------- cheer ------------------------------ */

public int cheer(string arg) 
{
  if (!stringp(arg))
  {
    write("You cheer enthusiastically.\n");
    _say(pn," cheers enthusiastically.\n",0,pl,1);
    return 1;
  }
    write("You cheer "+check_member(arg)+".\n");
    _say(pn," cheers "+check_member(arg)+".\n",0,pl,1);
    return 1;
}
/* -------------------------- chuckle ------------------------------ */

public int chuckle(string arg) 
{
   if (!stringp(arg))
   {
     write("You chuckle politely.\n");
     _say(pn," chuckles politely.\n",0,pl,1);
     return 1;
   }
   write("You chuckle "+check_member(arg)+".\n");
   _say(pn," chuckles "+check_member(arg)+".\n",0,pl,1);
   return 1;
}

/* -------------------------- clap ------------------------------ */

public int clap(string arg) 
{
  if (!stringp(arg))
  {
    write("You clap briefly.\n");
    _say(pn," claps briefly.\n",0,pl,1);
    return 1;
  }
   write("You clap "+check_member(arg)+".\n");
   _say(pn," claps "+check_member(arg)+".\n",0,pl,1);
   return 1;
}

/* -------------------------- comfort ------------------------------ */

public int comfort(string arg) 
{
    object who;

   if (stringp(arg))
   {
       who = apply(pres,arg, environment(pl));

    if ((objectp(who)) && living(who) && who!=pl)
	{
       tell_object(who, pn + " comforts you.\n");
       write("You comfort " + apply(call,who,"query_name") + ".\n");
       say(pn + " comforts " + apply(call,who,"query_name") + ".\n",who,pl,"");
       return 1;
    } 
   }
   write("Comfort whom ?\n"); 
   return 1;
}

/* -------------------------- confuse ------------------------------ */

public int confused()
{
     write("You try to think, but fail.\n");
     say(pn+" looks confused.\n",0,pl,"");
     return 1;
}

/* -------------------------- congratulate ------------------------------ */

public int congratulate(string arg) 
{
    object who;

   if (stringp(arg))
   {
       who = apply(pres,arg, environment(pl));

    if ((objectp(who)) && living(who) && who!=pl)
	{
       tell_object(who, pn + " congratulates you.\n");
       write("You congratulate " + apply(call,who,"query_name") + ".\n");
       _say(pn," congratulate " + apply(call,who,"query_name") + 
           ".\n",who,pl,1);
       return 1;
    } 
   }
   write("Congratulate whom ?\n"); 
   return 1;
}

/* -------------------------- cough ------------------------------ */

public int cough(string arg) 
{
  if (!stringp(arg))
  {
    write("You cough noisily.\n");
    _say(pn," coughs noisily.\n",0,pl,1);
    return 1;
  }
  write("You cough "+check_member(arg)+".\n");
  _say(pn," coughs "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- cry ------------------------------ */

public int cry(string arg) 
{
  if (!stringp(arg))
  {
    write("Waaaaah!\n");
    say(pn + " bursts into tears.\n",pl);
    return 1;
  }
  write("You cry "+check_member(arg)+".\n");
  _say(pn," cries "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- cuddle ------------------------------ */

public int cuddle(string arg) 
{
    object who;
    string h1,h2;

  if (stringp(arg))
  {
	if (sscanf(arg,"%s %s",h1,h2))
        who = apply(pres,h1, environment(pl));
    else 
        who = apply(pres,arg, environment(pl));

   if (objectp(who) && living(who) && who!=pl)
   {
	  if (stringp(h2))
	  {
        tell_object(who, pn + " "+check_member(h2)+" cuddles you.\n");
        write("You "+check_member(h2)+" cuddle " + who->query_name() + ".\n");
        _say(pn," "+check_member(h2)+" cuddles " 
					+ apply(call,who,"query_name") + ".\n",who,pl,1);
        return 1;
      }
     tell_object(who, pn + " cuddles you.\n");
     write("You cuddle " + apply(call,who,"query_name") + ".\n");
     _say(pn," cuddles " + apply(call,who,"query_name") + ".\n",who,pl,1);
    return 1;
   }
  } 
  write("Cuddle whom ?\n");
  return 1;
}

/* -------------------------- curse ------------------------------ */

public int curse(string arg) 
{
  if (!stringp(arg))
  {
     write("You swear loudly for a long time.\n");
     _say(pn," swears: #@@*\"*&^$%@@*&! !!!!!\n",0,pl,1);
     return 1;
  }
    write("You curse "+check_member(arg)+".\n");
    _say(pn," curses "+check_member(arg)+".\n",0,pl,1);
    return 1;
}

/* -------------------------- curtsey ------------------------------ */

public int curtsey(string arg) 
{
  if (!stringp(arg))
  {
    write("You curtsey gracefully.\n");
    say(pn + " curtseys gracefully.\n",0,pl,"");
    return 1;
  }
  write("You curtsey "+check_member(arg)+".\n");
  say(pn + " curtseys "+check_member(arg)+".\n",0,pl,"");
  return 1;
}

/* -------------------------- cringe ------------------------------ */

public int cringe() 
{
    write("You cringe in terror.\n");
    _say(pn," crings in terror.\n",0,pl,1);
    return 1;
}
/* -------------------------- dance ------------------------------ */

public int dance(string arg) 
{
    object who;

    if (stringp(arg))
	{
        who = apply(pres,arg, environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " sweeps you across the dance floor.\n");
       write("You sweep " + apply(call,who,"query_name") +
             " across the dance floor.\n");
       say(pn + " sweeps " + apply(call,who,"query_name") + 
		" across the dance floor.\n",who,pl,
      "Someone does the disco duck.\n");
       return 1;
    }
   }
   write("Feels silly, doesn't it?\n");
   say(pn + " does the disco duck.\n",0,pl,"");
   return 1;
}

/* -------------------------- die ------------------------------ */

public int die() 
{
   write("You fall down, acting dead.\n");
   say(pn + " rolls over and does " + 
	    pp + " best to look dead.\n",0,pl,
       "Thump ! Something rolls on the floor.\n");
   return 1;
}

/* -------------------------- dream ------------------------------ */
public int dream(string arg)
{

	if (!stringp(arg))
	{
	   write("You are dreaming something lovely.\n");
           say(pn+" seems to have sweet dreams.\n",0,pl,"");
       return 1;
    }
    write("You dream about "+arg+".\n");
    say(pn+" dreams about "+arg+".\n",0,pl,"");
  return 1;
}

/* -------------------------- duh ------------------------------ */

public int duh()
{
	 write("Uh, duhh.... feeling stupid, eh ?\n");
         say(pn + " goes duhh, must be feeling dumb.\n",0,pl,"Uhh duhh.\n");
	 return 1;
}
/* -------------------------- eeks ------------------------------ */

public int eeks()
{
	 write("Eeks ! Oh my gosh !\n");
         say(pn+ " goes eeks !\n",0,pl,"Eek !\n");
	 return 1;
}

/* -------------------------- excuse ------------------------------ */

public int excuse(string arg) 
{
    object who;

   if (stringp(arg))
   {
       who = apply(pres,arg, environment(pl));

    if ((objectp(who)) && living(who) && who!=pl)
	{
       tell_object(who, pn + " excuses "+pp+
	   "self.\n");
       write("You excuse yourself to " + apply(call,who,"query_name") + ".\n");
       say(pn + " excuses "+pp+"self to " 
		  + apply(call,who,"query_name") + ".\n",who,pl,"Sorry.\n");
       return 1;
    } 
   }
   write("Excuse to whom ?\n"); 
   return 1;
}

/* -------------------------- eyebrow ------------------------------ */

public int eyebrow(string arg) 
{
    object who;

   if (stringp(arg))
   {
       who = apply(pres,arg, environment(pl));

    if ((objectp(who)) && living(who) && who!=pl)
	{
       tell_object(who, pn + " raises an eyebrow at you.\n"); 
       write("You raise an eyebrow at "+apply(call,who,"query_name")+".\n");
       say(pn + " raises an eyebrow at " + apply(call,who,"query_name")+
           ".\n",who,pl,"");
       return 1;
    } 
   }
   write("You raise an eyebrow.\n"); 
   say(pn+" raises an eyebrow.\n",0,pl,""); 
   return 1;
}
/* -------------------------- fart ------------------------------ */

public int fart(string arg) 
{
  if (!stringp(arg))
  {
    write("How rude!\n");
    say(pn + " lets off a real rip-roarer.\n",0,pl,
        "Bfffptttt... Something smells strange.\n");
    return 1;
  }
  write("You fart "+check_member(arg)+".\n");
  say(pn + " farts "+check_member(arg)+".\n",0,pl,
      "Bfffptttt... Something smells strange.\n");
  return 1;
}

/* -------------------------- fume ------------------------------ */

public int fume(string arg) 
{
  if (!stringp(arg))
  {
    write("You fume angrily.\n");
    _say(pn," fumes angrily.\n",0,pl,1);
    return 1;
  }
  write("You fume "+check_member(arg)+".\n");
  _say(pn," fumes "+check_member(arg)+".\n",0,pl,1);
  return 1;
}
/* -------------------------- flip ------------------------------ */

public int flip() 
{
    write("You flip head over heels.\n");
    say(pn + " flips head over heels.\n",0,pl,"Bonk, Hurray, Jippi.\n");
    return 1;
}

/* -------------------------- fondle ------------------------------ */

public int fondle(string arg) 
{
    object who;

	if (stringp(arg))
	{
        who = apply(pres,arg, environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " fondles you sexily.\n");
       write("You fondle " + apply(call,who,"query_name") + ".\n");
       say(pn + " fondles " + apply(call,who,"query_name") + ".\n",who,pl,
       "Someone groans with pleasure.\n");
       return 1;
    }
   }
   write("Fondle whom ?\n");
   return 1;
}

/* -------------------------- french ------------------------------ */

public int french(string arg) 
{
  object who;

  if (stringp(arg))
  {
      who = apply(pres,arg, environment(pl));

  if (objectp(who) && living(who) && who!=pl)
  {
    tell_object(who, pn +
       " gives you a deep and passionate kiss..it seems to take forever...\n");
    write("You give " + apply(call,who,"query_name") + 
		  " a REAL kiss..it lasts a long time...\n");
    say(pn + " gives " + apply(call,who,"query_name") +
       " a deep and passionate kiss..it seems to take forever...\n",who,pl,
       "SMACK !\n");
    return 1;
  }
 }
 write("French whom ?\n");
 return 1;
}

/* -------------------------- frown ------------------------------ */

public int frown(string arg) 
{
  if (!stringp(arg))
  {
    write("Is something wrong?\n");
    _say(pn," frowns.\n",0,pl,1);
    return 1;
  }
  write("You frown "+check_member(arg)+"\n");
  _say(pn," frowns "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- gasp ------------------------------ */

public int gasp() 
{
    write("You gasp in astonishment.\n");
    say(pn + " gasps in astonishment!\n",0,pl,"Ohh Gosh !\n");
    return 1;
}

/* -------------------------- greet ------------------------------ */

public int greet(string arg) 
{
    object who;

   if (stringp(arg))
   {
       who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " greets you.\n",pl);
       write("You raise your hand to greet " + apply(call,who,"query_name") 
           + ".\n");
       say(pn + " raises "+pp+" hand to greet " 
		   + apply(call,who,"query_name") + ".\n", who,pl,"Salute !\n");
       return 1;
    }
   }
  write("Greet whom ?\n");
  return 1;
}


/* -------------------------- giggle ------------------------------ */

public int giggle(string arg) 
{
  if (!stringp(arg))
  {
    write("You giggle inanely.\n");
    _say(pn," giggles inanely.\n",0,pl,1);
    return 1;
  }
  write("You giggle "+check_member(arg)+".\n");
  _say(pn," giggles "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- glare ------------------------------ */

public int glare(string arg) 
{
    object who;

   if (stringp(arg))
   {
       who = apply(pres,arg, environment(pl));

	if (stringp(arg) && objectp(who) && living(who))
	{
       tell_object(who, pn + " glares at you.\n",pl);
       write("You glare stonily at " + apply(call,who,"query_name") + ".\n");
       say(pn + " glares at " + apply(call,who,"query_name")+".\n", who,pl,"");
       return 1;
    }
  }
  write("Glare at whom ?\n");
  return 1;
}

/* -------------------------- grin ------------------------------ */

public int grin(string arg) 
{
  if (!stringp(arg))
  {
    write("You grin evilly.\n");
    say(pn + " grins evilly.\n",0,pl,"");
    return 1;
  }
  write("You grin "+check_member(arg)+".\n");
  say(pn + " grins "+check_member(arg)+".\n",0,pl,"");
  return 1;
}

/* -------------------------- groan ------------------------------ */

public int groan(string arg) 
{
  if (!stringp(arg))
  {
    write("You groan loudly.\n");
    _say(pn," groans loudly.\n",0,pl,1);
    return 1;
  }
  write("You groan "+check_member(arg)+".\n");
  _say(pn," groans "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- grope ------------------------------ */

public int grope(string arg) 
{
    object who;

	if (stringp(arg))
    {
        who = apply(pres,arg, environment(pl));
   
    if (objectp(who) && living(who) && who!=pl)

	{
       tell_object(who, pn + " gropes you lustfully.\n");
       write("You lustfully grope "+who->query_name()+".\n");
       say(pn +" lustfully gropes "+ who->query_name() + ".\n",who,pl,
       "Ahhhhh Uhhhh !\n");
       return 1;
    }
  }
  write("Grope whom ?\n");
  return 1;
}

/* -------------------------- growl ------------------------------ */

public int growl(string arg) 
{
    object who;

    if (!stringp(arg)) 
	{
       write("You growl.\n");
       _say(pn," growls.\n",0,pl,1);
	   return 1;
    }

    who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who))
	{
       tell_object(who, pn + " growls at you.\n");
       write("You growl at " + apply(call,who,"query_name") +".\n");
       say(pn + " growls at " + apply(call,who,"query_name") + ".\n",who,pl,
       "Someone growls.\n");
       return 1;
    }
	write("You growl "+check_member(arg)+".\n");
	_say(pn," growls "+check_member(arg)+".\n",0,pl,1);
	return 1;
}

/* -------------------------- hiccup ------------------------------ */

public int hiccup() 
{
    write("Hic!\n");
    say(pn + " hiccups.\n",0,pl,"Hic !\n");
    return 1;
}

/* ------------------------- hop ------------------------------ */
public int hop(string arg)
{
  if (!stringp(arg))
  {
   write("You happily hop around.\n");
   say(pn+" happily hops around.\n",0,pl,"Bonk...Bonk..Bonk\n");
   return 1;
  }
  write("You "+check_member(arg)+" hop around.\n");
  say(pn+" " +check_member(arg)+" hops around.\n",0,pl,"Bonk...Bonk...Bonk\n");
  return 1;
}

/* ------------------------- hug ------------------------------ */

public int hug(string arg) 
{
    object who;
	string h1,h2;

  if (stringp(arg))
  {
	  if (sscanf(arg,"%s %s",h1,h2))
         who = apply(pres,h1, environment(pl));
      else 
         who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
	  if (stringp(h2))
	  {
         tell_object(who, pn + " "+check_member(h2)+" hugs you.\n");
         write("You "+check_member(h2)+" hug " + apply(call,who,"query_name") 
         + ".\n");
         _say(pn," "+check_member(h2)+" hugs " 
			 + apply(call,who,"query_name") + ".\n",who,pl,1);
         return 1;
       }
       tell_object(who, pn + " hugs you.\n");
       write("You hug " + apply(call,who,"query_name") + ".\n");
       _say(pn," hugs " + apply(call,who,"query_name") + ".\n",who,pl,1);
	   return 1;
    }
  }
  write("Hug whom ?\n");
  return 1;
}

/* -------------------------- kick ------------------------------ */

public int kick(string arg) 
{
    object who;

  if (stringp(arg))
  {
      who = apply(pres,arg, environment(pl));

	if (stringp(arg) && objectp(who) && who!=pl)
	{
	  if (living(who))
          tell_object(who, pn + " kicks you.   OUCH!!\n");
       say(pn+" kicks "+apply(call,who,"query_name") + ".\n",who,pl,
       "Autch !\n");
       write("You kick " + apply(call,who,"query_name") + ".\n");
       return 1;
    }
  }
  write("Kick whom ?\n");
  return 1;
}

/* -------------------------- kiss ------------------------------ */

public int kiss(string arg) 
{
    object who;
	string h1,h2;

  if (stringp(arg))
  {
	if (sscanf(arg,"%s %s",h1,h2)==2)
        who = apply(pres,h1, environment(pl));
    else 
		who = apply(pres,arg,environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
      if (stringp(h2))
	  {
          tell_object(who,pn +" "+check_member(h2)+" kisses you.\n");
          say(pn + " "+check_member(h2)+" kisses " 
			  + apply(call,who,"query_name") + ".\n",who,pl,"Smack..\n");
          write("You "+check_member(h2)+" kiss " + 
                apply(call,who,"query_name") + ".\n");
      } else  
	  {
          tell_object(who, pn + " kisses you.\n");
          say(pn + " kisses " + apply(call,who,"query_name") + ".\n",who,pl,
          "Smack..\n");
          write("You kiss " + apply(call,who,"query_name") + ".\n");
      }

      if (apply(call,who,"query_frog")) 
	   {
        apply(call,pl,"frog_curse",1);
        apply(call,who,"frog_curse",0);
      }
	  return 1;
    }  /* endif objectp */
  }  /* endif stringp */
  write("Kiss whom ?\n");
  return 1;
}

/* -------------------------- knee ------------------------------ */

public int knee(string arg) 
{
    object who;

   if (stringp(arg))
       who = apply(pres,arg, environment(pl));

 if (objectp(who) && living(who) && who!=pl)
 {
   if (apply(call,who,"query_male")) 
  {
	tell_object(who, pn + " hits you with " +
		    pp + " knee below your belt!\n" +
		    "You double over and fall to the ground, writhing in " +
		    "excruciating pain,\nfeeling like you may throw up " +
		    "everything you have eaten!\n");
	say(pn + " suddenly raises " + pp +
	    " knee, sending " + apply(call,who,"query_name") + 
		" to the floor, writhing in pain!\n",who,pl,
      apply(call,who,"query_name")+" screams holding his balls.\n");
	write("You hit " + apply(call,who,"query_name") + 
		  " with your knee, below his belt.\n"+apply(call,who,"query_name")+
		  " falls to the floor screaming in pain.\n");
	return 1;
  }
  else {
	tell_object(who, pn + 
		 " tries to knee you below your belt, without much effect.\n");
	say(pn + " knees " + arg + ", between her legs.\n", who,pl,"Autch..Ohh\n");
	write("You knee " + arg + " between her legs.\n");
	return 1;
  }
 }
 write("Knee whom ?\n");
 return 1;
}


/* -------------------------- laugh ------------------------------ */

public int laugh(string arg) 
{
  if (!stringp(arg))
  {
    write("You fall down laughing.\n");
    _say(pn," falls down laughing.\n",0,pl,1);
    return 1;
  }
  write("You laugh "+check_member(arg)+".\n");
  _say(pn, " laughs "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- lick ------------------------------ */

public int lick(string arg) 
{
    object who;
	string h1,h2;

  if (stringp(arg))
  {
	if (sscanf(arg,"%s %s",h1,h2)==2)
        who = apply(pres,h1, environment(pl));
    else 
		who = apply(pres,arg,environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
      if (stringp(h2))
	  {
          tell_object(who,pn +" "+check_member(h2)+" licks you.\n");
          say(pn + " "+check_member(h2)+" licks " 
			  + who->query_name() + ".\n",who,pl,
           "Someone groans lustfully.\n");
          write("You "+check_member(h2)+" lick " + who->query_name() + ".\n");
		  return 1;
      }  
      tell_object(who, pn + " licks you.\n");
      say(pn + " licks " + apply(call,who,"query_name") + ".\n",who,pl,
      "Someone groans lustfully.\n");
      write("You lick " + apply(call,who,"query_name") + ".\n");
	  return 1;
    }  
  } 
  write("Lick whom ?\n");
  return 1;
}

/* -------------------------- love ------------------------------ */

public int love(string arg) 
{
    object who;

  if (stringp(arg))
  {
      who = apply(pres,arg, environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " whispers to you sweet words of love.\n");
       say(pn + " whispers softly to " + apply(call,who,"query_name") + 
           ".\n",who,pl,"Ohh Sweety !\n");
       write("You tell your true feelings to " + 
             apply(call,who,"query_name") + ".\n");
       return 1;
    }
  }
  write("Love whom ?\n");
  return 1;
}

/* -------------------------- moan ------------------------------ */

public int moan(string arg) 
{
  if (!stringp(arg))
  {
    write("You start to moan.\n");
    _say(pn," starts moaning.\n",0,pl,1);
    return 1;
  }
  write("You moan "+check_member(arg)+".\n");
  _say(pn," moans "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- mount ------------------------------ */

public int mount(string arg) 
{
   object who;

  if (stringp(arg))
  {
      who = apply(pres,arg, environment(pl));

   if (objectp(who) && living(who) && who!=pl)
   {
      tell_object(who,pn+" mounts you and rides off into the sunset.\n");
      write("You mount "+apply(call,who,"query_name")+
            " and ride off into the sunset.\n");
      _say(pn," mounts "+apply(call,who,"query_name")+
	  " and rides off into the sunset.\n",who,pl,1);
      return 1;
   }
  }
  write("Mount whom ?\n");
  return 1;
}
  
/* -------------------------- nibble ------------------------------ */

public int nibble(string arg) 
{
   object who;

   if (stringp(arg))
   {
       who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " nibbles on your ear.\n");
       say(pn + " nibbles on " + apply(call,who,"query_name") + 
           "'s ear.\n",who,pl,"");
       write("You nibble " + apply(call,who,"query_name") + "'s ear.\n");
       return 1;
    }
  }
  write("Nibble whom ?\n");
  return 1;
}

/* -------------------------- nuzzle ------------------------------ */

public int nuzzle(string arg) 
{
    object who;

   if (stringp(arg))
   {
       who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " lovingly nuzzles your neck.\n");
       say(pn + " lovingly nuzzles " + apply(call,who,"query_name")+ 
		     "'s neck.\n", who,pl,"");
       write("You lovingly nuzzle " + apply(call,who,"query_name") + 
             "'s neck.\n");
       return 1;
    }
  }
  write("Nuzzle whom ?\n");
  return 1;
}

/* -------------------------- no ------------------------------ */

public int no() 
{
    write("You shake your head no.\n");
    say(pn + " shakes "+pp+" head no.\n",0,pl,"");
    return 1;
}

/* -------------------------- nod ------------------------------ */
/* 310794, Airborne: Fixed up nod. */

public int nod(string arg) {

  object who;

  if (!stringp(arg)){
    write("You nod solemnly.\n");
    say(pn + " nods solemnly.\n",0,pl,"");
    return 1;
  }
  who = apply(pres,arg, environment(pl));
  if(objectp(who) && living(who) && who!=pl){
    tell_object(who, pn +" nods to you.\n");
    write("You nod to "+ apply(call,who,"query_name")+".\n");
    say(pn +" nods to "+ apply(call,who,"query_name")+".\n", who, pl,"");
    return 1;
  }
  write("You nod "+check_member(arg)+".\n");
  say(pn +" nods "+check_member(arg)+".\n",0,pl,"");
  return 1;
}

/* -------------------------- oops ------------------------------ */

public int oops(string arg) 
{
    write("Oops up !\n");
	say("Oops, "+pn+" seems to have done a mistake.\n",0,pl,"Oops !\n");
	return 1;
}

/* -------------------------- panic ------------------------------ */

public int panic() 
{
    write("P A N I C !\n");
	say("Suddenly, "+pn+" panics and searches a place to hide.\n",0,pl,"");
	return 1;
}

/* -------------------------- ponder ------------------------------ */

public int ponder() 
{
    write("You ponder the situation.\n");
	say(pn+" ponders the situation.\n",0,pl,"");
	return 1;
}

/* -------------------------- poke ------------------------------ */

public int poke(string arg) 
{
    object who;

  if (stringp(arg))
  {
      who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " pokes you in the ribs.\n");
       say(pn + " pokes " + apply(call,who,"query_name") + 
           " in the ribs.\n", who,pl,"");
       write("You poke " + apply(call,who,"query_name") + " in the ribs.\n");
       return 1;
    }
  }
  write("Poke whom ?\n");
  return 1;
}

/* -------------------------- point ------------------------------ */

public int point(string arg) 
{
    object who;

  if (stringp(arg))
  {
      who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " points at you.\n");
       say(pn + " points at " + apply(call,who,"query_name") + ".\n",who,pl,"");
       write("You point at " + apply(call,who,"query_name") + ".\n");
       return 1;
    }
  }
  write("Point at whom ?\n");
  return 1;
}

/* -------------------------- pout ------------------------------ */

public int pout(string arg) 
{
  if (!stringp(arg))
  {
    write("Ah, don't take it so hard.\n");
    _say(pn, " pouts.\n",0,pl,1);
    return 1;
  }
  write("You pout "+check_member(arg)+".\n");
  _say(pn, " pouts "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- puke ------------------------------ */

public int puke(string arg) 
{
    object who;

    if(!stringp(arg)) 
	{
        write("You puke on your shoes.\n");
        _say(pn," doubles over and puke.\n",0,pl,1);
        return 1;
    }
    who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " pukes all over you!\n");
       write("You puke on "+apply(call,who,"query_name")+".\n");
       _say(pn, " pukes on "+apply(call,who,"query_name")+".\n",pl,who,1);
       return 1;
    }
	write("Puke over whom ?\n");
	return 1;
}

/* -------------------------- purr ------------------------------ */

public int purr(string arg) 
{
  if (!stringp(arg))
  {
    write("MMMMEEEEEEEEOOOOOOOWWWWWWW!\n");
    _say(pn," purrs contentedly.\n",0,pl,1);
    return 1;
  }
  write("You purr "+check_member(arg)+".\n");
  _say(pn, " purrs "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- rolleyes ------------------------------ */

public int rolleyes() 
{
    write("You roll your eyes in exasperation.\n");
	say(pn + " rolls "+pp+" eyes in exasperation.\n",0,pl,"");
	return 1;
}
/* -------------------------- ruffle ------------------------------ */

public int ruffle(string arg) 
{
    object who;

 if (stringp(arg))
 {
    who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
      tell_object(who, pn + " ruffles your hair playfully.\n");
      write("You ruffle " + apply(call,who,"query_name") + 
            "'s hair playfully.\n");
      say(pn + " ruffles " + apply(call,who,"query_name") + 
               "'s hair playfully.\n", who,pl,"Ruffle !\n");
      return 1;
    }
  }
  write("Ruffle whom ?\n");
  return 1;
}

/* -------------------------- scream ------------------------------ */

public int scream() 
{
    write("ARRGGGGGGHHHHHH!!!!\n");
    _say(pn, " screams loudly!\n",0,pl,1);
    return 1;
}

/* -------------------------- scratch ------------------------------ */

public int scratch(string arg) 
{
  if (!stringp(arg))
  {
   write("You scratch your head.\n");
	say(pn+ " scratches "+pp+" head.\n",0,pl,"Scratch...Scratch\n");
	return 1;
  }
  return 0;
}
/* -------------------------- shake ------------------------------ */

public int shake(string arg) 
{
    object who;

    if(!stringp(arg)) 
	{
        write("You're shaking in your boots.\n");
        say(pn + " shakes and quivers like a bowlful of jelly.\n",0,pl,"");
        return 1;
    }
    who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " shakes your hand.\n");
       write("You shake hands with " + apply(call,who,"query_name") +".\n");
       say(pn + " shakes "+apply(call,who,"query_name")+"s hand.\n",who,pl,"");
       return 1;
    }
  write("Shake whom ?\n");
  return 1;
 }

/* -------------------------- shiver ------------------------------ */

public int shiver() 
{
    write("Brrrrrr!!!\n");
    say(pn + " shivers from the cold.\n",0,pl,"");
    return 1;
}

/* -------------------------- shrug ------------------------------ */

public int shrug(string arg) 
{
  if (!stringp(arg))
  {
    write("You shrug helplessly.\n");
    say(pn + " shrugs helplessly.\n",0,pl,"");
    return 1;
  }
  write("You shrug "+check_member(arg)+".\n");
  say(pn + " shrugs "+check_member(arg)+".\n",0,pl,"");
  return 1;
}

/* -------------------------- sigh ------------------------------ */

public int sigh(string arg) 
{
  if (!stringp(arg))
  {
    write("You sigh deeply.\n");
    _say(pn, " sighs deeply.\n",0,pl,1);
    return 1;
  }
  write("You sigh "+check_member(arg)+".\n");
  _say(pn, " sighs "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- sing ------------------------------ */

public int sing(string arg) 
{
  if (!stringp(arg))
  {
    write("Oh sole mio!\n");
    _say(pn, " sings in Italian.\n",0,pl,1);
    return 1;
  }
  write("You sing "+check_member(arg)+".\n");
  _say(pn, " sings "+check_member(arg)+".\n",0,pl,1);
  return 1;
 }

/* -------------------------- slap ------------------------------ */

public int slap(string arg) 
{
    object who;

  if (stringp(arg))
  {
     who = apply(pres,arg, environment(pl));

   if (objectp(who) && living(who) && who!=pl)
   {
      write("You slap " + apply(call,who,"query_name") + ".\n");
      say(pn + " slaps "+apply(call,who,"query_name")+".\n",who,pl,"Slap !\n");
      tell_object(who, pn + " slaps you!\n");
      return 1;
   }
  }
  write("Slap whom ?\n");
  return 1;
 }

/* -------------------------- smirk ------------------------------ */

public int smirk() 
{
    write("You smirk.\n");
    say(pn + " smirks.\n",0,pl,"");
    return 1;
}

/* -------------------------- smile ------------------------------ */

public int smile(string arg) 
{
    object who;
	string h1,h2;

	if (!stringp(arg))
	{
      write("You smile happily.\n");
      say(pn + " smiles happily.\n",0,pl,"");
      return 1;
    } 

   if (sscanf(arg,"%s %s",h1,h2)==2)
          who = apply(pres,h1, environment(pl));
   else 
         who = apply(pres,arg, environment(pl));

   if (objectp(who) && living(who) && who!=pl)
   {
	if (stringp(h2))
	{
      tell_object(who, pn + " "+check_member(h2)+" smiles at you.\n",pl);
      write("You "+check_member(h2)+" smile at " + 
            apply(call,who,"query_name") +".\n");
      say(pn + " "+check_member(h2)+" smiles at " 
			 + apply(call,who,"query_name") + ".\n",who,pl,"");
      return 1;
    }
    tell_object(who, pn + " smiles at you.\n",pl);
    write("You smile at " + apply(call,who,"query_name") +".\n");
    say(pn + " smiles at " + apply(call,who,"query_name") + ".\n",who,pl,"");
    return 1;
   }
   write("You smile "+check_member(arg)+".\n");
   say(pn + " smiles "+check_member(arg)+".\n",0,pl,"");
   return 1;
 }

/* -------------------------- snap ------------------------------ */

public int snap() 
{
    write("You snap your fingers.\n");
    say(pn + " snaps " + pp + " fingers.\n",0,pl,"Snap !\n");
    return 1;
}

/* -------------------------- sneeze ------------------------------ */

public int sneeze() 
{
    write("Gesundheit!\n");
    _say(pn, " sneezes.\n",0,pl,1);
    return 1;
}

/* -------------------------- snicker ------------------------------ */

public int snicker(string arg) 
{
  if (!stringp(arg))
  {
    write("You snicker.\n");
    _say(pn, " snickers.\n",0,pl,1);
    return 1;
  }
  write("You snicker "+check_member(arg)+".\n");
  _say(pn, " snickers "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- sniff ------------------------------ */

public int sniff() 
{
    write("You sniff sadly.\n");
    _say(pn, " sniffs sadly.\n",0,pl,1);
    return 1;
}

/* -------------------------- snore ------------------------------ */

public int snore() 
{
    write("Zzzzzzzzzz...\n");
    _say(pn, " snores loudly.\n",0,pl,1);
    return 1;
}

/* -------------------------- snuggle ------------------------------ */

public int snuggle(string arg) 
{
    object who;
	string h1,h2;


	if (stringp(arg))
	{
	  if (sscanf(arg,"%s %s",h1,h2)==2)
         who = apply(pres,h1, environment(pl));
      else
         who = apply(pres,arg, environment(pl));

      if (objectp(who) && living(who) && who!=pl)
	  {
	   if (stringp(h2))
	   {
         write("You "+check_member(h2)+" snuggle " + 
               apply(call,who,"query_name") + ".\n");
         say(pn + " "+check_member(h2)+" snuggles up to "
				+apply(call,who,"query_name") + ".\n", who,pl,"Kiss..Nuzzle\n");
         tell_object(who, pn + " "+check_member(h2)+" snuggles up to you.\n");
         return 1;
       }
       write("You snuggle " + apply(call,who,"query_name") + ".\n");
       say(pn + " snuggles up to " + apply(call,who,"query_name") + 
       ".\n", who,pl,"Kiss..Nuzzle\n");
       tell_object(who, pn + " snuggles up to you.\n");
       return 1;
      }
    }
  write("Snuggle whom ?\n");
  return 1;
}

/* -------------------------- spit ------------------------------ */

public int spit(string arg) 
{
    object who;

    if(!stringp(arg)) 
	{
        write("You spit on the ground.\n");
        _say(pn, " spits on the ground.\n",0,pl,1);
        return 1;
    }
    who = apply(pres,arg, environment(pl));

   if (objectp(who) && living(who) && who!=pl)
   {
      tell_object(who, pn + " spits on you!\n");
      write("You spit on " + apply(call,who,"query_name") +".\n");
      _say(pn, " spits on " + apply(call,who,"query_name") + ".\n",who,pl,1);
      return 1;
   }
  write("Spit on whom ?\n");
  return 1;
}

/* -------------------------- squeeze ------------------------------ */

public int squeeze(string arg) 
{
   object who;
	string h1,h2;

   if (stringp(arg))
   {
	 if (sscanf(arg,"%s %s",h1,h2)==2)
        who = apply(pres,h1, environment(this_player()));
     else 
       who = apply(pres,arg, environment(this_player()));

	if (objectp(who) && living(who) && who!=pl)
	{
	  if (stringp(h2))
	  {
       write("You "+check_member(h2)+" squeeze " + who->query_name()+".\n");
       say(pn +" "+check_member(h2)+" squeezes " 
		   + apply(call,who,"query_name")+".\n", who,pl,"");
       tell_object(who, pn + " "+check_member(h2)+" squeezes you.\n");
       return 1;
      }
     write("You squeeze " + apply(call,who,"query_name")+".\n");
     say(pn +" squeezes " + apply(call,who,"query_name")+".\n", who,pl,"");
     tell_object(who, pn + " squeezes you.\n");
     return 1;
   }
  }
  write("Squeeze whom ?\n");
  return 1;
 }

/* -------------------------- stare ------------------------------ */

public int stare(string arg) 
{
    object who;

    if(!stringp(arg)) 
	{
        write("You stare into space.\n");
        say(pn + " stares into space.\n",0,pl,"");
        return 1;
    }
    who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " stares deep into your eyes.\n",pl);
       write("You stare dreamily at " + apply(call,who,"query_name") +".\n");
       say(pn + " stares dreamily at " + apply(call,who,"query_name") + 
       ".\n", who,pl,"");
       return 1;
    }
  write("Stare at whom ?\n");
  return 1;
}

/* -------------------------- strut ------------------------------ */

public int strut(string arg) 
{
  if (!stringp(arg))
  {
    write("Strut your stuff!\n");
    say(pn + " struts proudly.\n",0,pl,"");
    return 1;
  }
  write("You strut "+check_member(arg)+".\n");
  say(pn + " struts "+check_member(arg)+".\n",0,pl,"");
  return 1;
}

/* -------------------------- sulk ------------------------------ */

public int sulk(string arg) 
{
  if (!stringp(arg))
  {
    write("You sulk.\n");
    say(pn + " sulks in the corner.\n",0,pl,"Sigh !\n");
    return 1;
  }
  write("You sulk "+check_member(arg)+".\n");
  say(pn + " sulks "+check_member(arg)+".\n",0,pl,"Sigh !\n");
  return 1;
}

/* -------------------------- steam ------------------------------ */

public int steam() 
{
   write("Steam comes boiling out of your ears.\n");
	say(pn+"'s face turns purple and steam starts to boil out of "+
		 pp+" ears.\n",0,pl,"Steam !\n");
   return 1;
}
/* -------------------------- stomp ------------------------------ */
public int stomp() 
{
   write("You stomp your feet angrily on the ground.\n");
	say(pn+" stomps "+pp+" feet angrily on the ground.\n",0,pl,"Stomp !\n");
   return 1;
}

/* -------------------------- stretch ------------------------------ */
public int stretch(string arg) 
{
  if (!stringp(arg))
  {
    write("You stretch your tired body.\n");
	 say(pn+" stretches "+pp+" tired body.\n",0,pl,"Ahhhh !\n");
    return 1;
  }
  write("You "+check_member(arg)+" stretch your tired body.\n");
  say(pn+" "+check_member(arg)+" stretches "+pp+
   	  " tired body.\n",0,pl,"Ahhhh !\n");
  return 1;
 }

/* -------------------------- tap ------------------------------ */
public int tap(string arg) 
{
  if (!stringp(arg))
  {
     write("You tap your foot impatiently.\n");
	  say(pn+" taps "+pl->query_possessive()+" foot impatiently.\n",0,pl,
     "Tap..Tap\n");
   return 1;
   }
  return 0;  /* kegs */
}
/* -------------------------- tongue ------------------------------ */

public int tongue(string arg) 
{
    object who;

    if(!stringp(arg)) 
	{
        write("You stick out your tongue.\n");
        say(pn + " sticks out "+pp+" tongue.\n",0,pl,"");
        return 1;
    }
    who = apply(pres,arg, environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
       tell_object(who, pn + " sticks out "+pp+" tongue at you !\n",pl);
       write("You stick out your tongue at " + apply(call,who,"query_name")+
             ".\n");
       say(pn + " sticks out "+pp+" tongue at " 
		   + apply(call,who,"query_name") + " !\n", who,pl,"");
       return 1;
     }
    write("You "+arg+" stick out your tongue.\n");
    say(pn + " "+arg+" sticks out "+pp+" tongue.\n",0,pl,"");
    return 1;
}
   
/* -------------------------- think ------------------------------ */
public int think() 
{
   write("You try to look thoughtful, but fail.\n");
	say(pn+" tries to look thoughtful, but fails.\n",0,pl,"");
	return 1;
}
/* -------------------------- thank ------------------------------ */

public int thank(string arg) 
{
    object who;
    string h1,h2;

	if (stringp(arg))
	{
	  if (sscanf(arg,"%s %s",h1,h2) == 2)
         who = present(h1, environment(pl));
      else 
         who = present(arg, environment(pl));

	 if (objectp(who) && living(who) && who!=pl)
	 {
	   if (stringp(h2))
	   {
        write("You "+check_member(h2)+" thank " + 
              apply(call,who,"query_name") + ".\n");
        say(pn + " "+check_member(h2)+" thanks " 
			   + apply(call,who,"query_name") + ".\n", who,pl,"Thanks !\n");
        tell_object(who, pn + " "+check_member(h2)+" thanks you.\n");
        return 1;
        }
      write("You thank " + apply(call,who,"query_name") + ".\n");
      say(pn+" thanks "+apply(call,who,"query_name")+".\n",who,pl,"Thanks !\n");
      tell_object(who, pn + " thanks you.\n");
      return 1;
 	}
   }
  write("Thank whom ?\n");
  return 1;
}

/* -------------------------- tickle ------------------------------ */
public int tickle(string arg) 
{
    object who;
    string h1,h2;

	if (stringp(arg))
	{
	  if (sscanf(arg,"%s %s",h1,h2) == 2)
         who = apply(pres,h1, environment(pl));
      else 
         who = apply(pres,arg, environment(pl));

      if (objectp(who) && living(who) && who!=pl)
      {
      if (stringp(h2))
      {
        write("You tickle " + apply(call,who,"query_name") +" "+
              check_member(h2)+".\n");
        say(pn + " tickles " 
	       + apply(call,who,"query_name") +" "+check_member(h2)+ ".\n",who,pl,
        "You hear some snickering !\n");
        tell_object(who, pn + " tickles you "+check_member(h2)+".\n");
        command("laugh",who);
        return 1;
        }
      write("You tickle " + apply(call,who,"query_name")+" playfully.\n");
      say(pn + " tickles " + apply(call,who,"query_name")+" playfully.\n",who,
       pl,"You hear some snickering !\n");
      tell_object(who, pn + " tickles you playfully.\n");
      command("laugh",who);
      return 1;
      }
   }
  write("Tickle whom ?\n");
  return 1;
}
/* -------------------------- twiddle ------------------------------ */

public int twiddle(string arg) 
{
  if (!stringp(arg))
  {
    write("You twiddle your thumbs.\n");
    say(pn + " twiddles " + pp + " thumbs.\n",0,pl,"");
    return 1;
  }
  write("You "+check_member(arg)+" twiddle your thumbs.\n");
  say(pn + " "+check_member(arg)+" twiddles " + pp +" thumbs.\n",0,pl,"");
  return 1;
}

/* -------------------------- wave ------------------------------ */

public int wave(string arg) 
{
  object who;
  string h1,h2;

  if (stringp(arg))
  {
	if (sscanf(arg,"%s %s",h1,h2))
		who = apply(pres,h1,environment(pl));
    else 
		who = apply(pres,arg,environment(pl));

	if (objectp(who) && living(who) && who!=pl)
	{
	  if (stringp(h2))
	  {
        write("You "+check_member(h2)+" wave at " + 
              apply(call,who,"query_name") + ".\n");
        say(pn + " "+check_member(h2)+" waves at " 
			+ apply(call,who,"query_name") + ".\n",who,pl,
        "Someone says: Bye\n");
        tell_object(who, pn + " waves "+check_member(h2)+" at you.\n");
        return 1;
      }
      write("You wave at " + apply(call,who,"query_name") + ".\n");
      say(pn + " waves at " + apply(call,who,"query_name") + ".\n",who,pl,
      "Someone says: Bye\n");
      tell_object(who, pn + " waves at you.\n");
      return 1;
    }
   }
   write("You wave farewell.\n");
   say(pn+" waves farewell.\n",0,pl,"Someone says: Bye\n");
   return 1;
}

/* -------------------------- whistle ------------------------------ */

public int whistle(string arg) 
{
    object who;

    if(!stringp(arg)) 
	{
        write("You whistle appreciatively.\n");
        _say(pn," whistles appreciatively.\n",0,pl,1);
        return 1;
    }
    who = apply(pres,arg, environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
      tell_object(who, pn + " whistles appreciatively at you.\n");
      write("You whistle appreciatively at " + 
            apply(call,who,"query_name") +".\n");
      _say(pn, " whistles appreciatively at " + 
            apply(call,who,"query_name") + ".\n",who,pl,1);
      return 1;
    }
    write("Whistle at whom ?\n");
    return 1;
 }

/* -------------------------- worship ------------------------------ */

public int worship(string arg) 
{
    object who;

    if(stringp(arg)) 
	{
       who = apply(pres,arg, environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
      tell_object(who, pn + " falls on "+pp+" knees and shows you "+
	   " how much "+apply(call,pl,"query_pronoun")+" worships you.\n");
      write("You worship " + apply(call,who,"query_name") +".\n");
      say( pn + " falls on "+pp+" knees and worships "+
		    apply(call,who,"query_name")+".\n",who,pl,"");
      return 1;
     }
    }
    write("Worship whom ?\n");
    return 1;
 }
/* -------------------------- wiggle ------------------------------ */

public int wiggle(string arg) 
{
  if (!stringp(arg))
  {
    write("You wiggle your bottom.\n");
    say(pn + " wiggles " + pp +" bottom.\n",0,pl,"");
    return 1;
  }
  write("You wiggle your bottom "+check_member(arg)+".\n");
  say(pn + " wiggles " + pp +" bottom "+check_member(arg)+".\n",0,pl,"");
  return 1;
}

/* -------------------------- wink ------------------------------ */
public int wink(string arg) 
{
    object who;

    if(!stringp(arg)) 
	{
        write("You wink.\n");
      /*  say(pn + " winks suggestively.\n",0,pl,1);*/
        say (this_player()->query_name() + " winks suggestively.\n");
        return 1;
    }
    who = apply(pres,arg, environment(pl));

    if (objectp(who) && living(who) && who!=pl)
	{
      tell_object(who, pn + " winks suggestively at you.\n",pl);
      write("You wink at " + apply(call,who,"query_name") +".\n");
      say(pn + " winks suggestively at " + 
     		apply(call,who,"query_name") + ".\n", who,pl,"");
      return 1;
    }
   write("Wink at whom ?\n");
   return 1;
}

/* -------------------------- yawn ------------------------------ */

public int yawn(string arg) 
{
  if (!stringp(arg))
  {
    write("My, what big teeth you have!\n");
    _say(pn, " yawns.\n",0,pl,1);
    return 1;
  }
  write("You yawn "+check_member(arg)+".\n");
  _say(pn, " yawns "+check_member(arg)+".\n",0,pl,1);
  return 1;
}

/* -------------------------- yodel ------------------------------ */

public int yodel(string arg) 
{
  if (!stringp(arg))
  {
    write("You yodel in a merry tune.\n");
    _say(pn, " yodels in a merry tune.\n",0,pl,1);
    return 1;
  }
  write("You yodel "+check_member(arg)+".\n");
  _say(pn, " yodel "+check_member(arg)+".\n",0,pl,1);
  return 1;
}
/* -------------------------- me ------------------------------ */

public int fcn_me(string arg)
{
 if (stringp(arg))
 {
   write("Ok.\n");
   say("#"+pn+" "+arg+".\n",0,pl,"");
   return 1;
 }
 write("Me what ?\n");
 return 1;
}

  /* ------------------------ updating a new soul --------------------- */

public int
fcn_newsoul()
{
    new = 1;
   move_object(clone_object("/obj/soul"),pl);
   write("Your soul is now updated, type save please.\n");
   call_out("dest_me",1);
   
   return 1;
}  
  /* --------------------------- exits ---------------------------------- */

public int
fcn_exits()
{
    string *exits, short;
    int i, sz;

    if (!(sz = sizeof(exits = apply(call,environment(pl),"query_dest_dirs"))))
    {
       write("There are no obvious exits.\n");
       return 1;
     }
    write("Obvious Exits:\n\n");
    for (i = 1; i < sz; i = i + 2)
    {
       if (catch( apply(call,exits[(i-1)],"???") )==0)
         short = apply(call,exits[(i-1)],"short"); 
       else 
         short = "Somewhere";
         printf("%-15s","  "+exits[i]);
         
         if (stringp(short))
             printf("%-30s\n",short);
         else 
             printf("%-30s\n","Somewhere");
         
     }
         
    return 1;
}
/* endsoul */

  /* --------------------------- nokill ---------------------------------- */

public int
do_no_killer()
{
   write("Ok, you try to avoid killing players.\n");
   this_player()->set_no_pk(1);
   return 1;
}

public int
do_killer()
{
   write("Ok, you stop to care about your fellow players.\n");
   this_player()->set_no_pk(0);
   return 1;
}

/*
   Here the function extra_function calls the file with given Parameters.
   Please again check it carefully, because failure causes errors which
   are very hard to delete. Be sure that your functionname is the same
   as the action.
                                                                        */

public int  
extra_function(mixed arg)
{
   string verb;
   
   verb = query_verb();
   catch(funcall(call,funs[verb],verb,arg));
   return 1;
}

public int
standard_soul() 
{ 
   return 1; 
}
int query_command_soul()
{
    return 1;
}

void dest_me()
{
     destruct(this_object());
}


