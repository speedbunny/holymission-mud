inherit "/obj/corpse";

void reset(int arg){
 ::reset();
if (arg) return;
 set_name("knight");
 decay=1;
}

