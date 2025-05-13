#include "setlight.h"
#pragma strict_types
int full;

void reset(int arg) { if (!arg) full = 1; }
int id(string str) {return (str=="champagne" && full) || str=="glass"; }


int get() {return 1; }
string short() {return full ? "A glass of champagne" : "An empty glass"; }
string long() {return full ? "A glass of champagne" : "An empty glass"; }
string query_name() {return full ? "champagne" : "glass"; }
int query_value() {return full ? 30 : 5; }
void init() {add_action("drink", "drink"); }
int drink(string str) {
if(str && str !="champagne" && str !="from glass") return 0;
if(!full) return 0;
if(!this_player()->drink_alco(2)) return 1;
full = 0;
write("HAPPY NEW YEAR!\n");
say((string)this_player()->query_name() + "drinks a glass of champagne.\n");
return 1;
}
