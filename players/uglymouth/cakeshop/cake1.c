/* a delicious wedding cake */
#include "cakedefs.h"

inherit "obj/food";
int top,br,gr,parts;
string bride,groom;
int *clist,storeyparts;
int storeynr;

reset(arg) {
   ::reset(arg);

   if(!arg) {
      set_name("wedding cake");
      set_alias("cake");
      set_short("A two storey high wedding cake");
      set_value(0);   /* don't even think about selling it! */
      top=2;
      br=1;
      gr=1;
      parts=8;

/* list of choice codes (see shop for details) */
clist = allocate(3);
clist=({ 0,1,1 });

      }
   }

init() {
   ::init();
   add_action("smell","smell");
   add_action("eat","eat");
   add_action("look","look");
   }

smell(str) {
string *slist;
int storeynr;
   if(str=="cake" || str=="wedding cake") {
      write("It's so full of scents you'd better smell each storey separately. \n");
      return 1;
      }

   /* list of smell messages */
   slist = allocate(9);
   slist = ({ "dummy",
      "This storey is eaten, but a vague autumn smell still lingers in the air. \n",
      "The smell of fresh grapes, brambles and blackberries fills your nose. \n",
      "This storey is eaten, but a vague smell of fruits still lingers in the air. \n",
      "The sweet smell of ripe cherries, rosehips and raspberries tickles your nose. \n",
      "This storey is eaten, but a vague smell of fine chocolate still lingers in the air. /n",
      "The strong smell of the finest chocolate stays in your nose for a while. \n",
      "This storey is eaten, but a vague smell of nuts still lingers in the air. \n",
      "Through the smell of various nuts, the smell of pistachio is very obvious. \n",
      });
   if(sscanf(str,"storey %d",storeynr)!=1) return;
   if(storeynr < 1 || storeynr > 2) {
      write("There are not that many storeys in the cake. \n");
      return 1;
      }

   if(storeynr==2) {
      if(top==0) {
         write("The top storey is eaten, but a vague flowery smell still lingers in the air. \n");
         return 1;
         }
      if(TPQRN!=bride && TPQRN!=groom) {
         write("The images of "+cap(bride)+" and "+cap(groom)+" smile at you, but you don't smell anyting. \n");
         return 1;
         }
      if(TPQRN==bride) {
         write("The image of "+cap(groom)+" blows you a kiss, filling the air with the smell of roses. \n");
         return 1;
         }
      if(TPQRN==groom) {
         write("The image of "+cap(bride)+" blows you a kiss, filling the air with the smell of roses. \n");
         return 1;
         }
      }

   if(storeynr==1) {
      write(slist[clist[1]*2]);
      return 1;
      }
   }

eat(str) {
string *elist;
   if(str!="cake" && str!="wedding cake") return;
   if(top!=0) {
      if(TPQRN!=bride && TPQRN!=groom) {
         write("Behave yourself and wait until the happy couple has taken the first part. \n");
         return 1;
         }
      if(TPQRN==bride) {
         if(br==1) {
            write("The image of "+cap(groom)+" offers you elegantly his part of the top storey cake. \n"
                + "It tastes of all the mudlove he has to offer you. \n");
            say("The image of "+cap(groom)+" offers "+cap(bride)+" elegantly his part of the top storey cake. \n"
              + "Some lovely thoughts enter her mind as she eats it. \n",this_player());
            br=br-1;
            top=top-1;
            this_player()->heal_self(30);
            this_player()->eat_food(5);
            return 1;
            }
         write("Please wait for your husband to finish his part of the cake. \n");
         return 1;
         }
      if(TPQRN==groom) {
         if(gr==1) {
            write("The image of "+cap(bride)+" offers you elegantly her part of the top storey cake. \n"
                + "It tastes of all the mudlove she has to offer you. \n");
            say("The image of "+cap(bride)+" offers "+cap(groom)+" her part of the top storey cake. \n"
              + "Some lovely thoughts enter his mind as he eats it. \n",this_player());
            gr=gr-1;
            top=top-1;
            this_player()->heal_self(30);
            this_player()->eat_food(5);
            return 1;
            }
         write("Please wait for your wife to finish her part of the cake. \n");
         return 1;
         }
      }

   /* list of eating messages */
   elist = allocate(9);
   elist = ({ "dummy",
      "The icecream is a feast of black and blue autumn fruits. \n",
      "The jelly is richly filled with all kinds of sweet red fruits. \n",
      "The chocolate cake tastes devine as the icing mixes with it. \n",
      "You taste walnut, hazelnut, almond and many other tasty nuts. \n",
      "A spiral turns to golddust, whirls down and forms a heart. \n",
      "A dragon says: Happy marriage, " +bride+ " and " +groom+ ", and flies away. \n",
      "One of the wheels turns into a tulip, turning around the centre. \n",
      "The images of " +bride+ " and " +groom+ " appear in the ship as it sails to heaven. \n",
      });

   if(parts > 1) {
      write(elist[clist[1]] + elist[clist[2]+4]);
      say(cap(TPQRN) + " toasts to happiness and eats a part of the first storey. \n",TP);
      this_player()->heal_self(5);
      this_player()->restore_spell_points(25);
      this_player()->eat_food(5);
      parts--;
      return 1;
      }
   write(elist[clist[1]] + elist[clist[2]+4]);
   tell_room(environment(this_player()),"As "+cap(TPQRN)+" eats the last part of the wedding cake \n"
           + "its frame glows up in a bright white light and shoots to heaven. \n");
/*
   shout("The sky over Holy Mission is suddenly brightly lit by thousands of white sparks. \n"
       + "Descending they form the words: Happy Marriage "+cap(bride)+" and "+cap(groom)+" \n");
*/
   tell_room(environment(this_object()),"The sky over Holy Mission is suddenly lit by thousands of whit sparks. \n"
      + "Descending they form the words: Happy Marriage "+cap(bride)+" and "+cap(groom)+" \n");
   this_player()->heal_self(5);
   this_player()->restore_spell_points(25);
   this_player()->eat_food(5);
   parts--;
   destruct(this_object());
   return 1;
   }

look(str) {
string *dlist,*mlist;
   if(!str) return;
   if(sscanf(str,"at storey %d",storeynr)!=1) return;
   if(storeynr < 1 || storeynr > 2) {
      write("There aren't so many storeys in the cake. \n");
      return 1;
      }
   if(storeynr==2) {
      write("The top storey is made of soft cake covered with light yellow cream. \n"
         + "The images of " +cap(bride)+ " and " +cap(groom)+ " are waltzing on a merry symphony. \n");
      return 1;
      }
   if(storeynr==1) storeyparts = 8;

/* list of materials the cake is made of */
mlist = allocate(9);
mlist = ({ "dummy",
   "blue icecream",         "silvery sugar",
   "red fruits jelly",      "white cream",
   "brown chocolate cake",  "white chocolate",
   "mixed nuts cake",       "green pistachio",
   });

/* list of designs (to be determined per storey */
dlist = allocate(5);
dlist = ({ "dummy",
   "Storey " +storeynr+ " is made of glittering " +mlist[clist[(storeynr*2)-1]*2-1]+ ". On it, " +storeyparts+ "\n"
      + mlist[clist[storeynr*2]*2] + " spirals support the next storey and cast golden sparks around. \n",

   "Storey " +storeynr+ " is made of " +mlist[clist[(storeynr*2)-1]*2-1]+ " decorated with spots of \n"
      + mlist[clist[storeynr*2]*2] + ". " +storeyparts+" "+cap(mlist[clist[storeynr*2]*2])+ " dragons support the next storey \n"
      + "and breathe wine continuously. \n",

   "Storey " +storeynr+ " is made of " +mlist[clist[(storeynr*2)-1]*2-1]+ ". " +storeyparts+ " " +cap(mlist[clist[storeynr*2]*2])+ "\n"
      + "wheels support and rotate the next storey. Their axles meet in the centre, \n"
      + "where they transform into a beautiful red rose. \n",

   "Storey " +storeynr+ " is made of " +mlist[clist[(storeynr*2)-1]*2-1]+ ", its surface \n"
      + "waving like the sea. " +storeyparts+ " Ships of " +mlist[clist[storeynr*2]*2]+ "\n"
      + "sail on it in intricate patterns. \n",
   });

   write(dlist[clist[storeynr*2]]);
   say(cap(TPQRN) + " studies interestedly the details of the wedding cake. \n",TP);
   return 1;
   }

set_bride(str) {
   bride=str;
   return;
   }

set_groom(str) {
   groom=str;
   set_long("A two storey high wedding cake from Candy's confectioner's shop. \n"
          + "Specially created for the most happy marriage of " + cap(bride) + " and " + cap(groom) + ".\n"
          + "It's two storeys high and so detailed that you have to look \n"
          + "at each storey separately. \n");
   return;
   }

set_choices() {
int k;
object shop;
   shop=find_object("/players/uglymouth/cakeshop/cakeshop");
   for(k=0;k<sizeof(clist);k++) {
      clist[k] = shop->query_choices(k);
      }
   return;
   }
