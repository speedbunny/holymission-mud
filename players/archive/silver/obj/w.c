/*
  Wedding info tool ver. 1.1
  Last edit : Silver Sat 03-04-1995 2:16:15 pm
*/
inherit "obj/thing.c";

#define MIN_LEVEL 5
#define RINGTEST "players/moonchild/wedding/replace_it"

object PL1,PL2;
string PL1N,PL2N;
string relig;

 int sid;

query_auto_load()
 {
  return "/players/silver/obj/w:"+sid;
 }
 int drop() { return 1; }
/* reset tool */
int _mreset()
 {
  PL1N="";
  PL2N="";
  PL1=0;
  PL2=0;
  relig="";
  write("Wedding tool was reseted.\n");
  return 1;
 }

/* go to right church acording to religion of the players */
int _gowedd()
 {
  switch(relig)
   {
   case "il" : ;

    /* other wedding places will be added later */
default : transfer(this_player(),"/players/moonchild/wedding/chapel");return 1;
   }
  return 1;
 }

/* test players before wedding & set religion of tool */
int _mtest(string arg)
 {
  string belief1,belief2;
  int wrong;

  if(sscanf(arg,"%s %s",PL1N,PL2N)==!2)
   {
    write("Wrong set of arguments.\n");
    return 1;
   }

  PL1=find_player(PL1N);
  PL2=find_player(PL2N);

  if(!PL1)
   {
    write(PL1N + " is not an interactive player.\n");
    return 1;
   }
  if(!PL2)
   {
    write(PL2N + " is not an interactive player.\n");
    return 1;
   }

  if(RINGTEST->get_spouse(capitalize(PL1N)))
   {
    write("But " + capitalize(PL1N) + " is already married.\n");
    wrong = 1;
   }

  if(RINGTEST->get_spouse(capitalize(PL2N)))
   {
    write("But " + capitalize(PL2N) + " is already married.\n");
    wrong = 1;
   }

  if(PL1->query_gender() == PL2->query_gender())
   {
    write("We do not allow homosexual marriages here !\n");
    wrong = 1;
   }

  belief1=PL1->query_religion();
  belief2=PL2->query_religion();

  if(belief1!=belief2)
    {
     write(PL1->query_name()+" is a follower of "+belief1+".\n");
     write(PL2->query_name()+" is a follower of "+belief2+".\n");
     write("Religion doesn't match !\n");
     wrong = 1;
    }
   else
    {
     write("Both " + PL1->query_name() + " and " + PL2->query_name() +
           " are followers of "+capitalize(belief1)+".\n"
          );
     relig=belief1;
    }

  if(PL1->query_level()<MIN_LEVEL)
   {
    write(PL1->query_name()+"'s level is too low. ( "+
          PL1->query_level()+" )\n"
         );
    wrong = 1;
   }

  if(PL2->query_level()<MIN_LEVEL)
   {
    write(PL2->query_name()+"'s level is too low. ( "+
          PL2->query_level()+" )\n"
         );
    wrong = 1;
   }

  if(wrong) _mreset();
 return 1;
 }
int _minfo()
 {
  string info;

  if(!PL1 || !PL2 )
   {
    write("Nobody selected for wedding.\n");
    return 1;
   }

  info=
" knows anything why you should not be joined. \n"+
this_player()->query_name()+" tells you : ceremony goes this way ...\n"
" First one of you need to give 5000 coins to preacher man.\n" +
" Then I'll start the ceremony.\n"+
" Preacher man will ask you if you want to marry your lover.\n"+
" You need to 'say yes' but don't delay too long.\n"+
" In one passage of wedding preacher asks if anyone present\n"+
" knows anything why you should not be joined. \n"+
" Unfortunatelly if anyone says anything at that point wedding is canceled\n"+
" so don't be surprised if it happens :)))\n" +
" Ceremony would be restarted and you needn't pay again.\n"+
" That's all. If you still want to marry good luck to you and tell me\n"+
" to start. \n"+
this_player()->query_name() + " hugs you friendly.\n";

  tell_object(PL1,info);
  tell_object(PL2,info);
  write("You told info to "+PL1->query_name()+" and "+PL2->query_name()+
        ".\n"
       );
  return 1;
 }

void reset(int arg)
 {
  ::reset(arg);

  if(!arg)
    {
     set_name("Wedding info tool (ver. 1.1)");
     set_alias("info");
     set_alt_name("tool");
     set_long(
"This is tool which tells players what they need to know before wedding.\n"+
"1 ) both players must follow same religion\n"+
"2 ) both need to be level 5 at least\n"+
"3 ) both must be unmarried\n"+
"4 ) one of players need to pay 5000 coins to preacher man\n"+
"5 ) to marry in main church religion need to be Illuvatar\n\n"+
"Available commands are : 'mtest pl1 pl2' test players and set tool\n"+
"                         'minfo' tell them info \n"+
"                         'gowedd' go to wedding place\n"+
"                         'mreset' reset weding tool\n"
         );

/* will be more but not now */
     set_value(0);
     set_weight(0);
    }
 }

void init()
 {
  ::init();
  add_action("_minfo","minfo");
  add_action("_mtest","mtest");
  add_action("_gowedd","gowedd");
  add_action("_mreset","mreset");
 }
