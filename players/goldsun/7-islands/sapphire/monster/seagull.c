inherit "obj/monster";

void reset(int i){
string type;
 ::reset(i);
 
 if (i) return;
 type=({ "curious", "dirty-looking", "happy" })[random(3)];
 set_name(type + " seagull");
 set_alias("bird");
 set_race("seagull");
 set_gender(random(2)+1); 
 set_long("A " + type + " seagull. ");
 load_chat(20, ({ "Seagull squawks happily.\n",
  	          "Seagull snaps its beak.\n",
		  "Seagull seems to grin at you.\n",
 		  "Seagull flies past you, squawking.\n" }));
 set_level(7+random(5));
}
