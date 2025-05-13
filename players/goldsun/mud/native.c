inherit "/obj/monster";
#define NAME ({"zango",1,"jurasko",1,"bing-ovi",1,"fereira",2,"nganga",2,\
	       "hubba",1,"nefron",1,"zelonga",2,"papula",1,"frayer",1})
#define TH(x) move_object(clone_object(x),this_object())

void add_stuff()
{
TH("players/goldsun/7-islands/topaz/obj/hat");
TH("players/goldsun/7-islands/topaz/obj/amulet");
TH("players/goldsun/7-islands/topaz/obj/bow");
TH("players/goldsun/7-islands/topaz/obj/quiver");
TH("players/goldsun/7-islands/topaz/obj/ring");
TH("players/goldsun/7-islands/topaz/obj/tigerfur");
command("wear hat");
command("wear ring");
command("wear amulet");
command("wear tigerfur");
command("wield bow");
}

void reset(int arg)
 {
int i;

 ::reset(arg);
if (arg) return;
i=random(sizeof(NAME)/2)*2;
set_name(NAME[i]);
set_race("native");
set_short("A rich native");
set_gender(i+1);
set_long("You see a rich native.\n"+capitalize(query_pronoun())+" looks "+
	 "very rich and thirsty.\n");
set_level(14+random(10));
set_wc(9+level);
set_ac(4);
set_size(3);
set_al(30);
add_money(level*2500);
add_stuff();
}

