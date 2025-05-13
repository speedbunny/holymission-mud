inherit "room/room";

#include <lw.h>
#define qv query_verb()
#define TP this_player()
#define qch ob->query_chips()
#define TPRN capitalize(this_player()->query_real_name())

int c1,c2,c3,b,in_hand;
object at_table;

void reset(int arg) 
  {at_table=0;
  in_hand=0;
  if(!arg)
    {set_light( 1);
    clone_list=({1,1,"cashier","players/kawai/monst/cashier",0});
    property=({"no_fight","no_steal","no_teleport"});
    short_desc= "The Casino";
    long_desc=
    "The plush decorations and furniture make you think this "+
    "should be a legitimate establishment, but one look at its "+
    "patrons tells you otherwise.  Against the north wall is a bar "+
    "and cute dwarven waitresses carry drinks to those at the "+
    "gambling tables...\n"+
    "A menu hangs from the ceiling.\n";
    items=({
    "menu","A small iron sign with something written on it",
    "table","An Acey-Ducey table.  You might try sitting at it",
    "tables","Lots of gambling tables.",
    "chair","A plush, cushioned chair",
    "chairs","Some rather comfortable looking chairs",
    "bar","You can order drinks",
    "patron","This one looks rather grimey...or is that the mayor?",
    "waitress","She's rather cute...for a dwarf",
    "waitresses","They carry drinks and food to players at the tables",
    "decoration","Everything LOOKS high class, but another look at the patrons makes\n"+
    "you think otherwise",
    "decorations","Everything LOOKS high class, but another look at the patrons makes\n"+
    "you think otherwise",
    "furniture","It looks comfortable, especially those pieces by the tables",
    "patrons","Assorted fellow, ranging from the elite to the ugly"});
    dest_dir=({"/players/kawai/areas/dwarves/village29","west"});}
  ::reset(arg);}

int ct() 
  {if(at_table==TP)
    {return 1;}
  return 0;}

void disp_card(int num)
  {string x;
  x=(string)num;
  switch(num)
    {case 10: x="10";
              break;
    case 11: x=" J";
             break;
    case 12: x=" Q";
             break;
    case 13: x=" K";
             break;
    case 14: x=" A";
             break;
    default: x=" "+(string)num;
             break;}
  write("+-----+\n"+
  "|"+x+"   |\n"+
  "|     | \n"+
  "|   "+x+"|\n"+
  "+-----+\n\n");}

void disp_cards(int num, int num2)
  {string x,y;
  int temp;
  if(num>num2)
    {temp=num;
    num=num2;
    num2=temp;}
  x=(string)num;
  y=(string)num2;
 switch (num2)
    {case 10: y="10";
              break;
    case 11: y=" J";
             break;
    case 12: y=" Q";
             break;
    case 13: y=" K";
             break;
    case 14: y=" A";
             break;
    default: y=" "+(string)num;
             break;}
  switch (num)
     {case 10: x="10";
              break;
    case 11: x=" J";
             break;
    case 12: x=" Q";
             break;
    case 13: x=" K";
             break;
    case 14: x=" A";
             break;
    default: x=" "+(string)num;
             break;}
  write("+-----+     +-----+\n"+
            "|"+x+"   |     |"+y+"   |\n"+
            "|     |     |     |\n"+
            "|   "+x+"|     |   "+y+"|\n"+
            "+-----+     +-----+\n\n");}

status block(string str) 
  {string x;
  x=query_verb();
  if(!(x=="order"||x=="buy"||x=="help"||x=="read"||x=="bet"||x=="fold"||x=="deal"||
  x=="say"||x=="tell"||x=="bug"||x=="typo"))  
    {if(ct()) 
      {writelw("Your concentration is on the game, leave if you want to do "+
      "something else.\n");
      return 1;}}
  return 0;}

void init() 
  {::init();
  add_action("block","",1);
  add_action("order","order"); 
  add_action("order","buy"); 
  add_action("read","read"); 
  add_action("sitat","sit");
  add_action("sitat","play");
  add_action("betx","bet");
  add_action("helpc","help");
  add_action("fold","fold");
  add_action("deal","deal");}

status helpc(string str)
  {if(!str) 
    {return 0;}
  if(str=="cards")
    {writelw("In Acey-Ducy, you are dealt two cards, face up.  You "+
    "are then given the opportunity to bet or get new cards.  "+
    "If you do decide to bet, a third card is drawn--if that card "+
    "is between the first two, you win!  Simple game, really!  "+
    "The object is to know when to take risks...the smaller the "+
    "gap between cards, the more you win, if it's to easy, you "+
    "don't get anything.\n"+
    "Commands: deal  - draw 2 cards\n"+
    "          bet - bet an amount\n"+
    "          fold - quit\n");
    return 1;}
  return 0;}

status sitat(string str) 
  {if(query_verb()=="sit") 
    {if(str!="at table") 
      {notify_fail("Sit at what?\n");
      return 0;}}
  else if(query_verb()=="play")
    {if(str!="cards") 
      {notify_fail("Play what?\n");
      return 0;}}
  if(at_table)
    {if(at_table==TP) 
      {write("You're already there!\n");
      return 1;}
    write("Sorry, all the tables are full.\n");
    return 1;}
  at_table=TP;
  write("Ok...The game is Acey-Ducey! Type 'help cards' for more info.\n"); 
  say(TPRN+" sits down to play some cards...\n");
  return 1;}

status fold() 
  {if(!ct()) 
    {return 0;}
  write("Giving up, eh?\n");
  say(TPRN+" quits playing cards.\n");
  at_table=0;
  in_hand=0;
  return 1;}

int abs(int num) 
  {if(num<0) 
    {return -num;}
  return num;}

status betx(string str)
  {int has, bet;
  object ob;  
  if(!ct()) 
    {notify_fail("You're not playing!\n");
    return 0;}
  if(!in_hand)
    {write("It isn't time to bet!\n");
    return 1;}
  if(!str) 
    {notify_fail("Bet how much?\n");
    return 0;}
  ob=present("kq1-chips",TP);
  if(!ob) 
    {write("You have no chips to bet with.\n");
    return 1;}
  has=ob->query_chips();
  sscanf(str,"%d",bet);
  if(bet>has)
    {write("Sorry, you only have "+has+" chips!\n");
    return 1;}
  write("Ok...\n");
  say(TPRN+" bets.\n");
  c3=random(13)+2;
  while ((c3==c2||c3==c1)) 
    {c3=random(13)+2;}
  disp_card(c3);
  if(!((c1<c3&&c3<c2)||(c1>c3&&c3>c2)))
    {ob->add_chips(-bet);
    write("Sorry, you lost!! You now have "+ob->query_chips()+" chips!\n");
    say(TPRN+" lost!\n");
    if (!ob->query_chips())
      {write("You are out of chips! See ya, chump!\n");
      say(TPRN+" ran out of chips!\n");
      at_table=0;
      in_hand=0;
      destruct(ob);
      return 1;}
    in_hand=0;
    return 1;}
  switch (abs(c1-c2))
    {case 1..3: bet=bet*3;
                 break;
    case 4..7: bet=bet*2;
                break;
    case 8..10: break;
    default: bet=0;
             break;}
  ob->add_chips(bet);
  if(!bet)
    {write("That was too easy!  You win nothing for that!\n");}
  else 
    {write("Congratulations! You now have "+ob->query_chips()+" chips!\n");}
  say(TPRN+" won!\n");
  if((qch>7000)&&(qch<10000))
    {writelw("A few patrons start whispering to each other as they "+
    "watch you play.\n");
    say("People start watching "+TPRN+"\n");}
 else if((qch>10000)&&(qch<12500))
    {write("A rather burly troll watches from the corner.\n");}
 else if(ob->query_chips()>12500)
    {writelw("A large troll walks up to you and grabs you by the arm.  "+
    "The troll says: The boss would like to see you....Now!\n");
    say(TPRN+" is dragged off to the back room by a large troll!\n");
    TP->move_player("to see the boss","players/kawai/areas/dwarves/office");
    at_table=0;
    in_hand=0;
    destruct(ob);
    return 1;}
  in_hand=0;
  return 1;}

status deal()
  {if(!ct())
    {write("You're not playing!\n");
    return 1;}
  c1=random(13)+2;
  c2=random(13)+2;
  while (c1==c2)
    {c2=random(13)+2;}
  write("The cards....\n");
  say(TPRN+" draws a "+c1+" and a "+c2+".\n");
  disp_cards(c1,c2);
  write("Bet how much ('deal' for new hand, 'fold' to quit):\n");
  in_hand=1;
  return 1;}
   

status read(string str)
  {if (str=="menu" || str=="drink" || str=="drinks"||str=="sign")
    {say(TPRN+" reads the menu.\n");
    write(
    "#######################################################\n"+
    "                    Casino Bar & Grill!                       \n"+
    "#######################################################\n"+
    "We offer:\n"+
    "\n"+
    "1  Water                             5 coins \n"+
    "2  Ale                               10 coins \n"+
    "3  Dwarven Punch                     250 coins \n"+
    "4  Mole Jerky                       100 coins \n"+
    "5  Elf Steak                         600 coins \n\n"+
    "You can consume also in numbers....<buy 1> for the Water.\n");     
    return 1;}
  notify_fail("Read what?\n");
  return 0;}

status order(string str)
  {string name, short_desc,art, mess;
  int value, cost, strength, heal, scream;
  object dummy;
  scream=0;
  if(!str)
    {notify_fail("What would you like to order?\n");
    return 0;}
  if (str == "water" || str == "1")
    {mess = "A waitress comes over and hands you your drink.";
    heal = 5;
    value = 5;
    strength = 1;
    art ="soft";}
  else if (str == "ale" || str == "2") 
    {mess = "A waitress comes over and hands you your drink.";
    heal= 10;
    value = 10;
    strength = 2;
    art ="alko";}
  else if (str == "punch" ||str=="dwarven punch"|| str=="3")
    {mess = "A waitress comes over and hands you your drink.";
    heal= 60;
    value = 250;
    strength = 7;
    art = "alko";
    scream=1;}
  else if (str == "jerky" ||str=="mole jerky"|| str=="4")
    {mess = "A waitress comes over and hands you a plate.";
    heal = 20;
    value = 100;
    strength = 3;
    art = "food";}
  else if (str=="steak"||str=="elf"||str=="elf steak" || str=="5") 
    {mess = "A waitress comes over and hands you a plate.";
    heal = 100;
    value = 600;
    strength = 13;
    art = "food";}
  else
    {notify_fail("The waitress just shrugs.\n");
    return 0; }
  if (this_player()->query_money()<value)
    {notify_fail("The waitress says: Sorry, no gold, no service!\n");
    return 0;}
  if (art=="alko")
    {if(!this_player()->drink_alcohol(strength))
      {notify_fail("The waitress says: I think you've had enough.\n");
      return 0;}}
  else if(art=="soft")
    {if(!this_player()->drink_soft(strength))
      {notify_fail("The waitress says: Sorry, you're looking a little sick.\n");
      return 0;}}
  else if(art=="food")
    {if(!this_player()->eat_food(strength))
      {notify_fail("The waitress says: Sorry, you're looking a little sick.\n");
      return 0;}}
  write("You pay " + value + " coins.\n");
  this_player()->add_money(-value);
  this_player()->heal_self(heal);
  say(TPRN+" orders something.\n");
  write(mess + ".\n");
  return 1;}



