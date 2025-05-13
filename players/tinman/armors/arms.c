inherit "/obj/weapon";
void reset( int tick ){

      ::reset( tick );
      if(tick) return;

set_name("arm");
set_short("monk statue arm");
set_long("A broken arm of the monk statue of Tinman's workroom\n");
set_weight(1);
set_class(20);
}
int weapon_hit (object victim) {
switch( random(600)/ 100){
case 0: write("The monk statue makes a wide kick smashing you on your thigh.\n");
say("The monk statue makes a wide kick smashing his enemy on the thigh.\n"); break;
case 1: write("The monk statue punches at your shoulder breaking a bone.\n");
say("The monk statue punches at his victim's shoulder breaking a bone.\n"); break;
case 2: write("The monk statue picks you up from your leg and throws you.\n");
say("The monk statue picks his victim up from his leg and throws him.\n"); break;
case 3: write("The monk statue chops down at you bearing missing you.\n");
say("The monk statue chops down at his victim bearing missing his victim.\n"); break;
case 4: write("The monk statue claws you making 5 long gashes on your chest.\n");
say("The monk statue claws his victim making 5 long gashes on his chest.\n"); break;
case 5: write("The monk statue jumpkicks at your face knocking out a teeth.\n");
say("The monk statue jumpkicks at his victim's face lnocking out a teeth.\n"); break;
}
}
