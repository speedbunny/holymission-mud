id(str) { return str=="danseuse_ticket"; }

int coins=0;

extra_look() { return capitalize(environment()->query_pronoun())
            + " got "+ coins + " coins from the danseuse"; }

set_coins(c) { coins=c; }

get () {return 1;} 
drop() { return 1; }    /* dont drop it */
