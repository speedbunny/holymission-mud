inherit "obj/monster";

#include <lw.h>

#define TP this_player()
#define list present("kq1-list",TP)
#define cboy list->query_boy()
#define cbar list->query_bar()
#define core list->query_ore()
#define ENV  environment

object w, blade;
int sword, busy;

int id(string str) 
  {return str=="king"||str=="dwarven king"||str=="dwarf"||
  str=="dwarf king";}

void reset(int arg)
  {::reset(arg);
  sword=0;
  blade=0;
  if(!arg)
    {set_level(60);
    set_hp(8000);
    set_name("dwarven king");
    set_race("dwarf");
    set_alt_name("dwarf");
    set_al(1000);
    set_short("The Dwarf King");
    set_long(lw("The king is a kind and benevolent ruler, concerned about "+
    "his citizens at all times.  Despite his kindness, and many "+ 
    "grey hairs, he is a mighty warrior--the founder of the "+
    "Dwarven Legions as well-- he could probably lop off your "+
    "head with one swift hit.\nAsk king about <topic> for help!\n"));
    set_wc(35);
    set_ac(30);
    set_size(2);
    set_gender(1);
    set_aggressive(0);
    set_whimpy(-1);
    w=clone_object("obj/weapon");
    w->set_id("sword");
    w->set_name("a mystic sword"); 
    w->set_alt_name("mystic sword");
     w->set_alias("sword");
     w->set_class(22);
     w->set_weight(6);
     w->set_value(6000);
     w->set_short("A mystic sword");
     w->set_long(lw("The sword is of unknown origin, but simply by holding "+
     "it you get a sense of incredible power.  It glows with "+
     "a soft blue light.\n"));
     transfer(w,this_object());
     command("wield sword",this_object());}}

void greet()
  {writelw("The King says: Welcome, adventurer!  Enjoy my fine town, "+
  "and perhaps join me on a quest!  If you'd like, ask me about QUEST "+
  "or some other topic!\n");}

void check_ring()
  {object ob;
  if(ob=present("kq1-ring",TP))
    {tell_object(TP,
     lw("The King exclaims: My ring!  Thank you very much! I will not forget "+
     "this great service you have done me!\n"));
    if(!list)
      {transfer(clone_object("players/kawai/chklist"),TP);}
    list->set_bar(1);
    destruct(ob);}}

void init() 
  {add_action("askk","ask");
  greet();
  check_ring();}

varargs mixed hit_player(int dam,int kind,mixed elem)
  {int i;
  object ob;
  if(!present("guard",environment(this_object())))
    {for(i=1;i<=random(5);i++)
      {say("Several guards rush into the room!!!\n");
      transfer(ob=clone_object("players/kawai/monst/dguard"),
      environment(this_object()));
      command("kill "+query_attack()->query_real_name(),ob);}}
  return ::hit_player(dam, kind, elem);}


status askk(string str) 
  {object who, what;
  string w, mes,x;
  int trust;
  if(!str)
    {notify_fail("Ask who what?!?\n");
    return 0;}
  if(sscanf(str,"king about %s",mes)) 
    {who=TP;
    if(mes=="quest") 
      {tell_object(who,
      lw("The King sighs and tells you: Recently a terrible pestilence has "+
      "been ravaging the village.  In the eastern parts of the caves "+
      "north of here, a dark and evil CULT grows stronger.  They've "+
      "started murdering our children--we've found bits of their "+
      "bodies scattered throughout the caves--skulls piled in mounds.  "+
      "I would fight the cult myself, but I am old and the people need "+
      "me.  I could aid you in your fight, but you must earn my TRUST.\n"));
      return 1;}
    else if(mes=="cult")
      {tell_object(who,
      lw("The King tells you: The cult is comprised of an evil group of "+
      "powerful wizards, who worship the demi-god KAZAK.  You might "+
      "find it hard to penetrate their stronghold, as powerful magick "+
      "will blind you.  I do know, however, that somewhere near the "+
      "underground falls is an ORB that will let you see in the darkness.\n"));
      return 1;}
    else if(mes=="kazak")
      {tell_object(who,
      lw("The King tells you: Kazak is just another demi-god with a bad temper.  I wouldn't "+
      "be so concerned if it weren't for the abduction of our children "+
      "and the other strange things that have been happening as of late.  "+
      "Unfortunately, I don't know what will happen if he's left to do as "+
      "he will....\n"));
      return 1;}
   else if(mes=="orb")
      {tell_object(who,lw(
      "The King tells you: The orb is a mystic device that can illuminate the darkest places, "+
      "even when powerful magick has darkened the area.  Rumor has it "+
      "that the cult has been searching for the orb, in hopes that it may "+
      "assist in bringing Kazak to this world.\n"));
      return 1;}
   else if(mes=="ring")
      {tell_object(who,lw(
      "The King tells you: It was a gift from my father, and means much to me.\n"));
      return 1;}
   else if(mes=="trust")
      {if(!list)
        {transfer(clone_object("players/kawai/obj/chklist"),TP);}
      trust=0;
      if(cboy)
        {trust=trust+1;}
      if(cbar)
        {trust=trust+2;}
      if(core)
        {trust=trust+4;}
      switch(trust)
        {case 0: /*none*/
          tell_object(who,
          lw("The King says: I would greatly appreciate your help in the matter "+
          "of this cult, but I need to know that you are worthy.  Come back "+
          "to me after you have won the trust of my people.\n"));
          break;
        case 1: /*boy only*/
          tell_object(who,
          lw("The King tells you: I received word from our farmer that you "+
          "rescued his son.  I will keep this in mind.\n"));
          break;  
        case 2: /* ring only */
          tell_object(who,
          lw("The King tells you: I appreciate your great service to me in "+
          "returning my ring for me.  However, I must await the approval "+
          "of my citizens.  Perhaps they may give you a favorable review "+
          "if you assist them with their troubles.\n"));
          break;
        case 3: /* ring + boy */
          tell_object(who,
          lw("The King tells you: Reports from my citizens are slowly "+
          "arriving, and so far they are favorable.  However, I am still "+
          "a little unsure of your character.  Perhaps a few more words "+
          "from my people will change my mind.\n"));
          break;
        case 4: /* ore only */
          tell_object(who,
          lw("The King tells you: That cheese burger was delicious!  My alchemist "+
          "informed me that you found his crucial element!  I will not forget "+
          "your service!  However, I am still unsure of your loyalty.\n"));
          break;
        case 5: /* ore + boy */
          tell_object(who,
          lw("The King tells you: I have heard from both my farmer and alchemist, "+
          "and I am most pleased.  There is one last thing you can do for me "+
          "however.  Years ago, I foolishly entered a game with a rather slick "+
          "troll.  I was cheated, and lost a family ring that was treasured for "+
          "ages.  He now runs a casino somewhere in town, but none have my "+
          "guards have been able to locate it.  If you could somehow return it "+
          "to me, I would be ingrateful.\n"));
          break;
        case 6: /* ore + ring */ 
          tell_object(who,
          lw("The King tells you: Reports from my citizens are slowly "+
          "arriving, and so far they are favorable.  However, I am still "+
          "a little unsure of your character.  Perhaps a few more words "+
          "from my people will change my mind.\n"));
          break;
        case 7: /* ore + ring + boy */
          if(!sword)
            {tell_object(who,lw(
            "The king tells you: You have earned my trust.  I can only aid you on "+
            "your final quest to destroy the cult by giving you this sword.  It isn't "+
            "much against most opponents, but it has been enhanced to give you "+
            "an edge against Kazak.  Do not forget he is a demi-god and nearly "+
            "immortal.  This sword will see to it that he does not return to power "+
            "for a long time.\n"));
            sword=1;
            if(!present("kq1-sword",TP))
              {if(!blade)
                {blade=clone_object("/players/kawai/obj/qsword");}        
              if(transfer(blade,TP))
                {sword=0;
                tell_object(who,lw(
                "Sorry, my friend, but you appear unable to carry my "+
                "sword.  Return to me when you can.\n"));}}
            else
              {tell_object(who,"The King tells you:  I can do no more for you...\n");}}
          else
            {if(!present("kq1-sword",TP))
              {tell_object(who,lw("The King tells you:  Sorry, my friend, but someone "+
              "else has already come to me, and they are now on their way to face "+
              "Kazak.  So long as you stay near by, I will not forget your service, "+
              "perhaps in a short while, if the other person should fail or Kazak "+
              "manages to escape, you may continue the job.\n"));}
           else
             {tell_object(who,lw("The King tells you: I can do no more for you...\n"));}
          break;}}
      return 1;} 
    else
      {tell_object(who,lw("The King tells you: I know nothing of that...\n"));
      return 1;}}
  notify_fail("Ask who what?\n");
  return 0;}



