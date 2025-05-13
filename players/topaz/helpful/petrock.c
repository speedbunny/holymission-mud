#include "/players/kawai/macros"
#include "/obj/lw.h"
#define cap capitalize
#define CAW cap(atwho)
#define TPR tpro()
#define CTPR cap(tpro())
#define TPR2 tpro2()
#define CTPR2 cap(tpro2())
string NAME;
int SEX, ROCK, tricks;

id(str) {return str=="rock" || str=="pet rock" || str=="KROCK";}

short() {return NAME+" the "+query_gender()+" pet rock";}

long() {write(NAME+" the "+query_gender()+" pet rock\n");
        write("A small stone with a face painted on it.\n"+sex_desc()+"\n");
        write("For more information, 'ask rock for help'!!!\n");
        return 1;}

rockh(str) {
 if(!str) {notify_fail("Ask what?\n"); return;}
 if(str=="rock for help") {
    say(CTPN+" asks "+tphis()+" rock a question.\n");
    write("Available commands:\n"+
          "=============================================================\n"+
          "pet rock                   || Lets you pet your rock.\n"+
          "snuggle rock               || Snuggle close to your rock!\n"+
          "hug rock                   || Hug your rock!\n"+
          "kiss rock                  || Kiss your rock tenderly.\n"+
          "hit <player> with rock     || Hit somebody you don't like!\n"+
          "sleep with rock            || Cuddle up for a nap...\n"+
          "present rock               || Show your rock to everyone.\n"+
          "rock on / off              || Turns rock channel on or off\n"+
          "rtalk <mes>                || Sends a message to Pet Rock owners\n"+
          "erock <mes>                || Have your pet rock emote to the room.\n"+
          "trick <trick>              || Perform a trick.\n"+
          "  can be: bounce           || ::Make your rock bounce around\n"+
          "          fetch            || ::Make it fetch a stick\n"+
          "          hide             || ::or blend in with its surroundings!\n"+
          "          stay             || ::Watch how obedient it is!\n"+
          "          beg              || ::It even begs for food(?)!!\n"+
          "          kiss             || ::Let it kiss everyone!\n\n"+
          "Type 'name rock <name>' to give it a name.\n"+
          "Type 'make rock <male/female> to give it a gender!\n"+
          "To get rid of it, type 'throw rock at <player>'\n\n"+
          "More commands to come with the next rocks!\n"+
          "Use rockidea <idea> to make any suggestions!\n");
    return 1;}
  if(str=="rock about hidden commands"){write(NAME+
     ", the pet rock, whispers: For a good time, try 'fuck rock' or some\n"+
     "of the ususal variations.  Make sure you're up for the experience, you\n"+
     "may be a little sore afterwards!\n"); return 1;} return;}

query_weight() {return 1;}

query_gender() {if (SEX==1) {return "male";}
     return "female";}

query_value() {return 20;}

get() {return 1;}

query_auto_load() { return "players/kawai/obj/petrock:"+NAME+" #"+SEX+"#"+ROCK;}

init_arg(arg) {sscanf(arg,"%s #%d#%d",NAME, SEX, ROCK);}

drop() {write("As "+NAME+ " looks at you with "+qpp()+" usual loving gaze, you can't find\n"+
                     "it in your heart to drop "+qpn()+".\n");return 1;}

query_name() {return NAME;}

reset(arg) {tricks=0;}

give_sex(str) {
string type;
   if (!str || sscanf(str,"rock %s",type) !=1) { return;}
   if (type=="male") {SEX=1; write("OK.\n"); return 1;}
   if (type=="female") {SEX=2; write("OK.\n"); return 1;}
   write("I've never heard of one of those...\n"); return 1;}

sex_desc() {if (SEX==1) {
   return(NAME+" is probably the most handsome rock you've ever seen.  He is tough and\n"+
              "rugged, just as you would expect from a rock of his stature.\n");}
   return(NAME+" is adorable!  She is the cutest little rock you've ever seen!  She is small\n"+
             "and dainty and smooth, just as you would expect from a little rock like her!\n");}

sleepwith(str) {
 if(!str) {return;}
 if(str!="with rock") {return;}
 write("You cuddle up next to "+NAME+" and go to sleep!\n");
 say(CTPN+" cuddles up close to "+cap(query_his(TP))+" rock and takes a nap.\n");
 return 1;}

boastrock(str) {
 if(!str) {return;}
 if(!(str=="rock"||str==NAME)) {return;}
 write("You show off your pet rock to everyone!\n");
 say(CTPN+" walks around the room and shows "+cap(query_his(TP))+" rock to everyone!\n"+
     CTPN+" tells you: Don't you like my pet rock?  Isn't "+qpx()+" the cutest thing\n"+
     "You've ever seen?! Don't ya?  "+C(qpp())+" name is "+NAME+"!!\n");
 return 1;}

query_rock() {return ROCK;}

query_on_off() {if(ROCK) {return "on ";} return "off";}

set_talk(str) {if(!str) {write("Rock talk is "+query_on_off(ROCK)+".\n"); return 1;}
    if(str=="on") {if(ROCK){write("Its already on!\n"); return 1;}
                   write("Rock talk is now on.\n"); ROCK=1; return 1;}
    if(str=="off") {if(!ROCK){write("Its already off!\n"); return 1;}
                   write("Rock talk is now off.\n"); ROCK=0; return 1;}
    return;}

rockwho() {
  object who, *u;
  int i, count;
  u=users();
  count=0;
  write("Fellow Pet Rock owners:\n"+
        "---Owner Name-------------------Rock Name---On/off\n"+
        "====================================================\n");
  for(i=0;i<sizeof(u);i++) {
    if(who=present("KROCK",u[i])){count++;
       write(maxstr(u[i]->query_name(),30)+
            "   "+
            maxstr(who->query_name(),10)+
        "   "+who->query_on_off()+"\n");}}
 if(count==1) {write("1 rock owner on-line!  It's you!\n"); return 1;}
  write("\n"+count+" rock owners on-line!\n"); return 1;}

/*Herp: disabled*/
#if 0
rocktalk(str) {
  object who, *u;
  int i;
  if(!str) {rockwho(); return 1;}
  if(TP->query_spell_points()<1) {write(NAME+" looks too tired...\n"); return 1;}
  u=users();
  for(i=0;i<sizeof(u);i++) {
    if(who=present("KROCK",u[i])) {
        if(who->query_rock()) {
if(present("KROCK",u[i])->query_on_off()=="on ") {
             tell_object(u[i],lw("[ROCK] "+CTPRN+" says: "+str+"\n"));}}}}
  write("Ok.\n"); TP->reduce_spell_point(1); return 1;}

    
idear(str){
  if(!str) {write(NAME+" tells you: Try that again, but it would help if you actually\n"+
                  "told me your idea!\n");
            return 1;}
  write_file("/players/kawai/log/rock.idea",C(TPRN)+":"+ctime(time())+":"+str+"\n");
  write(NAME+" tells you: Ok!\n");  return 1;}
#endif

em(str) {
 if(!str) {notify_fail(NAME+" asks you: What should I emote?\n"); return;}
tell_room(environment(TP),"Petrock "
+NAME+" "+str+
"\n");
 return 1;}

init() 
{ if(!NAME) {NAME="Ralph";}
  if(!SEX) {SEX=1; ROCK=1;}
  add_action("pet_it","pet");
  if(TP->query_level()>30) {
  add_action("give","grock");
  add_action("updaterock","nrock");}
  add_action("set_talk","rock");
/*Herp: no talk */
#if 0
add_action("rocktalk","rtalk");
#endif
  add_action("sleepwith","sleep");
  add_action("boastrock","present");
  add_action("rockh","ask");
  add_action("em","erock");
  add_action("kiss","kiss");
  add_action("give_sex","make");
  add_action("give_name","name");
  add_action("snug","snuggle");
  add_action("destit","throw");
  add_action("hit","hit");
  add_action("hug","hug");
  add_action("idear","rockidea");
  add_action("rt","trick");
  add_action("fk","fuck");
  add_action("fk","screw");
  add_action("fk","eat"); 
 }

fk(str) {
 if(!str) {return;}
 if(str=="rock"||str=="petrock") {
   write("Damn! You are one sick little puppy!  Anyway.... If you must...\n");
   if(TP->query_gender()==1) {
      write("Because this is such an odd sexual practice, I'll be brief...\n"+
               "You lick "+NAME+" all over until your tounge bleeds, and at the\n"+
               "peak of your passion, you ram "+qpn()+" up your ass over and over\n"+
               "until you nearly collapse of exhaustion!\n");
     say(CTPN+", the rock-fucking lunatic, licks his pet rock then rams it up his ass.\n"+
            "You gasp in astonishment that people are actually that sick.\n");
     TP->reduce_hit_point(15);
      return 1;}
  if(TP->query_gender()==2) {
     write("Because this is such an odd sexual practice, I'' be brief...\n"+
              "You lick "+NAME+" all over until your tounge bleeds, the caress your\n"+
              "body until your breasts bleed.  Then, at the peak of your passion, you\n"+
              "ram it in your wet cunt over and over until you nearly collapse from the\n"+
              "most intense orgasm you've ever had.\n");
      say(CTPN+", the rock-fucking lunatic, licks her pet rock and rubs it all over her\n"+
            "body, then rams it up her wet cunt until nearly collapsing.\n"+
            "You gasp in astonishment that people are actually that sick.\n"); 
      TP->reduce_hit_point(15);
      return 1;}
  else {write("This isn't even worth coding...actually, I wouldn't even know where to begin!\n");}}}
 

qpp() {if(SEX==1) {return "his";}
         else if(SEX==2) {return "her";}
         else {return "its";}}
qpn() {if(SEX==1) {return "him";}
          if(SEX==2) {return "her";}
          else{return "it";}}
qpx() {if(SEX==1) {return "he";}
      if(SEX==2) {return "she";}
      return "it";}
tpro() {if(TP->query_gender()==2) {return "she";}
           return "he";}
tpro2() {if(TP->query_gender()==2) {return "her";}
           return "him";}
tpx(arg) {if(arg->query_gender()==2) {return "her";}
           return "him";}
tphis() {if(TP->query_gender()==2) {return "her";} return "his";}

destit(str) {
  string atwho, str2;
  object target, temp, me;
  if (!str || sscanf(str,"%s at %s",str2,atwho) !=2) { return;}
  if(str2=="rock" || str2==NAME || str2==lower_case(NAME)) {
  target=find_player(lower_case(atwho));
  if(!target) {write("Can't find "+CAW+"!\n"); return 1;}
  write(NAME+" looks at you with pleading, loving eyes as you get ready to toss "+qpn()+"!\n");
  write("You throw "+NAME+" with all your might at "+CAW+" and smack "+tpx(target)+
        " in the head!\n");
  me=TP;
  say(cap(TPN)+" hurls "+NAME+" the pet rock high into\n"+
                 "the air, hitting "+CAW+" in the head!\n");
  tell_room(environment(target),"A pet rock thrown by "+cap(me->query_name())+" hits "+
      CAW+" in the head, then crumbles to dust!\n");
  tell_object(target,"You were just hit in the head by a rock!\n");
  target->reduce_hit_point(2);
  destruct(this_object());
  return 1;}
}

mes()
{   int mc;
    mc=random(12);
    if(mc==1) {say(CTPN+" strokes "+TPP+" pet rock affectionately\n");}
    if(mc==2) {tell_object(TP,NAME+" thinks: I love it when you do that!\n");}
    if(mc==3) {say(CTPN+" is a little loco!\n");}
    if(mc==4) {tell_object(TP,NAME+" tells you: Ohhh...more!\n");}
    if(mc==5) {say(CTPN+" looks at "+TPP+" pet rock with loving eyes!\n");}
    if(mc==6) {tell_object(TP,NAME+" thinks: Hey!  Watch those hands!\n");}
    if(mc==7) {say(CTPN+" fondles a small stone.\n");}
    if(mc==8) {tell_object(TP,NAME+" the pet rock says: I love "+TPN+"!!\n");
               say(NAME+" the pet rock says: I love "+TPN+"!!\n");}
    if(mc==9) {say(CTPN+" is in love......with a rock!\n");}
    if(mc==10) {say(CTPN+"says: I love you "+NAME+", you adorable little rock...(*hug*)\n");
        tell_object(TP,CTPN+" says: I love you "+NAME+
                        ", you adorable little rock...(*hug*)\n");}
    if(mc==11) {say(NAME+" the pet rock tells you: I'm only using "+TPR2+" for sex!\n");}
    return 1;
 }

pet_it(str) 
{ 
  if (!str) {return;}
  if (str=="rock" || str=="pet rock" || str==NAME || str==lower_case(NAME))
   {tell_object(TP,"You stroke "+NAME+" affectionately!\n");
    say(CTPN+" pets "+TPP+" rock.\n");
      mes();
  return 1;
}
return 0;}

snug(str) 
{ 
  if (!str) {return;}
  if (str=="rock" || str=="pet rock" || str==NAME || str==lower_case(NAME))
   {tell_object(this_player(),"You snuggle "+NAME+" with love and tenderness!\n");
    say(CTPN+" snuggles close to "+TPP+" rock.\n");
mes();
  return 1;
}
return 0;}

hug(str) 
{ 
  if (!str) {return;}
  if (str=="rock" || str=="pet rock" || str==NAME || str==lower_case(NAME))
   {tell_object(this_player(),"You hug "+NAME+" tightly!\n");
    say(CTPN+" hugs "+TPP+" pet rock tightly!\n");
mes();
  return 1;
}
return 0;}

kiss(str) 
{ 
  if (!str) {return;}
  if (str=="rock" || str=="pet rock" || str==NAME || str==lower_case(NAME))
  {tell_object(this_player(),"You kiss "+NAME+" tenderly!\n");
    say(CTPN+" kisses "+TPP+" pet rock tenderly!\n");
    mes();
  return 1;
}
return 0;}


hit(str) {
 string name;
 object who;
 if(!str) {return;}
 if(!sscanf(str,"%s with rock",name)) {return;}
 if(!who=find_player(name)) {notify_fail("Can't find that player.\n"); return;}
 if(!present(who,environment(TP))) {notify_fail("That person isn't here!\n"); return;}
 if(name==TP->QRN) {write("You hit yourself!\n");
                    say(CTPN+" hits "+TPR2+"self with "+TPP+" pet rock!\n");
                    return 1;}
 write("You hit "+cap(name)+" with your rock!\n");
 tell_object(who,CTPN+" hits you with "+TPP+" pet rock!\n");
 say(CTPN+" hits "+cap(name)+" with "+TPP+" pet rock!\n");
 return 1;}

give_name(str)
{
 string to, temp;
 if(!str || sscanf(str,"%s %s",to,temp) !=2) { return 0;}
 if(to=="rock") {
   if(strlen(temp)>15) {write("Name to long, try again!\n"); return 1;}
   NAME=cap(temp);
   write("Ok!\n");
   return 1;}
}

rt(str)
{if (!str) {return;}
 if(tricks>3) {write(NAME+" tells you: Gimmie a chance to rest!\n"); return 1;}
 if(str=="fetch")
   {say(CTPN+" says: Hey, watch my pet rock do a trick!\n"+
        CTPR+" picks up a small twig and throws it out of sight!\n"+
        NAME+" the pet rock rolls out of the room after it!\n"+
        "A few moments later, "+NAME+" rolls back in nudging the corpse of a baby"+
        "dragon!\n"+CTPN+" says: Well...ummmm....nice rock...good rock...\n"+
        "The corpse decays into nothingness.\n");
    tell_object(TP,"You say: Hey, watch my pet rock do a trick!\n"+
        "You pick up a small twig and throws it out of sight!\n"+
        NAME+" the pet rock rolls out of the room after it!\n"+
        "A few moments later, "+NAME+" rolls back in nudging the corpse of a baby "+
        "dragon!\nYou say: Well...ummmm....nice rock...good rock...\n"+
        "The corpse decays into nothingness.\n"); tricks++;
    return 1;}
if(str=="bounce")
   {say(CTPN+" says: Hey, watch my pet rock do a trick!\n"+
        CTPR+" picks up "+TPP+" pet rock and throws "+qpn()+" against the wall!\n"+
        "You gasp in amazement as it bounces around the room and\nreturns right "+
        "back to "+TPR2+"!\n");
    tell_object(TP,"You say: Hey, watch my pet rock do a trick!\n"+
        "You pick up your pet rock and throws "+qpn()+" against the wall!\n"+
        "Everyone gasps in amazement as it bounces around the room and\n"+
        "returns right back to you!\n");   tricks++;     
    return 1;}
if(str=="hide")
   {say(CTPN+" says: Hey, everyone, look at "+NAME+"!\n"+
        CTPR+" tosses "+TPP+" pet rock onto the ground.  It shuffles around among\nthe rocks "+
        "until it blends in... It disappeared!\n"+"A few moments later, the rock stirs and "+
        "crawls back over to "+TPR2+".\n");
    tell_object(TP,"You say: Hey, everyone, look at "+NAME+"!\n"+
        "You toss "+NAME+" on the ground and watch "+qpn()+" blend into the surrounding rocks.\n"+
        "A few moments later it comes out of hiding and returns to you!\n"); tricks++;
    return 1;}
if(str=="stay")
    {say(CTPN+" says: Watch this!\n"+
         CTPN+" drops "+TPP+" rock and commands it to stay.  "+CTPR+" walks\naround the room"+
         "and to no surprise, "+TPP+" pet rock didn't move!\n");
     tell_object(TP,"You say: Watch this!\n"+
         "You drop your rock and command it to stay.  After walking around the room, you\n"+
         "are surprised it actually listened!\n"); tricks++;
     return 1;}
if(str=="beg")
    {say(CTPN+" says: You'll love this one!\n"+
         CTPN+" holds a small pebble over "+TPP+" pet rock.  It soon rolls\n on one side and "+
         "barks!  "+TPR+" rewards "+qpn()+" with the pebble and\n"+
         "it swallows (??) it in one bite!\n");
     tell_object(TP,"You say: You'll love this one!\n"+
         "You hold a small pebble over "+NAME+".  It rolls over on its sides and\n"+
         "barks!  You reward it with the pebble, and it eats it in one bite!\n"); tricks++;
     return 1;}
if(str=="kiss")
    {say(CTPN+"'s pet rock "+NAME+" jumps up and kisses you!\n");
     tell_object(TP,"Your rock kisses everyone in the room!\n"); tricks++;
     return 1;}
write(NAME+" tells you: I don't know that one!\n");
return 1;
}

give(str) {
object ob,x;
 if(!str) {notify_fail("Give to who?\n"); return;}
 if(!ob=find_player(str)) {notify_fail("Can't find player.\n"); return;}
 if(present("KROCK",ob)) {notify_fail("Player already has one!\n"); return;}
 transfer(x=clone_object("players/kawai/obj/petrock"),ob);
 tell_object(ob,"You have been given a pet rock by "+CTPRN+".\n");
 write("Ok.\n");
 write_file("/players/kawai/log/petrock",CTPRN+" gave a petrock to "+ob->query_real_name()+
  " on "+ctime(time())+"\n");
 return 1;}

updaterock() {
 object u,x;
 int i,tempgen;
 string tempname;
 u=users();
 for(i=0;i<sizeof(u);i++) {
   if(x=present("KROCK",u[i])) {
      tempname=x->query_name();
      tempgen=x->query_gender();
      tell_object(u[i],tempname+" tells you: Be back in a flash!  I'm being updated!\n");
      destruct(x);
      transfer(x=clone_object("players/kawai/obj/petrock"),u[i]);
      x->set_name(tempname);
      x->set_gender(tempgen);}}
 write("Ok.\n");
 return 1;}
