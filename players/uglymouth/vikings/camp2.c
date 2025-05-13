/* gamble with the vikings to get mead */
inherit "room/room";
object stump,vik,vitem,*item;
int gambling,rollx,i,j;
int res,*pdice,*vdice,one,two,thr;
int fdie,sdie,pnum,pval1,pval2,vnum,vval1,vval2;
string gambler;

void reset(int arg) {

   pdice=allocate(4);
   vdice=allocate(4);
   rollx=3;
   if(!(vik=present("viking luckar")) || !living(vik)) {
      vik=clone_object("/players/uglymouth/vikings/monsters/vluckar");
      transfer(vik,this_object());
      }

   if(arg) return;

   set_light(1);
   short_desc="Among gambling and drinking vikings";
   long_desc="The vikings are making a party here. A large flat tree trunk "
           + "serves as a table. Some mugs and dice are standing on it. "
           + "Southwest some tents are built up. East you look out over the "
           + "sea. A rowing boat is moored on the beach. \n";
   dest_dir=({"/players/uglymouth/vikings/campbeach","east",
              "/players/uglymouth/vikings/camp1","west", });
   items=({"vikings","They look drunk from celebrating their conquest",
           "trunk","The big trunk from some kind of palmtree",
           "mugs","They are filled with an alcoholic beverage",
           "dice","Home made wooden dice, probably not fully balanced",
           "tents","There are three tents",
           "sea","The sun reflects in a heavenly blue sea",
           "boat","The vikings must have used this boat for coming ashore", });

   smell="There is a sweet and alcoholic scent vaguely hanging in the air. \n";
   move_object(clone_object("/players/uglymouth/vikings/items/trunk"),this_object());
   }

/* added by James. Because query_no_teleport is going away */

int query_property(string str) { if (gambling==1 && str=="no_teleport") return 1; }

void init() {
   ::init();
   add_action("gamble","gamble");
   add_action("roll","roll");
   add_action("west","west");
   add_action("east","east");
   add_action("greedy","get");
   add_action("greedy","take");
   }

void write_res(string str) {
int k;
string *onestr,*twostr,*thrstr;
   onestr=allocate(6);
   twostr=allocate(6);
   thrstr=allocate(6);
   onestr=({"       ","o      ","o      ","o     o","o     o","o     o", });
   twostr=({"   o   ","       ","   o   ","       ","   o   ","o     o", });
   thrstr=({"       ","      o","      o","o     o","o     o","o     o", });

   if(str=="player") {
      write("You rolled: \n");
      i=pdice[1];
      j=pdice[2];
      k=pdice[3];
      write(i+"   "+j+"   "+k+" \n");
/*
      write(onestr[i]+"   "+onestr[j]+"   "+onestr[k]+" \n");
      write(twostr[i]+"   "+twostr[j]+"   "+twostr[k]+" \n");
      write(thrstr[i]+"   "+thrstr[j]+"   "+thrstr[k]+" \n");
*/
      return;
      }
   if(str=="viking") {
      write("Viking Luckar rolled: \n");
      i=vdice[1];
      j=vdice[2];
      k=vdice[3];
      write(i+"   "+j+"   "+k+" \n");
/*
      write(onestr[i]+"   "+onestr[j]+"   "+onestr[k]+" \n");
      write(twostr[i]+"   "+twostr[j]+"   "+twostr[k]+" \n");
      write(thrstr[i]+"   "+thrstr[j]+"   "+thrstr[k]+" \n");
*/
      return;
      }
   }

void pwin() {
object *all;
   tell_room(this_object(),"Viking Luckar says: You win "+this_player()->query_name()+" \n");
   say("Viking Luckar gives "+this_player()->query_name()+" back "+this_player()->query_possessive()
     + "bet and a mug of mead. \n",this_player());
   write("Viking Luckar gives you back your bet and a mug of mead. \n");
   stump=present("tree stump");
   vik=present("viking luckar");
   all=all_inventory(stump);
   for(j=0;j<sizeof(all);j++) {
      transfer(all[j],this_player());
      }
   gambling=0;
   gambler=0;
   return;
   }

void vwin() {
object *all;
   tell_room(this_object(),"Viking Luckar says: My luck makes me win this game. \n");
   tell_room(this_object(),"Viking Luckar takes the bets from the tree stump. \n");
   stump=present("tree stump");
   vik=present("viking luckar");
   all=all_inventory(stump);
   for(j=0;j<sizeof(all);j++) {
      transfer(all[j],vik);
      }
   gambling=0;
   gambler=0;
   return;
   }

int vikroll() {
/* how many dice must the vikig roll? */
   vnum=2;
   if(vdice[1] > 4) {
      fdie=2;          /* first die to roll */
      sdie=3;          /* second die to roll */
      }
   if(vdice[2] > 4) {
      fdie=1;
      sdie=3;
      }
   if(vdice[3] > 4) {
      fdie=1;
      sdie=2;
      }
   if(vdice[1]<5 && vdice[2]<5 && vdice[3]<5) vnum=3;
   if(((vdice[1] - vdice[2])==0) && ((vdice[1] - vdice[3])==0)) {
      vnum=0;
      }
   if(vdice[1]==vdice[2] && vdice[1]!=vdice[3]) {
      vnum=1;
      fdie=3;
      }
   if(vdice[1]==vdice[3] && vdice[1]!=vdice[2]) {
      vnum=1;
      fdie=2;
      }
   if(vdice[2]==vdice[3] && vdice[1]!=vdice[2]) {
      vnum=1;
      fdie=1;
      }

/* now roll his dice */
   write("Viking Luckar rolls "+vnum+" times. \n");
   if(vnum==0) {
      write("Viking Luckar smiles happily. \n");
      }
   if(vnum==1) {
      vdice[fdie]=random(7)+1;
      if(vdice[fdie]==7) vdice[fdie]=6;
      }
   if(vnum==2) {
      vdice[fdie]=random(7)+1;
      if(vdice[fdie]==7) vdice[fdie]=6;
      vdice[sdie]=random(7)+1;
      if(vdice[sdie]==7) vdice[sdie]=6;
      }
   if(vnum==3) {
      for(i=1;i<4;i++) {
         vdice[i]=random(7)+1;
         if(vdice[i]==7) vdice[i]=6;
         }
      }

   write_res("player");
   write_res("viking");
   say(this_player()->query_name()+" rolls the dice. \n",this_player());
   say("Viking Luckar rolls the dice. \n",this_player());
   rollx=rollx+1;

   if(rollx==2) {
      write("Viking Luckar says: Your turn again. \n");
      return 0;
      }

/* end of game. evaluate the results */
   if(rollx==3) {
      write("The game is over. \n");
      }

   pnum=1;
   pval1=pdice[1];
   if(pval1 < pdice[2]) pval1=pdice[2];
   if(pval1 < pdice[3]) pval1=pdice[3];
   if(pdice[1]==pdice[2] && pdice[1]==pdice[3]) {
      pnum=3;
      pval1=pdice[1];
      }
   if(pdice[1]==pdice[2] && pdice[1]!=pdice[3]) {
      pnum=2;
      pval1=pdice[1];
      pval2=pdice[3];
      }
   if(pdice[1]==pdice[3] && pdice[1]!=pdice[2]) {
      pnum=2;
      pval1=pdice[1];
      pval2=pdice[2];
      }
   if(pdice[2]==pdice[3] && pdice[1]!=pdice[2]) {
      pnum=2;
      pval1=pdice[2];
      pval2=pdice[1];
      }

   vnum=1;
   vval1=vdice[1];
   if(vval1 < vdice[2]) vval1=vdice[2];
   if(vval1 < vdice[3]) vval2=vdice[3];
   if(vdice[1]==vdice[2] && vdice[1]==vdice[3]) {
      vnum=3;
      vval1=pdice[1];
      }
   if(vdice[1]==vdice[2] && vdice[1]!=vdice[3]) {
      vnum=2;
      vval1=vdice[1];
      vval2=vdice[3];
      }
   if(vdice[1]==vdice[3] && vdice[1]!=vdice[2]) {
      vnum=2;
      vval1=vdice[1];
      vval2=vdice[2];
      }
   if(vdice[2]==vdice[3] && vdice[1]!=vdice[2]) {
      vnum=2;
      vval1=vdice[2];
      vval2=vdice[1];
      }

/* comparing the values */
   if(pnum==3 && pval1==1) {
      write("Viking Luckar says: Triple Ace, your luck must be greater than mine. \n");
      pwin();
      return 1;
      }
   if((pnum - vnum) > 0) {
      pwin();
      return 1;
      }
   if((pnum - vnum) < 0) {
      vwin();
      return 1;
      }
   if((pnum - vnum)==0) {
      if(vnum==3 && vval1==1) {
         write("Viking Luckar says: Triple Ace. My luck is good. \n");
         vwin();
         return 1;
         }
      if(pval1 > vval1) {
         pwin();
         return 1;
         }
      if(pval1 < vval1) {
         vwin();
         return 1;
         }
      if(pval1 == vval1) {
         if(pnum==1 || pnum==3) {
            write("Viking Luckar says: A tie. I roll again. Odd you win, even I win. \n");
            j=1 + random(7);
            if(j==7) j=6;
            write("Viking Luckar rolls a "+j+". \n");
            if(j==2 || j==4 || j==6) {
               vwin();
               return 1;
               }
            pwin();
            return 1;
            }
         if(pnum==2) {
            if(pval2 > vval2) {
               pwin();
               return 1;
               }
            if(pval2 < vval2) {
               vwin();
               return 1;
               }
            write("Viking Luckar says: A tie. I roll again. Odd you win, even I win. \n");
            j=1 + random(7);
            if(j==7) j=6;
            write("Viking Luckar rolls a "+j+". \n");
            if(j==2 || j==4 || j==6) {
               vwin();
               return 1;
               }
            pwin();
            return 1;
            }
         }
      }
   }

int gamble() {
   if(!(vik=present("viking luckar")) || !living(vik)) {
      write("There is no viking present who will gamble with you. \n");
      return 1;
      }
   if((gambling==1) && (this_player()->query_name()!=gambler)) {
      write("Viking Luckar says: Can't you see I'm busy with a game? \n");
      return 1;
      }
   stump=present("tree stump");
   vik=present("viking luckar");
   if(!present("mead",vik)) {
      write("Viking Luckar says: Sorry friend, But I have nothing to bet. \n");
      return 1;
      }
   if(rollx!=3) {
      write("But you're already playing this game! \n");
      return 1;
      }
   item=all_inventory(stump);
   j=0;
   for(i=0;i<sizeof(item);i++) {
      if(item[i]->query_weapon()) j=1;
      if(item[i]->query_armour()) j=1;
      }
   if(j==0) {
      write("Viking Luckar says: if you want to gamble, then put your bet in the tree stump. \n");
      return 1;
      }

/* start the game */
   gambling=1;
   gambler=this_player()->query_name();
   tell_room(this_object(),"Viking Luckar puts a mug of mead as his bet in the tree stump. \n");
   vitem=present("mead",vik);
   transfer(vitem,stump);

   for(i=1;i<4;i++) {         /* the player's first roll */
      pdice[i]=1 + random(7);
      if(pdice[i]==7) pdice[i]=6;
      }
   write_res("player");
   for(i=1;i<4;i++) {         /* the viking's first roll */
      vdice[i]=1 + random(7);   /* the dice are somewhat unbalanced */
      if(vdice[i]==7) vdice[i]=6;
      }
   write_res("viking");
   say(this_player()->query_name()+" rolls the dice. \n",this_player());
   say("Viking Luckar rolls the dice. \n",this_player());

   rollx=1;
   write("Viking Luckar says: Your turn to roll again. \n");
   return 1;
   }

/* second and third roll */
int roll(string str) {
   if(gambling==1 && this_player()->query_name()!=gambler) {
      write("Stay out of a game that isn't yours to play. \n");
      return 1;
      }
   if(rollx==3) {
      write("Game Over. Type 'gamble' if you want to play again. \n");
      return 1;
      }

   if(!str) {
      write("Roll what? \n");
      return 1;
      }
   if(sscanf(str,"%d, %d, %d",one,two,thr)==3) {
      if(one<0 || one>3 || two<0 || two>3 || thr<0 || thr>3) {
         write("There are only the dice 1, 2 and 3. Try again. \n");
         return 1;
         }
      pdice[one]=random(7)+1;
      if(pdice[one]==7) pdice[one]=6;
      pdice[two]=random(7)+1;
      if(pdice[two]==7) pdice[two]=6;
      pdice[thr]=random(7)+1;
      if(pdice[thr]==7) pdice[thr]=6;
      vikroll();
      return 1;
      }
   if(sscanf(str,"%d, %d",one,two)==2) {
      if(one < 0 || one > 3 || two < 0 || two > 3) {
         write("There are only the dice 1, 2 and 3. Try again. \n");
         return 1;
         }
      pdice[one]=random(7)+1;
      if(pdice[one]==7) pdice[one]=6;
      pdice[two]=random(7)+1;
      if(pdice[two]==7) pdice[two]=6;
      vikroll();
      return 1;
      }
   if(sscanf(str,"%d",one)==1) {
      if(one < 0 || one > 3) {
         write("There are only the dice 1, 2 and 3. Try again. \n");
         return 1;
         }
      pdice[one]=1 + random(7);
      if(pdice[one]==7) pdice[one]=6;
      vikroll();
      return 1;
      }
   notify_fail("That you cannot roll. \n");
   return 1;
   }

int west() {
   if(this_player()->query_name()!=gambler) return 0;
   write("Viking Luckar urges you to finish your game before you leave. \n");
   return 1;
   }

int east() {
   if(this_player()->query_name()!=gambler) return 0;
   write("Viking Luckar urges you to finish your game before you leave. \n");
   return 1;
   }

int greedy(string str) {
   if((sscanf(str,"%s from stump",item)==1) ||
       (sscanf(str,"%s from tree stump",item)==1)) {
      if(gambling==1) {
         write("Don't try to steal the bets!! \n");
         return 1;
         }
      }
   return 0;
   }

void vikings_leave() {
object vik,*inv;
int i;
   long_desc="You're walking on muddy ground, that continues west. To the east a small \n"
           + "stroke of beach is showing out over the sea. If you look carefully \n"
           + "trails of human presence can be found all over the place. \n";
   items=({
      "ground","Just some sticky, dirty, dark muddy ground. Nothing you'd give second thoughts",
      "beach","A beautiful white beach, giving a nice view over the sunny sea",
      "stroke","A beautiful white beach, giving a nice view over the sunny sea",
      "trails","Very vague footprints can be seen and the tree stump is handled by humans too",
      "footprints","You suspect the makers of those prints must have been quite big fellows..",
      });
   vik=present("viking");
   while(vik) {
      inv=all_inventory(vik);
      for(i=0;i<sizeof(inv);i++) {
         destruct(inv[i]);
         }
      destruct(vik);
      vik=present("viking");
      }
   if(gambling==1) {
      tell_room(this_object(),"Viking Luckar says: Sorry, "
         + gambler + ", but I just got orders \n"
         + "to board our drakar. We'll gamble again another day. \n");
      stump=present("tree stump");
      inv=all_inventory(stump);
      for(i=0;i<sizeof(inv);i++) {
         if(inv[i]->query_name()=="mead") {
            destruct(inv[i]);
            }
         }
      gambler=0;
      gambling=0;
      rollx=3;
      }
   tell_room(this_object(),"The vikings pick up all their belongings and head for their ship. \n");
   return;
   }

void vikings_arrive() {
object vik;
   long_desc="The vikings are making a party here. A large flat tree trunk "
           + "serves as a table. Some mugs and dice are standing on it. "
           + "Southwest some tents are built up. East you look out over the "
           + "sea. A rowing boat is moared on the beach. \n";
   items=({"vikings","They look drunk from celebrating their conquest",
           "trunk","The big trunk from some kind of palmtree",
           "mugs","They are filled with an alcoholic beverage",
           "dice","Home made wooden dice, probably not fully balanced",
           "tents","There are three tents",
           "sea","The sun reflects in a heavenly blue sea",
           "boat","The vikings must have used this boat for coming ashore", });
   vik=clone_object("/players/uglymouth/vikings/monsters/vluckar");
   transfer(vik,this_object());
   tell_room(this_object(),"The vikings arrive, just having ransacked the nearby village, and set up camp. \n");
   return;
   }
