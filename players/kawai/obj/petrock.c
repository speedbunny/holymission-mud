/* PETROCK.C - Programmed by Kawai */

#include "/obj/lw.h"
#define TP this_player()
#define CTPRN capitalize(this_player()->query_real_name())
#define TPos this_player()->query_possessive()
#define C(x) capitalize(x)

string NAME;

int SEX, tricks;

int id(string str)
  {return str=="rock" || str=="pet rock" || str=="KROCK";}

int query_value()
  {return 20;}

int get(string str)
  {return 1;}

string query_auto_load()
  {return "players/kawai/obj/petrock:"+NAME+" #"+SEX;}

void init_arg(string arg)
  {sscanf(arg,"%s #%d",NAME, SEX);}

string possessive()
  {if(SEX==1)
    {return "his";}
  else if(SEX==2)
    {return "her";}
  else
    {return "its";}}

string objective()
  {if(SEX==1)
    {return "him";}
  if(SEX==2)
    {return "her";}
  else
    {return "it";}}

string pronoun()
  {if(SEX==1)
    {return "he";}
  if(SEX==2)
    {return "she";}
  return "it";}

int drop() {
  if(!this_player()) return 1;
  write("As "+NAME+ " looks at you with "+possessive()+
  " usual loving gaze, you can't find\n"+
  "it in your heart to drop "+objective()+".\n");
  return 1;
}

string query_name()
  {return NAME;}

string sex_desc()
  {if (SEX==1)
    {return(NAME+" is probably the most handsome rock you've ever seen.  He is tough and "+
    "rugged, just as you would expect from a rock of his stature.\n");}
  return(NAME+" is adorable!  She is the cutest little rock you've ever seen!  She is small "+
  "and dainty and smooth, just as you would expect from a little rock like her!\n");}


string query_gender()
  {if (SEX==1)
    {return "male";}
  return "female";}

string short()
  {return NAME+" the "+query_gender()+" pet rock";}

void long()
  {write(NAME+" the "+query_gender()+" pet rock\n");
  writelw("A small stone with a face painted on it.\n"+sex_desc()+"\n");
  write("For more information, 'ask rock for help'!!!\n");}

int query_weight()
  {return 1;}

void reset(int arg)
  {tricks=0;}

void init() 
  {if(!NAME)
    {NAME="Ralph";}
  if(!SEX)
    {SEX=1;}
  add_action("pet_it","pet");
  if(TP->query_immortal())
    {add_action("give","grock");
    add_action("updaterock","nrock");}
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
  add_action("rt","trick");}

void mes()
  {switch(random(12))
    {case 1: say(CTPRN+" strokes "+TPos+" pet rock affectionately\n");
      break;
    case 2: tell_object(TP,NAME+" thinks: I love it when you do that!\n");
      break;
    case 3: say(CTPRN+" is a little loco!\n");
      break;
    case 4: tell_object(TP,NAME+" tells you: Ohhh...more!\n");
      break;
    case 5: say(CTPRN+" looks at "+TPos+" pet rock with loving eyes!\n");
      break;
    case 6: tell_object(TP,NAME+" thinks: Hey!  Watch those hands!\n");
      break;
    case 7: say(CTPRN+" fondles a small stone.\n");
      break;
    case 8: tell_object(TP,NAME+" the pet rock says: I love "+CTPRN+"!!\n");
      say(NAME+" the pet rock says: I love "+CTPRN+"!!\n");
      break;
    case 9: say(CTPRN+" is in love......with a rock!\n");
      break;
    case 10: say(lw(CTPRN+"says: I love you "+NAME+", you adorable little rock...(*hug*)\n"));
      break;
    case 11: say(lw(NAME+" the pet rock tells you: I'm only using "+CTPRN+" for sex!\n"));
      break;
    default: break;}}


status boastrock(string str)
  {if(!(str=="rock"||str==NAME))
    {notify_fail("Present what?\n");
    return 0;}
  write("You show off your pet rock to everyone!\n");
  say(lw(CTPRN+" walks around the room and shows "+TPos+" rock to everyone!\n"+
     CTPRN+" tells you: Don't you like my pet rock?  Isn't "+pronoun()+" the cutest thing "+
     "You've ever seen?! Don't ya?  "+C(possessive())+" name is "+NAME+"!!\n"));
 return 1;}

status destit(string str)
  {string atwho, str2;
  object target, temp, me;
  if(!str)
    {notify_fail("Throw what?\n");
    return 0;}
  else if(sscanf(str,"%s at %s",str2,atwho)!=2)
    {notify_fail("Throw what?\n");
    return 0;}
  if(str2=="rock" || str2==NAME || str2==lower_case(NAME))
    {target=find_player(lower_case(atwho));
    if(!target)
      {write("Can't find "+C(atwho)+"!\n");
      return 1;}
    writelw(NAME+" looks at you with pleading, loving eyes as you get ready to toss "+objective()+"!\n");
    writelw("You throw "+NAME+" with all your might at "+C(atwho)+" and smack "+target->query_objective()+
    " in the head!\n");
    say(lw(CTPRN+" hurls "+NAME+" the pet rock high into "+
    "the air, hitting "+C(atwho)+" in the head!\n"));
    tell_room(environment(target),
    lw("A pet rock thrown by "+CTPRN+" hits "+
    C(atwho)+" in the head, then crumbles to dust!\n"));
    tell_object(target,"You were just hit in the head by a rock!\n");
    target->reduce_hit_point(2);
    destruct(this_object());
    return 1;}
  return 0;}

status em(string str)
  {if(!str)
    {notify_fail(NAME+" asks you: What should I emote?\n");
    return 0;}
  tell_room(environment(TP),lw(NAME+", the petrock, "+str+"\n"));
  return 1;}

status give(string str)
  {object ob,x;
  if(!str)
    {notify_fail("Give to who?\n");
    return 0;}
  if(!ob=find_player(str))
    {notify_fail("Can't find player.\n");
    return 0;}
  if(present("KROCK",ob))
    {notify_fail("Player already has one!\n");
    return 0;}
  transfer(x=clone_object("players/kawai/obj/petrock"),ob);
  tell_object(ob,"You have been given a pet rock by "+CTPRN+".\n");
  write("Ok.\n");
  write_file("/players/kawai/log/petrock",CTPRN+" gave a petrock to "+ob->query_real_name()+
  " on "+ctime(time())+"\n");
  return 1;}

status give_name(string str)
  {string to, temp;
  if(!str)
    {notify_fail("Give what?\n");
    return 0;}
  else if(sscanf(str,"%s %s",to,temp)!=2)
    {return 0;}
  else if(to=="rock")
    {if(strlen(temp)>15)
      {write("Name to long, try again!\n");
      return 1;}
    NAME=C(temp);
    write("Ok!\n");
    return 1;}
  return 0;}

status give_sex(string str)
  {string type;
  if(!str)
    {notify_fail("Make what?\n");
    return 0;}
  else if(sscanf(str,"rock %s",type)!=1)
    {notify_fail("Make rock what?\n");
    return 0;}
  if(type=="male")
    {SEX=1;
    write("OK.\n");
    return 1;}
  if(type=="female")
    {SEX=2;
    write("OK.\n");
    return 1;}
  write("I've never heard of one of those...\n");
  return 1;}

status hit(string str)
  {string name;
  object who;
  if(!str)
    {notify_fail("Hit what?\n");
    return 0;}
  else if(!sscanf(str,"%s with rock",name))
    {return 0;}
  else if(!who=find_player(name))
    {notify_fail("Can't find that player.\n");
    return 0;}
  else if(!present(who,environment(TP)))
    {notify_fail("That person isn't here!\n");
    return 0;}
  else if(name==TP->query_real_name())
    {write("You hit yourself!\n");
    say(CTPRN+" hits "+TP->query_objective()+"self with "+TPos+" pet rock!\n");
    return 1;}
  write("You hit "+C(name)+" with your rock!\n");
  tell_object(who,CTPRN+" hits you with "+TPos+" pet rock!\n");
  say(CTPRN+" hits "+C(name)+" with "+TPos+" pet rock!\n");
  return 1;}

status hug(string str) 
  {if(!str)
    {notify_fail("Hug what?\n");
    return 0;}
  if(str=="rock" || str=="pet rock" || str==NAME || str==lower_case(NAME))
    {tell_object(TP,"You hug "+NAME+" tightly!\n");
    say(CTPRN+" hugs "+TPos+" pet rock tightly!\n");
    mes();
    return 1;}
  return 0;}

status idear(string str)
  {if(!str)
    {notify_fail(lw(NAME+" tells you: Try that again, but it would help if you actually "+
    "told me your idea!\n"));
    return 0;}
  write_file("/players/kawai/log/rock.idea",CTPRN+":"+ctime(time())+":"+str+"\n");
  write(NAME+" tells you: Ok!\n");
  return 1;}

status kiss(string str) 
  {if (!str)
    {notify_fail("Kiss what?\n");
    return 0;}
  if(str=="rock" || str=="pet rock" || str==NAME || str==lower_case(NAME))
    {tell_object(TP,"You kiss "+NAME+" tenderly!\n");
    say(CTPRN+" kisses "+TPos+" pet rock tenderly!\n");
    mes();
    return 1;}
  return 0;}

status pet_it(string str) 
  {if(!str)
    {notify_fail("Pet what?\n");
    return 0;}
  if(str=="rock" || str=="pet rock" || str==NAME || str==lower_case(NAME))
    {tell_object(TP,"You stroke "+NAME+" affectionately!\n");
    say(CTPRN+" pets "+TPos+" rock.\n");
    mes();
    return 1;}
  return 0;}

status rockh(string str)
  {if(!str)
    {notify_fail("Ask what?\n");
    return 0;}
  if(str=="rock for help")
    {say(CTPRN+" asks "+TPos+" rock a question.\n");
    write("Available commands:\n"+
    "=============================================================\n"+
    "pet rock                   || Lets you pet your rock.\n"+
    "snuggle rock               || Snuggle close to your rock!\n"+
    "hug rock                   || Hug your rock!\n"+
    "kiss rock                  || Kiss your rock tenderly.\n"+
    "hit <player> with rock     || Hit somebody you don't like!\n"+
    "sleep with rock            || Cuddle up for a nap...\n"+
    "present rock               || Show your rock to everyone.\n"+
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
  notify_fail("Ask what?\n");
  return 0;}

status rt(string str)
  {if(!str)
    {notify_fail("Which trick?\n");
    return 0;}
  if(tricks>3)
    {write(NAME+" tells you: Gimmie a chance to rest!\n");
    return 1;}
  if(str=="fetch")
    {say(CTPRN+" says: Hey, watch my pet rock do a trick!\n"+
    CTPRN+" picks up a small twig and throws it out of sight!\n"+
    NAME+" the pet rock rolls out of the room after it!\n"+
    "A few moments later, "+NAME+" rolls back in nudging the corpse of a baby"+
    "dragon!\n"+TP->query_pronoun()+" says: Well...ummmm....nice rock...good rock...\n"+
    "The corpse decays into nothingness.\n");
    tell_object(TP,"You say: Hey, watch my pet rock do a trick!\n"+
    "You pick up a small twig and throws it out of sight!\n"+
    NAME+" the pet rock rolls out of the room after it!\n"+
    "A few moments later, "+NAME+" rolls back in nudging the corpse of a baby "+
    "dragon!\nYou say: Well...ummmm....nice rock...good rock...\n"+
    "The corpse decays into nothingness.\n");
    tricks++;
    return 1;}
  if(str=="bounce")
    {say(lw(CTPRN+" says: Hey, watch my pet rock do a trick!\n"+
    CTPRN+" picks up "+TPos+" pet rock and throws "+objective()+" against the wall!  "+
    "You gasp in amazement as it bounces around the room and\nreturns right "+
    "back to "+TP->query_objective()+"!\n"));
    tell_object(TP,lw("You say: Hey, watch my pet rock do a trick!\n"+
    "You pick up your pet rock and throws "+objective()+" against the wall!  "+
    "Everyone gasps in amazement as it bounces around the room and "+
    "returns right back to you!\n"));
    tricks++;     
    return 1;}
  if(str=="hide")
   {say(lw(CTPRN+" says: Hey, everyone, look at "+NAME+"!\n"+
   C(TP->query_pronoun())+" tosses "+TPos+" pet rock onto the ground.  It shuffles around among the rocks "+
   "until it blends in... It disappeared!  A few moments later, the rock stirs and "+
   "crawls back over to "+TP->query_objective()+".\n"));
   tell_object(TP,lw("You say: Hey, everyone, look at "+NAME+"!\n"+
   "You toss "+NAME+" on the ground and watch "+objective()+" blend into the surrounding rocks.  "+
   "A few moments later it comes out of hiding and returns to you!\n"));
   tricks++;
   return 1;}
  if(str=="stay")
    {say(lw(CTPRN+" says: Watch this!\n"+
    CTPRN+" drops "+TPos+" rock and commands it to stay.  "+C(TP->query_pronoun())+" walks around the room"+
    "and to no surprise, "+TPos+" pet rock didn't move!\n"));
    tell_object(TP,lw("You say: Watch this!\n"+
    "You drop your rock and command it to stay.  After walking around the room, you "+
    "are surprised it actually listened!\n"));
    tricks++;
    return 1;}
  if(str=="beg")
    {say(lw(CTPRN+" says: You'll love this one!\n"+
    CTPRN+" holds a small pebble over "+TPos+" pet rock.  It soon rolls on one side and "+
    "barks!  "+C(TP->query_pronoun())+" rewards "+objective()+" with the pebble and "+
    "it swallows (??) it in one bite!\n"));
    tell_object(TP,lw("You say: You'll love this one!\n"+
    "You hold a small pebble over "+NAME+".  It rolls over on its sides and "+
    "barks!  You reward it with the pebble, and it eats it in one bite!\n"));
    tricks++;
    return 1;}
  if(str=="kiss")
    {say(CTPRN+"'s pet rock "+NAME+" jumps up and kisses you!\n");
    tell_object(TP,"Your rock kisses everyone in the room!\n");
    tricks++;
    return 1;}
  write(NAME+" tells you: I don't know that one!\n"); 
  return 1;}

status sleepwith(string str)
  {if(str!="with rock")
    {notify_fail("Sleep with what?\n");
    return 0;}
  write("You cuddle up next to "+NAME+" and go to sleep!\n");
  say(CTPRN+" cuddles up close to "+TPos+" rock and takes a nap.\n");
  return 1;}

status snug(string str) 
  {if (!str)
    {notify_fail("Snuggle what?\n");
    return 0;}
  if(str=="rock" || str=="pet rock" || str==NAME || str==lower_case(NAME))
    {tell_object(TP,"You snuggle "+NAME+" with love and tenderness!\n");
    say(CTPRN+" snuggles close to "+TPos+" rock.\n");
    mes();
    return 1;}
  return 0;}

status updaterock()
  {object x;
  mixed u;
  int i,tempgen;
  string tempname;
  u=users();
  for(i=0;i<sizeof(u);i++)
    {if(x=present("KROCK",u[i]))
      {tempname=x->query_name();
      tempgen=x->query_gender();
      tell_object(u[i],tempname+" tells you: Be back in a flash!  I'm being updated!\n");
      destruct(x);
      transfer(x=clone_object("players/kawai/obj/petrock"),u[i]);
      x->set_name(tempname);
      x->set_gender(tempgen);}}
  write("Ok.\n"); 
  return 1;}

