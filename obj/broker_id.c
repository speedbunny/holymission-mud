id(str) { return str=="broker_id"; }

extra_look() { return capitalize(environment()->query_pronoun())+" has an account at the Money Brokers Assoc"; }

/* query_auto_load() { return "/obj/broker_id:normal"; }i */

drop() { return 1; } 	/* dont drop it */
