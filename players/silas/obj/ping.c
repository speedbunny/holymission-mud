/* This was origianally written by Briareos on the Terrapin MUD 


   This code is copyright 1991 by John Wu.
   Permission is hereby granted to freely distribute this code as
   long as this copyright notice stays intact, and that any modifications
   to the code are clearly documented, including credits as to who
   made the modifications.

 */

status bing_on;

reset(arg) {
   if (arg) return;
   bing_on = 0;
   return 1;
}

init() {
    add_action("get", "get");
    add_action("get", "take");
    add_action("turn_on", "turnon");
    add_action("turn_off", "turnoff");
    bing_on = 0;
    return 1;
}

short() { return "A unique machine"; }

long() {
    write("A complex set of dials and switches that covers the front\n");
    write("panel of this device.  You do see two words that you make out:\n");
    write("turnon----turnoff\n\n");
}

id(str) { return str == "machine"; }

get() {
   write("Sorry, it's too heavy to take with you and cannot be moved.\n");
   return 0;
}

turn_on() {
    int i;
    if (!bing_on) {
        i = set_heart_beat(1);
        bing_on = 1;
        return 1;
    }
    write("The machine is already on.\n");
    return 1;
}

turn_off() {
    int i;
    if (bing_on) {
        i = set_heart_beat(0);
        bing_on = 0;
        return 1;
    }
    write("The machine does nothing.\n");
    return 1;
}

heart_beat() {
    int i;
    say("It's the machine that goes PING!\n");
    return 1;
}
