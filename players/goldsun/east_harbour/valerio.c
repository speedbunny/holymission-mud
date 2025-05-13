inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
   load_chat(18,({"Valerio smiles.\n",
	          "Valerio looks drunk.\n",
		  "Valerio burps.\n",
	          "Valerio stands and orders beer.\nValerios sits down.\n",
		  "Valerio mumbles something about huge whale.\n",
		  "Valerio looks around.\n",
	          "Valerio says: Hi.\n"}));
if (arg) return;
set_name("valerio");
set_race("half-elf");
set_short("Fisher Valerio");
set_long("Fisher Valerio. He is small, but not weak!\n"+
         "He likes fishing at the coast, but there are\n"+
         "no fishes now.\n");
set_level(49);
set_wc(48);
set_gender(1);
set_ac(13);
set_size(3);          
}

