/* Tegerl, 24.3.1995 */
/* monsters/kni */

inherit "obj/monster";
#define TP this_player()
/* Mangla: You have extra semi colon at end of next line. :)
#define TP this_player();
*/
#define TPN TP->query_name()
#define TPOBJ TP->query_objectice()
#define TPPOS TP->query_possessive()


reset(arg) 
{
::reset(arg);

if (!arg){

set_name("knight");
set_alt_name("man");
set_race("human");
set_short("Huge Knight");
set_long("A huge knight.\n"
       + "Man, this guy looks strong.\n"
       + "He isn't armed, but you know that you would have no chance.\n"
       + "You are sure that he is here to kill Jabberwocky.\n");  
set_level(500);
set_n_wc(100);
set_n_ac(100);
set_gender(1);
set_al(0);
set_aggressive(0);

}
}


void init() {
 ::init();
 add_action("_north","north");
}

int _north() {
if (present("AnUglyLookingRing",TP)
 && present("AWornDownArmour",TP)) 
{ if (present("ABadLance",TP)) {
write("The knight says: Yes, you are the one.\n");
}
return 0;
}
write("The knight bars your way and says: You are not the one to kill Jabberwocky.\n");
return 1;
}
