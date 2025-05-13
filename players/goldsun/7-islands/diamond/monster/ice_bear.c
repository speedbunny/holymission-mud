inherit "/obj/monster";

#define TH(x) transfer(clone_object(x),this_object())

void add_stuff()
{
TH("players/goldsun/7-islands/diamond/obj/claw");
TH("players/goldsun/7-islands/diamond/obj/fur");
command("wear fur");
command("wield claw");
}

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name("ice bear");
set_race("bear");
set_short("An ice bear");
set_gender(1);
set_long("A huge ice bear. He is white with black eyes and nose.\n"+
	 "His body is well build. He looks very danger.\n");
set_level(54+random(10));
set_wc(49);
set_ac(5);
set_size(4);
set_al(-130);
add_stuff();
set_aggressive(1);
}

