 
#include "std.h"

#undef  EXTRA_RESET
#define EXTRA_RESET     extra_reset(arg);

string chats,a_chats;
object creature,tam;

extra_reset(arg) {
object cx;

    if (!arg) { 
      if (!chats) {
	chats = allocate(4);
	chats[0] = "The Duppy Conqueror says: Now you get what you want!\n";
	chats[1] = "The Duppy Conqueror asks: Do you want more?\n";
	chats[2] = "The Duppy Conqueror says: Dem stab you in de back.\n"+
		   "                          And dem claim dat you're not lookin'.\n";
	chats[3] = "The Duppy Conqueror says: Who de cap fits, let dem wear it.\n";
      }
      if (!a_chats) {
	a_chats= allocate(2);
a_chats[0] = "The Duppy Conqueror says: I and I a go chant down Babylon system.\n";
a_chats[1] = "The Duppy Conqueror says: Give thanks and praises to Jah, Rastafari!.\n";
      }
    }

    if ((creature=present("conqueror")) && living (creature)) return;
    creature=clone_object("/obj/monster");
    creature->set_name("conqueror");
    creature->set_level(30);
    creature->set_hp(500);
    creature->set_sp(500);
    creature->set_ep(777777);
    creature->set_ac(50);
    creature->set_wc(50);
    creature->set_al(-1000);
    creature->load_chat(20,chats);
    creature->load_a_chat(80,a_chats);
    creature->set_short("Duppy Conqueror");
creature->set_long
 ("A Duppy Conqueror trying to find some ganja.\n"); 
    creature->set_aggressive(0);

    tam = clone_object("players/rasta/obj/tam");
    move_object(tam,creature);
    move_object(creature,this_object());
    return 1;
}

#undef EXTRA_MOVE2
#define EXTRA_MOVE2\
  if ((creature=present("conqueror")) && living(creature)) {\
     write("The Duppy Conqueror blocks your way.\n");\
     return 1;\
  }\

TWO_EXIT("players/rasta/room/wind1","south",
	"players/rasta/room/maze1","north",
	"Ganja jungle",
"Wizard Rasta used to operate here in a haze of ganja and hallucinogenic\n"+
"white rum and when the pressure drops down on him he indulges in haphazard,\n"+
"almost slap-stick violence toward everyone who happens to be around and\n"+
"unarmed.\n",1)
