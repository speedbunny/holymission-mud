inherit "/obj/thing";
#define TP this_player()
reset (arg) {
if (arg) return 1;
set_name("skull");
set_short("A human skull.");
set_long("A Human skull with golden teeth.  It is not verry decayed.");
set_value(500);
set_weight(1);
}
