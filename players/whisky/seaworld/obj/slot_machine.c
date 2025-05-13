
/* #########################################################################

                  NEWBIE QUEST (crack the jackpot) (c) Whisky 
    
    * the idea is to solve a gnomish mechanism of a jackpotmachine :)
   
   ######################################################################### */
   
#define TP this_player()
#define TPN TP->query_name()
#define SAY(X) tell_room(environment(this_object()),X)
#define MONEY_ADD(x,y) x->add_money(y)


int x,y,z,num1,num2,num3,num4;
static int pot, in_play;
string s1,s2,s3;

string short()
{
  return "wooden box";
}

int get()
{
  return 0;
}

int id(string arg)
{
   switch(arg)
   {
    case "box":
    case "wooden box":
    case "big wooden box":
     write("You see a big wooden box with a strange mechanism.\n"+
           "There are 3 holes in it's middle, 4 wheels inside\n"+
           "and a little slot on it's side.\n");
    return 1;
    case "slot":
     write("The slot is big enough to insert ten gold coins. There is\n"+
           "a strange kind of mechanism which between slots and wheels.\n");
     return 1;
    case "hole":
    case "holes":
       write("You see 3 holes in the wooden box and small slot.\n");
     return 1;
    case "mechanism":
       write("You see 3 big wheels with tiny white mice sitting in each.\n"+
          "There is one small wheel upon the 3 big wheels. A small silk\n"+
          "with a piece of cheese is fixed to the small wheel and fixed\n"+
          "to one side of a small alchemist-balance. The slot is above\n"+
          "the other side of the balance. It looks like a genial gnomish\n"+
          "gnomish invention. There is an inscription on the box.\n");
     return 1;
    case "wheel":
    case "wheels":
    case "big wheel":
    case "big wheels":
      write("You see a small iron wheel on the side of the box and 3 big\n"+
            "wheels with 1 mouse in each of them. On each wheel you see\n"+
            "severals small signs fixed to it. You see such signs as:\n"+
            "(!!!) or (---) or (+++) really strange.\n");
    return 1;
    case "balance":
      write("You see the following:\n\n"+
          "       __i_____o__  On the o a small silk is fixed and under the i\n"+
          "           / \      you see a small basket, big enough for some \n"+
          "                    gold coins.\n");
    return 1;
    case "basket":
      write("You see a small basket under the balance, big enough for\n"+
            "some gold coins. There is a small gnome sitting behind\n"+
            "the basket, counting money and grinning evily.\n");
    return 1;
    case "mouse":
      write("You see a small white mouse.\n");
    return 1;
    case "mice":
      write("You see 3 small white mice.\n");
    return 1;
    case "gnome":
      write("You see an evil grinning gnome counting money.\n");
    return 1;
    case "inscription":
      write("It seems a readable inscription.\n");
    return 1;
    default:
     return 0;
   }
 }


 init() {
   add_action("do_insert","insert");
   add_action("do_read","read");
   if (pot<10000) pot = 10000;
 } 

  do_read(arg) {
   if (arg!="inscription") return;
    write(
         "Strange you read:\n\n"+
         "min is 10 gold coins\n\n"+
         "(!!!)                    20 \n"+
         "            (!!!)        20 \n"+
         "(!!!)       (!!!)        30 \n"+
         "(!!!) (!!!)              40 \n"+ 
         "      (!!!) (!!!)        40 \n"+
         "(!!!) (!!!) (!!!)        80 \n"+
         "(---) (---) (---)       120 \n"+
         "(+++) (+++) (+++)       400 \n"+
         "(###) (###) (###)      1000 \n"+
         "($$$) ($$$) ($$$)      ??? \n\n");
      return ( 1 );
   }


  do_insert(arg) {
     string what,a,b;
     object player;

     player = this_player();
     
     what = (({"coin","coins","10 coins","10 gold coins","ten coins",
               "ten gold coins","gold coins"}));
     
  if (sscanf(arg,"%s in %s",a,b)==2) {
     arg = a;
     }
   player->catch_msg(arg);
    if (member_array(arg,what)==-1)
  {
         if (!present(arg,player)) {
             notify_fail("You can't insert something you don't have.\n");
         } else {
             notify_fail("The slot is much to small to insert that.\n");
         }
        return ( 0 );
    } else if (in_play) {
      notify_fail("You have to wait a bit.\n");
      return ( 0 );
     } else if (player->query_money() < 10) {
        notify_fail("You don't have that much money.\n");
      return ( 0 );
     } else {
       tell_object(this_player(),
          "\nYou insert 10 gold coins. The coins hits the balance.\n\n");
        call_out("start_box",2,this_player());
        say(TPN+" inserts something in the big box.\n"); 
        in_play = 1;
        MONEY_ADD(TP,-10);
        pot=pot+5;
        /* here a quest can be added */
           do_play();
           call_out("show1",3,player);
           call_out("show2",4,player);
           call_out("show3",6,player);
           call_out("win",8,player);           
    return ( 1 );
  }
  }

start_box(object player) {
      tell_object(player,
           "The balance goes down and the coins falls into the basket.\n"+
           "The cheese hanging on the silk on the wheel moves down towards\n"+
           "the nose of the mice. The mice start to run and the big wheels\n"+
           "turn fast around.\n\n");
   }
   
 show1(object player) {
   tell_object(player,"Looking at the wheels you see: "+s1+" ");
  }

 show2(object player) {
   tell_object(player,s2+" ");
  }

 show3(object player) {
  tell_object(player,s3+"\n\n"+"The mice stop to run.\n");
 }


 win(object player) { 
    in_play = 0;
        num1=x*10+y; 
        num2=y*10+z;
        num3=z*10+x;
        num4=x*100+y*10+z;

     if (num4==666) {
      tell_object(player,
              "The gnome growls: you had the Jack Pot.\n"+
              "A small hole in the box opens and you get "+(pot/2)+" coins.\n");
        MONEY_ADD(player,(pot/2));
        pot=0;
       }
     else if (num4==777) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 300 coins.\n");
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,300);
     pot=pot-(150);
     }
     else if (num4==222) {
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 80 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,80);

     pot=pot-(40);
     }
     else if (x==2 && z==2 && y==7) {
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 130 coins.\n");  
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,130);
     pot=pot-(60);
     }
     else if ((x==2 && y==2 && z==7) || (y==2 && z==2 && x==7)) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 140 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,140);
     pot=pot-(70);
     }
     else if (x==2 && y==7 && z==7) {
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 220 coins.\n");  
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,220);
     pot=pot-(110);
     }
     else if (y==2 && x==7 && z==7) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 220 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,220);
     pot=pot-(110);
     }
     else if (z==2 && x==7 && y==7) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 220 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,220);
     pot=pot-(110);
     }
     else if ((z==2) && (x==7 || y==7)) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 120 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,120);
     pot=pot-(60);
     }
     else if ((y==2) && (x==7 || z==7)) {
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 120 coins.\n");  
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,120);
     pot=pot-(60);
     }
     else if ((x==2) && (y==7 || z==7)) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 120 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,120);
     pot=pot-(60);
     }
     else if (x==2 && z==2) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 30 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,30);
     pot=pot-(10);
     }
     else if ((x==2 && y==2) || (y==2 && z==2)) {
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 40 coins.\n");  
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,40);
     pot=pot-(20);
     }
     else if (x==2 || z==2) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 20 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,20);
     pot=pot-(10);
     }
     else if ((x==7 && y==7) || (x==7 && z==7) || (z==7 && y==7)) {
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 200 coins.\n");  
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,200);
     pot=pot-(100);
     }
     else if (x==7 || y==7 || z==7) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 100 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,100);
     pot=pot-(50);
     }
     else if (num4==333) {
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 1200 coins.\n");  
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,1200);
     pot=pot-(600);
     }
     else if (num4==444) { 
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 400 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
     MONEY_ADD(player,400);
     pot=pot-(200);
     }
     else if (num4==555) { 
     MONEY_ADD(player,1000);
     pot=pot-(500);
     tell_object(player,
     "A small hole in the box opens and a gnomish hand gives you 1000 coins.\n"); 
     SAY("A small hole in the big box opens and a hand reaches out.\n");
    } else {
     tell_object(player,
     "The gnome laughs at you saying: Sorry, ** hehe ** you lost !\n");
     SAY("You hear a loud laughter coming out from the box.\n");
     return 1;
     }
   return 1;
  }




  do_play() {
     int chance1,chance2,chance3;

     chance1=random(100);
     chance2=random(100);
     chance3=random(100);
     if (chance1<3)       { x=6; s1="($$$)";}     
     else if (chance1<8)  { x=5; s1="(###)"; }   
     else if (chance1<15)  { x=4; s1="(+++)"; }  
     else if (chance1<24) { x=3; s1="(---)";}    
     else if (chance1<60) { x=2; s1="(!!!)";}   
     else if (chance1<62) { x=7; s1="(joker)";}
     else { x=1; s1="(???)"; } 

     if (chance2<5) { y=6; s2="($$$)"; }       
     else if (chance2<15) { y=5; s2="(###)"; }
     else if (chance2<35) { y=4; s2="(+++)"; } 
     else if (chance2<40) { y=3; s2="(---)"; }
     else if (chance2<60) { y=2; s2="(!!!)"; } 
     else if (chance2<61) { y=7; s2="(joker)"; }
     else { y=1; s2="(???)";  } 

     if (chance3<2) { z=6; s2="($$$)"; }    
     else if (chance3<6) { z=5; s3="(###)"; }   
     else if (chance3<10) { z=4; s3="(+++)"; }  
     else if (chance3<15) { z=3; s3="(---)"; } 
     else if (chance3<30) { z=2; s3="(!!!)";} 
     else if (chance3<31) { z=7; s3="(joker)";}
     else { z=1; s3="(???)"; } 
   return 1;
  }
     /* pot = 1/5000 , 1/500 , 1/60   */ 
           
 
         

