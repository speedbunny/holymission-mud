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
 set_long(
"A " + type + " seagull.  Its feathers are covered in grime from the seaside.  "+
"Its beak opens and closes as it restlessly flaps its wings.  This bird keeps "+
"hopping into the air and flying around looking for something to eat.\n");
 load_chat(20, ({ 
   "The seagull squawks happily.\n",
   "The seagull snaps its beak.\n",
   "The seagull seems to grin at you.\n",
   "The seagull flies past you, squawking.\n" 
 }));
 set_level(7+random(5));
}
