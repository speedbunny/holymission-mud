inherit "obj/monster";
reset(arg) {
::reset(arg);
if (arg) return;
set_size(4);
set_gender(1);
set_level(100);
set_wc(1);
set_ac(1);
set_hp(1);
set_name("lord");
set_short("The Lord Of the Manor");
set_long("The Lord of the Manor.\n"+ 
"This huge figure of a man rules over this land.\n");

}
