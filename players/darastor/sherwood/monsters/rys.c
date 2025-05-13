inherit "obj/monster";
void reset(int arg)
 { ::reset(arg);
if (arg) return;
set_name("lynx");
set_alias("tiger");
set_race("lynx");
set_short("Lynx Ostrovid");
set_long("This is Lynx Ostrovid. \n"
         +"It is strange animal which looks like tiger.\n");
set_level(17);
set_ac(3);
set_wc(25);
set_al(-400);
set_hp(2000);
set_aggressive(1);
set_size(3);
add_money(1200);
move_object(clone_object("/players/goldsun/sherwood/obj/tooth"),this_object());
command("wield tooth");
}
