inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
   load_chat(14,({"Billy hiccups.\n",
	          "Billy says: Ho bartender. One rum again !\n",
	          "Billy drinks rum.\n",
		  "Bartender says: Billy, I think you are drunk.\n"+
	          "Billy says: Ha ! Bring me rum again !\n",
	          "Billy grins at you.\n",
	   	  "Billy says: Hi adventurer.\n"}));
if (arg) return;
set_name("billy");
set_race("giant");
set_short("Sailor Billy");
set_long("This is sailor Billy. He is tall. His body\n"
         "is well built. He is waiting for job here.\n");
set_level(30);
set_gender(1);
set_wc(44);
set_ac(13);
set_size(4);          
}

