

/* Tegerl, 28.3.1995 */
/* monsters/ow */


inherit "obj/monster";

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
if (!(str=="woman for ring")) 
   {
   write("The woman looks at you.\n");
   return 1;
   }

if (str=="woman for ring")
   {
   write("The woman tells you: Don't junk it again.\n"); 
      {  
      write("She gives you a ring.\n");
      transfer(clone_object("/players/moonchild/wedding/ring"),this_player());     
      }  
   return 1;
   }
}
