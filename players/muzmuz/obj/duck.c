inherit "/obj/thing";
reset (arg) {
::reset (arg);
if (arg) return;
set_name ("rubber duck");
set_alias ("duck");
set_short ("rubber duck");
set_long ("A cute yellow rubber duck which wants to have a bath\n");
}
