inherit "/obj/treasure";

void reset(int i){
 ::reset(i);
 if (i) return;
 set_name("tooth");
 set_short("A tooth");
 set_long("A small mouse tooth.\nYou have never seen such tooth before.\n"+
          "It looks valuable.\n");
 set_weight(1);
 set_value(20);
}

