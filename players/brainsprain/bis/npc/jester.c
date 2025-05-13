inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
  ::reset(arg);
if(arg) return;
    set_name("jester");
    set_race("gnome");
    set_gender(1);
    set_alias("court jester");
    set_alt_name("man");
    set_short("Court Jester");
            set_long(
"This gnome performs a jig from foot to foot and merrily spins about "+
"the room.  His jester's cap bops about his head trying in vain to stay "+
"upright.  Bells jingle and jangle from the many places on his motley coat. "+
"He has several juggling balls in his hand.\n")+
    set_level(7);
    set_hp(150);
    set_al(10);
    set_ac(2);
    set_wc(9);
      load_chat(10, ({
"The jester juggles his balls.\n",
"Jester says: Like my balls?\n",
"Jester falls on his ass.\n",
"Jester says: How may i help you nuncle?\n",
"Jester says: I would rather be a fool than a wise man.\n",
 }));
  move_object(clone_object(bi+"/j_cap.c"),this_object());
  move_object(clone_object(bi+"/balls.c"),this_object());
  init_command("wear cap");
    }
