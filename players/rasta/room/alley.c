 
#include "std.h"

#undef  EXTRA_RESET
#define EXTRA_RESET	extra_reset(arg);

string chats,a_chats;
object creature;

extra_reset(arg) {
object cx;

    if (!arg) { 
      if (!chats) {
	chats = allocate(4);
	chats[0] = "You smell a diabolic stench.\n";
	chats[1] = "The stench makes you shiver.\n";
	chats[2] = "The creature seems to be hungry.\n";
	chats[3] = "The creature eyes you waryly.\n";
      }
      if (!a_chats) {
  	a_chats= allocate(3);
	a_chats[0] = "The creature rips out your guts.\n";
	a_chats[1] = "Think about what you are doing.\n";
	a_chats[2] = "Life is so precious. When you die you don't come back!!!\n";
      }
    }

  if ((creature=present("spirit")) && living (creature)) return;
    creature=clone_object("/obj/monster");
  creature->set_name("spirit");
    creature->set_level(30);
  creature->add_money(1000);
    creature->set_hp(500);
    creature->set_sp(500);
    creature->set_ep(777777);
    creature->set_ac(50);
    creature->set_wc(50);
    creature->set_al(-1000);
    creature->load_chat(20,chats);
    creature->load_a_chat(80,a_chats);
   creature->set_short("A terrifying spirit");
    creature->set_aggressive(0);
    move_object(creature,this_object());
    return 1;
}

#undef EXTRA_MOVE2
#define EXTRA_MOVE2\
 if ((creature=present("spirit")) && living(creature)) {\
   write("The spirit blocks your way.\n");\
     return 1;\
  }\

TWO_EXIT("players/rasta/room/afflict","north",
    "players/rasta/room/shack","southeast",
"Alley",
"Lit only by the occasional flickering oil lamp in the window this place\n"
+"looks like a desolate war zone of zinc, cement, and spit.\n",1)
