/* MUDTAG - Coded by Kawai @ Holy Mission (140.78.3.1 4242)
                     bazyl@bcvms.bc.edu
  Copyright 1993 by Steve Bazyl
  Free to distribute
  If you choose to modify and redistribute this file, please include a history
  of changes

*/

#include "/obj/lw.h"
#define TAGFILE "/players/kawai/games/tag.c"
#define TP this_player()
#define C capitalize
#define QRN query_real_name()
#define QL query_level()

int it, tagtime, mult, totl, totw, busy;
string oldpre, oldtitle, lasttag;

alert(str,ob) {
 int i;
 object u;
 u=users();
 for(i=0;i<sizeof(u);i++) {
   if(present("game_tag",u[i])) 
       {if(u[i]->QRN!=ob->QRN)
         tell_object(u[i],"<:MudTag:> MESSAGE: "+str+"\n");}}
 return 1;}

block(str) {
  write("You can't do that if you're playing MudTag!\n");
  return 1;}

check_it() {
 int i, isit;
 object u,x;
 u=users();
 isit=0;
 for(i=0;i<sizeof(u);i++)
   {if(x=present("game_tag",u[i])) 
      {if(x->query_it()) isit=1;}}
 return isit;}

de(str) {
  if(!str||str!="tag") 
     {notify_fail("Cease what\n?");
      return;}
  if(it) 
     {notify_fail("You can't give up if you're it!\n");
      return;}
  write("You tear up the sticker and toss it away (Biodegradable, don't worry!).\n");
  say(C(TP->QRN)+" tears up a MudTag sticker!\n");
  TP->set_title("survived MudTag and only got this lousy T-shirt!");
  TP->set_pretitle("none");
  alert(C(TP->QRN)+" quit!",TP);
  destruct(this_object());
  return 1;}

drop() {return 1;}

end_tag() {
 object u,x;
 int i;
 u=users();
 for(i=0;i<sizeof(u);i++) {
   if(x=present("game_tag",u[i])) {
       if(u[i]->QRN!=TP->QRN) {
         tell_object(u[i],C(TP->QRN)+" has ended the game!\n");
         u[i]->set_title("survived MudTag and only got this lousy T-shirt!");
         u[i]->set_pretitle("none");
         destruct(x);}}}
 write("Game ended.  Destructing this Sticker!\n");
 TP->set_title("is the bastard who ended MudTag!");
 TP->set_pretitle("none");
 destruct(this_object());
 return 1;}


gainxp(arg) {
  write("You earn "+(mult*arg)+" experience for that tag!\n");
  TP->add_experience(mult*arg);
  totw+=(mult*arg);
  return 1;}

get() {return 1;}

gtag(str) {
 object who,x, names;
 string a,b;
 int i;
 if(!str) 
    {notify_fail("Give MudTag sticker to who?\n");
     return;}
 if(!who=find_player(str))
    {if(str=="all"||str=="nowiz"||str=="room")
      {if(str=="nowiz")
         {who=filter_array(users(),"wiz_filt",this_object());}
       else if(str=="room")
         {who=filter_array(users(),"room_filt",this_object());}
       else
         {who=users();}
       for(i=0;i<sizeof(who);i++) 
          {if(!present("game_tag",who[i])) 
             {transfer(x=clone_object(TAGFILE),who[i]);
              x->set_mult(mult);
              tell_object(who[i],
               "You were just given a MudTag sticker by "+C(TP->QRN)+".\n"+
               "Look at sticker for more information.\n");}}
       alert("All players entered!",TP);
       write("All players now have MudTag stickers.\n");
       return 1;}
     else if(sscanf(str,"%s %s",a,b)==2)
/* Recursion anyone?  Scrolls too much on the screen though.....
        {gtag(a);
         gtag(b);
         return 1;}}
...'Tis being kept out for now. */
       {names=explode(str," ");
        if(sizeof(names)>0)
           {for(i=0;i<sizeof(names);i++)
               {if(!who=find_player(names[i]))
                   {write(C(names[i])+" not found.\n");}
                else
                   {if(x=present("game_tag",who))
                      {write(C(names[i])+" already has a sticker.\n");}
                    else
                      {transfer(x=clone_object(TAGFILE),who);
                       x->set_mult(mult);
                       write(C(names[i])+" was given a sticker.\n");
                       alert(C(names[i])+" joined in!",who);
                       tell_object(who,
                       "You were just given a MudTag sticker by "+C(TP->QRN)+".\n"+
                       "Look at sticker for more information.\n");}}}
            write("Ok.\n");
            return 1;}}
        else  
            {notify_fail("Can't find player.\n");
             return;}}
 if(present("game_tag",who))
    {notify_fail("That player already has a tag object!\n");
     return;}
 transfer(x=clone_object(TAGFILE),who);
 x->set_mult(mult);
 tell_object(who,"You were just given a MudTag sticker by "+C(TP->QRN)+".\n"+
             "Look at sticker for more information.\n");
 alert(C(who->QRN)+" joined in!",who);
 write("OK.\n");
 return 1;}

help(str) {
 if(!str||str!="mudtag") 
   {notify_fail("Help what?\n");
    return;}
 write(lw("MudTag! You know it, you love it!\n"+
       "Design and Concept by Airborne and Kawai.\n"+
       "Coded by Kawai.\n\n"+
       "Rules of the game:  Tag is played as you would expect--whoever is it "+
       "has the job of chasing another player down and tagging them.  To make "+
       "the game a bit more interesting, we've added an incentive program.  "+
       "Each time you tag another person (if you are it), you earn a multiplier "+
       "times that persons level worth of experience.  The default multiplier is "+
       "20, but can be changed by a wizard.  So if a you tagged a 10th level player, "+
       "you would earn 200xp.  Bewarned!  The same rule applies when being tagged!  You "+
       "will lose the multiplier times the level of the person who tagged you!  "+
       "There are also no re-tags, so two people can not just tag each other back and "+
       "forth forever.  Once you are tagged, you must find somebody other than the person "+
       "to tag you as a target.\nEnjoy!\n"));
 write("Commands: tag <player>     -- Obvious\n"+
       "          show tag         -- Shows MudTag players, locations, who is\n"+
       "                              it, and current xp wins/losses.\n"+
       "          cease tag        -- Stop playing the game.\n"+
       "          volunteer        -- Become it, if nobody else is.\n"+
       "          ttalk <msg>      -- Talk on the MudTag channel.\n"+
       "          ttalk/ <msg>     -- Emote over MudTag channel\n"+
       "          tbusy <level>    -- Sets the player level of messages to ignore\n"+
       "          help mudtag      -- This screen.\n");
 if(TP->QL>=30) 
    {write("Commands for wizards:\n"+
       "          wiztag <player>  -- Will change 'it' to that player.\n"+
       "          taglevel <num>   -- Sets the XP multipler (num*level).\n"+ 
       "          kicktag <player> -- Take away a players sticker.\n"+
       "          endtag           -- Will destruct all stickers.\n"+
       "          gtag <player>    -- Will give a tag object to a player.\n"+
       "               all         -- Give to all players.\n"+
       "               room        -- Give to all players in your current room.\n"+
       "               nowiz       -- Give to all but wizards.\n"+
       "               <list>      -- Give to specified list (seperate with space).\n");}
 return 1;}

id(str) {return str=="game_tag"||str=="sticker"||str=="mudtag"||
         str=="MudTag";}

init() {
 add_action("tg","tag");
 add_action("tt","ttalk");
 add_action("ts","tbusy");
 add_action("tt","ttalk/");
 add_action("de","cease");
 add_action("block","house");
 add_action("sh","show");
 add_action("help","help");
 add_action("vol","volunteer");
 if(TP->QL>30) {
    add_action("gtag","gtag");
    add_action("tgl","taglevel");
    add_action("end_tag","endtag");
    add_action("kick","kicktag");
    add_action("mi","wiztag");}}

kick(str) {
 object who,x;
 if(!str) 
    {notfify_fail("Who do you want to kick from the game?\n");
     return;}
 if(!who=find_player(lower_case(str))) 
    {notify_fail("Can't find that player.\n");
     return;}
 if(!x=present("game_tag",who)) 
    {notify_fail("That player isn't playing MudTag.\n");
     return;}
 tell_object(who,C(TP->QRN)+" removed you from the MudTag game.\n");
 say(C(TP->QRN)+" kicked "+C(who->QRN)+" from MudTag.\n");
 destruct(x);
 who->set_title("was kicked from MudTag for being a putz!");
 who->set_pretitle("none");
 alarm(C(TP->QRN)+" kicked "+C(who->QRN)+" from the game!");
 write("Ok.\n");
 return 1;}

level_desc(a, b) {
  return a->query_level()<=b->query_level();}

long() {
 if(!it) {
   environment(this_object())->set_title("is playing MudTag");
   environment(this_object())->set_pretitle("none");}
 write("MudTag v5.21\n"+
       "Brought to you by Airborne and Kawai at Holy Mission (140.78.3.1 4242)\n"+
       "type 'help mudtag' for more information!\n");
 return 1;}

losexp(arg, ob) {
  int xp;
  xp=(arg*mult);
  if(xp>ob->query_exp()) xp=ob->query_exp();
  if(!xp) {return;}
  tell_object(ob,"You lose "+(xp)+" experience for being tagged!\n");
  ob->add_experience(-(xp));
  totl-=xp;
  return 1;}

maxstr(str, max) {
 int len, i;
 string temp;
 if(!str) 
    {temp="";
     for(i=1;i<max;i++)
        {temp=temp+" ";}
     return temp;}
 len=strlen(str);
 if(len>max) 
    {return extract(str,0,max-2);}
 temp=str;
 for (i=1;i<max-len;i++) 
    {temp=temp+" ";}
 return temp;}

mi(str) {
 int i;
 object u,y,x,who;
 if(!str) 
    {notify_fail("Wiztag who?\n");
     return;}
 if(!who=find_player(str))
    {notify_fail("Player not found.\n");
     return;}
 if(!x=present("game_tag",who))
    {notify_fail("That player does not have a MudTag Sticker.\n");
     return;}
 if(x->query_it()) 
    {notify_fail("That person is already it!\n");
     return;}
 u=users();
 for(i=0;i<sizeof(u);i++) {
   if(y=present("game_tag",u[i])) 
      {y->tagit(0,u[i],u[i]);
       u[i]->set_pretitle("none");
       u[i]->set_title("is playing MudTag!");}}
 x->tagit(1,TP,who);
 write(C(who->QRN)+" is now it.\n");
 tell_object(who,C(TP->QRN)+" declared you It!\n");
 say(C(TP->QRN)+" declared "+C(who->QRN)+" as 'It' in MudTag.\n");
 alert(C(TP->QRN)+", the wizard, declared "+C(who->QRN)+" as it!",TP);
 return 1;}

query_busy() {return busy;}

query_ept() {return (totw+totl);}

query_it() {return it;}

reset(arg) {
 if(!arg) {
  it=0;
  totl=0;
  totw=0;
  busy=0;
  lasttag="";
  tagtime=0;
  mult=20;}}

room_filt(ob) {
 if(!ob) {return;}
 if(present(ob,environment(TP))) {return 1;}
 return 0;}

set_last(str) {lasttag=str;}

set_mult(arg){mult=arg;}

set_time() {tagtime=time();}

sh(str) {
int i,j, isit;
string lstr;
object u,x; 
 if(!str||str!="tag") 
    {notify_fail("Show what?\n");
     return;}
 u=sort_array(users(),"level_desc",this_object());
 isit=0;
 say(C(TP->QRN)+" checks the list of MudTag players.\n");
 j=0;
 write("\n             -----=====MudTag Players=====-----\n\n");
 write(maxstr(" Name",13)+" | Rank | It? | "+maxstr("Location",30)+" | XP totals\n");
 write("----------------------------------------------------------------------\n");
 for(i=0;i<sizeof(u);i++) 
   {if(x=present("game_tag",u[i]))
      {j++;
       if(x->query_busy()>TP->query_level())
          {write("*");}
       else
          {write(" ");}
       if(u[i]->query_level()>=30) {lstr="| wiz  ";}
       else if(u[i]->query_level()>20) {lstr="| high ";}
       else if(u[i]->query_level()>10) {lstr="| med  ";}
       else if(u[i]->query_level()>=5) {lstr="| low  ";}
       else {                           lstr="| new  ";}
       write(maxstr(C(u[i]->QRN),13)+lstr);
       if(x->query_it())
          {write("|-YES-| "); isit=1;}
       else
          {write("|-----| ");}
       write(maxstr(C(environment(u[i])->short()),30)+" |  ");
       if(x->query_ept()>0) 
         {write("+ "+x->query_ept()+" xp\n");}
       else if(x->query_ept()<0) 
         {write("- "+(-x->query_ept())+" xp\n");}
       else 
         {write("None\n");}}}
 if(j==1) 
    {write("\nYou are the only player right now!\n");}
 else
    {write("\nThere are "+j+" players.\n");}
 if(!isit) 
    {write("Nobody is it!  Somebody should 'volunteer'.\n");}
 if(it)
    {write("You are it!\n");
     if(lasttag!="") 
        {write("You were last tagged by "+lasttag+".\n");}}
 if(tagtime) 
   {write("You have been it for "+xtime(time()-tagtime)+".\n");}
 if(mult) 
   {write("The current multiplier is "+mult+".\n");}
 write("Current busy level is "+busy+".\n");
 if(query_ept()>0) {write("You have earned "+query_ept()+" experience since playing.\n");}
 else if(query_ept()<0) {write("You have lost "+query_ept()+" experience since playing.\n");}
 else {write("You're experience has not changed since playing.\n");}
 return 1;}

short() {return "A sticker labeled 'MudTag'";}

tagit(arg, was, is) {
  if(arg) 
     {tell_object(is, C(was->QRN)+" tagged you! You're it!\n");
      is->set_title("is it!");
      is->set_pretitle("-=>");
      it=1;}
  else 
     {if(it) 
        tell_object(environment(this_object()),"You are no longer it.\n");
     it=0;}}

tg(str) {
 string d;
 object who, tagob;
 if(!it) 
    {notify_fail("You aren't it!\n");
     return;}
 if(!str) 
    {notify_fail("Tag who?\n");
     return;}
 if(!who=find_player(str)) 
    {notify_fail("That person isn't online, never mind this room!\n");
     return;}
 if(!present(who,environment(TP))) 
    {notify_fail("That player isn't here!\n");
     return;}
 if(!tagob=present("game_tag",who)) 
    {notify_fail("That person isn't playing Tag....what a looser!\n");
     return;}
 if(who->QRN==TP->QRN)
    {write("You can't tag yourself!\n");
     say(C(TP->QRN)+" looks confused.\n");
     return 1;}
 if(who->QRN==lasttag) 
    {write("Sorry, no retags!\n");
     tell_object(who,C(TP->QRN)+" tried to tag you, but failed!\n");
     say(C(TP->QRN)+" tries to tag "+C(who->QRN)+"!\n");
     return 1;}
 tagob->tagit(1,TP,who);
 tagob->set_last(TP->QRN);
 lasttag=who->QRN;
 if(TP->QL>=30) 
    {write("You get no experience for that, you immature wizard!\n");}
 else
    {if(who->QL>=30) 
       {write("You shouldn't be tagging wizards like that!\n");}
     else
       {if(mult)
          {tagob->losexp(TP->QL, who);
           gainxp(who->QL);}}}
 tagob->set_time();
 TP->set_title("is playing MudTag!");
 TP->set_pretitle("none");
 it=0;
 tagtime=0;
 write("You tag "+C(who->QRN)+"!\n");
 alert(C(TP->QRN)+" tagged "+C(who->QRN)+"!",who);
 say(C(TP->QRN)+" tags "+C(who->QRN)+"!\n");
 return 1;}

tgl(str) {
  int l,i;
  object u,x;
  if(!str) 
     {notify_fail("Set tag mutliplier to what?\n");
      return;}
  if(!sscanf(str,"%d",l)) 
     {notify_fail("Argument must be an integer!\n");
      return;}
if((l>50)||(l<0))
   {notify_fail("Sorry, multiplier can only be from 0 to 50.\n");
      return;}
  u=users();
  for(i=0;i<sizeof(u);i++) 
    {if(x=present("game_tag",u[i])) 
        {x->set_mult(l);}}
  say(C(TP->QRN)+" changed the MudTag experience multiplier!\n");
  alert(C(TP->QRN)+", the wizard, changed the experience multipler to "+l+"!",TP); 
  write("XP multiplier set to "+l+".\n"); return 1;}

ts(str) {
 int l;
 if(!str)
    {notify_fail("Set MudTag silence to what?\n");
     return;}
 if(!sscanf(str,"%d",l))
    {notify_fail("Set MudTag silence to what?\n");
     return;}
 if(l>TP->query_level()) 
    {notify_fail("You may only set it as high as your level!\n");
     return;}
 write("MudTag Silence set to "+l+".\n");
 busy=l;
 return 1;}

tt(str) {
 object u,x;
 int i;
 if(!str)
    {notify_fail("To list tag players, type 'show tag'\n");
     return;}
 u=users();
 for(i=0;i<sizeof(u);i++)
   {if(x=present("game_tag",u[i])) 
      {if(x->query_busy()<=TP->query_level()) 
        {if(query_verb()=="ttalk") 
           tell_object(u[i],lw("<:MudTag:> "+C(TP->QRN)+" says: "+str+"\n"));
         else
           tell_object(u[i],lw("<:MudTag:> "+C(TP->QRN)+" "+str+"\n"));}}}
 write("Ok.\n");
 return 1;}

vol() {
 if(it)
    {notify_fail("You are already it!\n");
     return;}
 if(check_it()) 
   {notify_fail("Somebody is already it!\n");
    return;}
 it=1;
 TP->set_title("is it!");
 TP->set_pretitle("none");
 write("You are it!\n");
 alert(C(TP->QRN)+" volunteered to be It!",TP);
 tagtime=time();
 return 1;}

wiz_filt(ob) {
  if(ob->query_level()>=30) {return 0;}
  return 1;}


xtime(arg) {
 string time;
 time="";
 if(arg>3599) 
   {time=" "+arg/3600+" hours";
    arg=arg%3600;}
 if (arg>59) 
   {time+=" "+arg/60+" minutes";
    arg=arg%60;}
 if (arg>0)
   time+=" "+arg+" seconds";
 return time;}




