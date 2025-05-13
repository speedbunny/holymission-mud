

/* Tegerl, 28.3.1995 */
/* monsters/ow */


inherit "obj/monster";

int counter;

void reset(int arg) 
{
::reset(arg);

if (!arg){

set_name("old woman");
set_alt_name("woman");
set_race("human");
set_short("old Woman");
set_long("An old woman.\n"
       + "She is very old and as you look at her,\n"
       + "you think that she might have seen a lot of things in her life.\n"
       + "Maybe you should ask her a few things.\n");  
set_level(1);
set_n_wc(5);
set_n_ac(35);
set_gender(2);
set_al(0);
}
}
void init() {
 ::init();
 add_action("ask","ask");
}

int ask(string str) {
if (!(str=="woman about jabberwocky" || str=="woman about monster" ||
      str=="woman about weapon" || str=="woman about armour" || str=="woman about king")) 
   {
   write("The woman looks at you.\n");
   return 1;
   }
if (str=="woman about jabberwocky") 
   {
   write("The woman tells you: Jabberwocky is hard to kill. Many men have failed before.\n");
   write("She tells you: You need a special weapon and armour, and help from the king.\n");
   write("She tells you: And even then your chances aren't really good\n");
   return 1;
   }
if (str=="woman about monster")
   {
   write("The woman tells you: The monster is called Jabberwocky.\n");
   return 1;
   }
if (str=="woman about weapon")
   {
   write("The woman tells you: Only one special weapon can kill this monster.\n");
   write("The woman tells you: It is a lance, try to win it in tournament.\n");
   return 1;
   }
if (str=="woman about armour")
   {
   write("She tells you: You shouldn't try to kill the monster without the right armour.\n");
   return 1;
   }
if (str=="woman about king")
   {
   write("The woman tells you: Manage to get the king to support you, you need his help.\n");
   if (counter <=2) 
      {  
      write("She gives you a key.\n");
      transfer(clone_object("/players/tegerl/jabberwocky/obj/key"),this_player());
      counter++;      
      }
     else
      {
      write("But I can't help you now, come later.\n");
      }  
   return 1;
   }
}