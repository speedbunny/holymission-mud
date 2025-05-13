#pragma strict_types
inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if(!arg) {
	set_name("priest");
	set_level(10);
	set_race("human");
	set_al(200);
	set_short("a priest");
	set_long(
	  "The priest is the only remaining priest of Felnor in this world. He\n"+
	  "is dressed in pure white and wears the symbol of his deity on his chest.\n"+
	  "Felnor was the God of Wisdom in ages long past who prospered the land\n"+
	  "and people until the Vampire King challenged his rule. The Vampire King\n"+
	  "along with the armies of the dead invaded Felnor's realm and conquered\n"+
	  "it. This priest is the last of the faithful and he fights to the end\n"+
	  "to maintain Felnor's tenuous hold on this world.\n");
	set_wc(12); 
	set_ac(5);
	set_no_steal();
	load_chat(40,({ 
	    "The priest says: Halt trespasser what is your business here?\n",
	    "The priest says: I am the last of Felnor's faithful, who are you?\n",
	    "The priest says: Sacrifice money to Felnor and you will find favour.\n",
	    "The priest says: Felnor battles with the Vampire King.\n",
	  }));
    }
}
